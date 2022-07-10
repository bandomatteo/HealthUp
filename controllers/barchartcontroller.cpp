#include "barchartcontroller.h"

BarChartController::BarChartController(BarChartView* view, BarChartModel* model, QObject* parent)
    : Controller (view,model,parent)
{
    for (auto it = getModel()->getCalorieTotali().begin(); it != getModel()->getCalorieTotali().end(); ++it){
            if (it.value()>0)
                getView()->InserisciDato(QString::number(it.key()),it.value());
        }
        // applica le impostazioni al gragico
        getView()->showChart();
}

BarChartView* BarChartController::getView() const{
    return static_cast<BarChartView*>(view);
}

BarChartModel* BarChartController::getModel() const{
    return static_cast<BarChartModel*>(model);
}


