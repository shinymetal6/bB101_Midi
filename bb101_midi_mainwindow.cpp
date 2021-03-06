#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiIn.h>
#include <QMidiFile.h>
#include <QDebug>
#include <QFile>
#include <QFontDatabase>



/*
 * https://github.com/waddlesplash/QMidi
 */

QMidiOut    MidiOut;
QMidiIn     MidiIn;
QMidiFile   MidiFile;
QString     bB101_ID;
QByteArray  sysex_msg;

QFont Font24;
QFont Font20;
QFont Font14;
QFont Font12;
QFont Font10;
QFont Font8;

bB101_Midi_MainWindow::bB101_Midi_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bB101_Midi_MainWindow)
{
    ui->setupUi(this);
    QFile file1(":/Fonts/destructobeambb_bold.ttf");
    //QFile file1(":/Fonts/destructobeambb_reg.ttf");
    if ( file1.exists() )
    {
        set_all_fonts();
    }
    else
        qDebug() << ":/Fonts/destructobeambb_bold.ttf not found";
    QMap<QString, QString> out_vals = QMidiOut::devices();
    ui->statusbar->showMessage("Looking for bB101 ...");
    for (QString key : out_vals.keys()) {
        QString value = out_vals.value(key);
        qDebug() << "bB101_Midi\nOut Devices :";
        qDebug() << "Key : "  << key.toUtf8().constData() << "  \tID : " << value.toUtf8().constData();
        if ( value == "bB101")
        {
            bB101_ID = value;
            MidiOut.connect(key);
            MidiIn.connect(key);
            MidiIn.start();
            qDebug() << "bB101 connected to out";
            ui->statusbar->showMessage("bB101 : Connected");
        }
    }
    initVars();
}

bB101_Midi_MainWindow::~bB101_Midi_MainWindow()
{
    delete ui;
}

void bB101_Midi_MainWindow:: set_all_fonts()
{
QString family;
    QFontDatabase::addApplicationFont(":/Fonts/Godzilla.ttf");
    QFontDatabase::addApplicationFont(":/Fonts/Bauhaus.ttf");
    //QFontDatabase::addApplicationFont(":/Fonts/destructobeambb_bold.ttf");
    QFontDatabase::addApplicationFont(":/Fonts/destructobeambb_reg.ttf");

    /**/
    Font24 = QFont("DestructoBeam BB", 24, 1);
    Font20 = QFont("DestructoBeam BB", 20, 1);
    Font14 = QFont("DestructoBeam BB", 14, 1);
    Font12 = QFont("DestructoBeam BB", 12, 3);
    Font10 = QFont("DestructoBeam BB", 10, 3);

    QFontInfo info(Font12);
    family = info.family();
    qDebug() << family;
    /**/
    /*
    Font24 = QFont("Bauhaus", 24, 1);
    Font14 = QFont("Bauhaus", 14, 1);
    Font12 = QFont("Bauhaus", 12, 3);
    */

    ui->DutyValue1->setFont(Font12);
    ui->DutyValue2->setFont(Font12);
    ui->DutyValue3->setFont(Font12);
    ui->DutyValue4->setFont(Font12);
    ui->DetuneValue1->setFont(Font12);
    ui->DetuneValue2->setFont(Font12);
    ui->DetuneValue3->setFont(Font12);
    ui->DetuneValue4->setFont(Font12);
    ui->VolumeValue1->setFont(Font12);
    ui->VolumeValue2->setFont(Font12);
    ui->VolumeValue3->setFont(Font12);
    ui->VolumeValue4->setFont(Font12);
    ui->CutoffValue->setFont(Font12);
    ui->ResonanceValue->setFont(Font10);
    ui->DelayValue->setFont(Font10);

    ui->Flanger_radioButton->setFont(Font10);
    ui->Reverb_radioButton->setFont(Font10);
    ui->DLY_Enable_checkBox->setFont(Font10);
    ui->DLY_MIDI_checkBox->setFont(Font10);
    ui->MIDI_radioButton->setFont(Font10);
    ui->CV_radioButton->setFont(Font10);
    ui->Pot_radioButton->setFont(Font10);
    ui->ReadProgram->setFont(Font10);
    ui->ReadCurrentProgram->setFont(Font10);
    ui->SaveCurrentProgram->setFont(Font10);
    ui->Erase_pushButton->setFont(Font10);
    ui->CmdSource_pushButton->setFont(Font10);
    ui->Reset->setFont(Font10);
    ui->Close_pushButton->setFont(Font10);
    ui->ConfirmErase_checkBox->setFont(Font10);

    ui->AFXMOOG1_radioButton->setFont(Font10);
    ui->AFXMOOG2_radioButton->setFont(Font10);
    ui->AFXPhaser_radioButton->setFont(Font10);
    ui->VCFLP_radioButton->setFont(Font10);
    ui->VCFBP_radioButton->setFont(Font10);
    ui->VCFHP_radioButton->setFont(Font10);
    ui->AFX_Enable_checkBox->setFont(Font10);
    ui->AFX_Pot_radioButton->setFont(Font10);
    ui->AFX_MIDI_radioButton->setFont(Font10);
    ui->AFX_CV_radioButton->setFont(Font10);

    /* main labels */
    ui->Programs_label->setFont(Font20);
    ui->Oscillators_label->setFont(Font24);
    ui->VCF_label->setFont(Font24);
    ui->Delay_label->setFont(Font24);
    ui->ADSR_label->setFont(Font24);
    ui->System_label->setFont(Font24);

        /* labels */
    ui->Cutoff_label->setFont(Font10);
    ui->Resonance_label->setFont(Font10);
    ui->Wave_label->setFont(Font10);
    ui->Duty_label->setFont(Font10);
    ui->Volume_label->setFont(Font10);
    ui->Detune_label->setFont(Font10);
}

