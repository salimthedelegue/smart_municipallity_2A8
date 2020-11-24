#include "vehicule.h"

Vehicule::Vehicule()
{   id=0;
    date=".";
    matricule=".";
    marque=".";
    type=".";
}
Vehicule::Vehicule(int i,QString D,QString Mat,QString Marq,QString T)
{
    id=i;
    date=D;
    matricule=Mat;
    marque=Marq;
    type=T;
}

bool Vehicule::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO VEHICULES (date_mise,matricule,marque,type,id) VALUES (:date_mise,:matricule,:marque,:type,:id)");
    QString res= QString::number(id);
    query.bindValue(":id",res);
    query.bindValue(":matricule",matricule);
    query.bindValue(":marque",marque);
    query.bindValue(":type",type);
    query.bindValue(":date",date);
    return query.exec();
}

bool Vehicule::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE VEHICULES SET date_mise=:date_mise,matricule=:matricule,marque=:marque,type=:type WHERE id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":date_mise",date);
    query.bindValue(":matricule",matricule);
    query.bindValue(":marque",marque);
    query.bindValue(":type",type);

    return query.exec();
}


bool Vehicule::supprimer(int ID)
{
    QSqlQuery query ;
    query.prepare("DELETE FROM VEHICULES where ID= :ID");
    QString res= QString::number(ID);
    query.bindValue(":ID",res);
    return query.exec();
}

QSqlQueryModel * Vehicule:: afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select from * VEHICULES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Marque"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de mise en marche"));
    return model;

}


 QSqlQueryModel * Vehicule::tri_id()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("Select * from VEHICULES order by id ASC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Matricule"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Marque"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de mise en marche"));
     return model;
 }

 QSqlQueryModel * Vehicule::chercher(int id)
 {
 QSqlQueryModel * model= new QSqlQueryModel();
 QString code=QString::number(id);
 model->setQuery("select * FROM PARKINGS WHERE id="+code );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Matricule"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Marque"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de mise en marche"));
 return model;
 }