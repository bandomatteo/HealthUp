#include "calendarcontroller.h"



CalendarController::CalendarController(CalendarView* v, CalendarModel* m, QObject* parent)
    : Controller(v,m,parent)
{
    for (auto piatto : Piatti::getLista())
        getView()->AggiugniPiatto(piatto->getNome());

    CreaConnessioniVistaController();
}

void CalendarController::CreaConnessioniVistaController()const{
    connect(view,SIGNAL(CreateItem(const QString& , unsigned int , const QString& )),
            this, SLOT(onCreaItem(const QString& , unsigned int , const QString& )));

    connect(view,SIGNAL(selectDate(const QDate&)),
            this, SLOT(onSelectData(const QDate&)));

    connect(view, SIGNAL(ApriPieChart()),
            this, SLOT(onApriPieChart()));

    // serber per settare la proprità "enabled" delle actions nella view
    connect (this,SIGNAL(ControllaSize(bool)),
             view, SLOT(settaActions(bool)));

    connect (view, SIGNAL(Salva()),
             this, SLOT(onSalva()));

    connect (view, SIGNAL(ApriBarChart()),
             this, SLOT(onApriBarChart()));

    connect (view, SIGNAL(ApriLineChart()),
             this, SLOT(onApriLineChart()));

    connect (this , SIGNAL(SettaData(const QDate&)),
             view,  SIGNAL(SelezionaData(const QDate&)));

    connect (view, SIGNAL(Apri()),
             this, SLOT(onApri()));

    connect (this, SIGNAL(ErrorJSON(const QString&)),
             view, SLOT(onJSONError(const QString&)));
}

void CalendarController::onCreaItem(const QString& nome, unsigned int grams, const QString& tipo)const{
    // aggiungo l'item
    getModel()->AggiungiItem(nome,grams,Item::FromStringToTipo(tipo));
    // aggiorno le tabelle nella view
    DisplayItems();
}

void CalendarController::onSelectData(const QDate &d) const{ 
    // setto la data nel modello
    getModel()->setData(d);
    // aggiorno le tabelle nella view
    DisplayItems();

    if (!(getModel()->getCurrentGiorno()->getItemsList().empty()))
        emit ControllaSize(true);
    else
        emit ControllaSize(false);
}

void CalendarController::onApriPieChart() const
{

    Model* model = new PieChartModel(getModel());
    View* view = new PieChartView(getModel()->getData());

    Controller* pcc = new PieChartController(static_cast<PieChartView*>(view),static_cast<PieChartModel*>(model),const_cast<CalendarController*>(this));
    pcc->ShowView();

}

void CalendarController::onApriBarChart() const
{
    BarChartModel* model = new BarChartModel(getModel());
    BarChartView* view = new BarChartView(getModel()->getData());

    BarChartController* controller = new BarChartController(view,model,const_cast<CalendarController*>(this));
    controller->ShowView();
}

void CalendarController::onApriLineChart()const{
    LineChartModel* model = new LineChartModel(getModel());
    LineChartView* view = new LineChartView(getModel()->getData());

    LineChartController* controller = new LineChartController(view,model,const_cast<CalendarController*>(this));
    controller->ShowView();
}

CalendarView* CalendarController::getView() const{
    return static_cast<CalendarView*>(view);
}
CalendarModel* CalendarController::getModel() const{
    return static_cast<CalendarModel*>(model);
}

void CalendarController::DisplayItems()const{
    getView()->clearTables();
    getView()->AggiungiItems(getModel()->getCurrentGiorno()->getItemsList());


}
void CalendarController::onSalva() const{
    JSONParser::ScriviJSON(JSONParser::DaVectorAJSONDoc(getModel()->getGiorni()));
}

void CalendarController::onApri() const{
    // pulisco le tabelle
    getView()->clearTables();

    // rimuovo il garbae
    for (auto it : getModel()->getGiorni())
        delete it;

    //pulisco il vettore
    getModel()->getGiorni().clear();

    // carico il vettore
    if (JSONParser::CaricaVector(getModel())){
        // segnalo che voglio settare la data alla data odierna
        emit SettaData(QDate::currentDate());

        // seleziono la data ondierna
        onSelectData(QDate::currentDate());
    }
    else{
        onSelectData(QDate::currentDate());
        emit ErrorJSON("ERRORE NEL FILE JSON");
    }

}
