#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <iostream>
#include <QString>
#include <QVector>
#include <QObject>
#include <QFile>

#include "dados.h"
#include <algorithm>

//Classe criada para armazenar todas as Experiências Gastronômicas e para desenvolver as funções que envolvem o projeto.

class Experiencia
{
private:
    QVector <Dados> experiencias; // Vector de variáveis do tipo Dados que armazena todas as experiências vividas, (cada índice é uma experiência).

public:
    Experiencia();
    int size();                     // Função para acessar o tamanho do vector experiencias.
    Dados operator[](int i);        // Sobrecarga de operadores para acessar o índice do vector experiencias.
    void obterExperiencia(Dados a); // Função para adicionar uma nova Experiência (novo indice no vector experiencias).

    void ordenarPorRestaurante();   //Funções que ordenam o vector.
    void ordenarPorTipo();
    void ordenarPorNota();

    void limparExperiencias();      //Função que deleta todos os indices do vector experiencias.

    Dados melhorExperiencia();      //Função que acessa a melhor Experiência Gastronômica (maior nota).
    Dados piorExperiencia();        //Função que acessa a pior Experiência Gastronômica (menor nota).

    bool salvarExperiencias(QString arquivo); //Função que salva a tabela em um arquivo .CSV.
    bool abrirExperiencias(QString arquivo);  //Função que abre na tabela um arquivo .CSV.

    void editarRestaurante(int i,QString value); //Funções que editam a tabela.
    void editarTipo(int i,QString value);
    void editarPrato(int i,QString value);
    void editarNota(int i, int value);           //(OBS.: altera somente o valor final da nota).

};

bool compararPorRestaurante(Dados a, Dados b); //Funções usadas para comparar os indices do vector experiencias.
bool compararPorTipo(Dados a, Dados b);
bool compararPorNota(Dados a, Dados b);




#endif // EXPERIENCIA_H
