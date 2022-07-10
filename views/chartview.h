#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts>
#include <QtCharts/QChartView>

#include "views/view.h"

/**
 * @brief Classe astratta per i charts.
 *        Ogni charts dovrà implementare tutti le funzioni virtuale pure
 */
class ChartView: public View
{
    Q_OBJECT
public:
    explicit ChartView(View *parent = nullptr);
    /**
     * @brief Interfaccia che ogni derivata dovrà implementare.
     *        Setta le impostazioni del grafico
     */
    virtual void showChart() = 0;

protected:         
    QChart*     grafico;
    QChartView* chartView;
};

#endif // CHARTVIEW_H
