#include <QtWidgets/QMainWindow>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>

QT_USE_NAMESPACE
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    solver w;
    w.show();
    return a.exec();
}
