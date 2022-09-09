#include "solver.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>

QT_USE_NAMESPACE
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QtCharts::QChart *chart = new QtCharts::QChart();
//    chart->legend()->hide();
//    chart->createDefaultAxes();
//    chart->setTitle("Voltage doubler");
//    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    solver w;
    w.show();
//    QMainWindow window;
//    window.setCentralWidget(chartView);
//    window.resize(400, 300);
//    window.show();
    return a.exec();
}
