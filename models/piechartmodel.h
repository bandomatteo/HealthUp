#ifndef PIECHARTMODEL_H
#define PIECHARTMODEL_H

#include <QMap>
#include <QString>
#include <QDate>

#include "models/model.h"
#include "models/calendarmodel.h"

class PieChartModel: public Model
{
public:
    /**
     * @brief Costuttore del PieChartModel che è un PieChart che rappresenta in percentuale la quantita'
     *        di proteine, grassi e carboidrati assunti in un giorno
     * @param "am" CalendarModel dal quale prendiamo le informazioni per la mappa infoGiorno
     */
    explicit PieChartModel(CalendarModel* am);

    /**
     * @brief mi ritorna la lista con le info della mappa che sarà del tipo
     *        [Carboidrati] = carboidratiGiornalieri
     *        [Grassi] = grassiGiornalieri
     *        [Proteine] = proteineGiornaliere
     */
    const QMap<QString, unsigned int>& getInfoGiorno() const;

    /**
     * @brief getter della data
     *
     * @return data dell' instanza
     */
    const QDate& getData()const;


private:
    QDate                       data;
    QMap<QString, unsigned int> infoGiorno;

};

#endif // PIECHARTMODEL_H
