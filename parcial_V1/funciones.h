#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <map>
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
void inventario(map<char, map<char, int>> &, string n);
//void agregar_inventario(map<char, map<char, int>> &);
void leer_inventario(string n);
void agregar_inventario(map<char, map<char, int>> &, string n);

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
  cout<<"2. Modificar Inventario"<<endl;
  cout<<"3. Registro De Usuarios"<<endl;
  cout<<"4. salir "<<endl;
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

  //system("cls");
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
void inventario(map<char, map<char, int>> &mapa, string n){

  char c1,c2;
  int unid;
  ifstream archivo;
  archivo.open(n, ios::in);
  if(archivo.fail()){
    cout<<"El archivo no se pudo abrir......."<<endl;
    exit(1);
  }
  archivo>>c1;
  while(!archivo.eof()){
    archivo>>c2;
    archivo>>unid;
    mapa[c1][c2]=unid;
    archivo>>c1;
  }
  archivo.close();
}

/*void agregar_inventario(map<char, map<char, int>> &mapa){

  map<char, map<char, int>>::iterator i;
  map<char, int>::iterator j;

  for(i=mapa.begin();i!= mapa.end();i++){
    for(j=i->second.begin();j!=i->second.end();j++){
        cout<<i->first<<" "<<j->first<<" "<<j->second<<endl;
      }
    }
  system("pause");
}*/
void leer_inventario(string n){
  system("cls");
  cout<<"----------Inventario de productos del cinemas----------"<<endl<<endl;
  ifstream archivo;
  string texto;
  archivo.open(n, ios::in);
  if(archivo.fail()){
    cout<<"El archivo no se pudo abrir........"<<endl;
    exit(1);
  }
  while(!archivo.eof()){
    getline(archivo,texto);
    cout<<texto<<endl;
  }
  archivo.close();
  system("pause");
}
void agregar_inventario(map<char, map<char, int>> &mapa, string n,string m){
  system("cls");
  char ID,descripcion[1000],cantidad;
  int valor;
  ofstream archivo,archivo_2;
  archivo.open(n, ios::out | ios::app);
  cout<<"Ingrese informacion del producto"<<endl;
  cout<<"ID: ",cin>>ID;
  cout<<"descripcion del producto: ",cin>>descripcion;
  cout<<"Cantidad: ",cin>>cantidad;
  cout<<"Valor total: ",cin>>valor;
  archivo<<ID<<" "<<descripcion<<" "<<cantidad<<" "<<valor<<"\n";
  archivo_2.open(m, ios::out | ios::app);
  archivo_2<<ID<<" "<<cantidad<<" $"<<valor<<"\n";

  archivo.close();
  archivo_2.close();
  mapa[ID][cantidad]=valor;
}




#endif // FUNCIONES_H
