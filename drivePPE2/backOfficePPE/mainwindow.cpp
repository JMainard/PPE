#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherAnnonceVente();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::infoPourMail(QString pourquoi)
{
qDebug() <<"MainWindow::infoPourMail(QString pourquoi)";

    QSqlQuery reqRecupMailProd("select annProduit,annId,userPrenom,userNom,userMail from utilisateur natural join producteur natural join annonceVente where annId="+ui->tableWidgetProdAVerif->item(ui->tableWidgetProdAVerif->currentRow(),0)->text()+"");
    reqRecupMailProd.first();

    QString annProduit=reqRecupMailProd.value("annonceProduit").toString();
    QString annId=reqRecupMailProd.value("annonceId").toString();
    QString prenomProd=reqRecupMailProd.value("userPrenom").toString();
    QString nomProd=reqRecupMailProd.value("userNom").toString();
    QString mail=reqRecupMailProd.value("userMail").toString();

    qDebug() <<"select userMail from utilisateur natural join producteur natural join annonceVente where annId="+ui->tableWidgetProdAVerif->item(ui->tableWidgetProdAVerif->currentRow(),0)->text()+"";
    qDebug() << ui->tableWidgetProdAVerif->item(ui->tableWidgetProdAVerif->currentRow(),0)->text();

    if(pourquoi == "suppression")
    {
       QString objetMail="Supression de votre annonce n°"+annId+"";
       QString message="Bonjour "+nomProd+" "+prenomProd+",nous somme désolés mais votre annonce n°"+annId+" concernant le produit "+annProduit+" n'étant pas en règle avec nos instistutions.Nous nous devons de supprimer votre article de notre site.\n"
                       "Pour tout renseignement suplémentaire veuillez vous retourner au règlement concernant la vente de produit et ses conventions\n";
                        "Cordialement l'équipe de déolia.";
       //Requête qui vas implementer les informations des mails dans la bdd afin de les envoyer à 18 heures.
       QSqlQuery reqEnvoiMail("insert into mail values ('"+mail+"','"+objetMail+"','"+message+"' ");
       reqEnvoiMail.exec();
    }
    else if (pourquoi == "modification")
    {
        QString objetMail="Modification de votre annonce n°"+annId+"";
        //Envoie d'un mail et d'un lien pour savoir si le producteur est en accord avec la modification effectués par l'administrateur et qu'il puisse définitivement validé son annonce et que si refus des modifications, on annule l'annonce et il la recommence.
        QString message="Bonjour "+nomProd+" "+prenomProd+", nous vous informons que nous avons modfiés quelque informations concerant votre annonce n°"+annId+" concernant le produit "+annProduit+".\n";
                       /// "lien qui envoie sur le site /l'onglet on il peut valider la modifcation de 'lannonce (revue de l'annonce)  ";
                       "Cordialement l'équipe de déolia.";
        QSqlQuery reqEnvoiMail("insert into mail values ('"+mail+"','"+objetMail+"','"+message+"' ");
        reqEnvoiMail.exec();
    }

    else if (pourquoi == "validation")
    {
        QString objetMail ="Validation de votre annonce n°"+annId+"";
        QString message="Bonjour "+nomProd+" "+prenomProd+",nous avons le plaisir de vous informer de la confirmation de votre annonce n°"+annId+" concernant le produit "+annProduit+".\n"
                        "Elle est désormais disponible sur le site et vous pouvez voir toutes les commandes concernant votre annonce sur votre espace personnel dans mesAnnonces sur notre site web.\n"
                        "Cordialement l'équipe déolia";
        QSqlQuery reqEnvoiMail("insert into mail values ('"+mail+"','"+objetMail+"','"+message+"' ");
        reqEnvoiMail.exec();
    }

}

