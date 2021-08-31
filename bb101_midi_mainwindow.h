#ifndef BB101_MIDI_MAINWINDOW_H
#define BB101_MIDI_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#define	BB_EE_MACHINE_FAMILY				'1'
#define	BB_EE_MACHINE_MODEL					0x01

#define DELTA                   16
#define LINE_OFFSET_FROM_FRAME  5
#define CAPTURE_AREA            6
#define POINTS_VALID_AREA       8

#define	CC_OSCWAVE0				0x00
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
#define	CC_NOISE2WAVEWEIGHT0	0x10
#define	CC_NOISE2WAVEWEIGHT1	0x11
#define	CC_NOISE2WAVEWEIGHT2	0x12
#define	CC_NOISE2WAVEWEIGHT3	0x13
#define	CC_VCFENABLE			0x20
#define	CC_VCFTYPE				0x21
#define	CC_VCFFREQUENCY			0x22
#define	CC_VCFRESONANCE			0x23
#define	CC_VCFSOURCE			0x24
#define	CC_DLYENABLE			0x30
#define	CC_DELAYLEN				0x31
#define	CC_DELAYBALANCE			0x32
#define	CC_DELAYSOURCE			0x33
#define	CC_ATIME				0x40
#define	CC_DTIME				0x41
#define	CC_SVAL					0x42
#define	CC_RTIME				0x43
#define	CC_SEQUENCE				0x50

#define	SINE							0
#define	TRIANGLE						1
#define	SQUARE							2
#define	NOISE							3
#define	NOISEMODSINE					4
#define	NOISEMODTRIANGLE				5
#define	NOISEMODSQUARE					6

#define ADSR_CORRECTION_FACTOR_X  80.0F
#define ADSR_CORRECTION_FACTOR_Y  32.0F


#define	DLY_MIXER_FLANGER_POT		0x00
#define	DLY_MIXER_REVERB_POT		0x01
#define	DLY_MIXER_FLANGER_MIDI		0x02
#define	DLY_MIXER_REVERB_MIDI		0x03
#define	DLY_ENABLED					0x40


#define	VCF_CONTROL_POT				0x01
#define	VCF_CONTROL_MIDI			0x02
#define	VCF_CONTROL_CV				0x04
#define	VCF_TYPE_LP					0x08
#define	VCF_TYPE_BP					0x10
#define	VCF_TYPE_HP					0x20

#define PARAMS_PROG_FLAG0       1
#define PARAMS_PROG_FLAG1       2
#define PARAMS_OSC_FLAGS        3
#define PARAMS_CNTRL_FLAGS      4
#define PARAMS_VCF_FLAGS        5
#define PARAMS_EFFECT_FLAGS     6
#define PARAMS_DLY_FLAGS        7
#define PARAMS_DLY_VAL          8
#define PARAMS_OSC_WAVESH       9
#define PARAMS_OSC_WAVESL       10
#define PARAMS_OSC_DUTY0        11
#define PARAMS_OSC_DUTY1        12
#define PARAMS_OSC_DUTY2        13
#define PARAMS_OSC_DUTY3        14
#define PARAMS_OSC_DETUNE0      15
#define PARAMS_OSC_DETUNE1      16
#define PARAMS_OSC_DETUNE2      17
#define PARAMS_OSC_DETUNE3      18
#define PARAMS_OSC_VOL0         19
#define PARAMS_OSC_VOL1         20
#define PARAMS_OSC_VOL2         21
#define PARAMS_OSC_VOL3         22
#define PARAMS_ADSR_ATIME       23
#define PARAMS_ADSR_DTIME       24
#define PARAMS_ADSR_SVAL        25
#define PARAMS_ADSR_RTIME       26

/*
typedef struct _ProgramTypeDef
{									// Flash offset		MIDI Packet offset
    uint8_t 	program_flags0;		//	0				1
    uint8_t 	program_flags1;		//	1				2
    uint8_t 	oscillator_flags;	//	2				3
    uint8_t 	control_flags;		//	3				4
    uint8_t 	vcf_flags;			//	4				5
    uint8_t 	effect_flags;		//	5				6
    uint8_t 	delay_flags;		//	6 				7
    uint8_t 	delay_value;		//	7 				8
    uint8_t		osc_wavesh;			//	8 				9
    uint8_t		osc_wavesl;			//	9 				10
    uint8_t 	osc_duty_percent[4];//	10,11,12,13		11:14
    uint8_t 	osc_detune[4];		//	14,15,16,17		15:18
    uint8_t 	osc_volume[4];		//  18,19,20,21		19:22
    uint8_t 	Atime,Dtime,Sval,Rtime;	// 22,23,24,25	23:26
}ProgramTypeDef;
*/
QT_BEGIN_NAMESPACE
namespace Ui { class bB101_Midi_MainWindow; }
QT_END_NAMESPACE

