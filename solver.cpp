#include "solver.h"
#include "ui_solver.h"
#include <tgmath.h>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QApplication>
#include <QProcess>

solver::solver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::solver)
{
    ui->setupUi(this);
}

solver::~solver()
{
    delete ui;
}
QtCharts::QLineSeries *series_v1 = new QtCharts::QLineSeries();
QtCharts::QLineSeries *series_v2 = new QtCharts::QLineSeries();

double f = 1000.0;
double A = 3.0;
double C1 = 1.0e-7;
double C2 = 1.0e-7;
double is = 2.0e-9;
double nvt = 0.05;
double R = 1.0e9;
double rt = 2;
//double tol = 0.0001;
double v1 = 0.0, v2 = 0.0, t = 0.0;
double h = 1e-3;


double dv1(double v1, double v2, double t)
{
    double w=6.28*f;
    double vd = v1-v2;
    double res = w*A*cos(w*t) - is/C1*(exp(vd/nvt)-exp(-v1/nvt));
    return res;
}

double dv2(double v1, double v2)
{
    double vd = v1-v2;
    double res = 1/C2*(is*(exp(vd/nvt)-1)-v2/R);
    return res;
}

double rk4(double v1, double v2, double rt)
{

        double k0,k1,k2,k3,l0,l1,l2,l3;
        while(t<=rt)
        {
           k0 = dv1(v1,v2,t);
           l0 = dv2(v1,v2);

           k1 = dv1(v1+h*k0/2, v2+h*l0/2, t+h/2);
           l1 = dv2(v1+h*k0/2, v2+h*l0/2);

           k2 = dv1(v1+h*k1/2, v2+h*l1/2, t+h/2);
           l2 = dv2(v1+h*k1/2, v2+h*l1/2);

           k3 = dv1(v1+h*k2,v2+h*l2,t+h);
           l3 = dv2(v1+h*k2,v2+h*l2);

           series_v1 -> append(t,v1);
           series_v2 -> append(t,v2);

           v1 = v1+h*(k0+2*k1+2*k2+k3)/6;
           v2 = v2+h*(l0+2*l1+2*l2+l3)/6;




           t +=h;

        }
        return v2;
}


void solver::on_pushButton_clicked()
{

    rt = ui->lineEdit_5->text().toDouble();
    A = ui->lineEdit->text().toDouble();
    f = ui->lineEdit_3->text().toDouble();
    C1 = ui->lineEdit_2->text().toDouble();
    C2 = ui->lineEdit_4->text().toDouble();
    R = ui->lineEdit_6->text().toDouble();
    is = ui->lineEdit_8->text().toDouble();
    nvt = ui->lineEdit_7->text().toDouble();
    h = ui->lineEdit_9->text().toDouble();
    v2 = rk4(v1,v2,rt);
    ui->label->setText(QString::number(v2));
    DrawChart();

}

void solver::DrawChart()
{

    using namespace QtCharts;
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series_v2);
    chart->addSeries(series_v1);
    chart->createDefaultAxes();
    chart->setTitle("V1: Green, V2: Blue");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->ChartL->addWidget(chartView);

}

//void solver::clearLayout(QVBoxLayout* ChartL, bool deleteWidgets = true)
//{
//    while (QLayoutItem* item = ChartL->takeAt(0))
//    {
//        if (deleteWidgets)
//        {
//            if (QWidget* widget = item->widget())
//                widget->deleteLater();
//        }
//        if (QLayout* childLayout = item->layout())
//            clearLayout(childLayout, deleteWidgets);
//        delete item;
//    }
//}

void solver::on_pushButton_2_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

