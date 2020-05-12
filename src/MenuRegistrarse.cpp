#include "MenuRegistrarse.h"
#include "MenuMain.h"
#include <string.h>

void MenuRegistrarse::menuRegistrarse (Usuario *usuarios, int size)
{
	Usuario *usuariosActualizados;
    echo();
    move((getMAX_Y()/2)-3.5, getMAX_X()/4+1);
    attron(A_REVERSE);
    printw("    REGISTRATE    ");
    attroff(A_REVERSE);
    
    WINDOW* registro = newwin(5,getMAX_X()/2,(getMAX_Y()/2)-2.5, getMAX_X()/4);
    refresh();
    box(registro,0,0);
    

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_GREEN);

    wmove(registro, 1,1);
    wattron(registro, COLOR_PAIR(1));
    wprintw(registro, "NICKNAME:");

    wmove(registro, 2,1);
    wprintw(registro, "PASSWORD:");

    wmove(registro, 3,1);
    wprintw(registro, "CONFIRM PASSWORD:");

    wattroff(registro, COLOR_PAIR(1));
    wrefresh(registro);


    char aux[getMAX()];
    curs_set(1);
    wmove(registro, 1, 11);

    wgetnstr(registro, aux, getMAX());

    char *userIntroduced = new char [strlen(aux)+1];
    //char *userIntroduced = (char *) malloc((strlen(aux)+1) * sizeof(char));
    sscanf(aux, "%s", userIntroduced);

    int bl = 0;
    for (int i=0; i<size; i++)
    {
        if ((strcmp(usuarios[i].getNickname(), userIntroduced) == 0))
        {
            bl = 1;
            break;
        }
    }

    while (bl == 1)
    {
        move((getMAX_Y()/2)+3.5, getMAX_X()/4);
        wprintw(stdscr, "THAT NICKNAME ALREADY EXISTS! TRY AGAIN");
        refresh();
        wmove(registro, 1, 11);
        wprintw(registro, "             ");
        wmove(registro, 1, 11);

        wgetnstr(registro, aux, getMAX());
        userIntroduced = new char [strlen(aux)+1];
        //userIntroduced = (char *) malloc((strlen(aux)+1) * sizeof(char));
        sscanf(aux, "%s", userIntroduced);

        bl = 0;
        for (int i=0; i<size; i++)
        {
            if ((strcmp(usuarios[i].getNickname(), userIntroduced) == 0))
            {
                bl = 1;
                break;
            }
        }
    }

    move((getMAX_Y()/2)+3.5, getMAX_X()/4);
    wprintw(stdscr, "                                         ");
    refresh();


    wmove(registro, 2, 11);
    wgetnstr(registro, aux, getMAX());
    char *passIntroduced = new char [strlen(aux)+1];
    //char *passIntroduced = (char *) malloc((strlen(aux)+1) * sizeof(char));
    sscanf(aux, "%s", passIntroduced);

    wmove(registro, 3, 19);
    wgetnstr(registro, aux, getMAX());
    char *passConfiIntroduced = new char [strlen(aux)+1];
    //char *passConfiIntroduced = (char *) malloc((strlen(aux)+1) * sizeof(char));
    sscanf(aux, "%s", passConfiIntroduced);

    if (strcmp(passIntroduced, passConfiIntroduced) != 0)
    {
        move((getMAX_Y()/2)+3.5, getMAX_X()/4);
        wprintw(stdscr, "PASSWORDS ARE DIFFERENT! TRY AGAIN");
        menuRegistrarse(usuarios, size);
    }

    else
    {
        move((getMAX_Y()/2)+3.5, getMAX_X()/4);
        wprintw(stdscr, "REGISTRADO!");
        refresh();
        usuariosActualizados = new Usuario [size+1];
        //usuariosActualizados = (Usuario *) malloc ((size+1) * sizeof(Usuario));
        for (int i=0; i<size; i++)
        {
            usuariosActualizados[i] = usuarios[i];
        }

        /*usuariosActualizados[size].getNickname = new char [strlen(userIntroduced)+1];
        //usuariosActualizados[size].nickname = (char *) malloc((strlen(userIntroduced)+1) * sizeof(char));
        sscanf(userIntroduced, "%s", usuariosActualizados[size].getNickname());

        usuariosActualizados[size].getContrasenya() = new char [strlen(passIntroduced)+1];

        //usuariosActualizados[size].contrasenya = (char *) malloc((strlen(passIntroduced)+1) * sizeof(char));
        sscanf(passIntroduced, "%s", usuariosActualizados[size].getContrasenya());

        usuariosActualizados[size].getPuntuaciones = new float[2];
        //usuariosActualizados[size].puntuaciones = malloc(2 * sizeof(float));*/  //ESTA MAL, CORREGIR
        
        size++;


        Usuario user;
        user.escribirUsuarios(usuariosActualizados, size);
        sleep(1000);

        liberarMemoriaMenuRegistrarse(registro, usuariosActualizados, size, userIntroduced, passIntroduced, passConfiIntroduced);
        MenuMain menMain;
    }
}
void MenuRegistrarse::desplegarMenu()
{

}
void MenuRegistrarse::liberarMemoriaMenuRegistrarse(WINDOW* registro, Usuario* usuariosActualizados, int size, char* userIntroduced, char* passIntroduced, char* passConfiIntroduced)
{

}
