#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include <QMap>
#include <QDate>

#include "models/model.h"
#include "models/calendarmodel.h"

class LineChartModel : public Model
{
public:
    /**
     * @brief Costruttore di LineChartModel
     *
     * @param "am" modello da cui estrapolare informazioni
     */
    explicit LineChartModel(CalendarModel* am);

    /**
     * @brief getter di calorieSettimanali
     *
     * @return Mi ritorna un mappa che, dato un giorno della settimana preso dal modello,
     *         mi mostra l'andamento delle calorie assunte di quella settimana
     */
    const QMap<QDate, unsigned int>& getcalorieSettimanali() const;

private:
    QDate                    dataIniziale;
    QMap<QDate,unsigned int> calorieSettimanali;
};

#endif // LINECHARTMODEL_H
