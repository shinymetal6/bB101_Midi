#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiFile.h>
#include <QDebug>

extern  QByteArray  sysex_msg;
extern  QMidiOut    MidiOut;

void bB101_Midi_MainWindow::on_Delay_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value*50);
        ui->DelayValue->setText(str);
        /*
        if ( value < 10 )
            sysex_data = "F044030" + str + "F7";
        else
            sysex_data = "F04403" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
        */
}
