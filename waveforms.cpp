#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiFile.h>
#include <QDebug>

extern  QMidiOut MidiOut;
int cc_tx_enabled = 1 ;

void bB101_Midi_MainWindow::send_control_change(int control_number, int value )
{
    if ( cc_tx_enabled == 1 )
        MidiOut.controlChange(control_number,value);
}

void bB101_Midi_MainWindow::on_pushButton_Wave1_clicked()
{
QString PixMapName="";
    wave_state[0] ++;
    switch ( wave_state[0])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; send_control_change(CC_OSCWAVE0,SINE);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; send_control_change(CC_OSCWAVE0,TRIANGLE); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; send_control_change(CC_OSCWAVE0,SQUARE);break;
    case    3   : PixMapName=":/Icons/noise.bmp"; send_control_change(CC_OSCWAVE0,NOISE);break;
    default :   PixMapName=":/Icons/sin.bmp";   send_control_change(CC_OSCWAVE0,SINE);wave_state[0] = 0;break;
    }
    ui->pushButton_Wave1->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave2_clicked()
{
QString PixMapName="";
    wave_state[1] ++;
    switch ( wave_state[1])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; send_control_change(CC_OSCWAVE1,SINE);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; send_control_change(CC_OSCWAVE1,TRIANGLE); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; send_control_change(CC_OSCWAVE1,SQUARE);break;
    case    3   : PixMapName=":/Icons/noise.bmp"; send_control_change(CC_OSCWAVE1,NOISE);break;
    default :   PixMapName=":/Icons/sin.bmp";   send_control_change(CC_OSCWAVE1,SINE);wave_state[1] = 0;break;
    }
    ui->pushButton_Wave2->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave3_clicked()
{
QString PixMapName="";
    wave_state[2] ++;
    switch ( wave_state[2])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; send_control_change(CC_OSCWAVE2,SINE);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; send_control_change(CC_OSCWAVE2,TRIANGLE); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; send_control_change(CC_OSCWAVE2,SQUARE);break;
    case    3   : PixMapName=":/Icons/noise.bmp"; send_control_change(CC_OSCWAVE2,NOISE);break;
    default :   PixMapName=":/Icons/sin.bmp";   send_control_change(CC_OSCWAVE2,SINE);wave_state[2] = 0;break;
    }
    ui->pushButton_Wave3->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave4_clicked()
{
QString PixMapName="";
    wave_state[3] ++;
    switch ( wave_state[3])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; send_control_change(CC_OSCWAVE3,SINE);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; send_control_change(CC_OSCWAVE3,TRIANGLE); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; send_control_change(CC_OSCWAVE3,SQUARE);break;
    case    3   : PixMapName=":/Icons/noise.bmp"; send_control_change(CC_OSCWAVE3,NOISE);break;
    default :   PixMapName=":/Icons/sin.bmp";   send_control_change(CC_OSCWAVE3,SINE);wave_state[3] = 0;break;
    }
    ui->pushButton_Wave4->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_Volume1_valueChanged(int value)
{
QString str;
float vol_value;
    str.setNum(value);
    ui->VolumeValue1->setText(str);
    ui->Volume1->setValue(value);
    vol_value = (float ) value * 12.7F;
    send_control_change(CC_OSCVOLUME0,(int )vol_value);
}

void bB101_Midi_MainWindow::on_Volume2_valueChanged(int value)
{
    QString str;
    float vol_value;
        str.setNum(value);
        ui->VolumeValue2->setText(str);
        ui->Volume2->setValue(value);
        vol_value = (float ) value * 12.7F;
        send_control_change(CC_OSCVOLUME1,(int )vol_value);
}

void bB101_Midi_MainWindow::on_Volume3_valueChanged(int value)
{
    QString str;
    float vol_value;
        str.setNum(value);
        ui->VolumeValue3->setText(str);
        ui->Volume3->setValue(value);
        vol_value = (float ) value * 12.7F;
        send_control_change(CC_OSCVOLUME2,(int )vol_value);
}

void bB101_Midi_MainWindow::on_Volume4_valueChanged(int value)
{
    QString str;
    float vol_value;
        str.setNum(value);
        ui->VolumeValue4->setText(str);
        ui->Volume4->setValue(value);

        vol_value = (float ) value * 12.7F;
        send_control_change(CC_OSCVOLUME3,(int )vol_value);
}

void bB101_Midi_MainWindow::on_Duty1_valueChanged(int value)
{
    QString str;
        str.setNum(value);
        ui->DutyValue1->setText(str);
        ui->Duty1->setValue(value);
        send_control_change(CC_OSCDUTY0,value * 10);
}

void bB101_Midi_MainWindow::on_Duty2_valueChanged(int value)
{
    QString str;
        str.setNum(value);
        ui->DutyValue2->setText(str);
        ui->Duty2->setValue(value);
        send_control_change(CC_OSCDUTY1,value * 10);
}

void bB101_Midi_MainWindow::on_Duty3_valueChanged(int value)
{
    QString str;
        str.setNum(value);
        ui->DutyValue3->setText(str);
        ui->Duty3->setValue(value);
        send_control_change(CC_OSCDUTY2,value * 10);
}

void bB101_Midi_MainWindow::on_Duty4_valueChanged(int value)
{
    QString str;
        str.setNum(value);
        ui->DutyValue4->setText(str);
        ui->Duty4->setValue(value);
        send_control_change(CC_OSCDUTY3,value * 10);
}

