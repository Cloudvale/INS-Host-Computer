#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QVector>
#include "utctext.h"
#include <QUdpSocket>
#include  <QtNetwork>
#include <qstring.h>
#include <QString>

// 生成随机数
class Generate : public QObject
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

    void working(int num);
    void onSocketReadyRead();
    UTCtext *utctext;
    QUdpSocket *udpSockets;

    QFile file;                          //电脑保存txt的文件
    int save_flag;                       //关闭保存标志位
    int num;


signals:
    void sendArray(int num);




private:


};


class BubbleSort : public QObject
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);

    void working(QVector<int> list);

signals:
    void finish(QVector<int> num);

};


class QuickSort : public QObject
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);

    void working(QVector<int> list);

private:
    void quickSort(QVector<int> &list, int l, int r);

signals:
    void finish(QVector<int> num);

};

#endif // MYTHREAD_H