void bB101_Midi_MainWindow::on_Close_pushButton_clicked()
{
    exit(0);
}

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
    ui->Duty1->setValue(50);
    ui->Duty2->setValue(50);
    ui->Duty3->setValue(50);
    ui->Duty4->setValue(50);
    ui->DutyValue1->setText("50");
    ui->DutyValue2->setText("50");
    ui->DutyValue3->setText("50");
    ui->DutyValue4->setText("50");
    ui->VCFLP_radioButton->setChecked(false) ;
    ui->VCFBP_radioButton->setChecked(true);
    ui->VCFHP_radioButton->setChecked(false);
    ui->AFX_Enable_checkBox->setChecked(false) ;
    ui->AFX_Pot_radioButton->setChecked(false);
    ui->AFX_MIDI_radioButton->setChecked(true);
    ui->AFX_CV_radioButton->setChecked(false);
    ui->AFXMOOG1_radioButton->setChecked(true);
    ui->AFXMOOG2_radioButton->setChecked(false);
    ui->AFXPhaser_radioButton->setChecked(false);


    ui->CutoffValue->setText("0");
    ui->ResonanceValue->setText("0");
    ui->effectband_frame->setEnabled(false);
    ui->effectcontrol_frame->setEnabled(false);
    ui->effecttype_frame->setEnabled(false);


    ui->DelayValue->setText("0");
    ui->delayframe->setEnabled(false);


    int x = ui->ADSR_frame->x() + ui->ADSR_widget->x();
    int y = ui->ADSR_frame->y() + ui->ADSR_widget->y();
    int w = ui->ADSR_widget->width();
    int h = ui->ADSR_widget->height();
    AdsrPos.setRect(x,y,w,h);
    AdsrFramePos.setRect(x-1,y-1,w+2,h+2);
    AdsrActiveFramePos.setRect(x+POINTS_VALID_AREA/2,y+POINTS_VALID_AREA/2,w-POINTS_VALID_AREA,h-POINTS_VALID_AREA);
/*
    qDebug() << "ui->ADSR_widget->width() " << ui->ADSR_widget->width() << "ui->ADSR_widget->height() "<< ui->ADSR_widget->height();
    qDebug() << "AdsrPos.x()              " << AdsrPos.x()              << "AdsrPos.y()               "<< AdsrPos.y();
    qDebug() << AdsrPos.x()+LINE_OFFSET_FROM_FRAME<<AdsrPos.y()+ui->ADSR_widget->height()-LINE_OFFSET_FROM_FRAME<<AdsrPos.x()+AdsrPos.width()/4<<AdsrPos.y()+ui->ADSR_widget->height();
*/
    StartPoint.setX(AdsrPos.x()+LINE_OFFSET_FROM_FRAME);
    StartPoint.setY(AdsrPos.y()+ui->ADSR_widget->height()-LINE_OFFSET_FROM_FRAME);
    APoint.setX(AdsrPos.x()+AdsrPos.width()/4);
    APoint.setY(AdsrPos.y()+2*LINE_OFFSET_FROM_FRAME);
    DPoint.setX(AdsrPos.x()+AdsrPos.width()/4 +50 );
    DPoint.setY(AdsrPos.y()+LINE_OFFSET_FROM_FRAME+ui->ADSR_widget->height()/2 );
    SPoint.setX(AdsrPos.x()+AdsrPos.width()/4 + 200);
    SPoint.setY(AdsrPos.y()+LINE_OFFSET_FROM_FRAME+ui->ADSR_widget->height()/2 );
    RPoint.setX(AdsrPos.x()+ui->ADSR_widget->width()-LINE_OFFSET_FROM_FRAME);
    RPoint.setY(AdsrPos.y()+ui->ADSR_widget->height()-LINE_OFFSET_FROM_FRAME);
    ALine.setPoints(StartPoint,APoint);
    DLine.setPoints(APoint,DPoint);
    SLine.setPoints(DPoint,SPoint);
    RLine.setPoints(SPoint,RPoint);

    AMatch.setCoords(APoint.x()-CAPTURE_AREA , APoint.y()-CAPTURE_AREA , APoint.x()+CAPTURE_AREA , APoint.y()+CAPTURE_AREA);
    DMatch.setCoords(DPoint.x()-CAPTURE_AREA , DPoint.y()-CAPTURE_AREA , DPoint.x()+CAPTURE_AREA , DPoint.y()+CAPTURE_AREA);
    SMatch.setCoords(SPoint.x()-CAPTURE_AREA , SPoint.y()-CAPTURE_AREA , SPoint.x()+CAPTURE_AREA , SPoint.y()+CAPTURE_AREA);
    AColor.setRgb(0,255,0);
    DColor.setRgb(0,255,0);
    SColor.setRgb(0,255,0);
    Aselected = Dselected = Sselected = 0;

    adsr_correction_factorx = ADSR_CORRECTION_FACTOR_X/(ui->ADSR_widget->width()-LINE_OFFSET_FROM_FRAME);
    adsr_correction_factory = ADSR_CORRECTION_FACTOR_Y/(ui->ADSR_widget->height()-LINE_OFFSET_FROM_FRAME);

    delay_flag = DLY_MIXER_FLANGER_MIDI;
}