void bB101_Midi_MainWindow::on_Detune1_valueChanged(int value)
{
    QString str;
    float detune_value;
        str.setNum(value);
        ui->DetuneValue1->setText(str);
        ui->Detune1->setValue(value);
        detune_value = ((float ) value + 10.0F)* 6.35F;
        send_control_change(CC_OSCDETUNE0,(int )detune_value);
}

void bB101_Midi_MainWindow::on_Detune2_valueChanged(int value)
{
    QString str;
    float detune_value;
        str.setNum(value);
        ui->DetuneValue2->setText(str);
        ui->Detune2->setValue(value);
        detune_value = ((float ) value + 10.0F)* 6.35F;
        send_control_change(CC_OSCDETUNE1,(int )detune_value);
}

void bB101_Midi_MainWindow::on_Detune3_valueChanged(int value)
{
    QString str;
    float detune_value;
        str.setNum(value);
        ui->DetuneValue3->setText(str);
        ui->Detune3->setValue(value);

        detune_value = ((float ) value + 10.0F)* 6.35F;
        send_control_change(CC_OSCDETUNE2,(int )detune_value);
}

void bB101_Midi_MainWindow::on_Detune4_valueChanged(int value)
{
    QString str;
    float detune_value;
        str.setNum(value);
        ui->DetuneValue4->setText(str);
        ui->Detune4->setValue(value);

        detune_value = ((float ) value + 10.0F)* 6.35F;
        send_control_change(CC_OSCDETUNE3,(int )detune_value);
}

extern  QByteArray  sysex_msg;

void bB101_Midi_MainWindow::applyReceivedOSCParams()
{
    int vol0,vol1,vol2,vol3;
    int detune0,detune1,detune2,detune3;
    int duty0,duty1,duty2,duty3;
    int osc_wavesh,osc_wavesl;
    QString str;
    cc_tx_enabled = 0;


    osc_wavesh = sysex_msg.at(PARAMS_OSC_WAVESH);
    osc_wavesl = sysex_msg.at(PARAMS_OSC_WAVESL);
    switch ( osc_wavesh & 0x03)
    {
    case  SINE      :  wave_state[0] = NOISE;break;
    case  TRIANGLE  :  wave_state[0] = SINE;break;
    case  SQUARE    :  wave_state[0] = TRIANGLE;break;
    case  NOISE     :  wave_state[0] = SQUARE;break;
    }
    switch ( (osc_wavesh & 0x0c) >> 2 )
    {
    case  SINE      :  wave_state[1] = NOISE;break;
    case  TRIANGLE  :  wave_state[1] = SINE;break;
    case  SQUARE    :  wave_state[1] = TRIANGLE;break;
    case  NOISE     :  wave_state[1] = SQUARE;break;
    }
    switch ( osc_wavesl & 0x03)
    {
    case  SINE      :  wave_state[2] = NOISE;break;
    case  TRIANGLE  :  wave_state[2] = SINE;break;
    case  SQUARE    :  wave_state[2] = TRIANGLE;break;
    case  NOISE     :  wave_state[2] = SQUARE;break;
    }
    switch ( (osc_wavesl & 0x0c) >> 2 )
    {
    case  SINE      :  wave_state[3] = NOISE;break;
    case  TRIANGLE  :  wave_state[3] = SINE;break;
    case  SQUARE    :  wave_state[3] = TRIANGLE;break;
    case  NOISE     :  wave_state[3] = SQUARE;break;
    }
    on_pushButton_Wave1_clicked();
    on_pushButton_Wave2_clicked();
    on_pushButton_Wave3_clicked();
    on_pushButton_Wave4_clicked();

    duty0 = (sysex_msg.at(PARAMS_OSC_DUTY0)+1)/10;
    duty1 = (sysex_msg.at(PARAMS_OSC_DUTY1)+1)/10;
    duty2  =(sysex_msg.at(PARAMS_OSC_DUTY2)+1)/10;
    duty3 = (sysex_msg.at(PARAMS_OSC_DUTY3)+1)/10;
    on_Duty1_valueChanged(duty0);
    on_Duty2_valueChanged(duty1);
    on_Duty3_valueChanged(duty2);
    on_Duty4_valueChanged(duty3);


    detune0 = (sysex_msg.at(PARAMS_OSC_DETUNE0)- 50)/ 5;
    detune1 = (sysex_msg.at(PARAMS_OSC_DETUNE1)- 50)/ 5;
    detune2 = (sysex_msg.at(PARAMS_OSC_DETUNE2)- 50)/ 5;
    detune3 = (sysex_msg.at(PARAMS_OSC_DETUNE3)- 50)/ 5;
    on_Detune1_valueChanged(detune0);
    on_Detune2_valueChanged(detune1);
    on_Detune3_valueChanged(detune2);
    on_Detune4_valueChanged(detune3);

    vol0 = sysex_msg.at(PARAMS_OSC_VOL0);
    vol1 = sysex_msg.at(PARAMS_OSC_VOL1);
    vol2 = sysex_msg.at(PARAMS_OSC_VOL2);
    vol3 = sysex_msg.at(PARAMS_OSC_VOL3);
    on_Volume1_valueChanged(vol0);
    on_Volume2_valueChanged(vol1);
    on_Volume3_valueChanged(vol2);
    on_Volume4_valueChanged(vol3);
    cc_tx_enabled = 1;
}
