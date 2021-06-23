#ifndef SCREENVIEW_H
#define SCREENVIEW_H

#include <QWidget>
#include <QPainter>
#include <QScreen>
#include <QWindow>
#include <QPixmap>
#include <QMouseEvent>
#include <QRubberBand>
#include <QDateTime>
#include <QLabel>

#include "editwindow.h"
#include "mainwindow.h"

//添加
class QRubberBand;

namespace Ui {
class screenview;
}

class screenview : public QWidget
{
    Q_OBJECT

public:
    screenview(QWidget *parent = nullptr,int screentype=0);
    ~screenview();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

protected slots:
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::screenview *ui;
    QPainter painter;
    QPixmap originalPixmap;
    QPixmap sourcePixmap;

    QScreen *screen;
    QRubberBand *rubberBand;
    QPoint startpoint;
    QPoint endpoint;

    //记录鼠标位置
    int sx,sy,ex,ey;
    //记录矩形的大小
    int rw,rh;
    //截图类型
    int shottype;
    //固定截图的坐标
    int fixedx,fixedy;
    //固定大小的矩形
    QRect fixedRect;


signals:
    void senddata(QPixmap sourcePixmap);
};

#endif // SCREENVIEW_H
