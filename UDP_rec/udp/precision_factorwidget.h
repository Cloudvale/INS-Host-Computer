#ifndef PRECISION_FACTORWIDGET_H
#define PRECISION_FACTORWIDGET_H

#include <QWidget>

namespace Ui {
class Precision_factorWidget;
}

class Precision_factorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Precision_factorWidget(QWidget *parent = nullptr);
    ~Precision_factorWidget();
    void para_for_chart(float *P,float *H,float *V,float *T,float *G);
    void para_for_chart_test();
    void working(int num);

private slots:
    void slotTimeout_factor();

private:
    Ui::Precision_factorWidget *ui;
    float PDOP;float HDOP;float VDOP;float TDOP;float GDOP;
    QTimer* m_timer_factor;
    double pointCount_factor;
};

#endif // PRECISION_FACTORWIDGET_H
