#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiFile.h>
#include <QDebug>

extern  QByteArray  sysex_msg;
extern  QMidiOut    MidiOut;

void bB101_Midi_MainWindow::on_Reset_clicked()
{
    QByteArray sdata_reset = QByteArray::fromHex("F0305555F7");
    MidiOut.sendSysEx(sdata_reset);
    initVars();
}



void bB101_Midi_MainWindow::on_CmdSource_pushButton_clicked()
{

}

void bB101_Midi_MainWindow::on_MIDI_radioButton_clicked()
{
    ui->MIDI_radioButton->setChecked(true);
    ui->CV_radioButton->setChecked(false);
    ui->Pot_radioButton->setChecked(false);
}

void bB101_Midi_MainWindow::on_CV_radioButton_clicked()
{
    ui->MIDI_radioButton->setChecked(false);
    ui->CV_radioButton->setChecked(true);
    ui->Pot_radioButton->setChecked(false);
}

void bB101_Midi_MainWindow::on_Pot_radioButton_clicked()
{
    ui->MIDI_radioButton->setChecked(false);
    ui->CV_radioButton->setChecked(false);
    ui->Pot_radioButton->setChecked(true);
}

