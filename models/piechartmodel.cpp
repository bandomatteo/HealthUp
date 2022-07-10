#include "piechartmodel.h"


PieChartModel::PieChartModel(CalendarModel* am)
{
    data = am->getData();
    infoGiorno["Carboidrati"] = am->getCurrentGiorno()->CarboidratiTotali();
    infoGiorno["Grassi"] = am->getCurrentGiorno()->GrassiTotali();
    infoGiorno["Proteine"]= am->getCurrentGiorno()->ProteineTotali();
}

const QMap<QString,unsigned int>& PieChartModel::getInfoGiorno() const{
    return infoGiorno;
}

const QDate& PieChartModel::getData()const{
    return data;
}

