#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include <QTextEdit>
#include <QListView>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushQuitter_clicked();

    void on_pushEnregistrer_clicked();

    void on_pushVoir_clicked();

    void on_Liste_itemSelectionChanged();

    void on_pushSupprimer_clicked();

    void on_pushNouveau_clicked();

    void on_pushNouveau_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    bool check =false;
    QString Clc;
    QString dossier;
     QString filename;
    const QString FilesRootPath = "C:/home/hadjara-celina/Bureau/ProjetPOO/Editeur/EditeurAvancé/Files";
    QString LIRE(QLineEdit *);
    QString LIRE(QTextEdit *);
    void ECRIRE(QTextEdit *zt,double valeur);
    void ECRIRE(QTextEdit *zt,QString chaine);
    void ECRIRE(QLineEdit *zt,double valeur);
    void ECRIRE(QLineEdit *zt,QString chaine);
    void EFFACER(QLineEdit *p);
    void NOUVEAU(QTextEdit *t);
};
#endif // MAINWINDOW_H
