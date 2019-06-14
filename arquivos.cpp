#include "arquivos.h"

arquivos::arquivos()
{

}

bool arquivos::salvarExperiencias(QString arquivo)
{
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
           return false;

    for(i=0; i< experienc){
        linha = a.getNome() + ',' + QString::number(a.getMedia()) + '\n';
        file.write(linha.toLocal8Bit());
       }
       return true;

}
