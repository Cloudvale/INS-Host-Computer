#ifndef UTCTEXT_H
#define UTCTEXT_H

#include <QWidget>
#include <QThread>

namespace Ui {
class UTCtext;
}

class UTCtext : public QWidget
{
    Q_OBJECT

public:
    explicit UTCtext(QWidget *parent = nullptr);
    ~UTCtext();

    void working(int num);
    void test_utc();

signals:
    void sendArray(QVector<int> num);

private slots:
    void slotTimeout_utc();

private:
    Ui::UTCtext *ui;
    QThread thread;

    QTimer* m_timer_utc;
    double pointCount_utc;
};

#endif // UTCTEXT_H