class bB101_Midi_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bB101_Midi_MainWindow(QWidget *parent = nullptr);
    ~bB101_Midi_MainWindow();
    void set_Arect(float x , float y , float w , float h);
    void set_Drect(float x , float y , float w , float h);
    void set_Srect(float x , float y , float w , float h);
    void adsr(QPainter *qp);
    void draw(QPainter *painter);
    void calc_points(QMouseEvent *event);
    void set_Aline(int x  );
    void set_Dline(int x , int y );
    void set_Sline(int x , int y );
    void applyReceivedParams(void);
    void applyReceivedADSRParams(void);
    void applyReceivedOSCParams(void);
    void applyReceivedDelayParams(void);
    void send_control_change(int control_number, int value );
private slots:

    void on_pushButton_Wave1_clicked();

    void on_pushButton_Wave2_clicked();

    void on_pushButton_Wave3_clicked();

    void on_pushButton_Wave4_clicked();

    void on_Volume1_valueChanged(int value);

    void on_Volume2_valueChanged(int value);

    void on_Volume3_valueChanged(int value);

    void on_Volume4_valueChanged(int value);

    void on_Duty1_valueChanged(int value);

    void initVars(void);

    void on_Duty2_valueChanged(int value);

    void on_Duty3_valueChanged(int value);

    void on_Duty4_valueChanged(int value);

    void on_Detune1_valueChanged(int value);

    void on_Detune2_valueChanged(int value);

    void on_Detune3_valueChanged(int value);

    void on_Detune4_valueChanged(int value);

    void on_Reset_clicked();

    void on_ReadCurrentProgram_clicked();

    void on_IncrementReadProg_pushButton_clicked();

    void on_DecrementReadProg_pushButton_clicked();

    void on_IncrementSaveProg_pushButton_clicked();

    void on_DecrementSaveProg_pushButton_clicked();

    void on_ReadProgram_clicked();

    void on_Cutoff_valueChanged(int value);

    void on_Resonance_valueChanged(int value);

    void on_Delay_valueChanged(int value);

    void on_CmdSource_pushButton_clicked();

    void on_Erase_pushButton_clicked();

    void on_IncrementEraseProg_pushButton_clicked();

    void on_DecrementEraseProg_pushButton_clicked();

    void set_all_fonts(void);

    void on_Close_pushButton_clicked();

    void on_DLY_MIDI_checkBox_clicked(bool checked);

    void on_DLY_Enable_checkBox_clicked(bool checked);

    void on_VCF_Enable_checkBox_clicked(bool checked);

    void on_Flanger_radioButton_clicked(bool checked);

    void on_Reverb_radioButton_clicked(bool checked);

    void on_MIDI_radioButton_clicked(bool checked);

    void on_CV_radioButton_clicked(bool checked);

    void on_Pot_radioButton_clicked(bool checked);

    void on_VCF_Pot_radioButton_clicked(bool checked);

    void on_VCF_MIDI_radioButton_clicked(bool checked);

    void on_VCF_CV_radioButton_clicked(bool checked);

    void on_VCFLP_radioButton_clicked(bool checked);

    void on_VCFBP_radioButton_clicked(bool checked);

    void on_VCFHP_radioButton_clicked(bool checked);

private:
    Ui::bB101_Midi_MainWindow *ui;
    QGraphicsTextItem *text;
    unsigned int    wave_state[4];
    QRect AdsrFramePos , AdsrPos , AdsrActiveFramePos;
    QPoint StartPoint, APoint,DPoint,SPoint,RPoint;
    QRect AMatch , DMatch , SMatch;
    int Aselected,Dselected,Sselected;
    QLine ALine,DLine,SLine,RLine;
    QColor AColor,DColor,SColor;
    float adsr_correction_factorx , adsr_correction_factory;
    int delay_flag;


protected:
    void onMidiEvent(QByteArray data);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent*);
};


#endif // BB101_MIDI_MAINWINDOW_H
