#ifndef PIATTI_H
#define PIATTI_H

#include <QString>
#include <QList>
#include <QStringList>

#include "models/piatto.h"

/**
 * Class "Piatti" contiene tutti piatti caricati dal file piatti.json
 * Il file ci deve obbligatoriamente essere!
 * Di questo oggetto ne esiste un' unica copia in quanto è un singleton
 */
class Piatti
{
public:
    /**
     * Costruttore di copia reso non disponibile in quanto in memoria ci deve essere
     *  un'unica istanza di Piatti
     */
    Piatti(const Piatti&) = delete;

    /**
     * Operatore di assegnazione reso non disponibile in quanto in memoria ci deve essere
     *  un'unica istanza di Piatti
     */
    Piatti& operator = (const Piatti&)= delete;
    /**
     * Distuttore profondo che si ricorda di allocare ogni elemento di "plates"
     */
    ~Piatti();

    /**
     * Mi ritorna l'unica istanza della classe Piatti
     */
    static Piatti& getIstance();

    /**
     * @brief Aggiunge un item al giornoCorrente
     *
     * @param "s" nome del piatto che devo cercare nella lista dei piatti
     * @return puntarore a piatto con il nome del paramentro "s"
     */
    static Piatto* getPiatto(const QString& s);

    /**
     * @brief getter della lista
     *
     * @return ritorna la lista passibile di mofifiche
     */
    static QList<Piatto*>& getLista();

private:
    Piatti();
    QList<Piatto*>         plates;
    QStringList*           listaPiatti;
    Piatto*                getPlate(const QString& s)const;
    QList<Piatto*>&        getList();
};

#endif // PIATTI_H
