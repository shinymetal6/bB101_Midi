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
    send_control_change(CC_AFXFREQUENCY,value);
}

void bB101_Midi_MainWindow::on_Resonance_valueChanged(int value)
{
QString str,sysex_data;
    str.setNum(value);
    ui->ResonanceValue->setText(str);
    send_control_change(CC_AFXRESONANCE,value);
}

static void qSleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

void bB101_Midi_MainWindow::on_AFX_Enable_checkBox_clicked(bool checked)
{
    if ( checked == true )
    {
        ui->effectband_frame->setEnabled(true);
        ui->effectcontrol_frame->setEnabled(true);
        ui->effecttype_frame->setEnabled(true);
    }
    else
    {
        ui->effectband_frame->setEnabled(false);
        ui->effectcontrol_frame->setEnabled(false);
        ui->effecttype_frame->setEnabled(false);
    }
    send_control_change(CC_AFXENABLE,checked);
}

void bB101_Midi_MainWindow::on_AFX_Pot_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    send_control_change(CC_AFXCONTROLSOURCE,AFX_CONTROL_POT);
}

void bB101_Midi_MainWindow::on_AFX_MIDI_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    send_control_change(CC_AFXCONTROLSOURCE,AFX_CONTROL_MIDI);
}

void bB101_Midi_MainWindow::on_AFX_CV_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    send_control_change(CC_AFXCONTROLSOURCE,AFX_CONTROL_CV);
}

void bB101_Midi_MainWindow::on_VCFLP_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    send_control_change(CC_AFXTYPE,AFX_CONTROL_LP);
}

void bB101_Midi_MainWindow::on_VCFBP_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    send_control_change(CC_AFXTYPE,AFX_CONTROL_BP);
}

void bB101_Midi_MainWindow::on_VCFHP_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    send_control_change(CC_AFXTYPE,AFX_CONTROL_HP);
}

void bB101_Midi_MainWindow::on_AFXMOOG1_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    ui->effectband_frame->setEnabled(true);
    ui->Cutoff_label->setText("Cutoff");
    ui->Resonance_label->setText("Resonance");
    send_control_change(CC_AFXTYPE,AFXTYPE_MOOG1);
}


void bB101_Midi_MainWindow::on_AFXMOOG2_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    ui->effectband_frame->setEnabled(true);
    ui->Cutoff_label->setText("Cutoff");
    ui->Resonance_label->setText("Resonance");
    send_control_change(CC_AFXTYPE,AFXTYPE_MOOG2);
}

void bB101_Midi_MainWindow::on_AFXPhaser_radioButton_clicked(bool checked)
{
    Q_UNUSED(checked);
    ui->effectband_frame->setEnabled(false);
    ui->Cutoff_label->setText("Rate");
    ui->Resonance_label->setText("Feedback");
    send_control_change(CC_AFXTYPE,AFXTYPE_PHASER);
}

void bB101_Midi_MainWindow::applyReceivedAFXParams()
{

}
