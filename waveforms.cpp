#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiFile.h>

extern  QMidiOut MidiOut;
unsigned int    wave_state[4];
#define	SINE							0
#define	TRIANGLE						1
#define	SQUARE							2

void bB101_Midi_MainWindow::initVars(void)
{
int i;
QString PixMapName=":/Icons/sin.bmp";
    for(i=0;i<4;i++)
    {
        wave_state[i] = SINE;
    }
    ui->pushButton_Wave1->setIcon(QPixmap(PixMapName));
    ui->pushButton_Wave2->setIcon(QPixmap(PixMapName));
    ui->pushButton_Wave3->setIcon(QPixmap(PixMapName));
    ui->pushButton_Wave4->setIcon(QPixmap(PixMapName));
    ui->Volume1->setValue(10);
    ui->Volume2->setValue(10);
    ui->Volume3->setValue(10);
    ui->Volume4->setValue(10);
    ui->VolumeValue1->setText("10");
    ui->VolumeValue2->setText("10");
    ui->VolumeValue3->setText("10");
    ui->VolumeValue4->setText("10");
    ui->Detune1->setValue(0);
    ui->Detune2->setValue(0);
    ui->Detune3->setValue(0);
    ui->Detune4->setValue(0);
    ui->DetuneValue1->setText("0");
    ui->DetuneValue2->setText("0");
    ui->DetuneValue3->setText("0");
    ui->DetuneValue4->setText("0");
    ui->Duty1->setValue(5);
    ui->Duty2->setValue(5);
    ui->Duty3->setValue(5);
    ui->Duty4->setValue(5);
    ui->DutyValue1->setText("5");
    ui->DutyValue2->setText("5");
    ui->DutyValue3->setText("5");
    ui->DutyValue4->setText("5");
}

