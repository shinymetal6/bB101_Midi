#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiFile.h>

extern  QMidiOut MidiOut;

void bB101_Midi_MainWindow::on_Cutoff_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->CutoffValue->setText(str);
        /*
        if ( value < 10 )
            sysex_data = "F044000" + str + "F7";
        else
            sysex_data = "F04400" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
*/
}


void bB101_Midi_MainWindow::on_Resonance_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->ResonanceValue->setText(str);
        /*
        if ( value < 10 )
            sysex_data = "F044000" + str + "F7";
        else
            sysex_data = "F04400" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
*/
}
