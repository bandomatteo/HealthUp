#include "piechartview.h"

PieChartView::PieChartView(const QDate& d, View* parent)
    : ChartView (parent),
      series (new QPieSeries())
{   
    grafico->setTitle("DATA: " + d.toString("dd MMMM yyyy"));
    setMinimumSize(500,300);

    QHBoxLayout* mainL = new QHBoxLayout();
    mainL->addWidget(chartView);
    setLayout(mainL);
}



void PieChartView::showChart() {
    grafico->legend()->setVisible(false);
    series->setLabelsVisible(true);  
    grafico->addSeries(series);

    // titolo della window
    setTitolo("MACRONUTRIENTI");
}

void PieChartView::InserisciDato(const QString &info, unsigned int dato){
    series->append(info + ": " + QString::number(dato)+ " grammi",dato );
}

