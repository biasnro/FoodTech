#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "dados.h"
#include "experiencia.h"

class arquivos
{
public:
    arquivos();

    Experiencia xp;

    bool salvarExperiencias(QString arquivo);

};

#endif // ARQUIVOS_H
