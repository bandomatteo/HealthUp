#include "chartview.h"

ChartView::ChartView(View *parent)
    : View(parent),
      grafico(new QChart()),
      chartView(new QChartView(grafico))
{
    grafico->setAnimationOptions(QChart::AllAnimations);
    grafico->setAnimationDuration(1000);
}

