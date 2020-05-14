#include "funciones.h"


int main(){
  int in=0,ad=0,us=0;
  bool a,u;
  map<string, map<string, map<string, map<string,string>>>> mapa;
  map<char, map<string,int>> combo;
  map<char, list<char>> comparacion;

  principio:
  system("cls");
  in = menu();
  switch (in){
    case 1:
      a = admin();
      volver:
      if(a == true){ system("cls"); ad = menu_admin(); }
      else{ cout<<"Try again........ :("<<endl;system("pause"); goto principio;}
      do{
        switch(ad){
          case 1:
            leer_inventario("inventario.txt", mapa);
            leer_mapa(mapa);
            goto volver;
          case 2:
             agregar_inventario(mapa, "inventario.txt");
            goto volver;
          case 3:
            crear_combo(combo, comparacion, "combos.txt");
            goto volver;
          case 4:
            ver_combos(combo, "combos.txt");
            goto volver;
          case 5:
            agregar_user("user.txt");
            goto volver;
          case 6:
            leer_user("user.txt");
            goto volver;
          case 7:
            goto volver;
        }
      }while(ad<8 and ad>0);
        goto principio;
    case 2:
      u=user();
      //volver_user:
      if(u == true){ system("cls"); ver_combos(combo, "combos.txt"); us = menu_user(); }
      else{ cout<<"Try again........ :("<<endl;system("pause");}
      do{
        switch(us){
          case 1: break;
        case 2: break;

        }
      }while(us<3 and us>0);
      goto principio;




  }
  return 0;

 }



