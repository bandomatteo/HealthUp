#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "views/view.h"
#include "models/model.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(View* v, Model* m, QObject* parent = nullptr);

    /**
     * @brief Metodo virtuale puro
     *        Deve essere implementato nelle classi derivanti e ritorna il tipo del modello corretto per covarianza
     *
     * @return puntatore al modello
     */
    virtual Model* getModel() const = 0;

    /**
     * @brief Metodo virtuale puro
     *        Deve essere implementato nelle classi derivanti e ritorna il tipo della vista corretto per covarianza
     *
     * @return puntatore alla vista
     */
    virtual View* getView() const = 0;

    /**
     * @brief Distruttore virtuale "profondo"
     */
    virtual ~Controller();

    /**
     * @brief mostra la view collegata al controller
     */
     virtual void ShowView() const;

protected:
    View* view;
    Model* model;  

private:

signals:

public slots:
};

#endif // CONTROLLER_H