void MainWindow::afficherAnnonceVente()
{
    //Permet d'appeler toutes les annonces ventes qui ne sont toujours pas accepté/validé ni supprimé
    QSqlQuery reqAfficheAnnonce("select annId,uMesureLib, annProduit, annVariete, annCategorie, annQuantite, annPhoto, annPrixKG, annPrixHT, annPrixTTC, annDLC from annonceVente inner join uniteMesure on annUMesure=uMesureId where annValide=0 and annSupprime=0 ");

    int numLigne=0;
    ui->tableWidgetProdAVerif->setRowCount(0);
    while (reqAfficheAnnonce.next()) {

    ui->tableWidgetProdAVerif->setRowCount(ui->tableWidgetProdAVerif->rowCount()+1);
    //On récupère les information en fonction de leur "valeur".
    QString annId =reqAfficheAnnonce.value("annId").toString();
    QString uniteMesureProd = reqAfficheAnnonce.value("uMesureLib").toString();
    QString nomProd = reqAfficheAnnonce.value("annProduit").toString();
    QString varieteProd = reqAfficheAnnonce.value("annVariete").toString();
    QString categorieProd = reqAfficheAnnonce.value("annCategorie").toString();
    QString quantiteProd = reqAfficheAnnonce.value("annQuantite").toString();
    QString cheminPhotoProd = reqAfficheAnnonce.value("annPhoto").toString();
    QString prixKGProd = reqAfficheAnnonce.value("annPrixKG").toString();
    QString prixHTProd = reqAfficheAnnonce.value("annPrixHT").toString();
    QString prixTTCProd = reqAfficheAnnonce.value("annPrixTTC").toString();
    QString dlcProd = reqAfficheAnnonce.value("annDLC").toString();




    //On ajoute les info dans le tableau en créant des items dans le tableau qui indique en premier la ligne puis la colonne
    //Puis l'info a ajouter en créant un nouveau QTableWidgetItem et le nom de la variable juste au dessus
    ui->tableWidgetProdAVerif->setItem(numLigne,0,new QTableWidgetItem (annId));
    ui->tableWidgetProdAVerif->setItem(numLigne,1,new QTableWidgetItem (nomProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,2,new QTableWidgetItem (varieteProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,3,new QTableWidgetItem (quantiteProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,4,new QTableWidgetItem (categorieProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,5,new QTableWidgetItem (uniteMesureProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,6,new QTableWidgetItem (prixTTCProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,7,new QTableWidgetItem (prixHTProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,8,new QTableWidgetItem (prixKGProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,9,new QTableWidgetItem (cheminPhotoProd));
    ui->tableWidgetProdAVerif->setItem(numLigne,10,new QTableWidgetItem (dlcProd));

    numLigne++;


    }
}


void MainWindow::on_tableWidgetProdAVerif_cellClicked(int row, int column)
{
    ui->lineEditProduit->setText(ui->tableWidgetProdAVerif->item(row,1)->text());
    ui->lineEditDesc->setText(ui->tableWidgetProdAVerif->item(row,2)->text());
    ui->lineEditCategorie->setText(ui->tableWidgetProdAVerif->item(row,3)->text());
    ui->lineEditQuantiteProd->setText(ui->tableWidgetProdAVerif->item(row,4)->text());
    ui->lineEditUniteMesure->setText(ui->tableWidgetProdAVerif->item(row,5)->text());
    ui->lineEditPrixTTC->setText(ui->tableWidgetProdAVerif->item(row,6)->text());
    ui->lineEditPrixHT->setText(ui->tableWidgetProdAVerif->item(row,7)->text());
    ui->lineEditPrixKg->setText(ui->tableWidgetProdAVerif->item(row,8)->text());
    ui->labelCheminPhotoProd->setText(ui->tableWidgetProdAVerif->item(row,9)->text());

    QString cheminPhoto = ui->labelCheminPhotoProd->text();
    if(!cheminPhoto.isEmpty())
    {
    QPixmap imageAAfficher (ui->labelCheminPhotoProd->text());
        if (!imageAAfficher.isNull())
        {
            ui->labelPhotoProd->setPixmap(imageAAfficher);
        }
    }
}



void MainWindow::on_pushButtonValiderProd_clicked()
{
    infoPourMail("validation");
    //Changement de variables sur le champs annValide de 0 à 1;


}
void MainWindow::on_pushButtonModifProd_clicked()
{
    infoPourMail("modification");
}
