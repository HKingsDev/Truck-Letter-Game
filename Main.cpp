#include <allegro.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define  ANCHO 400                                      //DEFINE LA VARIABLE ANCHO CON UN VALOR FIJO DE 400
#define ALTO 600                                        //DEFINE LA BARIABLE ALTO CON UN VALOR FIJO DE 600
//DECLARACION DE VARIABLES DE LAS IMAGENES
BITMAP *buffer;         //PARA CARGAR LAS IMAGENES
//---------------------------------------------------------------------------//
BITMAP *Puntero;        //DECLARACION VARIABLE BITMAP DEL PUNTERO DEL RATON
BITMAP *Menu_Normal;    //      ""        ""      ""  DEL MENU PRINCIPAL
BITMAP *Menu_Jugar;     //                            DEL MENU PARA JUGAR
BITMAP *Menu_Tablero;   //                                MENU DEL SCORE
BITMAP *Menu_Ayuda;     //                                MENU AYUDA
BITMAP *Menu_Salir;     //                                MENU SALIDA
//---------------------------------------------------------------------------//
BITMAP *Tablero_Normal; //                            DEL TABLERO
BITMAP *Tablero_Salir;
//---------------------------------------------------------------------------//
BITMAP *Ayuda_Normal;
BITMAP *Ayuda_Salir;

BITMAP *Jugar_Normal;
BITMAP *Jugar_Salir;

BITMAP *Registrar_Normal;
BITMAP *Registrar_Cancelar;
BITMAP *Registrar_Aceptar;



//DELCARACION DE VARIABLES
bool salida = false;        //VARIABLE BOOLEANA PARA SALIR. SE MANTIENE EN FALSE.
bool salida1 = false;
bool salida2 = false; 		//VARIABLE QUE SOLO SERVIRA PARA ENTRAR Y SALIR DE JUGAR,AYUDA,TABLERO
bool salida3 = false;
bool salida4 = false;
bool confirmar = false;

void Menu();
//___________________________________________FUNCION DE INICIO__________________________________________________________//
void Inicio()                                               //FUNCION INICIO DECLARACION DE TODOS LOS COMPONENTES PARA QUE ARRANQUE
{
  allegro_init();                                           //INICIALIZACION DE ALLEGRO
  set_color_depth(32);                                      //IGNORAR EL COLOR MAGENTA
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 400, 600, 0, 0);    //PARA INICIALIZARLO COMO VENTANA CON UN ANCHO DE 400 Y ALTO DE 600 PX.
  set_window_title("Truck Letter");                         //PONE TITULO EN LA BARRA DE LA VENTANA
  install_keyboard();                                       //PERMITE EL USO DE TECLADO EN EL PROGRAMA
  install_mouse();                                          //PERMITE EL USO DE MOUSE EN EL PROGRAMA
  install_timer();                                          //PERMITE EL USO DE MEDIR DE TIEMPO
}
//______________________________________________________________________________________________________________

void Final()                                                //FUNCION PARA CUANDO SE TERMINA DE EJECUTAR
{
  clear_keybuf();                                           //LIMPIA EL BUFFER DEL TECLADO
  allegro_exit();                                           //SALE DE LA BIBLIOTECA ALLEGRO.
}

void Registro()
{
	while ( !salida4 )                                                     //SE INICIA CON UN WHILE PARA QUE REVISE PRIMERO LA VARIABLE
  {
    if ( mouse_x > 230 && mouse_x < 325 &&
    mouse_y > 273 && mouse_y < 296) //LASDIMENCIONES SE CAMBIARAN####
    {
      blit(Registrar_Aceptar, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        salida4 = true;
        confirmar= true;
      }
    }

    else if ( mouse_x > 53 && mouse_x < 148 &&
    mouse_y > 273 && mouse_y < 296) //LASDIMENCIONES SE CAMBIARAN####
    {
      blit(Registrar_Cancelar, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        salida4 = true;
      }
    }

    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Registrar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    printf("X: [%d] | Y: [%d] \n",mouse_x,mouse_y);
    // se muestra todo por pantalla
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);

  }
  if (salida4==true)
  {
      salida4 = false;
  }

}

//______________________________________________________________________________________________________________
void Jugar()
{
    salida1 = false;
  while ( !salida1 )                                                      //SE INICIA CON UN WHILE PARA QUE REVISE PRIMERO LA VARIABLE
  {
  	if ( mouse_x > 347 && mouse_x < 370 &&
    mouse_y > 552 && mouse_y < 575) //LASDIMENCIONES SE CAMBIARAN####
    {
      blit(Jugar_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        //salida1 = true;
        Registro();
        salida4=false;
        if(confirmar == true)
        {
            salida1 = true;
        }
      }
    }
    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    printf("X: [%d] | Y: [%d] \n",mouse_x,mouse_y);
    // se muestra todo por pantalla
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);

  }
	if (salida1==true)
  {
      Menu();
      salida1 = false;
  }
}

