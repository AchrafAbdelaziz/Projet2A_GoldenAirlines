#include "client.h"
#include <QString>
Client::Client()
{
id=0;
nom="";
prenom="";
adresse="";
datenaiss="";
}
Client::Client(int id,QString nom,QString prenom,QString adresse,QString datenaiss)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->datenaiss=datenaiss;
}
QString Client::get_nom(){return nom;};
int Client::get_id(){return id;};
QString Client::get_adresse(){return adresse;};
QString Client::get_prenom(){return prenom;};
QString Client::get_datenaiss(){return datenaiss;};

bool Client::ajouter1()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO client (ID, NOM, PRENOM, ADRESSE, DATENAISS) "
                    "VALUES (:id, :nom, :prenom, :adresse, :datenaiss)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":datenaiss", datenaiss);

return    query.exec();
}
QSqlQueryModel * Client::afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATENAISS"));
    return model;
}
QSqlQueryModel * Client::afficherorder1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client order by nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATENAISS"));
    return model;
}

bool Client::supprimer1(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from client where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Client::modifier1(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE client SET NOM=:nom,PRENOM=:prenom,ADRESSE=:adresse,DATENAISS=:datenaiss WHERE ID=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":datenaiss",datenaiss);

    return    query.exec();
}
QSqlQueryModel * Client::recherche1(const QString& id)
{

    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client WHERE (ID LIKE '"+id+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATENAISS"));
    return model;
}
QVector<double> Client:: statistique()
{
    QSqlQuery q;
    QVector<double> stat(12);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    stat[5]=0;
    stat[6]=0;
    stat[7]=0;
    stat[8]=0;
    stat[9]=0;
    stat[10]=0;
    stat[11]=0;
    q.prepare("SELECT * FROM client WHERE 1.1<=DATENAISS and DATENAISS<=1.31");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }

    q.prepare("SELECT * FROM client WHERE 1.31<DATENAISS and DATENAISS<=2.31");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }

   q.prepare("SELECT * FROM client WHERE 2.31<DATENAISS and DATENAISS<=3.31");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }

   q.prepare("SELECT * FROM client WHERE 3.31<DATENAISS and DATENAISS<=4.31");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }

    q.prepare("SELECT * FROM client WHERE 4.31<DATENAISS and DATENAISS<=5.31");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    q.prepare("SELECT * FROM client WHERE 5.31<DATENAISS and DATENAISS<=6.31");
    q.exec();
    while (q.next())
    {
        stat[5]++;
    }
    q.prepare("SELECT * FROM client WHERE 6.31<DATENAISS and DATENAISS<=7.31");
    q.exec();
    while (q.next())
    {
        stat[6]++;
    }
    q.prepare("SELECT * FROM client WHERE 7.31<DATENAISS and DATENAISS<=8.31");
    q.exec();
    while (q.next())
    {
        stat[7]++;
    }
    q.prepare("SELECT * FROM client WHERE 8.31<DATENAISS and DATENAISS<=9.31");
    q.exec();
    while (q.next())
    {
        stat[8]++;
    }
    q.prepare("SELECT * FROM client WHERE 9.31<DATENAISS and DATENAISS<=10.31");
    q.exec();
    while (q.next())
    {
        stat[9]++;
    }
    q.prepare("SELECT * FROM client WHERE 10.31<DATENAISS and DATENAISS<=11.31");
    q.exec();
    while (q.next())
    {
        stat[10]++;
    }
    q.prepare("SELECT * FROM client WHERE 11.31<DATENAISS and DATENAISS<=12.31");
    q.exec();
    while (q.next())
    {
        stat[11]++;
    }
    return stat;
}
