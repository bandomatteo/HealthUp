#ifndef LINECHARTVIEW_H
#define LINECHARTVIEW_H

#include <QLineSeries>
#include "views/chartview.h"

class LineChartView : public ChartView
{
    Q_OBJECT
public:
    /**
     * @brief Costruttore di LineChartView
     *
     * @param "d" data per informazioni della view
     * @param "parent" vista che mi ha generato
     */
    LineChartView(const QDate& d, View* parent = nullptr);

    /**
     * @brief overriding del metodo
     *        Applica i "settaggi" del grafico
     */
    void showChart() override;

    /**
     * @brief Inserisce i dati nel grafico
     *
     * @param "date" giorno della settimana
     * @param "dato" calorie assunte in quel giorno
     */
    void InserisciDato(const QDate& info, unsigned int dato);

protected:
    QLineSeries* series;
};

#endif // LINECHARTVIEW_H
