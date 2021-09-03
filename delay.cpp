#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiFile.h>
#include <QDebug>

extern  QByteArray  sysex_msg;
extern  QMidiOut    MidiOut;
extern  int cc_tx_enabled;

void bB101_Midi_MainWindow::on_Delay_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum((value/10)*10);
        ui->DelayValue->setText(str);
        ui->Delay->setValue((value/10)*10);
        send_control_change(CC_DELAYLEN,value/10);
}

void bB101_Midi_MainWindow::on_Flanger_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);

    //ui->Reverb_radioButton->setChecked(false);
    delay_flag |= DLY_MIXER_FLANGER_MIDI;
    delay_flag &= ~DLY_MIXER_REVERB_MIDI;
    send_control_change(CC_DLYENABLE,delay_flag);
}



void bB101_Midi_MainWindow::on_Reverb_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    //ui->Flanger_radioButton->setChecked(false);
    delay_flag |= DLY_MIXER_REVERB_MIDI;
    delay_flag &= ~DLY_MIXER_FLANGER_MIDI;
    send_control_change(CC_DLYENABLE,delay_flag);
}

void bB101_Midi_MainWindow::on_DLY_Enable_checkBox_clicked(bool checked)
{
    if ( checked )
    {
        delay_flag |= DLY_ENABLED;
        ui->delayframe->setEnabled(true);
    }
    else
    {
        delay_flag &= ~DLY_ENABLED;
        ui->delayframe->setEnabled(false);
    }
    send_control_change(CC_DLYENABLE,delay_flag);
}

extern  QByteArray  sysex_msg;

void bB101_Midi_MainWindow::applyReceivedDelayParams()
{
unsigned char delay_val;

    cc_tx_enabled = 0;
    delay_val = sysex_msg.at(PARAMS_DLY_VAL);
    qDebug() << "delay_val " << hex << delay_val;
    on_Delay_valueChanged(delay_val*10);
    cc_tx_enabled = 1;
}

void bB101_Midi_MainWindow::on_DLY_MIDI_checkBox_clicked(bool checked)
{
    send_control_change(CC_DELAYSOURCE,checked);
}
