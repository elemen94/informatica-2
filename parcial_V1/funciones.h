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
#include <string.h>
#include <list>

using namespace std;
//map<char, map<int, map<string, map<int,int>>>> mapa;

int menu();
int menu_admin();
int manu_user();
bool admin();
void leer_user(string n);
void inventario(map<char, map<int, map<string, map<int,int>>>> &);
void leer_mapa(map<char, map<int, map<string, map<int,int>>>> &);
void crear_combo(map<char, map<string,int>> &, map<char, list<char>> &);
void ver_combos(map<char, map<string,int>> &);
void agregar_user(string n);

int menu(){
  int x;
  cout<<"<<----------Bienvenido---------->>"<<endl<<endl;
  cout<<"1. Ingresar como Administrador"<<endl;
  cout<<"2. Ingresar como Usuario"<<endl;
  cout<<"3. Salir"<<endl;
  cout<<"Ingrese una opcion: ",cin>>x;
  return x;
}

int menu_admin(){
  int x;
  cout<<"<<----------Bienvenido Administrador---------->>"<<endl<<endl;
  cout<<"1. Inventario"<<endl;
  cout<<"2. Ingresar productos al Inventario"<<endl;
  cout<<"3. Crear Combos"<<endl;
  cout<<"4. Ver Combos registrados"<<endl;
  cout<<"5. Ingresar Usuario"<<endl;
  cout<<"6. Ver usuarios resigistrados"<<endl;
  cout<<"7. ........................."<<endl;
  cout<<"8. salir "<<endl;
  cout<<"Ingrese una opcion: ",cin>>x;
  return x;
}

int menu_user(){
  int x;
  cout<<"<<----------Bienvenido Usuario---------->>"<<endl<<endl;
  cout<<"1. Saldo"<<endl;
  cout<<"2. Compra de productos"<<endl;
  cout<<"3. salir "<<endl;
  cout<<"Ingrese una opcion: ",cin>>x;
  return x;
}

void leer_user(string n){

  system("cls");
  int x;
  ifstream archivo;
  string txt,cc,contra,saldo,line1,line2;
  archivo.open(n, ios::in);

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

  cout<<endl;
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
void inventario(map<char, map<int, map<string, map<int,int>>>> &mapa){
  system("cls");
  char id;
  string des;
  int precio,cantidad,unidades;
  cin.sync();
  cout<<"<<----------Inventario del Cinema----------->>"<<endl<<endl;
  cout<<"Ingrese informacion del producto"<<endl;
  cout<<"ID: ",cin>>id;cin.sync();
  cout<<"Cantidad: ",cin>>cantidad;cin.sync();
  cout<<"descripcion del producto: ";getline(cin,des);
  cout<<"unidades: ",cin>>unidades;cin.sync();
  cout<<"Valor total: ",cin>>precio;cin.sync();
  mapa[id][unidades][des][cantidad]=precio;
  cin.sync();
}

void leer_mapa(map<char, map<int, map<string, map<int,int>>>> &mapa){
  system("cls");
  cout<<"<<----------Inventario del Cinema----------->>"<<endl<<endl;
  map<char, map<int, map<string, map<int,int>>>>:: iterator a;
  map<int, map<string, map<int,int>>>::iterator b;
  map<string, map<int,int>>::iterator c;
  map<int,int>::iterator d;

  for(a=mapa.begin();a!= mapa.end();a++){
    for(b=a->second.begin();b!=a->second.end();b++){
      for(c=b->second.begin();c!=b->second.end();c++){
        for(d=c->second.begin();d!=c->second.end();d++){
        cout<<"ID: "<<a->first<<" |unidades: "<<b->first<<" |descripcion: "<<c->first<<" |cantidad: "<<d->first<<" |precio:"<<d->second<<endl;
        }
      }
    }
  }system("pause");
}

void crear_combo(map<char, map<string,int>> &combo, map<char, list<char>> &comparacion){
  system("cls");

  int costo,numin,cont=0;
  char id,ID,cant;
  string descripcion;
  cout<<"<<----------Planifica tu combo----------->>"<<endl<<endl;
  cout<<"Ingrese informacion del producto"<<endl;cin.sync();
  cout<<"nombre para el combo: ";getline(cin,descripcion);
  cout<<"Valor total: ",cin>>costo;
  cout<<"ID: ",cin>>id;
  combo[id][descripcion]=costo;cout<<endl;
  cout<<endl;system("cls");
  list<char> lista;
  cout<<"<<----------Ingredientes para el combo---------->>"<<endl;
  cout<<"Ingrese el numero de ingredientes: ",cin>>numin;cin.sync();
  while(cont<numin){
    cout<<"Ingrese el ID del producto: ",cin>>ID;cin.sync();
    cout<<"Ingrese cuanta del cantidad del produnto; ",cin>>cant;cin.sync();
    lista.push_back(ID);
    lista.push_back(cant);
    cont++;
  }
  comparacion[id]=lista;
}
void ver_combos(map<char, map<string,int>> &combo){
  system("cls");
  cout<<"<<----------Combos del Cinema----------->>"<<endl<<endl;
  map<char, map<string,int>>::iterator i;
  map<string, int>::iterator j;
  for(i=combo.begin();i!=combo.end();++i){
    for(j=i->second.begin();j!=i->second.end();++j){
      cout<<i->first<<" "<<j->first<<" ...... "<<j->second<<endl;
    }
  }
  system("pause");
}
void agregar_user(string n){

  system("cls");
  ofstream en;
  string Cc,contra,saldo;
  en.open(n, ios::out | ios::app);
  cout<<"Ingrese informacion del usuario"<<endl;
  cout<<"Cedula: ",cin>>Cc;
  cout<<"Contrase"<<char(164)<<"a: ",cin>>contra;
  cout<<"Saldo: ",cin>>saldo;
  en<<Cc<<" "<<contra<<" "<<saldo<<"\n";
  en.close();
}

#endif // FUNCIONES_H
