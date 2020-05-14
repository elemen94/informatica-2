#include "funciones.h"


int main(){
  int in=0,ad=0,us=0;
  bool a,x;
  map<char, map<int, map<string, map<int,int>>>> mapa;
  principio:
  system("cls");
  in = menu();
  switch (in){
    case 1:
      a = admin();
      volver:
      if(a == true){ system("cls"); ad = menu_admin(); }
      else{ cout<<"Try again........ :("<<endl;system("pause");}
      do{
        switch(ad){
          case 1:
            leer_mapa(mapa);
            goto volver;
          case 2:
             inventario(mapa);
            //agregar_inventario(mapa,"inventario.txt","inventario_2.txt");
            goto volver;
          case 3:
            leer_user("user.txt");
            goto volver;
          case 4:
            //agregar_user("user.txt");
            goto volver;
          //case 5:
        }
      }while(ad<6 and ad>0);
        goto principio;
  }
  return 0;

 }



