#include "dialogauth.h"
#include "ui_dialogauth.h"
#include <QAuthenticator>
#include <QDebug>
#include <QSqlQuery>
#include <QByteArray>
#include <QCryptographicHash>

//On doit passser par ici obligatoirement
DialogAuth::DialogAuth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAuth)
{
    ui->setupUi(this);
    ui->lineEditLogin->setText("admin");
    ui->lineEditPwd->setText("admin");
}

DialogAuth::~DialogAuth()
{
    delete ui;
}

void DialogAuth::on_pushButtonEnvoyer_clicked()
{
qDebug() << "DialogAuth::on_pushButtonEnvoyer_clicked()";
 //Chek pour savoir si les line edit ne sont pas vide
    if (!(ui->lineEditLogin->text().isEmpty() && ui->lineEditPwd->text().isEmpty()))
    {
    QString login =  ui->lineEditLogin->text();
    QByteArray pwd = ui->lineEditPwd->text().toLocal8Bit(); // on creer le mdp en octet pour pouvoir le lire avec cryptographichash
    QSqlQuery reqRechercheInfo("select userLogin,userMdp from utilisateur where userRole>=3 and userLogin='"+login+"'");
    reqRechercheInfo.first();
    QString loginSql = reqRechercheInfo.value("userLogin").toString();
    QString mdpSql = reqRechercheInfo.value("userMdp").toString();
    QString mdpEntreeMd5 = QString(QCryptographicHash::hash((pwd),QCryptographicHash::Md5).toHex()); //permet de transformer le mdp normal en md5 . toHex de convertir de binaiare en hexa.
qDebug() << mdpEntreeMd5;
qDebug() << loginSql << mdpSql;
     if(login==loginSql && mdpEntreeMd5==mdpSql)
     {
            accept();
     }
     else
     {
         ui->labelRemplir->setText("Mot de passe ou identifiant incorrect veuillez réessayer.");
     }
qDebug() << "ca marche et c'est pas vide ";
    }
    else
    {
qDebug() << "ca marche est c'est vide ";
    ui->labelRemplir->setText("Remplir le login et le mot de passe s'il vous plaît");
    }


   //Check avec la base de donneés savoir si il est un superAdmin/admin
}

void DialogAuth::on_pushButtonAnnuler_clicked()
{
    //Doit quitter l'application en entier
    reject();
}
