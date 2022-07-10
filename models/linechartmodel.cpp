#include "linechartmodel.h"



LineChartModel::LineChartModel(CalendarModel* am)
{
    // data corrente
    dataIniziale = am->getData();

    // vettore dei giorni
    const QVector<Giorno*>& giorni = am->getGiorni();

    for (const auto giorno : giorni)
        // controllo che che il il numero della settimana e l'anno
        // sia uguale a quello selezionato dal calendario
        if (giorno->getData().weekNumber()  == dataIniziale.weekNumber() &&
            giorno->getData().year() == dataIniziale.year()){
             calorieSettimanali[giorno->getData()] = giorno->CalorieTotali();
        }
}

const QMap<QDate, unsigned int>& LineChartModel::getcalorieSettimanali()const{
    return calorieSettimanali;
}


