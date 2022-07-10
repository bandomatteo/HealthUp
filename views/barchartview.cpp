#include "barchartview.h"

BarChartView::BarChartView(const QDate& d, View* parent)
    :ChartView(parent),
      set(new QBarSet("Calorie")),
      series(new QBarSeries()),
      list (new QStringList()),
      asseX(new QBarCategoryAxis()),
      asseY(new QValueAxis())
{
    // setto il titolo
    grafico->setTitle("Calorie assunte nel mese di  " + d.toString("MMMM"));

    // impostazioni layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(chartView);

    setLayout(layout);
}

void BarChartView::InserisciDato(const QString& info, unsigned int dato){
    // setto l' asse y
    *set <<dato;
    // setto l'asse x
    *list<<info;
}



void BarChartView::showChart() {
    grafico->legend()->setVisible(true);
    grafico->legend()->setAlignment(Qt::AlignBottom);
    asseY->setLabelsVisible(false);

    setMinimumSize(800,800);

    set->setLabelColor(Qt::black);


    series->append(set);
    grafico->addSeries(series);

    asseX->append(*list);
    grafico->addAxis(asseX, Qt::AlignBottom);
    series->attachAxis(asseX);

    grafico->addAxis(asseY, Qt::AlignLeft);
    series->attachAxis(asseY);
    series->setLabelsVisible(true);
    // titolo della window
    setTitolo("CALORIE ASSUNTE MENSILI");

    grafico->axisX()->setTitleText("Giorno della settimana");

    grafico->axisY()->setTitleText("Calorie assunte");
}
