#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QCalendarWidget>
#include <QGroupBox>
#include <QDate>
#include <QHBoxLayout>
#include <QComboBox>
#include <QTableWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QStringList>
#include <QLabel>

#include "views/view.h"
#include "models/giorno.h"
#include "helpers/piatti.h"
#include "helpers/jsonparser.h"
#include "models/item.h"
#include "controllers/piechartcontroller.h"


class CalendarView : public View
{
    Q_OBJECT
public:
    explicit CalendarView(View* parent = nullptr);
    /**
     * @brief Distruttore di CalendarView profondo che cancella tutti i layouts creati
     *  nel costruttore, i quali se lasciati li potrebbero creare memory leak
     */
    virtual ~CalendarView();

    /**
     * @brief setta gli headers delle tabelle in cui vengono visualizzati gli items
     *
     * @param "headers" lista degli headers da applicare alle tabelle
     */
    void setHeaders(QStringList* headers);

    void AggiungiItems(const QList<Item*>& list);
    void clearTables();
    void AggiugniPiatto(const QString& nome);

private:
    QVBoxLayout*     mainLayout;
    QMenuBar*        barraMenu;
    QMenu*           menuFile;
    QAction*         apri;
    QAction*         salva;
    QMenu*           menuGrafici;
    QAction*         grafico1;
    QAction*         grafico2;
    QAction*         grafico3;
    QCalendarWidget* calendario;
    QGroupBox*       GPcolazione;
    QGroupBox*       GPpranzo;
    QGroupBox*       GPcena;
    QGroupBox*       GPaggiungiPasto;
    QComboBox*       CBpiatto;
    QSpinBox*        SBgrammi;
    QComboBox*       CBtipo;
    QTableWidget*    TWcolazione;
    QTableWidget*    TWpranzo;
    QTableWidget*    TWcena;
    QPushButton*     PBAggiungi;
    // lista con tutti i layouts
    QList<QLayout*>  layouts;

    /**
     * @brief setta gli headers delle tabelle in cui vengono visualizzati gli items
     *
     * @param "headers" lista degli headers
     */
    void setTableSettings(QTableWidget*, QStringList* headers);
    /**
     * @brief overriding di connettiSignalsESlots
     *        Connette SIGNALS e SLOT affinchè CalendarController riesca a "catturare"
     *        i SIGNALS della view
     */
    void connettiSignalsESlots()const;


signals:
    /**
     * @brief Avvisa il controller che deve aggiornare la "dataCorrente" nel modello
     *        E' collegato al calendario e viene intercettata dal controller
     *
     * @param "d" data selezionata dall' utente
     */
    void selectDate(const QDate& d)const ;

    /**
     * @brief Avvisa il controller che voglio creare un nuovo item
     *
     * @param "nome" nome del piatto che ho mangiato
     * @param "grams" grammi mangiati
     * @param "tipo" tipo del pasto
     */
    void CreateItem(const QString& nome, unsigned int grams, const QString& tipo)const;

    /**
     * @brief SIGNAL per indicare al controller che voglio aprire il PieChart
     */
    void ApriPieChart()const;

    /**
     * @brief SIGNAL per indicare al controller che voglio aprire il BarChart
     */
    void ApriBarChart()const;

    /**
     * @brief SIGNAL per indicare al controller che voglio aprire il LineChart
     */
    void ApriLineChart()const;

    /**
     * @brief SIGNAL per indicare al controller che voglio salvare su file .json
     */
    void Salva()const;

    void Apri();

    void SelezionaData(const QDate& d);


private slots:
    /**
     * @brief Serve per "emettere" CreateItem, così da avvisare il controller che voglio
     *        Aggiungere un nuovo item alla lista degli item
     */
    void VoglioCreareUnItem()const;

public slots:
    /**
     * @brief Setta  il fatto di essere "enabled" delle action del menu
     *
     * @param b booleno con cui settare le actions
     */
    void settaActions(bool b);
    void onJSONError(const QString& t)const;
};

#endif // CALENDARVIEW_H
