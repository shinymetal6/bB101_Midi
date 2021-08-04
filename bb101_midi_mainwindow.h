#ifndef BB101_MIDI_MAINWINDOW_H
#define BB101_MIDI_MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class bB101_Midi_MainWindow; }
QT_END_NAMESPACE

class bB101_Midi_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bB101_Midi_MainWindow(QWidget *parent = nullptr);
    ~bB101_Midi_MainWindow();
    //QByteArray sysex_msg;

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

    void on_DumpCurrentProgram_clicked();

    void on_IncrementProg_pushButton_clicked();


    void on_DecrementProg_pushButton_clicked();

private:
    Ui::bB101_Midi_MainWindow *ui;
protected:
    void onMidiEvent(QByteArray data);

};
#endif // BB101_MIDI_MAINWINDOW_H
