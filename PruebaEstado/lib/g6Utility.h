/**
 * Copyright �2023. All Rights Reserved, pat_mic
 * libreria de utilitarios para fines acad�micos de programaci�n I - EPN
 **/

#include <iostream>
#include <stdlib.h>
#include <string>
#include "../lib/PruebaSenTemp.h"

using namespace std;

/**
 * Obtener un numero positivo
 * @label, establece una etiqueta
*/
int getNumeroPositivo(string label) //
{
    int numero,a;
    string str ="01";  //999 abc
    do
    {
        cout << "\n" << label;
        getline(cin, str);
        //numero = stoi(str);
        
        try {
            numero = stoi(str);
            a=1;
        } catch (const std::invalid_argument& e) {
            a=0;
        }
    } while ((numero <= 0 || numero >=50) || a==0);
    return numero;  
}

int menuGeneral( )
{
    int opc;
    cout << "\t\tPRUEBA ELEMENTOS SISTEMA DE RIEGO" <<endl;
    cout << endl;
    cout << "\tMenu" <<endl;
    cout << "\t1. Prueba Sistema" <<endl;
    //cout << "\t2. Prueba Rele" <<endl;
    //cout << "\t3. Prueba Boton" <<endl;
    cout << "\t2. Salir" <<endl;

    do
    {
        opc = getNumeroPositivo("\t>>Ingrese opcion: ");
    } while (opc>2);

    switch (opc)
    {
        case 1: //system("clear");
                cout << "\n\tIngreso a Prueba de Estado del Sistema de Riego" <<endl;
                cout << endl;
                cout << "\t";
                ImprimirEstado();
                //menuGeneral();           
                break;
        // case 2: cout << "\n\tIngreso a Prueba Rele" <<endl;
        //         menuGeneral();           
        //         break;
        // case 3: cout << "\n\tIngreso a Prueba Boton" <<endl;
        //         menuGeneral();                  
        //         break;
        case 2: cout << "\n\tChao Usuario!" <<endl;               
                break;
        default:    cout<< "\n\tError No deberia ni entrar aca"; 
                    break;
    }

    return opc;
}
