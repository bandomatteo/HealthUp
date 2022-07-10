#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include "views/chartview.h"

class BarChartView : public ChartView
{
    Q_OBJECT
public:
    /**
     * @brief Costruttore di BarChartView
     *
     * @param "d" data per informazioni della view
     * @param "parent" vista che mi ha generato
     */
    BarChartView(const QDate& d, View* parent = nullptr);

    /**
     * @brief overriding del metodo
     *        Applica i "settaggi" del grafico
     */
    void showChart() override;

    /**
     * @brief Inserisce i dati nel grafico
     *
     * @param "info" giorno della settimana
     * @param "dato" calorie assunte in quel giorno
     */
    void InserisciDato(const QString& info, unsigned int dato);

protected:
    QBarSet*          set;
    QBarSeries*       series;
    QStringList*      list;
    QBarCategoryAxis* asseX;
    QValueAxis*       asseY;
};

#endif // BARCHARTVIEW_H