//______________________________________________________________________________________________________________
void Tablero()                                                            //FUNCION TABLRO
{
  while ( !salida2 )                                                     //SE INICIA CON UN WHILE PARA QUE REVISE PRIMERO LA VARIABLE
  {
    if ( mouse_x > 347 && mouse_x < 370 &&
    mouse_y > 552 && mouse_y < 575) //LASDIMENCIONES SE CAMBIARAN####
    {
      blit(Tablero_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        salida2 = true;
      }
    }
    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Tablero_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    printf("X: [%d] | Y: [%d] \n",mouse_x,mouse_y);
    // se muestra todo por pantalla
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);

  }
  if (salida2==true)
  {
      Menu();
      salida2 = false;
  }
}

//______________________________________________________________________________________________________________//
void Ayuda()
{
   while ( !salida3 )                                                      //SE INICIA CON UN WHILE PARA QUE REVISE PRIMERO LA VARIABLE
  {

if ( mouse_x > 347 && mouse_x < 370 &&
    mouse_y > 552 && mouse_y < 575) //LASDIMENCIONES SE CAMBIARAN####
    {
      blit(Ayuda_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        salida3 = true;
      }
    }


    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Ayuda_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    printf("X: [%d] | Y: [%d] \n",mouse_x,mouse_y);
    // se muestra todo por pantalla
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);
  }
  if(salida3 == true)
  {
      Menu();
      salida3 = false;
  }
}
//______________________________________________________________________________________________________________

void Menu()                                                                 //FUNCION DE MENU
{
//ASIGANACION DE IMAGENES A LAS VARIABLES
  buffer=create_bitmap(ANCHO,ALTO);                                         //CREA EL BUFFER CON EL TAMAÑO PREDEFINIDO EN EL INICIO
  Puntero = load_bitmap("Img/Puntero/Puntero.bmp",NULL);                    //CARGA LA IMAGEN DEL PUNTERO DEL RATON
  Menu_Normal=load_bitmap("Img/Menu/Menu_Normal.bmp",NULL);                 //CARGA LA IMAGEN DEL MENU NORMAL
  Menu_Jugar=load_bitmap("Img/Menu/Menu_Jugar.bmp",NULL);                   //CARGA LA IMAGEN DEL MENU JUGAR
  Menu_Tablero=load_bitmap("Img/Menu/Menu_Tablero.bmp",NULL);               //CARGA LA IMAGEN DEL MENU TABLERO
  Menu_Ayuda=load_bitmap("Img/Menu/Menu_Ayuda.bmp",NULL);                   //CARGA LA IMAGEN DEL MENU AYUDA
  Menu_Salir=load_bitmap("Img/Menu/Menu_Salir.bmp",NULL);                   //CARGA LA IMAGEN DEL MENU SALIR
//-------------------------------------------------------------------------//
  Tablero_Normal = load_bitmap("Img/Tablero/Tablero_Normal.bmp",NULL);      //CARGA LA IMAGEN DEL TABLERO NORMAL
  Tablero_Salir = load_bitmap("Img/Tablero/Tablero_Salir.bmp",NULL);        //CARGA LA IMAGEN DEL TABLERO SALIR
//--------------------------------------------------------------------------//
  Ayuda_Normal = load_bitmap("Img/Ayuda/Ayuda_Normal.bmp",NULL);            //CARGA LA IMAGEN DE AYUDA NORMAL
  Ayuda_Salir = load_bitmap("Img/Ayuda/Ayuda_Salir.bmp",NULL);              //CARGA LA IMAGEN DE AYUDA SALIR
//--------------------------------------------------------------------------//
  Jugar_Normal = load_bitmap("Img/Jugar/jugar/Jugar_Normal.bmp",NULL);
  Jugar_Salir = load_bitmap("Img/Jugar/jugar/Jugar_Salir.bmp",NULL);

  Registrar_Normal = load_bitmap("Img/Jugar/salir/Registrar_Normal.bmp",NULL);
  Registrar_Cancelar = load_bitmap("Img/Jugar/salir/Registrar_Cancelar.bmp",NULL);
  Registrar_Aceptar = load_bitmap("Img/Jugar/salir/Registrar_Aceptar.bmp",NULL);

  while ( !salida )                                                      //SE INICIA CON UN WHILE PARA QUE REVISE PRIMERO LA VARIABLE
	{                                                                    //BOOLEANA Y DESPUES ENTRE AL CICLO
    //*****************************************************[JUGAR]*********************************************//
    if ( mouse_x > 162 && mouse_x < 334 &&
    mouse_y > 228 && mouse_y < 257)
    {
      blit(Menu_Jugar, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Jugar();
      }
    }
    //*****************************************************[TABLERO]************************************************//
    else if ( mouse_x > 130 && mouse_x < 263 &&
    mouse_y > 282 && mouse_y < 310)
    {
      blit(Menu_Tablero, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Tablero();
      }
    }
    //*****************************************************[AYUDA]************************************************//
    else if ( mouse_x > 162 && mouse_x < 334 &&
    mouse_y > 337 && mouse_y < 364)
    {
      blit(Menu_Ayuda, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Ayuda();
      }
    }
    //**************************************************[SALIR]****************************************************//
    else if ( mouse_x > 162 && mouse_x < 334 &&
    mouse_y > 393 && mouse_y < 420)
    {
      blit(Menu_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        salida = true;
      }
    }


    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Menu_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    printf("X: [%d] | Y: [%d] \n",mouse_x,mouse_y);
    // se muestra todo por pantalla
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);
  }
}

int main()
{
    Inicio();

    Menu();

    Final();
}
END_OF_MAIN();
