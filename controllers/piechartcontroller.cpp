#include "piechartcontroller.h"

PieChartController::PieChartController(PieChartView* view, PieChartModel* model,QObject* parent)
    : Controller(view,model,parent)
{
    for (auto it = getModel()->getInfoGiorno().begin(); it != getModel()->getInfoGiorno().end(); ++it)
    {
        //qDebug()<<it.key()<<it.value();
        getView()->InserisciDato(it.key(),it.value());
    }
    // applica le impostazioni al gragico
    getView()->showChart();
}

PieChartView* PieChartController::getView() const{
    return static_cast<PieChartView*>(view);
}

PieChartModel* PieChartController::getModel() const{
    return static_cast<PieChartModel*>(model);
}

