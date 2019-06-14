#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <QString>
#include <QObject>
#include <QMessageBox>

// Classe criada para armazenar cada Experiência Gastronômica, com base nos dados e nas avaliações.

class Dados{

private:

    QString restaurante; //Esses são meus atributos (dados).
    QString prato;
    QString tipo;

    int comida; // Esses são os meus atributos (critérios de avaliação para calcular a nota).
    int ambiente;
    int atendimento;
    int preco;

    double nota; // Esse atributo é usado em algumas funções (quando não posso usar a função obterNota).


public:

    Dados();

    double obterNota(); // Função obterNota (calcula a nota da experiência de acordo com os critérios de avaliação).


    QString getRestaurante() const;             //Getters e setters dos meus atributos
    void setRestaurante(const QString &value);

    QString getPrato() const;
    void setPrato(const QString &value);

    QString getTipo() const;
    void setTipo(const QString &value);



    int getComida() const;                      // Getters e setters dos meus atributos
    void setComida(int value);

    int getAmbiente() const;
    void setAmbiente(int value);

    int getAtendimento() const;
    void setAtendimento(int value);

    int getPreco() const;
    void setPreco(int value);


    double getNota() const;
    void setNota(double value);
};

#endif // DADOS_H
