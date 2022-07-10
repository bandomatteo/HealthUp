#include "jsonparser.h"
#include <QDebug>

JSONParser::JSONParser()
{}

JSONParser& JSONParser::getInstance(){
    static JSONParser instance;
    return instance;
}

const QJsonDocument* JSONParser::fromVectorToJSONDoc(const QVector<Giorno *> &giorni)const{
    //creo il documento
    QJsonArray file;

    for (auto giorno : giorni){
        // ogni oggetto dell'array del file JSON, è del tipo  | {"data" : " ", "items": []}
        QJsonObject elemento;
        // rappresenta l'array degli items
        QJsonArray items;
        // rappresenta il singolo item | {"nomePiatto": " " , grammi: " ", "tipo" : " "
        QJsonObject itemJ;
        if (giorno->contaItemGiornalieri() > 0){
            // inserisco la data
            elemento.insert("data",giorno->getData().toString());
             for (auto item : giorno->getItemsList()){
                 itemJ.insert("nomePiatto:",item->getPiatto().getNome());
                 itemJ.insert("grammi:",(int) item->getGrammi());
                 itemJ.insert("tipo:",item->FromTipoToString());
                 items.push_back(itemJ);
             }
             elemento.insert("items",items);
             file.push_back(elemento);
        }
    }
    QJsonDocument* jsonDoc = new QJsonDocument;
    jsonDoc->setArray(file);

    return jsonDoc;
}

const QJsonDocument* JSONParser::DaVectorAJSONDoc(const QVector<Giorno*>& v){
    return getInstance().fromVectorToJSONDoc(v);
}


void JSONParser::ScriviJSON(const QJsonDocument* doc, const QString& nome){
    getInstance().WriteJSON(doc,nome);
}

void JSONParser::WriteJSON(const QJsonDocument* doc, const QString& nome) const{

    QFile saveFile(nome);
    saveFile.open(QIODevice::WriteOnly);
    saveFile.write(QJsonDocument(*doc).toJson());
    saveFile.close();
    delete doc;
}

void JSONParser::CaricaListaDaJSON(QList<Piatto *> &lista){
    getInstance().uploadListFromJson(lista);
}

void JSONParser::uploadListFromJson(QList<Piatto *> &lista) const {

    if (!(QFile::exists("piatti.json")))
        WriteJSON(CreaPiattiJSON(), "piatti.json");

    QFile piatti("piatti.json");
    QString jsonString;

    piatti.open(QIODevice::ReadOnly | QIODevice::Text);
    jsonString = piatti.readAll();
    piatti.close();


    auto json_doc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonArray jArr = json_doc.array();
    QJsonValue val;

    for(auto jsonObj : jArr){
        val = jsonObj.toObject().value("nomePiatto");
        auto nomePiatto = val.toString();

        val = jsonObj.toObject().value("calorie");
        auto calorie = val.toInt();

        val = jsonObj.toObject().value("carboidrati");
        auto carboidrati = val.toInt();

        val = jsonObj.toObject().value("grassi");
        auto grassi = val.toInt();

        val = jsonObj.toObject().value("proteine");
        auto proteine = val.toInt();

        lista.push_back(new Piatto(nomePiatto,calorie,carboidrati,grassi,proteine));
    }
}


/*void JSONParser::caricaVector(CalendarModel* am){
    getInstance().uploadVector(am);
}*/

bool JSONParser::CaricaVector(CalendarModel* am){
    return getInstance().UploadVector(am);
}

/*void JSONParser::uploadVector(CalendarModel* am) const{
    QFile piatti("save.json");
    QString jsonString;

    if (piatti.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonString = piatti.readAll();
        piatti.close();
     }
    else
        qDebug()<< "file not found";

    auto doc = QJsonDocument::fromJson(jsonString.toUtf8());

    QJsonArray arrayCompleto = doc.array();
    QJsonValue val;

    for (auto giorno : arrayCompleto){

        QJsonObject giornoObj = giorno.toObject();
        val = giornoObj.value("data");
        am->setData(QDate::fromString(val.toString()));

        QJsonArray items = giornoObj.value("items").toArray();

        for (auto item : items){
            QJsonObject itemObj = item.toObject();

            val = itemObj.value("grammi:");
            unsigned int grammi = val.toInt();

            val = itemObj.value("nomePiatto:");
            QString nomePiatto = val.toString();

            val = itemObj.value("tipo:");
            QString tipo = val.toString();

            am->AggiungiItem(nomePiatto,grammi,Item::FromStringToTipo(tipo));
        }
    }
  }*/

bool JSONParser::UploadVector(CalendarModel* am) const{
    QFile piatti("save.json");
    QString jsonString;

    if (piatti.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonString = piatti.readAll();
        piatti.close();
     }
    else
        return false;

    auto doc = QJsonDocument::fromJson(jsonString.toUtf8());


    QJsonArray arrayCompleto = doc.array();
    QJsonValue val;

    for (auto giorno : arrayCompleto){
        QJsonObject giornoObj = giorno.toObject();

        if(!giornoObj.contains("data") || !giornoObj.contains("items")){
            return false;
        }
        else
        {
            val = giornoObj.value("data");
            am->setData(QDate::fromString(val.toString()));

            QJsonArray items = giornoObj.value("items").toArray();

            for (auto item : items){
                QJsonObject itemObj = item.toObject();

                val = itemObj.value("grammi:");
                unsigned int grammi = val.toInt();

                val = itemObj.value("nomePiatto:");
                QString nomePiatto = val.toString();

                val = itemObj.value("tipo:");
                QString tipo = val.toString();

                am->AggiungiItem(nomePiatto,grammi,Item::FromStringToTipo(tipo));
            }
        }
    }
    return true;
}

QJsonDocument* JSONParser::CreaPiattiJSON() const
{
    QJsonArray file;
    QJsonObject item;

    item.insert("nomePiatto", QJsonValue::fromVariant("Torta di albumi e mele light"));
    item.insert("calorie", QJsonValue::fromVariant(233));
    item.insert("carboidrati", QJsonValue::fromVariant(33));
    item.insert("grassi", QJsonValue::fromVariant(9));
    item.insert("proteine", QJsonValue::fromVariant(4));
    file.push_back(item);

    item.insert("nomePiatto", QJsonValue::fromVariant("Torta di mele"));
    item.insert("calorie", QJsonValue::fromVariant(230));
    item.insert("carboidrati", QJsonValue::fromVariant(34));
    item.insert("grassi", QJsonValue::fromVariant(10));
    item.insert("proteine", QJsonValue::fromVariant(3));
    file.push_back(item);

    item.insert("nomePiatto", QJsonValue::fromVariant("Kebab"));
    item.insert("calorie", QJsonValue::fromVariant(248));
    item.insert("carboidrati", QJsonValue::fromVariant(24));
    item.insert("grassi", QJsonValue::fromVariant(12));
    item.insert("proteine", QJsonValue::fromVariant(10));
    file.push_back(item);

    QJsonDocument* jsonDoc = new QJsonDocument;
    jsonDoc->setArray(file);

    return jsonDoc;
}
