#ifndef LINECHARTCONTROLLER_H
#define LINECHARTCONTROLLER_H

#include "views/linechartview.h"
#include "models/linechartmodel.h"
#include "controllers/controller.h"

class LineChartController : public Controller
{
public:
    /**
     * @brief Costruttore per la LineChartController
     *
     * @param "view" vista
     * @param "model" modello
     * @param "parent" il QObject che mi ha creato
     */
    LineChartController(LineChartView* view, LineChartModel* model,QObject* parent = nullptr);

    /**
     * @brief getter della vista. E' un overriding della base. Ritorna il tipo LineChartView* per covarianza
     *
     * @return puntatore alla vista del tipo corretto
     */
    LineChartView* getView() const override;

    /**
     * @brief getter della vista. E' un overriding della base. Ritorna il tipo LineChartModel* per covarianza
     *
     * @return puntatore alla vista del tipo corretto
     */
    LineChartModel* getModel() const override;
};

#endif // LINECHARTCONTROLLER_H
