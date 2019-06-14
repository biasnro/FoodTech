#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLocale>

#include "dados.h"
#include "experiencia.h"

//Classe da janela de visualização.

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
        void atualizarTabela();                                 //Função que atualiza a tabela.
        void inserirExperienciaNaTabela(Dados a, int linha);    //Função que insere a Experiência Gastronômica na tabela.
        Experiencia xp;                                         //Objeto Experiência criado para auxiliar no desenvolvimento das ações.

public:
    Dados dado;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_cadastrar_clicked();                                //Função realizada quando o usário clica no botão "cadastrar".

    void on_ordenar_restaurante_clicked();                      //Funções que são realizadas quando o usuário clica nos botões de ordenar.

    void on_ordenar_tipo_clicked();

    void on_ordenar_nota_clicked();



    void on_limpar_clicked();                                   //Função realizada quando o usuário clica no botão "limpar tabela"

    void on_atualizar_estatisticas_clicked();                   //Função realizada o usuário atualiza as estatísticas.


    void on_salvar_triggered();                                 //Funções para salvar ou abrir um arquivo.

    void on_abrir_triggered();


    void on_tabela_cellDoubleClicked(int row, int column);      //Função para editar itens da tabela.

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