void bB101_Midi_MainWindow::on_pushButton_Wave1_clicked()
{
QString PixMapName="";
QByteArray sdata_sin = QByteArray::fromHex("F0420000F7");
QByteArray sdata_tri = QByteArray::fromHex("F0420001F7");
QByteArray sdata_sqr = QByteArray::fromHex("F0420002F7");

    wave_state[0] ++;
    if ( wave_state[0] > 2 )
        wave_state[0] = 0;
    switch ( wave_state[0])
    {
    case    0   : PixMapName=":/Icons/sin.bmp"; MidiOut.sendSysEx(sdata_sin);break;
    case    1   : PixMapName=":/Icons/tri.bmp"; MidiOut.sendSysEx(sdata_tri); break;
    case    2   : PixMapName=":/Icons/sqr.bmp"; MidiOut.sendSysEx(sdata_sqr);break;
    }
    ui->pushButton_Wave1->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave2_clicked()
{
    QString PixMapName="";
    QByteArray sdata_sin = QByteArray::fromHex("F0420100F7");
    QByteArray sdata_tri = QByteArray::fromHex("F0420101F7");
    QByteArray sdata_sqr = QByteArray::fromHex("F0420102F7");

        wave_state[1] ++;
        if ( wave_state[1] > 2 )
            wave_state[1] = 0;
        switch ( wave_state[1])
        {
        case    0   : PixMapName=":/Icons/sin.bmp"; MidiOut.sendSysEx(sdata_sin);break;
        case    1   : PixMapName=":/Icons/tri.bmp"; MidiOut.sendSysEx(sdata_tri); break;
        case    2   : PixMapName=":/Icons/sqr.bmp"; MidiOut.sendSysEx(sdata_sqr);break;
        }
        ui->pushButton_Wave2->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave3_clicked()
{
    QString PixMapName="";
    QByteArray sdata_sin = QByteArray::fromHex("F0420200F7");
    QByteArray sdata_tri = QByteArray::fromHex("F0420201F7");
    QByteArray sdata_sqr = QByteArray::fromHex("F0420202F7");

        wave_state[2] ++;
        if ( wave_state[2] > 2 )
            wave_state[2] = 0;
        switch ( wave_state[2])
        {
        case    0   : PixMapName=":/Icons/sin.bmp"; MidiOut.sendSysEx(sdata_sin);break;
        case    1   : PixMapName=":/Icons/tri.bmp"; MidiOut.sendSysEx(sdata_tri); break;
        case    2   : PixMapName=":/Icons/sqr.bmp"; MidiOut.sendSysEx(sdata_sqr);break;
        }
        ui->pushButton_Wave3->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_pushButton_Wave4_clicked()
{
    QString PixMapName="";
    QByteArray sdata_sin = QByteArray::fromHex("F0420300F7");
    QByteArray sdata_tri = QByteArray::fromHex("F0420301F7");
    QByteArray sdata_sqr = QByteArray::fromHex("F0420302F7");

        wave_state[3] ++;
        if ( wave_state[3] > 2 )
            wave_state[3] = 0;
        switch ( wave_state[3])
        {
        case    0   : PixMapName=":/Icons/sin.bmp"; MidiOut.sendSysEx(sdata_sin);break;
        case    1   : PixMapName=":/Icons/tri.bmp"; MidiOut.sendSysEx(sdata_tri); break;
        case    2   : PixMapName=":/Icons/sqr.bmp"; MidiOut.sendSysEx(sdata_sqr);break;
        }
        ui->pushButton_Wave4->setIcon(QPixmap(PixMapName));
}

void bB101_Midi_MainWindow::on_Volume1_valueChanged(int value)
{
QString str,sysex_data;
    str.setNum(value);
    ui->VolumeValue1->setText(str);
    if ( value < 10 )
        sysex_data = "F044000" + str + "F7";
    else
        sysex_data = "F04400" + str + "F7";
    QByteArray sdata_vol = sysex_data.toUtf8();
    MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}

void bB101_Midi_MainWindow::on_Volume2_valueChanged(int value)
{
QString str,sysex_data;
    str.setNum(value);
    ui->VolumeValue2->setText(str);
    if ( value < 10 )
        sysex_data = "F044010" + str + "F7";
    else
        sysex_data = "F04401" + str + "F7";
    QByteArray sdata_vol = sysex_data.toUtf8();
    MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}

void bB101_Midi_MainWindow::on_Volume3_valueChanged(int value)
{
QString str,sysex_data;
    str.setNum(value);
    ui->VolumeValue3->setText(str);
    if ( value < 10 )
        sysex_data = "F044020" + str + "F7";
    else
        sysex_data = "F04402" + str + "F7";
    QByteArray sdata_vol = sysex_data.toUtf8();
    MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}

void bB101_Midi_MainWindow::on_Volume4_valueChanged(int value)
{
QString str,sysex_data;
    str.setNum(value);
    ui->VolumeValue4->setText(str);
    if ( value < 10 )
        sysex_data = "F044030" + str + "F7";
    else
        sysex_data = "F04403" + str + "F7";
    QByteArray sdata_vol = sysex_data.toUtf8();
    MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}

void bB101_Midi_MainWindow::on_Duty1_valueChanged(int value)
{
QString str,sysex_data;
    str.setNum(value);
    ui->DutyValue1->setText(str);
    if ( value < 10 )
        sysex_data = "F043000" + str + "F7";
    else
        sysex_data = "F04300" + str + "F7";
    QByteArray sdata_vol = sysex_data.toUtf8();
    MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}

void bB101_Midi_MainWindow::on_Duty2_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->DutyValue2->setText(str);
        if ( value < 10 )
            sysex_data = "F043010" + str + "F7";
        else
            sysex_data = "F04301" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}

void bB101_Midi_MainWindow::on_Duty3_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->DutyValue3->setText(str);
        if ( value < 10 )
            sysex_data = "F043020" + str + "F7";
        else
            sysex_data = "F04302" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}

void bB101_Midi_MainWindow::on_Duty4_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->DutyValue4->setText(str);
        if ( value < 10 )
            sysex_data = "F043030" + str + "F7";
        else
            sysex_data = "F04303" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}


void bB101_Midi_MainWindow::on_Detune1_valueChanged(int value)
{
QString str,sysex_data;
    str.setNum(value);
    ui->DetuneValue1->setText(str);
    if ( value < 10 )
        sysex_data = "F041000" + str + "F7";
    else
        sysex_data = "F04100" + str + "F7";
    QByteArray sdata_vol = sysex_data.toUtf8();
    MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));
}



void bB101_Midi_MainWindow::on_Detune2_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->DetuneValue2->setText(str);
        if ( value < 10 )
            sysex_data = "F041010" + str + "F7";
        else
            sysex_data = "F04101" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));

}

void bB101_Midi_MainWindow::on_Detune3_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->DetuneValue3->setText(str);
        if ( value < 10 )
            sysex_data = "F041020" + str + "F7";
        else
            sysex_data = "F04102" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));

}

void bB101_Midi_MainWindow::on_Detune4_valueChanged(int value)
{
    QString str,sysex_data;
        str.setNum(value);
        ui->DetuneValue4->setText(str);
        if ( value < 10 )
            sysex_data = "F041030" + str + "F7";
        else
            sysex_data = "F04103" + str + "F7";
        QByteArray sdata_vol = sysex_data.toUtf8();
        MidiOut.sendSysEx(QByteArray::fromHex(sdata_vol));

}
