#include "piatto.h"

Piatto::Piatto(const QString& nome,  unsigned int cal,  unsigned int carbs, unsigned int grassi, unsigned int prot):
    mNome(nome),
    mCalorie(cal),
    mCarboidrati(carbs),
    mGrassi(grassi),
    mProteine(prot){}

const QString& Piatto::getNome() const{
    return mNome;
}

unsigned int Piatto::getCalorie() const{
    return mCalorie;

}
unsigned int Piatto::getCaroidrati() const{
    return mCarboidrati;
}

unsigned int Piatto::getGrassi() const{
    return mGrassi;
}

unsigned int Piatto::getProteine() const{
    return mProteine;
}

bool Piatto::operator==(const Piatto& p) const{
    return mNome == p.mNome &&
           mCalorie == p.mCalorie &&
           mCarboidrati == p.mCarboidrati &&
           mGrassi == p.mGrassi &&
           mProteine == p.mProteine;
}


