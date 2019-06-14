#include "experiencia.h"


Experiencia::Experiencia()
{

}

int Experiencia::size(){
    return experiencias.size();
}


Dados Experiencia::operator[](int i){
    return experiencias[i];
}


void Experiencia::obterExperiencia(Dados a){
    experiencias.push_back(a);
}


void Experiencia::ordenarPorRestaurante(){
std :: sort(experiencias.begin(), experiencias.end(), compararPorRestaurante);
}


void Experiencia::ordenarPorTipo(){
std :: sort(experiencias.begin(), experiencias.end(), compararPorTipo);
}


void Experiencia::ordenarPorNota(){
    std:: sort(experiencias.begin(), experiencias.end(), compararPorNota);
}



void Experiencia::limparExperiencias(){
    experiencias.erase(experiencias.begin(),experiencias.end());
}



Dados Experiencia::melhorExperiencia(){
    std :: sort(experiencias.begin(), experiencias.end(), compararPorNota);
    return experiencias[0];
}


Dados Experiencia::piorExperiencia(){
    std :: sort(experiencias.begin(), experiencias.end(), compararPorNota);

    return experiencias[experiencias.size()-1];
}

bool Experiencia::salvarExperiencias(QString arquivo)
{
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
       return false;

    for(Dados a : experiencias){
        linha = a.getTipo() + ' , ' + a.getRestaurante() + ' , ' + a.getPrato() + ' , ' +  QString::number(a.obterNota()) + '\n';
        file.write(linha.toLocal8Bit());
        }
        return true;


}

bool Experiencia::abrirExperiencias(QString arquivo)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
           return false;

    QString linha;
    Dados a;
    while(!file.atEnd()){
          linha = file.readLine();
          QStringList dados = linha.split(",");
          a.setTipo(dados[0]);
          a.setRestaurante(dados[1]);
          a.setPrato(dados[2]);
          a.setNota(dados[3].toDouble());
          obterExperiencia(a);
       }
       return true;

}

void Experiencia::editarRestaurante(int i, QString value)
{
    experiencias[i].setRestaurante(value);
}

void Experiencia::editarTipo(int i, QString value)
{
    experiencias[i].setTipo(value);
}

void Experiencia::editarPrato(int i, QString value)
{
    experiencias[i].setPrato(value);
}

void Experiencia::editarNota(int i, int value)
{
    experiencias[i].setNota(value);
}


bool compararPorRestaurante(Dados a, Dados b)
{
    return a.getRestaurante()<b.getRestaurante();
}

bool compararPorTipo(Dados a, Dados b)
{
    return a.getTipo()<b.getTipo();
}

bool compararPorNota(Dados a, Dados b)
{
    return a.obterNota()>b.obterNota();
}


