#include "mainwindow.h"
#include "dialogauth.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Création de la connection a la base de donnée
    QSqlDatabase maBase = QSqlDatabase::addDatabase("QMYSQL");
    maBase.setHostName("localhost");
    maBase.setDatabaseName("drivePPE2");
    maBase.setUserName("jeremy");
    maBase.setPassword("elini01");
    bool bddOk = maBase.open();
    if(bddOk)
    {
        qDebug() << "Ok";
        //Créer la condition d'ouverture de la main window
     }       
     DialogAuth dAuth;

    if (dAuth.exec()==QDialog::Accepted)
    {
    MainWindow w;
    w.show();
     return a.exec();
    }
}
