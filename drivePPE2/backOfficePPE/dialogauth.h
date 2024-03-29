#ifndef DIALOGAUTH_H
#define DIALOGAUTH_H

#include <QDialog>

namespace Ui {
class DialogAuth;
}

class DialogAuth : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAuth(QWidget *parent = 0);
    ~DialogAuth();

private slots:
    void on_pushButtonEnvoyer_clicked();

    void on_pushButtonAnnuler_clicked();

private:
    Ui::DialogAuth *ui;
};

#endif // DIALOGAUTH_H
