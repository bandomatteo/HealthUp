#include "calendarview.h"


CalendarView::CalendarView(View* parent)
    : View (parent),
      mainLayout (new QVBoxLayout),
      barraMenu(new QMenuBar(this)),
      menuFile (new QMenu("FILE",barraMenu)),
      apri (new QAction("Apri",menuFile)),
      salva(new QAction("Salva",menuFile)),
      menuGrafici(new QMenu("GRAFICI",barraMenu)),
      grafico1(new QAction("Macronutrienti giornalieri ",menuGrafici)),
      grafico2(new QAction("Andamento mensile assunzione calorie ",menuGrafici)),
      grafico3(new QAction("Andamento settimanale assunzione delle calorie",menuGrafici)),
      calendario(new QCalendarWidget(this)),
      GPcolazione(new QGroupBox("Colazione",this)),
      GPpranzo(new QGroupBox("Pranzo",this)),
      GPcena(new QGroupBox("Cena",this)),
      GPaggiungiPasto(new QGroupBox("Pasto",this)),
      CBpiatto(new QComboBox(this)),
      SBgrammi(new QSpinBox(this)),
      CBtipo(new QComboBox(this)),
      TWcolazione(new QTableWidget(this)),
      TWpranzo(new QTableWidget(this)),
      TWcena(new QTableWidget(this)),
      PBAggiungi(new QPushButton("+",this))
{
    // aggiungo il menu alla barra dei menu
    barraMenu->addMenu(menuFile);
    barraMenu->addMenu(menuGrafici);

    // aggiungo le  actions
    menuFile->addAction(apri);
    menuFile->addAction(salva);
    menuGrafici->addAction(grafico1);
    menuGrafici->addAction(grafico2);
    menuGrafici->addAction(grafico3);

    //modifiche al calendario
    calendario->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
    QDate min (2000,1,1);
    calendario->setMinimumDate(min);

    //modifiche alla combobox tipo
    CBtipo->addItem("COLAZIONE");
    CBtipo->addItem("PRANZO");
    CBtipo->addItem("CENA");

    /*       ------------------------
     *       |                       |    <--- sopra
     *       -------------------------
     *       |           |           |
     *       |           |           |    <---- sotto
     *       |           |           |
     *       |           |           |
     *        ------------------------
     *         ^               ^
     *         |               |
     *        left            right
     */

    QVBoxLayout* sopra = new QVBoxLayout();
    QHBoxLayout* sotto = new QHBoxLayout();

    QVBoxLayout* left = new QVBoxLayout();
    QVBoxLayout* right = new QVBoxLayout();

    QHBoxLayout* GBpiattoLayout = new QHBoxLayout();

    QVBoxLayout* GBcolazioneLayout = new QVBoxLayout();
    QVBoxLayout* GBpranzoLayout = new QVBoxLayout();
    QVBoxLayout* GBcenaLayout = new QVBoxLayout();

    layouts.push_back(sopra);
    layouts.push_back(sotto);
    layouts.push_back(left);
    layouts.push_back(right);
    layouts.push_back(GBpiattoLayout);
    layouts.push_back(GBcolazioneLayout);
    layouts.push_back(GBpranzoLayout);
    layouts.push_back(GBcenaLayout);



    GBcolazioneLayout->addWidget(TWcolazione);
    GBpranzoLayout->addWidget(TWpranzo);
    GBcenaLayout->addWidget(TWcena);

    // setto i layout ai group box di sotto/sx
    GPcolazione->setLayout(GBcolazioneLayout);
    GPpranzo->setLayout(GBpranzoLayout);
    GPcena->setLayout(GBcenaLayout);

    // aggiungo al main layout quello sopra e quello sotto
    mainLayout->addLayout(sopra);
    mainLayout->addLayout(sotto);

    // aggiungo il menu al layout sopra
    sopra->addWidget(barraMenu);


    //aggiungo layout left e right al layout sotto
    sotto->addLayout(left);
    sotto->addLayout(right);

    // modifiche layout sotto sx
    left->addWidget(calendario);
    left->addWidget(GPcolazione);
    left->addWidget(GPpranzo);
    left->addWidget(GPcena);

    //modifiche al p
    QLabel* logo = new QLabel(this);
    QPixmap pic = QPixmap(":/resources/logo.png");
    pic = pic.scaledToHeight(500);
    //pic = pic.scaledToWidth(400);
    logo->setPixmap(pic);
    //logo->setFixedSize(600,200);
    right->addWidget(logo);

    //right->addSpacing(400);
    right->addWidget(GPaggiungiPasto);


    // modifiche layout per il groupBox Piatto
    GBpiattoLayout->addWidget(CBpiatto);
    GBpiattoLayout->addWidget(SBgrammi);
    GBpiattoLayout->addWidget(CBtipo);
    GBpiattoLayout->addWidget(PBAggiungi);

    GPaggiungiPasto->setLayout(GBpiattoLayout);

    // setto i labesl delle QTablet widget
    QStringList* labels = new QStringList;
    labels->append("Piatto");
    labels->append("Grammi");

    setTableSettings(TWcolazione, labels);
    setTableSettings(TWpranzo, labels);
    setTableSettings(TWcena, labels);

    JSONParser::CaricaListaDaJSON(Piatti::getLista());

    SBgrammi->setMinimum(10);
    SBgrammi->setMaximum(500);

    grafico1->setEnabled(false);
    grafico2->setEnabled(false);
    grafico3->setEnabled(false);


    mainLayout->setSpacing(0);
    setLayout(mainLayout);
    setFixedSize(850, 700);

    // per impostarla al centro dello schermo
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-width()) / 2;
    int y = (screenGeometry.height()-height()) / 2;
    move(x, y);

    setWindowIcon((QIcon(":/resources/icon.png")));

    connettiSignalsESlots();
}

