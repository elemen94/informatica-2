#include "funciones.h"


int main()
{
  int in,ad,us;
  bool a;
  ofstream esc;
  ifstream lee;
  system("cls");
  in = menu();
  switch (in) {
    case 1:
      system("cls");
      a = admin();
      volver:
      if(a == true){ system("cls"); ad = menu_admin(); }
      else{ cout<<"Try again........ :("<<endl;
        system("pause");}
      do{
        switch(ad){
       case 1:
          cout<<"hola"<<endl;
          goto volver;
        case 2:
          leer_user(lee);
          goto volver;
          //break;
      }while(ad<3 and ad>0);
        main();
        ad=0;
      break;
    case 2:
      system("cls");
      menu_user();
      do{
        us = menu_user();
      }while(us<3 and us>0);
        main();
        us=0;
      break;
  }
while(in<3 and in>0);
  system("cls");
  if(in == 3) cout<<"Gracias te esperamos pronto...... ;)"<<endl;
  else cout<<"Valor erroneo......"<<endl;
  return 0;
}
}
