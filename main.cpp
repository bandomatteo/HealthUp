#include <QApplication>
#include "views/calendarview.h"
#include "controllers/calendarcontroller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CalendarView* view = new CalendarView();
    Controller* controller = new CalendarController(view);
    controller->ShowView();

    return a.exec();
}
