#ifndef PIECHARTCONTROLLER_H
#define PIECHARTCONTROLLER_H

#include "views/piechartview.h"
#include "models/piechartmodel.h"
#include "controllers/controller.h"

class PieChartController : public Controller
{
    Q_OBJECT
public:
    /**
     * @brief Costruttore per la classe PieChartController
     *
     * @param "view" vista
     * @param "model" modello
     * @param "parent" il QObject che mi ha creato
     */
    PieChartController(PieChartView* view, PieChartModel* model,QObject* parent = nullptr);

    /**
     * @brief getter della vista. E' un overriding della base. Ritorna il tipo PieChartView* per covarianza
     *
     * @return puntatore alla vista del tipo corretto
     */
    PieChartView* getView() const override;

    /**
     * @brief getter del modello. E' un overriding della base. Ritorna il tipo PieChartModel* per covarianza
     *
     * @return puntatore al modello del tipo corretto
     */
    PieChartModel* getModel() const override;
};

#endif // PIECHARTCONTROLLER_H
