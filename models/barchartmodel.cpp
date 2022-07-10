#include "barchartmodel.h"


BarChartModel::BarChartModel(CalendarModel* am)
{
    // data corrente
    data = am->getData();
    // mese della data corrente
    int mese = data.month();

    const QVector<Giorno*>& giorni = am->getGiorni();

    for (auto giorno : giorni){
        // controllo che il mese della data presa nel vector sia uguale alla al mese della data
        //  selezionata dal calendario
        if (giorno->getData().month() == mese){
            calorieTotali[giorno->getData().day()] = giorno->CalorieTotali();
        }
    }
}

const QMap<unsigned int , unsigned int>& BarChartModel::getCalorieTotali()const{
    return calorieTotali;
}

