#include "view.h"

View::View(View *parent) : QWidget(parent,Qt::Window){

}

void View::setTitolo(const QString &t){
    setWindowTitle(t);
}

View::~View(){
    setParent(nullptr);
}

