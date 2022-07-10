#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QVector>
#include <QDate>

#include"models/giorno.h"
#include "models/model.h"
#include "models/item.h"
#include "helpers/piatti.h"

class CalendarModel : public Model
{
public:
    /**
     * @brief Crea un nuovo Model a partire da una data
     *        Ovviamente la prima volta che si crea un modello il vettore dei giorni sarà vuoto
     *        quindi viene creato il nuovo un nuovo giorno, viene aggiunto alla lista dei giorni
     *        e current viene fatto puntare al nuovo giorno creato
     *
     * @param q: data nel nuovo giorno creato
     */
    explicit CalendarModel(const QDate& q = QDate::currentDate());

    /**
     * @brief Distruttore profondo di CalendarModel
     *        Si preouccupa di eliminare tutti gli item nella lista
     */
    ~CalendarModel();

    /**
     * @brief Aggiunge un item al giornoCorrente
     *
     * @param "nome" nome del piatto
     * @param "grams" grammi mangiati
     * @param "tipo" tipo del pasto
     */
    void AggiungiItem(const QString& nome, unsigned int grams, Item::Tipo tipo);

    /**
     * @brief imposto la data corrente = alla data "d" e cerco all'interno del vettore dei
     *        giorni se esiste un giorno con la stessa data "d", se ci fosse allora
     *        setto il currentGiorno = al giorno con la stessa data nel vettore
     *        In caso negativo creo un nuovo giorno con la data d
     *
     * @param "d" data che voglio impostare alla dataCorrente
     */
    void setData(const QDate& d);

    /**
     * @brief getter della data
     *
     * @return dataCorrente
     */
    const QDate& getData()const;

    /**
     * @brief Calcola i Carboidrati del giorno corrente
     *
     * @return somma dei carboidrati di tutti gli items del giorno corrente
     */
    unsigned int CarbsGiornalieri()const;

    /**
     * @brief Mi ritorna il giorno attuale
     *
     * @return "Giorno*" puntatore al giorno corrente
     */
    Giorno* getCurrentGiorno()const;

    /**
     * @brief Mi ritorna il numero dei piatti consumati in un giorno dato un nomePiatto
     *
     * @param "nomePiatto" nome del piatto per cui devo calcolare il numero di piatti mangiati
     * @return numero dei piatti mangiati
     */
    unsigned int contaNumeroPiatti(const QString& nomePiatto)const;

    /**
     * @brief Conta tutti gli items
     *
     * @return il numero di items totali
     */
    unsigned int contaItemTotali()const;

    /**
     * @brief getter della lista dei giorni
     *
     * @return vettore con i puntatori ai giorni costante
     */
    const QVector<Giorno*>& getGiorni() const;

    /**
     * @brief getter della lista dei giorni
     *
     * @return vettore con i puntatori ai giorni non constante
     */
    QVector<Giorno*>& getGiorni();


private:
    QVector<Giorno*>  giorni;
    QDate             dataCorrente;
    Giorno*           currentGiorno;   //  giorno dove andrò a fare le modifiche
};

#endif // CALENDARMODEL_H
