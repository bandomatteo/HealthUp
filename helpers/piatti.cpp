#include "piatti.h"

Piatti::Piatti(){}

Piatti& Piatti::getIstance(){
    static Piatti instance;
    return instance;
}

Piatto* Piatti::getPlate(const QString& s) const{
    for (auto it = plates.begin(); it!= plates.end(); ++it){
        if((**it).getNome() == s)
            return *it;
    }
    return nullptr;
}

Piatto* Piatti::getPiatto(const QString& s){
  return getIstance().getPlate(s);
}

Piatti::~Piatti(){
    for (auto p : plates)
        delete p;
}


QList<Piatto*>& Piatti::getLista(){
    return getIstance().getList();
}

QList<Piatto*>& Piatti::getList(){
    return plates;
}


