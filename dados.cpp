#include "dados.h"




QString Dados::getRestaurante() const
{
    return restaurante;
}

void Dados::setRestaurante(const QString &value)
{
    QMessageBox msgBox;

    if(value.size() > 2){
       restaurante = value;
    }else{
        msgBox.setText("Restaurante Inválido");
        msgBox.exec();
    }
}

QString Dados::getPrato() const
{
    return prato;
}

void Dados::setPrato(const QString &value)
{
    QMessageBox msgBox;

    if(value.size() > 2){
       prato = value;
    }else{
        msgBox.setText("Prato Inválido");
        msgBox.exec();
    }}

QString Dados::getTipo() const
{
    return tipo;
}

void Dados::setTipo(const QString &value)
{
    tipo = value;
}

int Dados::getComida() const
{
    return comida;
}

void Dados::setComida(int value)
{
    QMessageBox msgBox;

    if((value >= 0) and (value <= 100)){
       comida = value;
    }else{
        msgBox.setText("Valor Inválido");
        msgBox.exec();
    }
}
int Dados::getAmbiente() const
{
    return ambiente;
}

void Dados::setAmbiente(int value)
{
    ambiente = value;
}

int Dados::getAtendimento() const
{
    return atendimento;
}

void Dados::setAtendimento(int value)
{
    atendimento = value;
}

int Dados::getPreco() const
{
    return preco;
}

void Dados::setPreco(int value)
{
    preco = value;
}


double Dados::getNota() const
{
    return nota;
}

void Dados::setNota(double value)
{
    nota = value;
}

Dados::Dados()
{

}

double Dados::obterNota()
{
    return (4*comida + 2*ambiente + 2*atendimento + 2*preco)/10;
}
