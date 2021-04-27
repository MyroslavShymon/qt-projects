#ifndef TICKET_H
#define TICKET_H

#include <QDate>
#include <QString>



class Ticket
{
public:
    Ticket();
private:
    QString place;
    int numberOfRace;
    QString surname;
    QString initials;
    QDate data;
public:
    Ticket(QString _place, int _numberOfRace, QString _surname, QString _initials, QDate _data):
        place(_place), numberOfRace(_numberOfRace), surname(_surname), initials(_initials), data(_data){

    }
    QString getPlace(){return place;}
    int getNumberOfRace(){return numberOfRace;}
    QString getSurname(){return surname;}
    QString getInitials(){return initials;}
    QDate getData(){return data;}
};

#endif // TICKET_H
