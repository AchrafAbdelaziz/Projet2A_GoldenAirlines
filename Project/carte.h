#ifndef CARTE_H
#define CARTE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Carte
{
public:
    Carte();
    Carte(int,QString,int);
    int get_id();
    int get_points();
    QString get_type();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherorder();
    QSqlQueryModel * recherche(const QString &);
    bool supprimer(int);
    bool modifier(int);
private:
    QString type;
    int id,points;
};

#endif // CARTE_H
