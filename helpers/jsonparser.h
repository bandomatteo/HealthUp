#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVector>

#include "models/giorno.h"
#include "models/model.h"
#include "models/calendarmodel.h"

/**
 * @brief La classe si occupa di salvare o caricare da file di tipo JSON.
 *        Si è voluto seguire il pattern Singleton in quando basta un' unica
 *        instanza di questa classe
 */
class JSONParser
{
public:
    JSONParser(const JSONParser&) = delete;
    JSONParser& operator =(const JSONParser&)=delete;
    /**
     * @brief Funge da "costruttore" logico, in quanto mi restituisce l'unica istanza statica
     *        creata
     *
     * @return istanza della classe JSONParser
     */
    static JSONParser& getInstance();

    /**
     * @brief Mi Costruisce un JSONDocument a partire da un vettore di giorni
     *
     * @param "v" vettore da "parsare"
     * @return puntatore al QJSONDocument creato
     */
    static const QJsonDocument* DaVectorAJSONDoc(const QVector<Giorno*>& v);

    /**
     * @brief Scrive un file .JSON su disco
     *
     * @param "doc" documento che si vuole scrivere su disco
     * @param "nome" nome con cui si vuole salvare il file
     */
    static void ScriviJSON(const QJsonDocument* doc, const QString& nome = "save.json" );

    /**
     * @brief Carica i dati della lista dei piatti da un file .JSON
     *
     * @param "lista" lista che si vuole caricare
     */
    static void CaricaListaDaJSON(QList<Piatto*>& lista);


    //static void caricaVector(CalendarModel* am);
    /**
     * @brief Carica il vettore degli dei giorni
     *
     * @param "am" modello contenente il vettore
     */
    static bool CaricaVector(CalendarModel* am);
private:
    /**
     * @brief Costruttore di JSONParser. Crea l'unica istanza statica
     */
    JSONParser();

    void WriteJSON(const QJsonDocument* doc, const QString& nome) const;
    const QJsonDocument*  fromVectorToJSONDoc(const QVector<Giorno*>& v)const; //fatta
    void uploadListFromJson(QList<Piatto*>& lista)const;
    void uploadVector(CalendarModel* am)const;
    bool UploadVector(CalendarModel* am)const;
    QJsonDocument* CreaPiattiJSON()const;
};

#endif // JSONPARSER_H
