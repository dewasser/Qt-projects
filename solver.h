#ifndef SOLVER_H
#define SOLVER_H

#include <QMainWindow>
#include <QtCharts>
QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class solver; }
QT_END_NAMESPACE

class solver : public QMainWindow
{
    Q_OBJECT

public:
    solver(QWidget *parent = nullptr);
    ~solver();

private slots:
    void on_pushButton_clicked();
    void DrawChart();
    //void clearLayout(QVBoxLayout *ChartL, bool deleteWidgets);
    void on_pushButton_2_clicked();

private:
    Ui::solver *ui;
};
#endif // SOLVER_H
