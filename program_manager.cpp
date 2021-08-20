#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiFile.h>
#include <QDebug>

extern  QByteArray  sysex_msg;
extern  QMidiOut    MidiOut;


void qSleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

void bB101_Midi_MainWindow::on_ReadCurrentProgram_clicked()
{
    QByteArray sdata_dumpprog = QByteArray::fromHex("F0302300F7");
    qDebug() << "txed " << sdata_dumpprog;

    sysex_msg = "No RX";
    MidiOut.sendSysEx(sdata_dumpprog);
    qSleep(100);
    if ( sysex_msg != "No RX" )
    {
        if ( sysex_msg[1] == 'b' )
            qDebug() << "received " << sysex_msg;
        else
            qDebug() << "Invalid program";
    }
    else
        qDebug() << "RX Failed";
}

void bB101_Midi_MainWindow::on_ReadProgram_clicked()
{
    QString str,sysex_data;
        str.setNum(ui->Read_lcdNumber->value());
        ui->DetuneValue3->setText(str);
        if ( ui->Read_lcdNumber->value() < 10 )
            sysex_data = "F030220" + str + "F7";
        else
            sysex_data = "F03022" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        sysex_msg = "No RX";
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
        qSleep(100);
        if ( sysex_msg != "No RX" )
        {
            if ( sysex_msg[1] == 'b' )
                qDebug() << "received " << sysex_msg;
            else
                qDebug() << "Invalid program";
        }
        else
            qDebug() << "RX Failed";
}

void bB101_Midi_MainWindow::on_IncrementReadProg_pushButton_clicked()
{
    if ( ui->Read_lcdNumber->value() < 32)
        ui->Read_lcdNumber->display(ui->Read_lcdNumber->value()+1);
}

void bB101_Midi_MainWindow::on_DecrementReadProg_pushButton_clicked()
{
    if ( ui->Read_lcdNumber->value() > 0)
        ui->Read_lcdNumber->display(ui->Read_lcdNumber->value()-1);
}

void bB101_Midi_MainWindow::on_IncrementSaveProg_pushButton_clicked()
{
    if ( ui->Save_lcdNumber->value() < 32)
        ui->Save_lcdNumber->display(ui->Save_lcdNumber->value()+1);
}

void bB101_Midi_MainWindow::on_DecrementSaveProg_pushButton_clicked()
{
    if ( ui->Save_lcdNumber->value() > 0)
        ui->Save_lcdNumber->display(ui->Save_lcdNumber->value()-1);
}


void bB101_Midi_MainWindow::on_Erase_pushButton_clicked()
{

}


void bB101_Midi_MainWindow::on_IncrementEraseProg_pushButton_clicked()
{
    if ( ui->Erase_lcdNumber->value() < 32)
        ui->Erase_lcdNumber->display(ui->Erase_lcdNumber->value()+1);
}

void bB101_Midi_MainWindow::on_DecrementEraseProg_pushButton_clicked()
{
    if ( ui->Erase_lcdNumber->value() > 0)
        ui->Erase_lcdNumber->display(ui->Erase_lcdNumber->value()-1);

}
