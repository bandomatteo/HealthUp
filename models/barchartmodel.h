#ifndef BARCHARTMODEL_H
#define BARCHARTMODEL_H

#include <QMap>
#include <QString>
#include <QVector>

#include "models/model.h"
#include "models/calendarmodel.h"

class BarChartModel : public Model
{
public:
    /**
     * @brief Costruttore di BarChartModel
     *
     * @param "am" modello da cui estrapolare informazioni
     */
    explicit BarChartModel(CalendarModel* am);
    /**
     * @brief getter di calorieTotali
     *
     * @return Mi ritorna una mappa che rappresenta per ogni giorno del mese della data selezionata dal calendario
     *         il giorno ed il numero di calorie assunte in quel giorno
     */
    const QMap<unsigned int , unsigned int>& getCalorieTotali() const;

private:
    QDate                             data;
    QMap<unsigned int , unsigned int> calorieTotali;

};

#endif // BARCHARTMODEL_H
