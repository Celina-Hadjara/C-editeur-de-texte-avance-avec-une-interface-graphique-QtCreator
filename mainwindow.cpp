#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString fileName="";

    ui->liste->clear();
    ui->liste->addItem("fichier1.txt");
    ui->liste->addItem("fichier2.txt");
    ui->liste->addItem("fichier3.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushQuitter_clicked()
{
    this->close();
}

QString MainWindow::LIRE(QLineEdit *zt)
{
   return zt->text();
}
QString MainWindow::LIRE(QTextEdit *zt)
{
   return zt->toPlainText();
}

void MainWindow::on_pushEnregistrer_clicked()
{
    if(check){
        filename =Clc;
    }else{
        filename = QFileDialog::getSaveFileName(this,tr("Exporter dans un fichier texte"),FilesRootPath,tr("Fichiers Textes (*.txt)"));
    }
     QFile file(filename);
    if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        return;
    QTextStream out(&file);

    out << LIRE(ui->Titre) << endl;
    out << LIRE(ui->Text) << endl;
    out << LIRE(ui->Auteur) << endl;
    file.close();
}



void MainWindow::ECRIRE(QLineEdit *zt, double valeur)
{
    zt->setText(QString::number(valeur));
}

void MainWindow::ECRIRE(QLineEdit *zt, QString chaine)
{
    zt->setText(chaine);
}

void MainWindow::ECRIRE(QTextEdit *zt, double valeur)
{
    zt->setText(QString::number(valeur));
}

void MainWindow::ECRIRE(QTextEdit *zt, QString chaine)
{
    zt->setText(chaine);
}

void MainWindow::on_pushVoir_clicked()
{
    if(ui->liste->currentRow()==0){
        dossier = QCoreApplication::applicationDirPath() + "/Files/fichier1.txt";
    }
    if(ui->liste->currentRow()==1){
        dossier = QCoreApplication::applicationDirPath() + "/Files/fichier2.txt";
    }
    if(ui->liste->currentRow()==2){
        dossier = QCoreApplication::applicationDirPath() + "/Files/fichier3.txt";
    }
    filename = dossier;
    QFile fichier(filename);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&fichier);
    if(!fichier.exists())
        {
            printf( "Problème à la lecture du fichier");
        }
    ECRIRE(ui->Titre,in.readLine());
    ECRIRE(ui->Text,in.readLine());
    ECRIRE(ui->Auteur,in.readLine());
    fichier.close();
}

void MainWindow::on_pushSupprimer_clicked()
{
   QFile::remove(filename);
   EFFACER(ui->Titre);
   EFFACER(ui->Auteur);
   NOUVEAU(ui->Text);
}

void MainWindow::on_pushNouveau_clicked()
{
    check =true;
    EFFACER(ui->Titre);
    EFFACER(ui->Auteur);
    NOUVEAU(ui->Text);
    QString filename=QFileDialog::getSaveFileName(this,tr("Exporter dans un fichier texte"),FilesRootPath,tr("Fichiers Textes (*.txt)"));
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        return;
    QTextStream out(&file);

    out << LIRE(ui->Titre) << endl;
    out << LIRE(ui->Text) << endl;
    out << LIRE(ui->Auteur) << endl;
    Clc=filename;
    file.close();
}
void MainWindow::EFFACER(QLineEdit *p)
{
    p->clear();
}

void MainWindow::NOUVEAU(QTextEdit *t)
{
    t->clear();
}




