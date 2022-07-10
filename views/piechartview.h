#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include <QtCharts/QPieSeries>
#include <QHBoxLayout>
#include <QDate>

#include "views/chartview.h"


class PieChartView : public ChartView
{
    Q_OBJECT
public:
    /**
     * @brief Costruttore di PieChartView
     *
     * @param "d" data per informazioni della view
     * @param "parent" vista che mi ha generato
     */
    PieChartView(const QDate& d, View* parent = nullptr);

    /**
     * @brief overriding del metodo
     *        Applica i "settaggi" del grafico
     */
    void showChart() override;

    /**
     * @brief Inserisce i dati nel grafico
     *
     * @param "info" tipo di valore nutrizionale
     * @param "dato" quantità assunta
     */
    void InserisciDato(const QString& info, unsigned int dato);

protected:
    QPieSeries* series;

private:
    /**
     * @brief overriding della base
     */
    //void connettiSignalsESlots() const override;
};

#endif // PIECHARTVIEW_H
