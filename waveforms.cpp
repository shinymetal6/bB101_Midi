#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiFile.h>

extern  QMidiOut MidiOut;




#define	CC_OSCWAVE0             0x00
#define	CC_OSCWAVE1				0x01
#define	CC_OSCWAVE2				0x02
#define	CC_OSCWAVE3				0x03
#define	CC_OSCVOLUME0			0x04
#define	CC_OSCVOLUME1			0x05
#define	CC_OSCVOLUME2			0x06
#define	CC_OSCVOLUME3			0x07
#define	CC_OSCDUTY0				0x08
#define	CC_OSCDUTY1				0x09
#define	CC_OSCDUTY2				0x0A
#define	CC_OSCDUTY3				0x0B
#define	CC_OSCDETUNE0			0x0C
#define	CC_OSCDETUNE1			0x0D
#define	CC_OSCDETUNE2			0x0E
#define	CC_OSCDETUNE3			0x0F
#define	SINE                    0
#define	TRIANGLE				1
#define	SQUARE					2

void bB101_Midi_MainWindow::on_pushButton_Wave1_clicked()
{
QString PixMapName="";
    wave_state[0] ++;
    switch ( wave_state[0])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; MidiOut.controlChange(CC_OSCWAVE0,SINE);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; MidiOut.controlChange(CC_OSCWAVE0,TRIANGLE); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; MidiOut.controlChange(CC_OSCWAVE0,SQUARE);break;
    default :   PixMapName=":/Icons/sin.bmp";   MidiOut.controlChange(CC_OSCWAVE0,SINE);wave_state[0] = 0;break;
    }
    ui->pushButton_Wave1->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave2_clicked()
{
QString PixMapName="";
    wave_state[1] ++;
    switch ( wave_state[1])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; MidiOut.controlChange(CC_OSCWAVE1,SINE);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; MidiOut.controlChange(CC_OSCWAVE1,TRIANGLE); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; MidiOut.controlChange(CC_OSCWAVE1,SQUARE);break;
    default :   PixMapName=":/Icons/sin.bmp";   MidiOut.controlChange(CC_OSCWAVE1,SINE);wave_state[1] = 0;break;
    }
    ui->pushButton_Wave2->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave3_clicked()
{
QString PixMapName="";
    wave_state[2] ++;
    switch ( wave_state[2])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; MidiOut.controlChange(CC_OSCWAVE2,SINE);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; MidiOut.controlChange(CC_OSCWAVE2,TRIANGLE); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; MidiOut.controlChange(CC_OSCWAVE2,SQUARE);break;
    default :   PixMapName=":/Icons/sin.bmp";   MidiOut.controlChange(CC_OSCWAVE2,SINE);wave_state[2] = 0;break;
    }
    ui->pushButton_Wave3->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave4_clicked()
{
QString PixMapName="";
    wave_state[3] ++;
    switch ( wave_state[3])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; MidiOut.controlChange(CC_OSCWAVE3,SINE);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; MidiOut.controlChange(CC_OSCWAVE3,TRIANGLE); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; MidiOut.controlChange(CC_OSCWAVE3,SQUARE);break;
    default :   PixMapName=":/Icons/sin.bmp";   MidiOut.controlChange(CC_OSCWAVE3,SINE);wave_state[3] = 0;break;
    }
    ui->pushButton_Wave4->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_Volume1_valueChanged(int value)
{
QString str;
float vol_value;
    str.setNum(value);
    ui->VolumeValue1->setText(str);
    vol_value = (float ) value * 12.7F;
    MidiOut.controlChange(CC_OSCVOLUME0,(int )vol_value);
}

void bB101_Midi_MainWindow::on_Volume2_valueChanged(int value)
{
    QString str;
    float vol_value;
        str.setNum(value);
        ui->VolumeValue2->setText(str);
        vol_value = (float ) value * 12.7F;
        MidiOut.controlChange(CC_OSCVOLUME1,(int )vol_value);
}

void bB101_Midi_MainWindow::on_Volume3_valueChanged(int value)
{
    QString str;
    float vol_value;
        str.setNum(value);
        ui->VolumeValue3->setText(str);
        vol_value = (float ) value * 12.7F;
        MidiOut.controlChange(CC_OSCVOLUME2,(int )vol_value);
}

void bB101_Midi_MainWindow::on_Volume4_valueChanged(int value)
{
    QString str;
    float vol_value;
        str.setNum(value);
        ui->VolumeValue4->setText(str);
        vol_value = (float ) value * 12.7F;
        MidiOut.controlChange(CC_OSCVOLUME3,(int )vol_value);
}

void bB101_Midi_MainWindow::on_Duty1_valueChanged(int value)
{
    QString str;
    float duty_value;
        str.setNum(value);
        ui->DutyValue1->setText(str);
        duty_value = (float ) value * 12.7F;
        MidiOut.controlChange(CC_OSCDUTY0,(int )duty_value);
}

void bB101_Midi_MainWindow::on_Duty2_valueChanged(int value)
{
    QString str;
    float duty_value;
        str.setNum(value);
        ui->DutyValue2->setText(str);
        duty_value = (float ) value * 12.7F;
        MidiOut.controlChange(CC_OSCDUTY1,(int )duty_value);
}

void bB101_Midi_MainWindow::on_Duty3_valueChanged(int value)
{
    QString str;
    float duty_value;
        str.setNum(value);
        ui->DutyValue3->setText(str);
        duty_value = (float ) value * 12.7F;
        MidiOut.controlChange(CC_OSCDUTY2,(int )duty_value);
}

void bB101_Midi_MainWindow::on_Duty4_valueChanged(int value)
{
    QString str;
    float duty_value;
        str.setNum(value);
        ui->DutyValue4->setText(str);
        duty_value = (float ) value * 12.7F;
        MidiOut.controlChange(CC_OSCDUTY3,(int )duty_value);
}


void bB101_Midi_MainWindow::on_Detune1_valueChanged(int value)
{
    QString str;
    float detune_value;
        str.setNum(value);
        ui->DetuneValue1->setText(str);
        detune_value = ((float ) value + 10.0F)* 6.35F;
        MidiOut.controlChange(CC_OSCDETUNE0,(int )detune_value);
}

void bB101_Midi_MainWindow::on_Detune2_valueChanged(int value)
{
    QString str;
    float detune_value;
        str.setNum(value);
        ui->DetuneValue2->setText(str);
        detune_value = ((float ) value + 10.0F)* 6.35F;
        MidiOut.controlChange(CC_OSCDETUNE1,(int )detune_value);
}

void bB101_Midi_MainWindow::on_Detune3_valueChanged(int value)
{
    QString str;
    float detune_value;
        str.setNum(value);
        ui->DetuneValue3->setText(str);
        detune_value = ((float ) value + 10.0F)* 6.35F;
        MidiOut.controlChange(CC_OSCDETUNE2,(int )detune_value);
}

void bB101_Midi_MainWindow::on_Detune4_valueChanged(int value)
{
    QString str;
    float detune_value;
        str.setNum(value);
        ui->DetuneValue4->setText(str);
        detune_value = ((float ) value + 10.0F)* 6.35F;
        MidiOut.controlChange(CC_OSCDETUNE3,(int )detune_value);
}
