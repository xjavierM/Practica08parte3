/*
 * Curso Programación
 * Autor: Mauricio Vega
 * Fecha: 02-01-2021
 * Practica 08 parte 3
 */
#include <QCoreApplication>
#include <iostream>
#include <QDir>
#include <QDebug>
void Path();
void leer();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int opc = 0;
    do{
        qDebug() << "**MENU**\n";
        qDebug() << "1. Path\n";
        qDebug() << "2. Informacion\n";
        qDebug() << "3. Salir\n";
        qDebug() << "\nIngrese su opción: ";
        std::cin >> opc;
        switch (opc) {
        case 1:
            qDebug() << "** Path **\n";
            Path();
            break;
        case 2:
            qDebug() << "Informacion\n";
            leer();
        case 3:
            qDebug() << "Salir";
            break;
        default:
            qDebug() << "No valido";
            break;
        }
    }while(opc != 3);
    return a.exec();
}
void Path(){
    QList<QDir> directorios;
    directorios.append(QDir::current());
    directorios.append(QDir::home());
    directorios.append(QDir::root());
    directorios.append(QDir::temp());
    qDebug() << "\nListar directorios:";
    foreach (QDir d, directorios) {
        qDebug() << d.absolutePath();
    }
}
void leer(){
    QDir directorio("C:/");
    qDebug() << "\nObteniendo información de" << directorio.absolutePath() << ":";
    QFileInfoList contenido = directorio.entryInfoList();
    foreach (const QFileInfo &info, contenido) {
        qDebug() << "Nombre:" << info.fileName();
        qDebug() << "directorio:" << info.isDir();
        qDebug() << "Se puede escribir:" << info.isWritable();
        qDebug() << "-------------------";
    }
}
