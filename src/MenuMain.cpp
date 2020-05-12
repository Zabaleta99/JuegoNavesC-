#include "MenuMain.h"
#include "Usuario.h"
#include "Menu.h"

#include <stdio.h>
#include <curses.h>
#include <iostream>
using namespace std;

void MenuMain::desplegarMenu()
{

}

MenuMain::MenuMain()
{
	tamanyoTerminal();
	cout << getMAX_X();


	FILE *file = fopen("Usuarios.txt", "r");
    if (file == NULL)
    {
        cout <<"Error al abrir el fichero Usuarios.txt\n" << endl;
        exit(-1);
    }
    int* size = new int();
    //int* size = malloc(sizeof(int));
    
    Usuario user;
    Usuario* usuarios = user.leerUsuarios(file, size);

    int player;
    int opcion;
    while(1)
    {
        //opcion = menuInicio();
        switch(opcion)
        {   case 0:
                //player = (int) menuIniciarSesion(usuarios, *size);
                int selected;
                while(1)
                {
                    //selected = menuPlayer();
                    switch(selected)
                    {
                        case 0:
                           // jugarClasico(usuarios, player);
                            //escribirUsuarios(usuarios, *size);
                            break;
                        case 1:
                            //jugarSupervivencia(usuarios, player);
                            //escribirUsuarios(usuarios, *size);
                            break;
                        case 2:
                            //rankingClasico(usuarios, *size);
                            break;
                        case 3:
                            //rankingSupervivencia(usuarios, *size);
                            break;
                        default:
                            break;
                    }
                    if(selected == 4) break;
                }
                break;
            case 1:
                //menuRegistrarse(usuarios, *size);
                break;
            default:
                break;
        }
        if(opcion == 2) break; 
    }
    liberarMemoriaMenuMain (size, usuarios);
    exit(0);
	
}

void MenuMain::liberarMemoriaMenuMain (int *size, Usuario* arrayUsers)
{
    
}