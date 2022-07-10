#include "controller.h"

Controller::Controller(View* v, Model* m, QObject *parent)
    : QObject(parent),
      view(v),
      model(m)
{}

Controller::~Controller(){

    while ( QWidget* w = findChild<QWidget*>() )
        delete w;

    delete model;
    delete view;
}

void Controller::ShowView()const{
    view->show();
}


