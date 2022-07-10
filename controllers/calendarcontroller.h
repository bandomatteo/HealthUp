#ifndef CALENDARCONTROLLER_H
#define CALENDARCONTROLLER_H

#include "controllers/controller.h"
#include "controllers/linechartcontroller.h"
#include "controllers/barchartcontroller.h"
#include "models/linechartmodel.h"
#include "models/barchartmodel.h"
#include "models/calendarmodel.h"
#include "models/barchartmodel.h"
#include "views/calendarview.h"
#include "views/barchartview.h"
#include "views/linechartview.h"

class CalendarController : public Controller
{
     Q_OBJECT
public:
    explicit CalendarController(CalendarView* v, CalendarModel* m = new CalendarModel(QDate::currentDate()), QObject* parent = nullptr);

    CalendarView* getView() const override;
    CalendarModel* getModel() const override;
private:
    /**
     * @brief Overriding della metodo della base. Serve a fare comunicare vista e controller tramite i SIGNALs e gli SLOTs
     *
     */
    void CreaConnessioniVistaController() const;
    /**
     * @brief Serve per mostrare gli items del giorno corrente nelle tabelle della view
     */
    void DisplayItems()const;

signals:
    /**
     * @brief Serve ad indicare se le actions nella view devo essere enabled
     *        Se la lista degli items del giorno corrente è vuota, allora non
     *        sarà possibile aprire i grafici
     *
     * @param "b" parametro per settare le proprietà delle actions
     */
    void ControllaSize(bool b)const;

    /**
     * @brief Signal che serve per settare la data nel calendario
     *
     * @param "d" data
     */
    void SettaData(const QDate& d)const;

    /**
     * @brief Serve a segnalare che che c'è stato un erroe della lettura del file .json
     *
     * @param "s" messaggio da mostrare
     */
    void ErrorJSON(const QString&)const;


public slots:
    /**
     * @brief SLOT che server a creare un nuovo item e lo inserisce nel modello
     *
     * @param "nome" nome del piatto
     * @param "grams" numero dei grammi
     * @param "tipo" tipo del pasto
     */
    void onCreaItem(const QString& nome, unsigned int grams, const QString& tipo) const;

    /**
     * @brief SLOT che server a cambiare il giorno corrente nel modello
     *
     * @param "d" data nel giorno da impostare
     */
    void onSelectData(const QDate& d)const;

    /**
     * @brief routine da eseguire quando viene premuto "Grafico1" nel menu della view
     */
    void onApriPieChart()const;

    /**
     * @brief routine da eseguire quando viene premuto "Grafico2" nel menu della view
     */
    void onApriBarChart()const;

    /**
     * @brief routine da eseguire quando viene premuto "Grafico3" nel menu della view
     */
    void onApriLineChart()const;

    /**
     * @brief routine da eseguire quando viene premuto "Salva" nel menu della view.
     */
    void onSalva()const;

    /**
     * @brief routine da eseguire quando viene premuto "Apri" nel menu della view.
     */
    void onApri() const;

private slots:
};

#endif // CALENDARCONTROLLER_H