void CalendarView::connettiSignalsESlots()const{

    connect(calendario,SIGNAL(clicked(QDate)),
            this,SIGNAL(selectDate(const QDate)));

    // quando premo sul "+" segnalo che voglio creare un item chiamando la funzione
    //  "VoglioCreareUnItem" la quale emetterà un signal che avvisera il controller
    //  deve creare un nuovo item
    connect(PBAggiungi, SIGNAL(clicked()),
            this, SLOT(VoglioCreareUnItem()));

    connect (grafico1, SIGNAL(triggered()),
             this, SIGNAL(ApriPieChart()));

    connect(salva,SIGNAL(triggered()),
            this,SIGNAL(Salva()));

    connect(apri, SIGNAL(triggered()),
            this, SIGNAL(Apri()));

    connect (grafico2,SIGNAL(triggered()),
             this, SIGNAL(ApriBarChart()));

    connect(grafico3,SIGNAL(triggered()),
            this, SIGNAL(ApriLineChart()));

    connect(this , SIGNAL (SelezionaData(const QDate&)),
            calendario, SLOT(setSelectedDate(const QDate&)));
}

void CalendarView::VoglioCreareUnItem()const{
    //segnala al controller che deve creare un item
    emit CreateItem(CBpiatto->currentText(),SBgrammi->value(),CBtipo->currentText());
}

void CalendarView::settaActions(bool b){
    grafico1->setEnabled(b);
    grafico2->setEnabled(b);
    grafico3->setEnabled(b);
}


CalendarView::~CalendarView(){
    for (auto it : layouts)
        delete it;
}

void CalendarView::setTableSettings(QTableWidget* table, QStringList* headers){
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels(*headers);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setColumnWidth(0,240);
    table->setColumnWidth(1,140);
    //table->setColumnWidth(2,20);
}

void CalendarView::setHeaders(QStringList *headers){
    setTableSettings(TWcolazione, headers);
    setTableSettings(TWpranzo, headers);
    setTableSettings(TWcena, headers);
}

void CalendarView::AggiungiItems(const QList<Item*>& list){
    unsigned int rowIndexColazione = 0;
    unsigned int rowIndexPranzo = 0;
    unsigned int rowIndexCena= 0;

    clearTables();

    if (!list.empty()){
        grafico1->setEnabled(true);
        grafico2->setEnabled(true);
        grafico3->setEnabled(true);
    }


    for (auto item : list){
        // se l'item è del tipo "colazione" devo inserirlo nella tabella
        // della colazione
        if (item->getTipo() == Item::Tipo::COLAZIONE){
            TWcolazione->insertRow(rowIndexColazione);
            TWcolazione->setCellWidget(rowIndexColazione,0,new QLabel(item->getPiatto().getNome(),this));
            TWcolazione->setCellWidget(rowIndexColazione++,1,new QLabel(QString::number(item->getGrammi()),this));
        }
        if (item->getTipo() == Item::Tipo::PRANZO){
            TWpranzo->insertRow(rowIndexPranzo);
            TWpranzo->setCellWidget(rowIndexPranzo,0,new QLabel(item->getPiatto().getNome(),this));
            TWpranzo->setCellWidget(rowIndexPranzo++,1,new QLabel(QString::number(item->getGrammi()),this));
        }
        if (item->getTipo() == Item::Tipo::CENA){
            TWcena->insertRow(rowIndexCena);
            TWcena->setCellWidget(rowIndexCena,0,new QLabel(item->getPiatto().getNome(),this));
            TWcena->setCellWidget(rowIndexCena++,1,new QLabel(QString::number(item->getGrammi()),this));
        }
    }
   //0 qDebug()<<size();
}

void CalendarView::clearTables(){
     TWcolazione->setRowCount(0);
     TWpranzo->setRowCount(0);
     TWcena->setRowCount(0);
}

void CalendarView::AggiugniPiatto(const QString& nome)
{
    CBpiatto->addItem(nome);
}

void CalendarView::onJSONError(const QString& t)const{
    QMessageBox::critical(const_cast<CalendarView*>(this),"ERRORE NEL FILE JSON",t);
}


