#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiIn.h>
#include <QMidiFile.h>
#include <QDebug>
#include <QFile>
#include <QFontDatabase>

extern  QMidiOut MidiOut;

void bB101_Midi_MainWindow:: adsr(QPainter *qp)
{
    Q_UNUSED(qp);
}

void bB101_Midi_MainWindow::on_pushButton_clicked()
{
    AdsrFramePos.setRect(180,220,300,200);
    update();
}

void bB101_Midi_MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPen pen;

    pen.setWidth(2);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawLine(ALine);
    painter.drawLine(DLine);
    painter.drawLine(SLine);
    painter.drawLine(RLine);

    pen.setColor(AColor);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawEllipse(AMatch);
    pen.setColor(DColor);
    painter.setPen(pen);
    painter.drawEllipse(DMatch);
    pen.setColor(SColor);
    painter.setPen(pen);
    painter.drawEllipse(SMatch);
}

void bB101_Midi_MainWindow::set_Aline(int x )
{
    APoint.setX(x);
    AMatch.setCoords(APoint.x()-CAPTURE_AREA , APoint.y()-CAPTURE_AREA , APoint.x()+CAPTURE_AREA , APoint.y()+CAPTURE_AREA);
    ALine.setPoints(StartPoint,APoint);
    DLine.setPoints(APoint,DPoint);
}

void bB101_Midi_MainWindow::set_Dline(int x , int y )
{
    DPoint.setX(x);
    DPoint.setY(y);
    DMatch.setCoords(DPoint.x()-CAPTURE_AREA , DPoint.y()-CAPTURE_AREA , DPoint.x()+CAPTURE_AREA , DPoint.y()+CAPTURE_AREA);
    DLine.setPoints(APoint,DPoint);
    SLine.setPoints(DPoint,SPoint);

    SPoint.setY(y);
    SMatch.setCoords(SPoint.x()-CAPTURE_AREA , SPoint.y()-CAPTURE_AREA , SPoint.x()+CAPTURE_AREA , SPoint.y()+CAPTURE_AREA);
    SLine.setPoints(DPoint,SPoint);
    RLine.setPoints(SPoint,RPoint);
}

void bB101_Midi_MainWindow::set_Sline(int x , int y )
{
    SPoint.setX(x);
    SPoint.setY(y);
    SMatch.setCoords(SPoint.x()-CAPTURE_AREA , SPoint.y()-CAPTURE_AREA , SPoint.x()+CAPTURE_AREA , SPoint.y()+CAPTURE_AREA);
    SLine.setPoints(DPoint,SPoint);
    RLine.setPoints(SPoint,RPoint);

    DPoint.setY(y);
    DMatch.setCoords(DPoint.x()-CAPTURE_AREA , DPoint.y()-CAPTURE_AREA , DPoint.x()+CAPTURE_AREA , DPoint.y()+CAPTURE_AREA);
    DLine.setPoints(APoint,DPoint);
    SLine.setPoints(DPoint,SPoint);
}

void bB101_Midi_MainWindow::calc_points(QMouseEvent *event)
{
    if (  Aselected == 1 )
    {
        if ( event->pos().x() <  DPoint.x())
            set_Aline(event->pos().x());
    }
    if (  Dselected == 1 )
    {
        if (( event->pos().x() >  APoint.x()) && ( event->pos().x() <  SPoint.x()) )
            set_Dline(event->pos().x(),event->pos().y());
    }
    if (  Sselected == 1 )
    {
        if ( event->pos().x() >  DPoint.x())
            set_Sline(event->pos().x(),event->pos().y());
    }
}

void setcolor( QColor *color , int selected)
{
    if ( selected )
        color->setRgb(255,0,0);
    else
        color->setRgb(0,255,0);
}

void bB101_Midi_MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    QRect MousePos;
    MousePos.setRect(event->pos().x()-1 , event->pos().y()-1 , 2 , 2);
    if ( AdsrActiveFramePos.contains(MousePos))
    {
        setcolor(&AColor,Aselected);
        setcolor(&DColor,Dselected);
        setcolor(&SColor,Sselected);
        calc_points(event);
        update();
    }
}

void bB101_Midi_MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    Aselected = Dselected = Sselected = 0;
    setcolor(&AColor,Aselected);
    setcolor(&DColor,Dselected);
    setcolor(&SColor,Sselected);
    update();
    int atime,dtime,sval,rtime;

    atime = (int )((APoint.x() - AdsrPos.x()) * adsr_correction_factorx);
    dtime = (int )((DPoint.x() - AdsrPos.x()) * adsr_correction_factorx);
    sval = ADSR_CORRECTION_FACTOR_Y-(int )((DPoint.y() - AdsrPos.y()) * adsr_correction_factory);
    rtime = (int )((SPoint.x() - AdsrPos.x()) * adsr_correction_factorx);

    MidiOut.controlChange(CC_ATIME,atime);
    MidiOut.controlChange(CC_DTIME,dtime);
    MidiOut.controlChange(CC_SVAL,sval);
    MidiOut.controlChange(CC_RTIME,rtime);
}

void bB101_Midi_MainWindow::mousePressEvent(QMouseEvent *event)
{
    QRect MousePos;
    MousePos.setRect(event->pos().x()-1 , event->pos().y()-1 , 2 , 2);
    if ( AMatch.contains(MousePos))
        Aselected=1;
    if ( DMatch.contains(MousePos))
        Dselected=1;
    if ( SMatch.contains(MousePos))
        Sselected=1;
    setcolor(&AColor,Aselected);
    setcolor(&DColor,Dselected);
    setcolor(&SColor,Sselected);
    update();
}

extern  QByteArray  sysex_msg;

void bB101_Midi_MainWindow::applyReceivedADSRParams(void)
{
    int atime,dtime,sval,rtime;
    int ax,dx,dy,sx,sy;
    atime = sysex_msg.at(PARAMS_ADSR_ATIME);
    dtime = sysex_msg.at(PARAMS_ADSR_DTIME);
    sval  = sysex_msg.at(PARAMS_ADSR_SVAL);
    rtime = sysex_msg.at(PARAMS_ADSR_RTIME);
    //qDebug() << hex << atime << dtime << sval << rtime;

    ax = (atime / adsr_correction_factorx) + AdsrPos.x();
    dx = (dtime / adsr_correction_factorx) + AdsrPos.x();
    dy = AdsrActiveFramePos.height() - (sval / adsr_correction_factory) + AdsrPos.y();
    sx = (rtime / adsr_correction_factorx) + AdsrPos.x();
    sy = dy;
    set_Aline(ax);
    set_Dline(dx,dy);
    set_Sline(sx,sy);
    update();
}
