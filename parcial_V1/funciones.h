#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <sstream>

using namespace std;

int menu();
int menu_admin();
int manu_user();
void leer_user(ifstream &archivo);
bool admin();


int menu(){
  int x;
  cout<<"<<----------Bienvenido---------->>"<<endl<<endl;
  cout<<"1. Ingresar como Administrador"<<endl;
  cout<<"2. Ingresar como Usuario"<<endl;
  cout<<"3. salir"<<endl;
  cin>>x;
  return x;
}

int menu_admin(){
  int x;
  cout<<"<<----------Bienvenido Administrador---------->>"<<endl<<endl;
  cout<<"1. Inventario"<<endl;
  cout<<"2. Registro De Usuarios"<<endl;
  cout<<"3. salir "<<endl;
  cin>>x;
  return x;
}

int menu_user(){
  int x;
  cout<<"<<----------Bienvenido Usuario---------->>"<<endl<<endl;
  cout<<"1. Saldo"<<endl;
  cout<<"2. Compra de productos"<<endl;
  cout<<"3. salir "<<endl;
  cin>>x;
  return x;
}

void leer_user(ifstream &archivo){

  system("cls");
  int x;
  string txt,cc,contra,saldo,line1,line2;
  archivo.open("user.txt", ios::in);

  if(archivo.fail()){
      cout<<"El archivo no se pudo abrir "<<endl;
      exit(1);
      }
  archivo>>line1;
  archivo>>line2;
  x = line1.size() + line2.size()+2;
  archivo.seekg(x);
  archivo>>cc;

  while(!archivo.eof()){
    archivo>>contra;
    archivo>>saldo;
    cout<<"Cedula usuario: "<<cc<<endl;
    cout<<"Contrase"<<char(164)<<"a: "<<contra<<endl;
    cout<<"saldo: "<<saldo<<endl;
    archivo>>cc;
    cout<<endl;
  }
  archivo.close();system("pause");
}
bool admin(){

  system("cls");
  fstream en;
  string cc, contra, cc_2, contra_2;

  cout<<"Enter you ID: ", cin>>cc_2;
  cout<<"Enter you password: ", cin>>contra_2;

  en.open("user.txt", ios::in);
  if(en.fail()){
    cout<<"Error el archivo no se pudo abrir "<<endl;
  }
  en>>cc;
  en>>contra;
  if(cc == cc_2 and contra == contra_2) return true;
  else return false;
}



#endif // FUNCIONES_H
