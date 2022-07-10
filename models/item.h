#ifndef ITEM_H
#define ITEM_H

#include "models/piatto.h"

class Item
{
public:
    /**
     * @brief Tipo rappresenta il tipo del pasto
     */
    enum Tipo
    {
        COLAZIONE, ///< Pasto consumato durante la colazione
        PRANZO,    ///< Pasto consumato durante il pranzo
        CENA,      ///< Pasto consumato durante la cena
        SNACK,     ///< Pasto consumato durante la giornata che non sia colazione, pranzo o cena
    };

    /**
     * @brief Costruttore per l'item
     * @param "p" è il piatto usato per costuire il l'oggetti dell'item che verrà presso
     *          dalla lista di Piatti caricati da file
     * @param "grams" grammi mangiati
     * @param "tipo" speficatore del tipo di pasto
     */
    explicit Item(const Piatto& p, unsigned int grams, Tipo tipo);

    /**
     * @brief Controlla se due item hanno lo stesso nome del piatto e lo stesso tipo di tipo
     *         Usa anche l'"operator ==" del pasto
     * @param "i" item passato per vedere se è uguale
     * @return true sse l'item ha lo stesso piatto e lo stesso tipo ( non controlla i grammi)
     */
    bool operator==(const Item& i)const;

    // GETTERS
    unsigned int getGrammi() const;
    Tipo getTipo() const;
    const Piatto& getPiatto()const;

    // SETTERS
    void setGrammi(unsigned int grams);
    //void setTipo(Tipo type);

    /**
     * @brief Calcola i carboidrati del piatto in corrispondenza dei grammi mangiati
     *
     * @return carboidrati assunti
     */
    unsigned int calcolaCarbs() const;

    /**
     * @brief Calcola i grassi del piatto in corrispondenza dei grammi mangiati
     *
     * @return grassi assunti
     */
    unsigned int calcolaGrassi() const;

    /**
     * @brief Calcola le proteine del piatto in corrispondenza dei grammi mangiati
     *
     * @return proteine assunte
     */
    unsigned int calcolaProteine() const;

    /**
     * @brief Calcola le calorie del piatto in corrispondenza dei grammi mangiati
     *
     * @return calorie assunte
     */

    unsigned int calcolaCalorie()const;

    /**
     * @brief Mi ritorna il Tipo del piatto corretto
     *
     * @param "s" stringa da convertire al Tipo corretto
     * @return il Tipo del piatto
     */
    static Tipo FromStringToTipo(const QString& s);

    // ritornata per valore perchè sennò causerebbe ilegalità UB
    QString FromTipoToString()const;

private:
    Piatto        mPiatto;
    unsigned int  mGrammi;
    Tipo          mTipo;
};

#endif // ITEM_H
