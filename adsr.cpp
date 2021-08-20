#include "bb101_midi_mainwindow.h"
#include "ui_bb101_midi_mainwindow.h"

#include <QMidiOut.h>
#include <QMidiIn.h>
#include <QMidiFile.h>
#include <QDebug>
#include <QFile>
#include <QFontDatabase>


void bB101_Midi_MainWindow:: adsr(QPainter *qp)
{
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
    pen.setColor(Qt::cyan);
    //painter.setBrush(Qt::VerPattern);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawRect(AdsrFramePos);

    pen.setWidth(2);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLine(ALine);
    painter.drawLine(DLine);
    painter.drawLine(SLine);
    painter.drawLine(RLine);
    //pen.setColor(Qt::green);

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

void bB101_Midi_MainWindow::calc_points(QMouseEvent *event)
{
    if (  Aselected == 1 )
    {
        if ( event->pos().x() <  DPoint.x())
        {
            APoint.setX(event->pos().x());
            APoint.setY(event->pos().y());
            AMatch.setCoords(APoint.x()-CAPTURE_AREA , APoint.y()-CAPTURE_AREA , APoint.x()+CAPTURE_AREA , APoint.y()+CAPTURE_AREA);
            ALine.setPoints(StartPoint,APoint);
            DLine.setPoints(APoint,DPoint);
        }
    }
    if (  Dselected == 1 )
    {
        if (( event->pos().x() >  APoint.x()) && ( event->pos().x() <  SPoint.x()) )
        {
            DPoint.setX(event->pos().x());
            DPoint.setY(event->pos().y());
            DMatch.setCoords(DPoint.x()-CAPTURE_AREA , DPoint.y()-CAPTURE_AREA , DPoint.x()+CAPTURE_AREA , DPoint.y()+CAPTURE_AREA);
            DLine.setPoints(APoint,DPoint);
            SLine.setPoints(DPoint,SPoint);

            SPoint.setY(event->pos().y());
            SMatch.setCoords(SPoint.x()-CAPTURE_AREA , SPoint.y()-CAPTURE_AREA , SPoint.x()+CAPTURE_AREA , SPoint.y()+CAPTURE_AREA);
            SLine.setPoints(DPoint,SPoint);
            RLine.setPoints(SPoint,RPoint);
        }
    }
    if (  Sselected == 1 )
    {
        if ( event->pos().x() >  DPoint.x())
        {
            SPoint.setX(event->pos().x());
            SPoint.setY(event->pos().y());
            SMatch.setCoords(SPoint.x()-CAPTURE_AREA , SPoint.y()-CAPTURE_AREA , SPoint.x()+CAPTURE_AREA , SPoint.y()+CAPTURE_AREA);
            SLine.setPoints(DPoint,SPoint);
            RLine.setPoints(SPoint,RPoint);

            DPoint.setY(event->pos().y());
            DMatch.setCoords(DPoint.x()-CAPTURE_AREA , DPoint.y()-CAPTURE_AREA , DPoint.x()+CAPTURE_AREA , DPoint.y()+CAPTURE_AREA);
            DLine.setPoints(APoint,DPoint);
            SLine.setPoints(DPoint,SPoint);
        }
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
    Aselected = Dselected = Sselected = 0;
    setcolor(&AColor,Aselected);
    setcolor(&DColor,Dselected);
    setcolor(&SColor,Sselected);
    update();
}

void bB101_Midi_MainWindow::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << event->pos();
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
