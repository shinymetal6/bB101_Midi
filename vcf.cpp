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
}


void bB101_Midi_MainWindow::on_Resonance_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->ResonanceValue->setText(str);
}

static void qSleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

void bB101_Midi_MainWindow::on_VCF_Enable_checkBox_clicked(bool checked)
{
    send_control_change(CC_VCFENABLE,checked);
    /*
    qSleep(100);

    if ( checked )
    {
        if ( ui->VCF_MIDI_radioButton->isChecked() )
            on_VCF_MIDI_radioButton_clicked(true);
        if ( ui->VCF_Pot_radioButton->isChecked() )
            on_VCF_Pot_radioButton_clicked(true);
        if ( ui->VCF_CV_radioButton->isChecked() )
            on_VCF_CV_radioButton_clicked(true);
    }
    */
}

void bB101_Midi_MainWindow::on_VCF_Pot_radioButton_clicked(bool checked)
{
    send_control_change(CC_VCFSOURCE,VCF_CONTROL_POT);
}

void bB101_Midi_MainWindow::on_VCF_MIDI_radioButton_clicked(bool checked)
{
    send_control_change(CC_VCFSOURCE,VCF_CONTROL_MIDI);
}

void bB101_Midi_MainWindow::on_VCF_CV_radioButton_clicked(bool checked)
{
    send_control_change(CC_VCFSOURCE,VCF_CONTROL_CV);
}

void bB101_Midi_MainWindow::on_VCFLP_radioButton_clicked(bool checked)
{
    send_control_change(CC_VCFTYPE,VCF_TYPE_LP);

}

void bB101_Midi_MainWindow::on_VCFBP_radioButton_clicked(bool checked)
{
    send_control_change(CC_VCFTYPE,VCF_TYPE_BP);

}

void bB101_Midi_MainWindow::on_VCFHP_radioButton_clicked(bool checked)
{
    send_control_change(CC_VCFTYPE,VCF_TYPE_HP);

}
