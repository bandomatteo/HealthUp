#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(View *parent = nullptr);
    /**
     * @brief Metodo che serve a modificare il nome della Viw
     *
     * @param "t" titolo della view
     */
    void setTitolo(const QString& t);
    virtual ~View();

private:
    /**
     * @brief Serve a connettere SIGNALS E SLOT tra oggetti della view affinchè il controller
     *        riesca a "catturare" i signals emessi dalla view
     *        E' da implementare nelle derivate in quanto virtuale pura
     */
    //virtual void connettiSignalsESlots()const = 0;

signals:

public slots:
};

#endif // VIEW_H
