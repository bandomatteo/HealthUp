#ifndef PIATTO_H
#define PIATTO_H

#include <QString>

class Piatto
{
public:
    /**
     * @brief Costruttore di Piatto ( tutti i valori si riferiscono per 100 grammi di prodotto)
     *
     * @param "nome" nome del piatto
     * @param "cal" calorie del piatto
     * @param "carbs" carboidrati del piatto
     * @param "grassi" grassi del piatto
     * @param "proteine" proteine del piatto
     */
    explicit Piatto(const QString& nome,  unsigned int cal,  unsigned int carbs, unsigned int grassi, unsigned int prot);
    /**
     * @brief Server per controllare se due piatti sono uguali. Viene usata quando controlliamo
     *        che due items siamo uguali
     * @param "p" parametr
     * @return true sse "p" è uguale al piatto di invocazione
     */
    bool operator==(const Piatto& p) const;

    // GETTERs
    const QString& getNome() const;
    unsigned int getCalorie() const;
    unsigned int getCaroidrati() const;
    unsigned int getGrassi() const;
    unsigned int getProteine() const;

private:
    const QString      mNome;
    const unsigned int mCalorie;
    const unsigned int mCarboidrati;
    const unsigned int mGrassi;
    const unsigned int mProteine;
};

#endif // PIATTO_H
