#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlQuery>
#include <QPixmap>
#include <QTableWidget>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    //Methodes permettant de récuperer les infos pour envoie de mail
    void infoPourMail(QString pourquoi);

    void afficherAnnonceVente();
    void on_tableWidgetProdAVerif_cellClicked(int row, int column);
    void on_pushButtonValiderProd_clicked();
    void on_pushButtonModifProd_clicked();
};

#endif // MAINWINDOW_H
