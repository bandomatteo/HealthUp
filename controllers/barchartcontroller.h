#ifndef BARCHARTCONTROLLER_H
#define BARCHARTCONTROLLER_H
#include "views/barchartview.h"
#include "models/barchartmodel.h"
#include "controllers/controller.h"

class BarChartController : public Controller
{
public:
    /**
     * @brief Costruttore per la classe BarChartController
     *
     * @param "view" vista
     * @param "model" modello
     * @param "parent" il QObject che mi ha creato
     */
    BarChartController(BarChartView* view, BarChartModel* model, QObject* parent = nullptr);

    /**
     * @brief getter della vista. E' un overriding della base. Ritorna il tipo BarChartView* per covarianza
     *
     * @return puntatore alla vista del tipo corretto
     */
    BarChartView* getView() const override;

    /**
     * @brief getter del modello. E' un overriding della base. Ritorna il tipo BarChartModel* per covarianza
     *
     * @return puntatore al modello del tipo corretto
     */
    BarChartModel* getModel() const override;
};

#endif // BARCHARTCONTROLLER_H
