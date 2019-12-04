#include "carte.h"

Carte::Carte()
{
id=0;
type="";
points=0;
}
Carte::Carte(int id,QString type,int points)
{
    this->id=id;
    this->points=points;
    this->type=type;
}
QString Carte::get_type(){return type;};
int Carte::get_id(){return id;};
int Carte::get_points(){return points;};

bool Carte::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO carte (ID, TYPE, POINTS) "
                    "VALUES (:id, :type, :points)");
query.bindValue(":id", res);
query.bindValue(":type", type);
query.bindValue(":points", points);

return    query.exec();
}
QSqlQueryModel * Carte::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTS"));
    return model;
}
QSqlQueryModel * Carte::afficherorder()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte order by id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTS"));
    return model;
}
bool Carte::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE carte SET TYPE=:type,POINTS=:points WHERE ID=:id");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":points",points);

    return    query.exec();
}


bool Carte::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from carte where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * Carte::recherche(const QString& id)
{

    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte WHERE (ID LIKE '"+id+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTS"));
    return model;
}

