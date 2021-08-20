#ifndef BB101_MIDI_MAINWINDOW_H
#define BB101_MIDI_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#define DELTA   16
#define	SINE							0
#define	TRIANGLE						1
#define	SQUARE							2
#define LINE_OFFSET_FROM_FRAME 5
#define CAPTURE_AREA 6
#define POINTS_VALID_AREA 8

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

    void on_Echo_radioButton_clicked();

    void on_Reverb_radioButton_clicked();

    void on_Enable_checkBox_stateChanged(int arg1);

    void on_CmdSource_pushButton_clicked();

    void on_MIDI_radioButton_clicked();

    void on_CV_radioButton_clicked();

    void on_Pot_radioButton_clicked();

    void on_Erase_pushButton_clicked();

    void on_IncrementEraseProg_pushButton_clicked();

    void on_DecrementEraseProg_pushButton_clicked();

    void set_all_fonts(void);

    void on_Close_pushButton_clicked();

    void on_pushButton_clicked();

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


protected:
    void onMidiEvent(QByteArray data);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent*);
};


#endif // BB101_MIDI_MAINWINDOW_H
