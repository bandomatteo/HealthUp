#include "linechartcontroller.h"

LineChartController::LineChartController(LineChartView* view, LineChartModel* model,QObject* parent)
    : Controller(view,model,parent)
{
    for (auto it = getModel()->getcalorieSettimanali().begin();
         it != getModel()->getcalorieSettimanali().end();
         ++it){
        if (it.value() > 0)
            getView()->InserisciDato(it.key(), it.value());
    }
    //applico le impostazioni
    getView()->showChart();

}

LineChartView* LineChartController::getView() const{
    return static_cast<LineChartView*>(view);
}

LineChartModel* LineChartController::getModel() const{
    return static_cast<LineChartModel*>(model);
}


