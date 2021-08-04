#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiIn.h>
#include <QMidiFile.h>
#include <QDebug>


/*
 * https://github.com/waddlesplash/QMidi
 */

QMidiOut    MidiOut;
QMidiIn     MidiIn;
QMidiFile   MidiFile;
QString     bB101_ID;
QByteArray  sysex_msg;

bB101_Midi_MainWindow::bB101_Midi_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bB101_Midi_MainWindow)
{
    ui->setupUi(this);
    qDebug() << "bB101_Midi\nOut Devices :";
    initVars();
    QMap<QString, QString> out_vals = QMidiOut::devices();
    ui->statusbar->showMessage("Looking for bB101 ...");
    for (QString key : out_vals.keys()) {
        QString value = out_vals.value(key);
        qDebug() << "Key : "  << key.toUtf8().constData() << "  \tID : " << value.toUtf8().constData();
        if ( value == "bB101")
        {
            bB101_ID = value;
            MidiOut.connect(key);
            MidiIn.connect(key);
            MidiIn.start();
            qDebug() << "bB101 connected to out";
            ui->statusbar->showMessage("bB101 connected");
        }
    }
}

bB101_Midi_MainWindow::~bB101_Midi_MainWindow()
{
    delete ui;
}


void bB101_Midi_MainWindow::on_Reset_clicked()
{
    QByteArray sdata_reset = QByteArray::fromHex("F0305555F7");
    MidiOut.sendSysEx(sdata_reset);
    initVars();
}

void qSleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

void bB101_Midi_MainWindow::on_DumpCurrentProgram_clicked()
{
    QMidiEvent event;
    event.setMessage(0x80);
    QByteArray sdata_dumpprog = QByteArray::fromHex("F0302300F7");
    sysex_msg = "No RX";
    MidiOut.sendSysEx(sdata_dumpprog);
    qSleep(100);
    if ( sysex_msg != "No RX" )
        qDebug() << "received " << sysex_msg;
}

void bB101_Midi_MainWindow::on_IncrementProg_pushButton_clicked()
{
    if ( ui->lcdNumber->value() < 32)
        ui->lcdNumber->display(ui->lcdNumber->value()+1);
}


void bB101_Midi_MainWindow::on_DecrementProg_pushButton_clicked()
{
    if ( ui->lcdNumber->value() > 0)
        ui->lcdNumber->display(ui->lcdNumber->value()-1);
}
