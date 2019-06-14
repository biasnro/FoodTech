#include "FoodTech.h"
#include "ui_mainwindow.h"
#include "dados.h"
#include "experiencia.h"
#include <QLocale>
#include <QDebug>
#include <QInputDialog>
#include <QVector>
#include <QFileDialog>


void MainWindow::atualizarTabela()
{
    ui->tabela->clearContents();
    for(int i=0; i< xp.size();i++){
           inserirExperienciaNaTabela(xp[i],i);
    }
}

void MainWindow::inserirExperienciaNaTabela(Dados a, int linha)
{
    qDebug() << a.getTipo() << " " << a.getRestaurante() << " " << a.getPrato() << " " << a.obterNota() << "\n";

    ui->tabela->setItem(linha, 0, new QTableWidgetItem(a.getTipo()));
    ui->tabela->setItem(linha, 1, new QTableWidgetItem(a.getRestaurante()));
    ui->tabela->setItem(linha, 2, new QTableWidgetItem(a.getPrato()));
    ui->tabela->setItem(linha, 3, new QTableWidgetItem(QString::number(a.obterNota())));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_cadastrar_clicked()
{
Dados dado;

if(ui->restaurante->text().size() != 0 and ui->prato->text().size() != 0 and ui->tipo->currentText() != "Escolher..." )
    {
    dado.setRestaurante(ui->restaurante->text());
    dado.setPrato(ui->prato->text());
    dado.setTipo(ui->tipo->currentText());
    dado.setComida(ui->comida->text().toInt());
    dado.setAmbiente(ui->ambiente->text().toInt());
    dado.setAtendimento(ui->atendimento->text().toInt());
    dado.setPreco(ui->preco->text().toInt());

    xp.obterExperiencia(dado);
    int qtde = ui->tabela->rowCount();
    ui->tabela->insertRow(qtde);
    atualizarTabela();
    }

ui->restaurante->clear();
ui->prato->clear();
ui->tipo->setCurrentIndex(0);
ui->comida->clear();
ui->ambiente->clear();
ui->atendimento->clear();
ui->preco->clear();


}





void MainWindow::on_ordenar_restaurante_clicked()
{
    xp.ordenarPorRestaurante();
    atualizarTabela();
}

void MainWindow::on_ordenar_tipo_clicked()
{
    xp.ordenarPorTipo();
    atualizarTabela();
}

void MainWindow::on_ordenar_nota_clicked()
{
    xp.ordenarPorNota();
    atualizarTabela();
}

void MainWindow::on_limpar_clicked()
{
xp.limparExperiencias();
int qntLinhas = ui->tabela->rowCount();
for(int i = 0; i < qntLinhas; i++){
 ui->tabela->removeRow(0);
}
}

void MainWindow::on_atualizar_estatisticas_clicked()
{
    if(xp.size()>0){
    ui->melhor_restaurante->setText(xp.melhorExperiencia().getRestaurante());
    ui->melhor_prato->setText(xp.melhorExperiencia().getPrato());

    ui->pior_restaurante->setText(xp.piorExperiencia().getRestaurante());
    ui->pior_prato->setText(xp.piorExperiencia().getPrato());
    }else{
        ui->melhor_restaurante->setText(" ");
        ui->melhor_prato->setText(" ");

        ui->pior_restaurante->setText(" ");
        ui->pior_prato->setText(" ");
    }
}

void MainWindow::on_salvar_triggered()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Experiências","","(*.txt);;(*.csv)");

    xp.salvarExperiencias(nomeArquivo);
}

void MainWindow::on_abrir_triggered()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Experiências","","CSV(*.csv)");
        xp.abrirExperiencias(nomeArquivo);
        for(int i=0;i<xp.size();i++){
            ui->tabela->insertRow(i);
            inserirExperienciaNaTabela(xp[i],i);
        }
}

void MainWindow::on_tabela_cellDoubleClicked(int row, int column)
{
    if(column == 0){
            QString tipo = QInputDialog::getText(this,"Editar Tipo","Insira um novo tipo de culinária:",QLineEdit::Normal);
            if(tipo.size() != 0){
                QString nome2 = tipo.toLower();
                nome2[0] = nome2[0].toUpper();
                xp.editarTipo(row,nome2);
                inserirExperienciaNaTabela(xp[row],row);
                QMessageBox::information(this,"Editar Tipo","O tipo de culinária foi alterado com sucesso!");
            }
        }
        else if(column == 1){
            QString restaurante = QInputDialog::getText(this,"Editar Restaurante","Insira o nome do novo restaurante: ",QLineEdit::Normal);
            if(restaurante.size() != 0){
                QString nome2 = restaurante.toLower();
                nome2[0] = nome2[0].toUpper();
                xp.editarRestaurante(row,restaurante);
                inserirExperienciaNaTabela(xp[row],row);
                QMessageBox::information(this,"Editar Restaurante","O nome do Restaurante foi alterado com sucesso!");
            }
        }
        else if(column == 2){
            QString prato = QInputDialog::getText(this,"Editar Prato","Insira o nome do novo prato: ",QLineEdit::Normal);
            if(prato.size() != 0){
                QString nome2 = prato.toLower();
                nome2[0] = nome2[0].toUpper();
                xp.editarPrato(row,prato);
                inserirExperienciaNaTabela(xp[row],row);
                QMessageBox::information(this,"Editar Prato","O nome do prato foi alterado com sucesso!");
            }
        }
}
