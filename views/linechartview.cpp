#include "linechartview.h"

LineChartView::LineChartView(const QDate& d, View* parent)
    : ChartView(parent),
      series (new QLineSeries())
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
    setMinimumSize(500,300);   
    setTitolo("Calorie assunte nella settimana del " + d.toString("dd MMMM"));
}

void LineChartView::InserisciDato(const QDate& info, unsigned int dato){
   series->append(info.day(), dato);


}

void LineChartView::showChart() {

    //grafico->setTitle("Calorie assunte in questa settimana");
    chartView->setRenderHint(QPainter::Antialiasing);
    grafico->legend()->setVisible(false);

    grafico->addSeries(series);
    grafico->createDefaultAxes();

    QValueAxis* asse = new QValueAxis;
    asse->setTickCount(7);
    asse->setLabelFormat("%.2d");
    grafico->setAxisX(asse, series);



    grafico->axisX()->setTitleText("Giorno della settimana");

    grafico->axisY()->setTitleText("Calorie assunte");


}
