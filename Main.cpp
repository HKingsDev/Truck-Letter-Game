#include <allegro.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

//http://store.steampowered.com/app/367520?snr=1_41_4__42

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

BITMAP *Seleccionar_Alto;
BITMAP *Seleccionar_Medio;
BITMAP *Seleccionar_Bajo;
BITMAP *Seleccionar_Normal;
BITMAP *Seleccionar_Salir;

BITMAP *Problema;
BITMAP *Respuesta_1;
BITMAP *Respuesta_2;
BITMAP *Respuesta_3;
BITMAP *Respuesta_4;

BITMAP *Problema_1;
  BITMAP *Problema_1_Respuesta_Correcta;
  BITMAP *Problema_1_Respuesta_Falsa_1;
  BITMAP *Problema_1_Respuesta_Falsa_2;
  BITMAP *Problema_1_Respuesta_Falsa_3;

BITMAP *Problema_2;
  BITMAP *Problema_2_Respuesta_Correcta;
  BITMAP *Problema_2_Respuesta_Falsa_1;
  BITMAP *Problema_2_Respuesta_Falsa_2;
  BITMAP *Problema_2_Respuesta_Falsa_3;

BITMAP *Problema_3;
  BITMAP *Problema_3_Respuesta_Correcta;
  BITMAP *Problema_3_Respuesta_Falsa_1;
  BITMAP *Problema_3_Respuesta_Falsa_2;
  BITMAP *Problema_3_Respuesta_Falsa_3;

BITMAP *Problema_4;
  BITMAP *Problema_4_Respuesta_Correcta;
  BITMAP *Problema_4_Respuesta_Falsa_1;
  BITMAP *Problema_4_Respuesta_Falsa_2;
  BITMAP *Problema_4_Respuesta_Falsa_3;

BITMAP *Problema_5;
  BITMAP *Problema_5_Respuesta_Correcta;
  BITMAP *Problema_5_Respuesta_Falsa_1;
  BITMAP *Problema_5_Respuesta_Falsa_2;
  BITMAP *Problema_5_Respuesta_Falsa_3;

BITMAP *Problema_6;
  BITMAP *Problema_6_Respuesta_Correcta;
  BITMAP *Problema_6_Respuesta_Falsa_1;
  BITMAP *Problema_6_Respuesta_Falsa_2;
  BITMAP *Problema_6_Respuesta_Falsa_3;

BITMAP *Problema_7;
  BITMAP *Problema_7_Respuesta_Correcta;
  BITMAP *Problema_7_Respuesta_Falsa_1;
  BITMAP *Problema_7_Respuesta_Falsa_2;
  BITMAP *Problema_7_Respuesta_Falsa_3;

BITMAP *Problema_8;
  BITMAP *Problema_8_Respuesta_Correcta;
  BITMAP *Problema_8_Respuesta_Falsa_1;
  BITMAP *Problema_8_Respuesta_Falsa_2;
  BITMAP *Problema_8_Respuesta_Falsa_3;

BITMAP *Problema_9;
  BITMAP *Problema_9_Respuesta_Correcta;
  BITMAP *Problema_9_Respuesta_Falsa_1;
  BITMAP *Problema_9_Respuesta_Falsa_2;
  BITMAP *Problema_9_Respuesta_Falsa_3;

BITMAP *Problema_10;
  BITMAP *Problema_10_Respuesta_Correcta;
  BITMAP *Problema_10_Respuesta_Falsa_1;
  BITMAP *Problema_10_Respuesta_Falsa_2;
  BITMAP *Problema_10_Respuesta_Falsa_3;







//DELCARACION DE VARIABLES
bool salida = false;        //VARIABLE BOOLEANA PARA SALIR. SE MANTIENE EN FALSE.
bool salida_Nivel_Bajo = false;
bool salida_Nivel_Medio = false;
bool salida_Nivel_Alto = false;
bool salida_Tablero = false; 		//VARIABLE QUE SOLO SERVIRA PARA ENTRAR Y SALIR DE JUGAR,AYUDA,TABLERO
bool salida_Ayuda = false;
bool salida_Registro = false;
bool salida_Seleccionar = false;
bool confirmar = false;

int Numero_Random_10;
int Numero_Random_24;
int Identificador_de_Problema[10];
int La_Respuesta_es;
int Puntuacion;

int milisegundo;
int segundo;
int minuto;
int hora;
int cont;

int Contador_Entrada_Funcion;

bool Permite_Cancelar_Registro = false;
bool Puerta_Entrada = false;

char nick[20];//Variable global donde se almacena el nombre
int id=1; //Id de el numero de registro
int vuelta=0; //contador de vueltas dentro de un ciclo
bool after=false; //tiene como finalidad el verificar si entras ono a la parte de gusrdar datos








//Aquie se encuentran 3 estructuras que tienenen como
//finalidad el poder guardar enmemoria dinamica
//las puntuaciones, nombres, etc.
struct game //primera estructura, esta tiene como funcion el cargar los datos del archivo
//que se genera para despues mostrarlo por pantalla
{//sus respectivas variables que conforman la estructura
int id;
char nick[20];
int Puntuacion;
}GAME[10];// esta estructura funciona como un arreglo de 10 (sepuede modificar el tamaño remplasando el 10 por otro numero).

// segunda estructura, en esta se emplea lamemoria dinamica,valla esta estructura no esta definida pero
//puede crecer tanto como los registros que quieras ingresar
struct nodo
{//sus respectivas variables que conforman la estructura.
int id;
char nick[20];
int Puntuacion;
struct nodo*next;
}temporal;

typedef struct nodo NODO; // se definen los nodos de la estructura
typedef NODO *NODOPTR; // y apuntadores

struct temp//tercera estructura, en esta tiene como finalizar pasar los datos de la memoria dinamica a los archivos y de los archivos
//a la primera estructura para mostrarlos por pantalla
{//sus respectivas variables
int id;
char nick[20];
int Puntuacion;
}secundario;

void insertar(NODOPTR*,NODOPTR*,int,char*,int);// se manda llamar la funcion de inseratr que se encuentra hasta abajo de todo el codigo.

NODOPTR inicio_nodo=NULL; // se crea un puntero parala memoria dinamica
NODOPTR empiezo_nodo=NULL;// se crea otro puntero

//int main();
void Menu();
void Random();
void Generar_Imagenes_Random();
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

/////////////////////////////////////////////////////////////////////////////////////////////////
void REGISTRAR(NODOPTR inicio_nodo) //LOS DATOS QUE SE ENCUENTRAN EN MEMORIA DINAMICA PASAN DIRECTAMETE AL ARCHIVO
{// esta funcion permite reistrar los datos que estan almacenados en la memoria dinamica al archivo

FILE*fich;// se declara el apuntador que nos permitira almacenar la ruta del archivo


if((fich=fopen("C:\\Users\\Ortus Atq\\Desktop\\Truck-Letter\\DataBase\\DB.dat", "ab")) ==NULL) { //sele asigna la ruta del archivo
    exit(0);
  }

fread(&secundario,sizeof(struct temp),1,fich);//verifica el tamaño de los datos a guardar

secundario.id=inicio_nodo->id; //en la estructura Temp en la variable inicio se gusrdara lo que se encuentre en la memoria dinamica

strcpy(secundario.nick,temporal.nick);// strcpy es para copiar cadenas de texto, lo anterior a esto y lo que sigue es para numeros enteros o flotantes

secundario.Puntuacion=inicio_nodo->Puntuacion;

fwrite(&secundario,sizeof(temp),1,fich);//se escribe en el archivo

fclose(fich);// se cierra el archivo

}

/*********************************************************************************************************************************/

void CARGAR(){ //LOS DATOS QUE SE ENCUENTRAN EN EL ARCHIVO PASAN A LA ESTRUCTURA GAME QUE ES LA QUE MUESTRA
  //En esta parte es donde cargamos los datos de el archivo a la estructura game la cual nos permite mostrarlo por pantalla

FILE*fich;//al igual que ene lnterior punto e spara crear la ruta del archivo
int x=0; // es una variable que ayudara a alamcenar los datos para desplegarlos por pantalla
int y_y=215;// esta variable nos ayudara a poder imprimirlo de forma acendente

if((fich=fopen("C:\\Users\\Ortus Atq\\Desktop\\Truck-Letter\\DataBase\\DB.dat", "rb")) ==NULL) { //abromos el archivo
    printf("Error al crear fichero");
    exit(0);// en caso de que no se pueda abrir se termina de ejecutar le programa
  }
    rewind(fich);//prepara el archivo para leerlo y se posiciona en la primera posicion
    while(!feof(fich))//un ciclo donde nos permitira leer todo el archivo
    {

          fread(&secundario,sizeof(struct temp),1,fich); //nos ayuda a caragar los datosa al estructura
          GAME[x].id=secundario.id; //la estructura game sea = a la estructura secundaria ya que la estructura es donde carga 1 dato en 1 y lo pasa a la estructura game
          //que es la que lo mostrara en pantalla aparte de que es un arreglo de 10
          strcpy(GAME[x].nick,secundario.nick);
          GAME[x].Puntuacion=secundario.Puntuacion;

          text_mode(-1);// cuando escribimos texto en modo grafico sale un fondo de color negro, esto lo elimina

          textprintf(screen,font,25,y_y,palette_color[0],"%d", GAME[x].id); // esun printf pero en allegro

          textout(screen, font, GAME[x].nick, 80,y_y, palette_color[0]);

          textprintf(screen,font,280,y_y,palette_color[0],"%d", GAME[x].Puntuacion);

      x++; // nosayuda a cambiar la posicion del arreglo
      y_y=y_y+20;// hace un salto delinapara imprimir nuevos datos
    }

    fclose(fich);// cierra el archivo
}


void escribir()
    {//funcion para escribir texto

          char cadena_usuario[20]={' '}; // se crea un arreglo local

           bool salir = false; // variable que funcion para el ciclo
          int x = 0; // variable auxiliar para el arreglo

              while(!salir) // inicia el ciclo de captura
              {
              if(keypressed()) //esto hace referencia a que si estamos usando el teclado(prcionando teclas)
              {
              int newkey = readkey(); // convertimos cada tecla que piquemos en codigo ascci
              char asciiCode = newkey &0xff;
              char scancode = newkey >> 8;

              /* Validacion de solo texto */
              if(asciiCode >= 64 && asciiCode <= 90  || asciiCode >= 97 && asciiCode <= 122 ) {

                  if(x < 19) {
                    //se va almacenando en el arreglo caracter por caracter
                    cadena_usuario[x] = asciiCode;
                    x++;
                    cadena_usuario[x] = '\0';
                    }
                  }

              else if(scancode == KEY_BACKSPACE)
              {// eso es para dar un espacio
                  if (x > 0)
                   {
                       cadena_usuario[x] = '\0';
                       x--;
                       cadena_usuario[x] = ' ';
                   }
                  }
              }

              if(key[KEY_ENTER]) {// si pulsamos enter es que ya terminamos
                salir = true;
              }
              //imprime cada caracter que perecionemos en la pantalla

              textout(screen, font, cadena_usuario, 180,150, palette_color[10]);


              }//WHILE

                textout(screen, font, ("[Listo] Pulse [Enter] para salir"), 180,170, palette_color[10]);

                strcpy(nick, cadena_usuario); // copia lo que este en la cadena local a la cadena global que esta en el main

                readkey();
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Ajustar_Arrays()
{
  for(int x=0;x<24;x++)
  {
    Identificador_de_Problema[x]=0;
  }
}
void Random()// Esta es la funcion que genera un numero aletorio
{
  Numero_Random_10=rand()%10+1;
  Numero_Random_24=rand()%24+1;
}
void Generar_Imagenes_Random()
{

  if(Puerta_Entrada == false)
  {
    Puerta_Entrada = true;
    printf("Antes del Random:: Num 10:%d - Num 24:%d - R:%d - Cont:%d \n",Numero_Random_10, Numero_Random_24, La_Respuesta_es, Contador_Entrada_Funcion );
    Contador_Entrada_Funcion= Contador_Entrada_Funcion +1;
    Random();
    printf("Despues del Random:: Num 10:%d - Num 24:%d - R:%d - Cont:%d \n",Numero_Random_10, Numero_Random_24, La_Respuesta_es, Contador_Entrada_Funcion );

    switch(Numero_Random_10)
    {
      case 1:
        //if(Identificador_de_Problema[0]==0)
        //{
          Identificador_de_Problema[0]=1;
          Problema = Problema_1;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_1_Respuesta_Correcta;Respuesta_2 = Problema_1_Respuesta_Falsa_1;Respuesta_3  = Problema_1_Respuesta_Falsa_2;Respuesta_4  = Problema_1_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_1_Respuesta_Falsa_1;Respuesta_2  = Problema_1_Respuesta_Correcta;Respuesta_3 = Problema_1_Respuesta_Falsa_2;Respuesta_4  = Problema_1_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_1_Respuesta_Falsa_1;Respuesta_2  = Problema_1_Respuesta_Falsa_2;Respuesta_3  = Problema_1_Respuesta_Correcta;Respuesta_4 = Problema_1_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_1_Respuesta_Falsa_1;Respuesta_2  = Problema_1_Respuesta_Falsa_2;Respuesta_3  = Problema_1_Respuesta_Falsa_3;Respuesta_4  = Problema_1_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_1_Respuesta_Falsa_3;Respuesta_2  = Problema_1_Respuesta_Falsa_1;Respuesta_3  = Problema_1_Respuesta_Falsa_2;Respuesta_4  = Problema_1_Respuesta_Correcta;La_Respuesta_es = 4;break;

            case 6:Respuesta_1  = Problema_1_Respuesta_Falsa_2;Respuesta_2  = Problema_1_Respuesta_Falsa_1;Respuesta_3  = Problema_1_Respuesta_Falsa_3;Respuesta_4  = Problema_1_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_1_Respuesta_Correcta;Respuesta_2 = Problema_1_Respuesta_Falsa_3;Respuesta_3  = Problema_1_Respuesta_Falsa_2;Respuesta_4  = Problema_1_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_1_Respuesta_Correcta;Respuesta_2 = Problema_1_Respuesta_Falsa_2;Respuesta_3  = Problema_1_Respuesta_Falsa_1;Respuesta_4  = Problema_1_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_1_Respuesta_Correcta;Respuesta_2 = Problema_1_Respuesta_Falsa_3;Respuesta_3  = Problema_1_Respuesta_Falsa_1;Respuesta_4  = Problema_1_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_1_Respuesta_Falsa_2;Respuesta_2  = Problema_1_Respuesta_Falsa_1;Respuesta_3  = Problema_1_Respuesta_Correcta;Respuesta_4 = Problema_1_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;

            case 11:Respuesta_1 = Problema_1_Respuesta_Falsa_2;Respuesta_2  = Problema_1_Respuesta_Falsa_3;Respuesta_3  = Problema_1_Respuesta_Correcta;Respuesta_4 = Problema_1_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_1_Respuesta_Falsa_2;Respuesta_2  = Problema_1_Respuesta_Falsa_3;Respuesta_3  = Problema_1_Respuesta_Falsa_1;Respuesta_4  = Problema_1_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_1_Respuesta_Falsa_1;Respuesta_2  = Problema_1_Respuesta_Correcta;Respuesta_3 = Problema_1_Respuesta_Falsa_3;Respuesta_4  = Problema_1_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_1_Respuesta_Correcta;Respuesta_2 = Problema_1_Respuesta_Falsa_2;Respuesta_3  = Problema_1_Respuesta_Falsa_3;Respuesta_4  = Problema_1_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_1_Respuesta_Correcta;Respuesta_2 = Problema_1_Respuesta_Falsa_1;Respuesta_3  = Problema_1_Respuesta_Falsa_3;Respuesta_4  = Problema_1_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_1_Respuesta_Falsa_1;Respuesta_2  = Problema_1_Respuesta_Falsa_3;Respuesta_3  = Problema_1_Respuesta_Correcta;Respuesta_4 = Problema_1_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_1_Respuesta_Falsa_1;Respuesta_2  = Problema_1_Respuesta_Falsa_3;Respuesta_3  = Problema_1_Respuesta_Falsa_2;Respuesta_4  = Problema_1_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_1_Respuesta_Falsa_2;Respuesta_2  = Problema_1_Respuesta_Correcta;Respuesta_3 = Problema_1_Respuesta_Falsa_1;Respuesta_4  = Problema_1_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_1_Respuesta_Falsa_2;Respuesta_2  = Problema_1_Respuesta_Correcta;Respuesta_3 = Problema_1_Respuesta_Falsa_3;Respuesta_4  = Problema_1_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_1_Respuesta_Falsa_3;Respuesta_2  = Problema_1_Respuesta_Falsa_1;Respuesta_3  = Problema_1_Respuesta_Correcta;Respuesta_4 = Problema_1_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_1_Respuesta_Falsa_3;Respuesta_2  = Problema_1_Respuesta_Falsa_2;Respuesta_3  = Problema_1_Respuesta_Correcta;Respuesta_4 = Problema_1_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_1_Respuesta_Falsa_3;Respuesta_2  = Problema_1_Respuesta_Falsa_2;Respuesta_3  = Problema_1_Respuesta_Falsa_1;Respuesta_4  = Problema_1_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_1_Respuesta_Falsa_3;Respuesta_2  = Problema_1_Respuesta_Correcta;Respuesta_3 = Problema_1_Respuesta_Falsa_1;Respuesta_4  = Problema_1_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_1_Respuesta_Falsa_3;Respuesta_2  = Problema_1_Respuesta_Correcta;Respuesta_3 = Problema_1_Respuesta_Falsa_2;Respuesta_4  = Problema_1_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;

          }
        //}
      break;
      case 2:
        //if(Identificador_de_Problema[1]==0)
        //{
          Identificador_de_Problema[1]=1;
          Problema = Problema_2;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_2_Respuesta_Correcta;Respuesta_2 = Problema_2_Respuesta_Falsa_1;Respuesta_3  = Problema_2_Respuesta_Falsa_2;Respuesta_4  = Problema_2_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_2_Respuesta_Falsa_1;Respuesta_2  = Problema_2_Respuesta_Correcta;Respuesta_3 = Problema_2_Respuesta_Falsa_2;Respuesta_4  = Problema_2_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_2_Respuesta_Falsa_1;Respuesta_2  = Problema_2_Respuesta_Falsa_2;Respuesta_3  = Problema_2_Respuesta_Correcta;Respuesta_4 = Problema_2_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_2_Respuesta_Falsa_1;Respuesta_2  = Problema_2_Respuesta_Falsa_2;Respuesta_3  = Problema_2_Respuesta_Falsa_3;Respuesta_4  = Problema_2_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_2_Respuesta_Falsa_3;Respuesta_2  = Problema_2_Respuesta_Falsa_1;Respuesta_3  = Problema_2_Respuesta_Falsa_2;Respuesta_4  = Problema_2_Respuesta_Correcta;La_Respuesta_es = 4;break;

            case 6:Respuesta_1  = Problema_2_Respuesta_Falsa_2;Respuesta_2  = Problema_2_Respuesta_Falsa_1;Respuesta_3  = Problema_2_Respuesta_Falsa_3;Respuesta_4  = Problema_2_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_2_Respuesta_Correcta;Respuesta_2 = Problema_2_Respuesta_Falsa_3;Respuesta_3  = Problema_2_Respuesta_Falsa_2;Respuesta_4  = Problema_2_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_2_Respuesta_Correcta;Respuesta_2 = Problema_2_Respuesta_Falsa_2;Respuesta_3  = Problema_2_Respuesta_Falsa_1;Respuesta_4  = Problema_2_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_2_Respuesta_Correcta;Respuesta_2 = Problema_2_Respuesta_Falsa_3;Respuesta_3  = Problema_2_Respuesta_Falsa_1;Respuesta_4  = Problema_2_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_2_Respuesta_Falsa_2;Respuesta_2  = Problema_2_Respuesta_Falsa_1;Respuesta_3  = Problema_2_Respuesta_Correcta;Respuesta_4 = Problema_2_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;

            case 11:Respuesta_1 = Problema_2_Respuesta_Falsa_2;Respuesta_2  = Problema_2_Respuesta_Falsa_3;Respuesta_3  = Problema_2_Respuesta_Correcta;Respuesta_4 = Problema_2_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_2_Respuesta_Falsa_2;Respuesta_2  = Problema_2_Respuesta_Falsa_3;Respuesta_3  = Problema_2_Respuesta_Falsa_1;Respuesta_4  = Problema_2_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_2_Respuesta_Falsa_1;Respuesta_2  = Problema_2_Respuesta_Correcta;Respuesta_3 = Problema_2_Respuesta_Falsa_3;Respuesta_4  = Problema_2_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_2_Respuesta_Correcta;Respuesta_2 = Problema_2_Respuesta_Falsa_2;Respuesta_3  = Problema_2_Respuesta_Falsa_3;Respuesta_4  = Problema_2_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_2_Respuesta_Correcta;Respuesta_2 = Problema_2_Respuesta_Falsa_1;Respuesta_3  = Problema_2_Respuesta_Falsa_3;Respuesta_4  = Problema_2_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_2_Respuesta_Falsa_1;Respuesta_2  = Problema_2_Respuesta_Falsa_3;Respuesta_3  = Problema_2_Respuesta_Correcta;Respuesta_4 = Problema_2_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_2_Respuesta_Falsa_1;Respuesta_2  = Problema_2_Respuesta_Falsa_3;Respuesta_3  = Problema_2_Respuesta_Falsa_2;Respuesta_4  = Problema_2_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_2_Respuesta_Falsa_2;Respuesta_2  = Problema_2_Respuesta_Correcta;Respuesta_3 = Problema_2_Respuesta_Falsa_1;Respuesta_4  = Problema_2_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_2_Respuesta_Falsa_2;Respuesta_2  = Problema_2_Respuesta_Correcta;Respuesta_3 = Problema_2_Respuesta_Falsa_3;Respuesta_4  = Problema_2_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_2_Respuesta_Falsa_3;Respuesta_2  = Problema_2_Respuesta_Falsa_1;Respuesta_3  = Problema_2_Respuesta_Correcta;Respuesta_4 = Problema_2_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_2_Respuesta_Falsa_3;Respuesta_2  = Problema_2_Respuesta_Falsa_2;Respuesta_3  = Problema_2_Respuesta_Correcta;Respuesta_4 = Problema_2_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_2_Respuesta_Falsa_3;Respuesta_2  = Problema_2_Respuesta_Falsa_2;Respuesta_3  = Problema_2_Respuesta_Falsa_1;Respuesta_4  = Problema_2_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_2_Respuesta_Falsa_3;Respuesta_2  = Problema_2_Respuesta_Correcta;Respuesta_3 = Problema_2_Respuesta_Falsa_1;Respuesta_4  = Problema_2_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_2_Respuesta_Falsa_3;Respuesta_2  = Problema_2_Respuesta_Correcta;Respuesta_3 = Problema_2_Respuesta_Falsa_2;Respuesta_4  = Problema_2_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;

          }
        //}
      break;
      case 3:
        //if(Identificador_de_Problema[2]==0)
        //{
          Identificador_de_Problema[2]=1;
          Problema = Problema_3;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_3_Respuesta_Correcta;Respuesta_2 = Problema_3_Respuesta_Falsa_1;Respuesta_3  = Problema_3_Respuesta_Falsa_2;Respuesta_4  = Problema_3_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_3_Respuesta_Falsa_1;Respuesta_2  = Problema_3_Respuesta_Correcta;Respuesta_3 = Problema_3_Respuesta_Falsa_2;Respuesta_4  = Problema_3_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_3_Respuesta_Falsa_1;Respuesta_2  = Problema_3_Respuesta_Falsa_2;Respuesta_3  = Problema_3_Respuesta_Correcta;Respuesta_4 = Problema_3_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_3_Respuesta_Falsa_1;Respuesta_2  = Problema_3_Respuesta_Falsa_2;Respuesta_3  = Problema_3_Respuesta_Falsa_3;Respuesta_4  = Problema_3_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_3_Respuesta_Falsa_3;Respuesta_2  = Problema_3_Respuesta_Falsa_1;Respuesta_3  = Problema_3_Respuesta_Falsa_2;Respuesta_4  = Problema_3_Respuesta_Correcta;La_Respuesta_es = 4;break;

            case 6:Respuesta_1  = Problema_3_Respuesta_Falsa_2;Respuesta_2  = Problema_3_Respuesta_Falsa_1;Respuesta_3  = Problema_3_Respuesta_Falsa_3;Respuesta_4  = Problema_3_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_3_Respuesta_Correcta;Respuesta_2 = Problema_3_Respuesta_Falsa_3;Respuesta_3  = Problema_3_Respuesta_Falsa_2;Respuesta_4  = Problema_3_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_3_Respuesta_Correcta;Respuesta_2 = Problema_3_Respuesta_Falsa_2;Respuesta_3  = Problema_3_Respuesta_Falsa_1;Respuesta_4  = Problema_3_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_3_Respuesta_Correcta;Respuesta_2 = Problema_3_Respuesta_Falsa_3;Respuesta_3  = Problema_3_Respuesta_Falsa_1;Respuesta_4  = Problema_3_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_3_Respuesta_Falsa_2;Respuesta_2  = Problema_3_Respuesta_Falsa_1;Respuesta_3  = Problema_3_Respuesta_Correcta;Respuesta_4 = Problema_3_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;

            case 11:Respuesta_1 = Problema_3_Respuesta_Falsa_2;Respuesta_2  = Problema_3_Respuesta_Falsa_3;Respuesta_3  = Problema_3_Respuesta_Correcta;Respuesta_4 = Problema_3_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_3_Respuesta_Falsa_2;Respuesta_2  = Problema_3_Respuesta_Falsa_3;Respuesta_3  = Problema_3_Respuesta_Falsa_1;Respuesta_4  = Problema_3_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_3_Respuesta_Falsa_1;Respuesta_2  = Problema_3_Respuesta_Correcta;Respuesta_3 = Problema_3_Respuesta_Falsa_3;Respuesta_4  = Problema_3_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_3_Respuesta_Correcta;Respuesta_2 = Problema_3_Respuesta_Falsa_2;Respuesta_3  = Problema_3_Respuesta_Falsa_3;Respuesta_4  = Problema_3_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_3_Respuesta_Correcta;Respuesta_2 = Problema_3_Respuesta_Falsa_1;Respuesta_3  = Problema_3_Respuesta_Falsa_3;Respuesta_4  = Problema_3_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_3_Respuesta_Falsa_1;Respuesta_2  = Problema_3_Respuesta_Falsa_3;Respuesta_3  = Problema_3_Respuesta_Correcta;Respuesta_4 = Problema_3_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_3_Respuesta_Falsa_1;Respuesta_2  = Problema_3_Respuesta_Falsa_3;Respuesta_3  = Problema_3_Respuesta_Falsa_2;Respuesta_4  = Problema_3_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_3_Respuesta_Falsa_2;Respuesta_2  = Problema_3_Respuesta_Correcta;Respuesta_3 = Problema_3_Respuesta_Falsa_1;Respuesta_4  = Problema_3_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_3_Respuesta_Falsa_2;Respuesta_2  = Problema_3_Respuesta_Correcta;Respuesta_3 = Problema_3_Respuesta_Falsa_3;Respuesta_4  = Problema_3_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_3_Respuesta_Falsa_3;Respuesta_2  = Problema_3_Respuesta_Falsa_1;Respuesta_3  = Problema_3_Respuesta_Correcta;Respuesta_4 = Problema_3_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_3_Respuesta_Falsa_3;Respuesta_2  = Problema_3_Respuesta_Falsa_2;Respuesta_3  = Problema_3_Respuesta_Correcta;Respuesta_4 = Problema_3_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_3_Respuesta_Falsa_3;Respuesta_2  = Problema_3_Respuesta_Falsa_2;Respuesta_3  = Problema_3_Respuesta_Falsa_1;Respuesta_4  = Problema_3_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_3_Respuesta_Falsa_3;Respuesta_2  = Problema_3_Respuesta_Correcta;Respuesta_3 = Problema_3_Respuesta_Falsa_1;Respuesta_4  = Problema_3_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_3_Respuesta_Falsa_3;Respuesta_2  = Problema_3_Respuesta_Correcta;Respuesta_3 = Problema_3_Respuesta_Falsa_2;Respuesta_4  = Problema_3_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;

          }
        //}
      break;
      case 4:
        //if(Identificador_de_Problema[3]==0)
        //{
          Identificador_de_Problema[3]=1;
          Problema = Problema_4;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_4_Respuesta_Correcta;Respuesta_2 = Problema_4_Respuesta_Falsa_1;Respuesta_3  = Problema_4_Respuesta_Falsa_2;Respuesta_4  = Problema_4_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_4_Respuesta_Falsa_1;Respuesta_2  = Problema_4_Respuesta_Correcta;Respuesta_3 = Problema_4_Respuesta_Falsa_2;Respuesta_4  = Problema_4_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_4_Respuesta_Falsa_1;Respuesta_2  = Problema_4_Respuesta_Falsa_2;Respuesta_3  = Problema_4_Respuesta_Correcta;Respuesta_4 = Problema_4_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_4_Respuesta_Falsa_1;Respuesta_2  = Problema_4_Respuesta_Falsa_2;Respuesta_3  = Problema_4_Respuesta_Falsa_3;Respuesta_4  = Problema_4_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_4_Respuesta_Falsa_3;Respuesta_2  = Problema_4_Respuesta_Falsa_1;Respuesta_3  = Problema_4_Respuesta_Falsa_2;Respuesta_4  = Problema_4_Respuesta_Correcta;La_Respuesta_es = 4;break;

            case 6:Respuesta_1  = Problema_4_Respuesta_Falsa_2;Respuesta_2  = Problema_4_Respuesta_Falsa_1;Respuesta_3  = Problema_4_Respuesta_Falsa_3;Respuesta_4  = Problema_4_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_4_Respuesta_Correcta;Respuesta_2 = Problema_4_Respuesta_Falsa_3;Respuesta_3  = Problema_4_Respuesta_Falsa_2;Respuesta_4  = Problema_4_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_4_Respuesta_Correcta;Respuesta_2 = Problema_4_Respuesta_Falsa_2;Respuesta_3  = Problema_4_Respuesta_Falsa_1;Respuesta_4  = Problema_4_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_4_Respuesta_Correcta;Respuesta_2 = Problema_4_Respuesta_Falsa_3;Respuesta_3  = Problema_4_Respuesta_Falsa_1;Respuesta_4  = Problema_4_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_4_Respuesta_Falsa_2;Respuesta_2  = Problema_4_Respuesta_Falsa_1;Respuesta_3  = Problema_4_Respuesta_Correcta;Respuesta_4 = Problema_4_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;

            case 11:Respuesta_1 = Problema_4_Respuesta_Falsa_2;Respuesta_2  = Problema_4_Respuesta_Falsa_3;Respuesta_3  = Problema_4_Respuesta_Correcta;Respuesta_4 = Problema_4_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_4_Respuesta_Falsa_2;Respuesta_2  = Problema_4_Respuesta_Falsa_3;Respuesta_3  = Problema_4_Respuesta_Falsa_1;Respuesta_4  = Problema_4_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_4_Respuesta_Falsa_1;Respuesta_2  = Problema_4_Respuesta_Correcta;Respuesta_3 = Problema_4_Respuesta_Falsa_3;Respuesta_4  = Problema_4_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_4_Respuesta_Correcta;Respuesta_2 = Problema_4_Respuesta_Falsa_2;Respuesta_3  = Problema_4_Respuesta_Falsa_3;Respuesta_4  = Problema_4_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_4_Respuesta_Correcta;Respuesta_2 = Problema_4_Respuesta_Falsa_1;Respuesta_3  = Problema_4_Respuesta_Falsa_3;Respuesta_4  = Problema_4_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_4_Respuesta_Falsa_1;Respuesta_2  = Problema_4_Respuesta_Falsa_3;Respuesta_3  = Problema_4_Respuesta_Correcta;Respuesta_4 = Problema_4_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_4_Respuesta_Falsa_1;Respuesta_2  = Problema_4_Respuesta_Falsa_3;Respuesta_3  = Problema_4_Respuesta_Falsa_2;Respuesta_4  = Problema_4_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_4_Respuesta_Falsa_2;Respuesta_2  = Problema_4_Respuesta_Correcta;Respuesta_3 = Problema_4_Respuesta_Falsa_1;Respuesta_4  = Problema_4_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_4_Respuesta_Falsa_2;Respuesta_2  = Problema_4_Respuesta_Correcta;Respuesta_3 = Problema_4_Respuesta_Falsa_3;Respuesta_4  = Problema_4_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_4_Respuesta_Falsa_3;Respuesta_2  = Problema_4_Respuesta_Falsa_1;Respuesta_3  = Problema_4_Respuesta_Correcta;Respuesta_4 = Problema_4_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_4_Respuesta_Falsa_3;Respuesta_2  = Problema_4_Respuesta_Falsa_2;Respuesta_3  = Problema_4_Respuesta_Correcta;Respuesta_4 = Problema_4_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_4_Respuesta_Falsa_3;Respuesta_2  = Problema_4_Respuesta_Falsa_2;Respuesta_3  = Problema_4_Respuesta_Falsa_1;Respuesta_4  = Problema_4_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_4_Respuesta_Falsa_3;Respuesta_2  = Problema_4_Respuesta_Correcta;Respuesta_3 = Problema_4_Respuesta_Falsa_1;Respuesta_4  = Problema_4_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_4_Respuesta_Falsa_3;Respuesta_2  = Problema_4_Respuesta_Correcta;Respuesta_3 = Problema_4_Respuesta_Falsa_2;Respuesta_4  = Problema_4_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;

          }
        //}
      break;
      case 5:
        //if(Identificador_de_Problema[4]==0)
        //{
          Identificador_de_Problema[4]=1;
          Problema = Problema_5;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_5_Respuesta_Correcta;Respuesta_2 = Problema_5_Respuesta_Falsa_1;Respuesta_3  = Problema_5_Respuesta_Falsa_2;Respuesta_4  = Problema_5_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_5_Respuesta_Falsa_1;Respuesta_2  = Problema_5_Respuesta_Correcta;Respuesta_3 = Problema_5_Respuesta_Falsa_2;Respuesta_4  = Problema_5_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_5_Respuesta_Falsa_1;Respuesta_2  = Problema_5_Respuesta_Falsa_2;Respuesta_3  = Problema_5_Respuesta_Correcta;Respuesta_4 = Problema_5_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_5_Respuesta_Falsa_1;Respuesta_2  = Problema_5_Respuesta_Falsa_2;Respuesta_3  = Problema_5_Respuesta_Falsa_3;Respuesta_4  = Problema_5_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_5_Respuesta_Falsa_3;Respuesta_2  = Problema_5_Respuesta_Falsa_1;Respuesta_3  = Problema_5_Respuesta_Falsa_2;Respuesta_4  = Problema_5_Respuesta_Correcta;La_Respuesta_es = 4;break;

            case 6:Respuesta_1  = Problema_5_Respuesta_Falsa_2;Respuesta_2  = Problema_5_Respuesta_Falsa_1;Respuesta_3  = Problema_5_Respuesta_Falsa_3;Respuesta_4  = Problema_5_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_5_Respuesta_Correcta;Respuesta_2 = Problema_5_Respuesta_Falsa_3;Respuesta_3  = Problema_5_Respuesta_Falsa_2;Respuesta_4  = Problema_5_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_5_Respuesta_Correcta;Respuesta_2 = Problema_5_Respuesta_Falsa_2;Respuesta_3  = Problema_5_Respuesta_Falsa_1;Respuesta_4  = Problema_5_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_5_Respuesta_Correcta;Respuesta_2 = Problema_5_Respuesta_Falsa_3;Respuesta_3  = Problema_5_Respuesta_Falsa_1;Respuesta_4  = Problema_5_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_5_Respuesta_Falsa_2;Respuesta_2  = Problema_5_Respuesta_Falsa_1;Respuesta_3  = Problema_5_Respuesta_Correcta;Respuesta_4 = Problema_5_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;

            case 11:Respuesta_1 = Problema_5_Respuesta_Falsa_2;Respuesta_2  = Problema_5_Respuesta_Falsa_3;Respuesta_3  = Problema_5_Respuesta_Correcta;Respuesta_4 = Problema_5_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_5_Respuesta_Falsa_2;Respuesta_2  = Problema_5_Respuesta_Falsa_3;Respuesta_3  = Problema_5_Respuesta_Falsa_1;Respuesta_4  = Problema_5_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_5_Respuesta_Falsa_1;Respuesta_2  = Problema_5_Respuesta_Correcta;Respuesta_3 = Problema_5_Respuesta_Falsa_3;Respuesta_4  = Problema_5_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_5_Respuesta_Correcta;Respuesta_2 = Problema_5_Respuesta_Falsa_2;Respuesta_3  = Problema_5_Respuesta_Falsa_3;Respuesta_4  = Problema_5_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_5_Respuesta_Correcta;Respuesta_2 = Problema_5_Respuesta_Falsa_1;Respuesta_3  = Problema_5_Respuesta_Falsa_3;Respuesta_4  = Problema_5_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_5_Respuesta_Falsa_1;Respuesta_2  = Problema_5_Respuesta_Falsa_3;Respuesta_3  = Problema_5_Respuesta_Correcta;Respuesta_4 = Problema_5_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_5_Respuesta_Falsa_1;Respuesta_2  = Problema_5_Respuesta_Falsa_3;Respuesta_3  = Problema_5_Respuesta_Falsa_2;Respuesta_4  = Problema_5_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_5_Respuesta_Falsa_2;Respuesta_2  = Problema_5_Respuesta_Correcta;Respuesta_3 = Problema_5_Respuesta_Falsa_1;Respuesta_4  = Problema_5_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_5_Respuesta_Falsa_2;Respuesta_2  = Problema_5_Respuesta_Correcta;Respuesta_3 = Problema_5_Respuesta_Falsa_3;Respuesta_4  = Problema_5_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_5_Respuesta_Falsa_3;Respuesta_2  = Problema_5_Respuesta_Falsa_1;Respuesta_3  = Problema_5_Respuesta_Correcta;Respuesta_4 = Problema_5_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_5_Respuesta_Falsa_3;Respuesta_2  = Problema_5_Respuesta_Falsa_2;Respuesta_3  = Problema_5_Respuesta_Correcta;Respuesta_4 = Problema_5_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_5_Respuesta_Falsa_3;Respuesta_2  = Problema_5_Respuesta_Falsa_2;Respuesta_3  = Problema_5_Respuesta_Falsa_1;Respuesta_4  = Problema_5_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_5_Respuesta_Falsa_3;Respuesta_2  = Problema_5_Respuesta_Correcta;Respuesta_3 = Problema_5_Respuesta_Falsa_1;Respuesta_4  = Problema_5_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_5_Respuesta_Falsa_3;Respuesta_2  = Problema_5_Respuesta_Correcta;Respuesta_3 = Problema_5_Respuesta_Falsa_2;Respuesta_4  = Problema_5_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;

          }
        //}
      break;
      case 6:
        //if(Identificador_de_Problema[5]==0)
        //{
          Identificador_de_Problema[5]=1;
          Problema = Problema_6;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_6_Respuesta_Correcta;Respuesta_2 = Problema_6_Respuesta_Falsa_1;Respuesta_3  = Problema_6_Respuesta_Falsa_2;Respuesta_4  = Problema_6_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_6_Respuesta_Falsa_1;Respuesta_2  = Problema_6_Respuesta_Correcta;Respuesta_3 = Problema_6_Respuesta_Falsa_2;Respuesta_4  = Problema_6_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_6_Respuesta_Falsa_1;Respuesta_2  = Problema_6_Respuesta_Falsa_2;Respuesta_3  = Problema_6_Respuesta_Correcta;Respuesta_4 = Problema_6_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_6_Respuesta_Falsa_1;Respuesta_2  = Problema_6_Respuesta_Falsa_2;Respuesta_3  = Problema_6_Respuesta_Falsa_3;Respuesta_4  = Problema_6_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_6_Respuesta_Falsa_3;Respuesta_2  = Problema_6_Respuesta_Falsa_1;Respuesta_3  = Problema_6_Respuesta_Falsa_2;Respuesta_4  = Problema_6_Respuesta_Correcta;La_Respuesta_es = 4;break;

            case 6:Respuesta_1  = Problema_6_Respuesta_Falsa_2;Respuesta_2  = Problema_6_Respuesta_Falsa_1;Respuesta_3  = Problema_6_Respuesta_Falsa_3;Respuesta_4  = Problema_6_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_6_Respuesta_Correcta;Respuesta_2 = Problema_6_Respuesta_Falsa_3;Respuesta_3  = Problema_6_Respuesta_Falsa_2;Respuesta_4  = Problema_6_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_6_Respuesta_Correcta;Respuesta_2 = Problema_6_Respuesta_Falsa_2;Respuesta_3  = Problema_6_Respuesta_Falsa_1;Respuesta_4  = Problema_6_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_6_Respuesta_Correcta;Respuesta_2 = Problema_6_Respuesta_Falsa_3;Respuesta_3  = Problema_6_Respuesta_Falsa_1;Respuesta_4  = Problema_6_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_6_Respuesta_Falsa_2;Respuesta_2  = Problema_6_Respuesta_Falsa_1;Respuesta_3  = Problema_6_Respuesta_Correcta;Respuesta_4 = Problema_6_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;

            case 11:Respuesta_1 = Problema_6_Respuesta_Falsa_2;Respuesta_2  = Problema_6_Respuesta_Falsa_3;Respuesta_3  = Problema_6_Respuesta_Correcta;Respuesta_4 = Problema_6_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_6_Respuesta_Falsa_2;Respuesta_2  = Problema_6_Respuesta_Falsa_3;Respuesta_3  = Problema_6_Respuesta_Falsa_1;Respuesta_4  = Problema_6_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_6_Respuesta_Falsa_1;Respuesta_2  = Problema_6_Respuesta_Correcta;Respuesta_3 = Problema_6_Respuesta_Falsa_3;Respuesta_4  = Problema_6_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_6_Respuesta_Correcta;Respuesta_2 = Problema_6_Respuesta_Falsa_2;Respuesta_3  = Problema_6_Respuesta_Falsa_3;Respuesta_4  = Problema_6_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_6_Respuesta_Correcta;Respuesta_2 = Problema_6_Respuesta_Falsa_1;Respuesta_3  = Problema_6_Respuesta_Falsa_3;Respuesta_4  = Problema_6_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_6_Respuesta_Falsa_1;Respuesta_2  = Problema_6_Respuesta_Falsa_3;Respuesta_3  = Problema_6_Respuesta_Correcta;Respuesta_4 = Problema_6_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_6_Respuesta_Falsa_1;Respuesta_2  = Problema_6_Respuesta_Falsa_3;Respuesta_3  = Problema_6_Respuesta_Falsa_2;Respuesta_4  = Problema_6_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_6_Respuesta_Falsa_2;Respuesta_2  = Problema_6_Respuesta_Correcta;Respuesta_3 = Problema_6_Respuesta_Falsa_1;Respuesta_4  = Problema_6_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_6_Respuesta_Falsa_2;Respuesta_2  = Problema_6_Respuesta_Correcta;Respuesta_3 = Problema_6_Respuesta_Falsa_3;Respuesta_4  = Problema_6_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_6_Respuesta_Falsa_3;Respuesta_2  = Problema_6_Respuesta_Falsa_1;Respuesta_3  = Problema_6_Respuesta_Correcta;Respuesta_4 = Problema_6_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_6_Respuesta_Falsa_3;Respuesta_2  = Problema_6_Respuesta_Falsa_2;Respuesta_3  = Problema_6_Respuesta_Correcta;Respuesta_4 = Problema_6_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_6_Respuesta_Falsa_3;Respuesta_2  = Problema_6_Respuesta_Falsa_2;Respuesta_3  = Problema_6_Respuesta_Falsa_1;Respuesta_4  = Problema_6_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_6_Respuesta_Falsa_3;Respuesta_2  = Problema_6_Respuesta_Correcta;Respuesta_3 = Problema_6_Respuesta_Falsa_1;Respuesta_4  = Problema_6_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_6_Respuesta_Falsa_3;Respuesta_2  = Problema_6_Respuesta_Correcta;Respuesta_3 = Problema_6_Respuesta_Falsa_2;Respuesta_4  = Problema_6_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;

          }
        //}
      break;
      case 7:
        //if(Identificador_de_Problema[6]==0)
        //{
          Identificador_de_Problema[6]=1;
          Problema = Problema_7;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_7_Respuesta_Correcta;Respuesta_2 = Problema_7_Respuesta_Falsa_1;Respuesta_3  = Problema_7_Respuesta_Falsa_2;Respuesta_4  = Problema_7_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_7_Respuesta_Falsa_1;Respuesta_2  = Problema_7_Respuesta_Correcta;Respuesta_3 = Problema_7_Respuesta_Falsa_2;Respuesta_4  = Problema_7_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_7_Respuesta_Falsa_1;Respuesta_2  = Problema_7_Respuesta_Falsa_2;Respuesta_3  = Problema_7_Respuesta_Correcta;Respuesta_4 = Problema_7_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_7_Respuesta_Falsa_1;Respuesta_2  = Problema_7_Respuesta_Falsa_2;Respuesta_3  = Problema_7_Respuesta_Falsa_3;Respuesta_4  = Problema_7_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_7_Respuesta_Falsa_3;Respuesta_2  = Problema_7_Respuesta_Falsa_1;Respuesta_3  = Problema_7_Respuesta_Falsa_2;Respuesta_4  = Problema_7_Respuesta_Correcta;La_Respuesta_es = 4;break;

            case 6:Respuesta_1  = Problema_7_Respuesta_Falsa_2;Respuesta_2  = Problema_7_Respuesta_Falsa_1;Respuesta_3  = Problema_7_Respuesta_Falsa_3;Respuesta_4  = Problema_7_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_7_Respuesta_Correcta;Respuesta_2 = Problema_7_Respuesta_Falsa_3;Respuesta_3  = Problema_7_Respuesta_Falsa_2;Respuesta_4  = Problema_7_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_7_Respuesta_Correcta;Respuesta_2 = Problema_7_Respuesta_Falsa_2;Respuesta_3  = Problema_7_Respuesta_Falsa_1;Respuesta_4  = Problema_7_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_7_Respuesta_Correcta;Respuesta_2 = Problema_7_Respuesta_Falsa_3;Respuesta_3  = Problema_7_Respuesta_Falsa_1;Respuesta_4  = Problema_7_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_7_Respuesta_Falsa_2;Respuesta_2  = Problema_7_Respuesta_Falsa_1;Respuesta_3  = Problema_7_Respuesta_Correcta;Respuesta_4 = Problema_7_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;

            case 11:Respuesta_1 = Problema_7_Respuesta_Falsa_2;Respuesta_2  = Problema_7_Respuesta_Falsa_3;Respuesta_3  = Problema_7_Respuesta_Correcta;Respuesta_4 = Problema_7_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_7_Respuesta_Falsa_2;Respuesta_2  = Problema_7_Respuesta_Falsa_3;Respuesta_3  = Problema_7_Respuesta_Falsa_1;Respuesta_4  = Problema_7_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_7_Respuesta_Falsa_1;Respuesta_2  = Problema_7_Respuesta_Correcta;Respuesta_3 = Problema_7_Respuesta_Falsa_3;Respuesta_4  = Problema_7_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_7_Respuesta_Correcta;Respuesta_2 = Problema_7_Respuesta_Falsa_2;Respuesta_3  = Problema_7_Respuesta_Falsa_3;Respuesta_4  = Problema_7_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_7_Respuesta_Correcta;Respuesta_2 = Problema_7_Respuesta_Falsa_1;Respuesta_3  = Problema_7_Respuesta_Falsa_3;Respuesta_4  = Problema_7_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_7_Respuesta_Falsa_1;Respuesta_2  = Problema_7_Respuesta_Falsa_3;Respuesta_3  = Problema_7_Respuesta_Correcta;Respuesta_4 = Problema_7_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_7_Respuesta_Falsa_1;Respuesta_2  = Problema_7_Respuesta_Falsa_3;Respuesta_3  = Problema_7_Respuesta_Falsa_2;Respuesta_4  = Problema_7_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_7_Respuesta_Falsa_2;Respuesta_2  = Problema_7_Respuesta_Correcta;Respuesta_3 = Problema_7_Respuesta_Falsa_1;Respuesta_4  = Problema_7_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_7_Respuesta_Falsa_2;Respuesta_2  = Problema_7_Respuesta_Correcta;Respuesta_3 = Problema_7_Respuesta_Falsa_3;Respuesta_4  = Problema_7_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_7_Respuesta_Falsa_3;Respuesta_2  = Problema_7_Respuesta_Falsa_1;Respuesta_3  = Problema_7_Respuesta_Correcta;Respuesta_4 = Problema_7_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_7_Respuesta_Falsa_3;Respuesta_2  = Problema_7_Respuesta_Falsa_2;Respuesta_3  = Problema_7_Respuesta_Correcta;Respuesta_4 = Problema_7_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_7_Respuesta_Falsa_3;Respuesta_2  = Problema_7_Respuesta_Falsa_2;Respuesta_3  = Problema_7_Respuesta_Falsa_1;Respuesta_4  = Problema_7_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_7_Respuesta_Falsa_3;Respuesta_2  = Problema_7_Respuesta_Correcta;Respuesta_3 = Problema_7_Respuesta_Falsa_1;Respuesta_4  = Problema_7_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_7_Respuesta_Falsa_3;Respuesta_2  = Problema_7_Respuesta_Correcta;Respuesta_3 = Problema_7_Respuesta_Falsa_2;Respuesta_4  = Problema_7_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;

          }
        //}
      break;
      case 8:
        //if(Identificador_de_Problema[7]==0)
        //{
          Identificador_de_Problema[7]=1;
          Problema = Problema_8;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_8_Respuesta_Correcta;Respuesta_2 = Problema_8_Respuesta_Falsa_1;Respuesta_3  = Problema_8_Respuesta_Falsa_2;Respuesta_4  = Problema_8_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_8_Respuesta_Falsa_1;Respuesta_2  = Problema_8_Respuesta_Correcta;Respuesta_3 = Problema_8_Respuesta_Falsa_2;Respuesta_4  = Problema_8_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_5_Respuesta_Falsa_1;Respuesta_2  = Problema_5_Respuesta_Falsa_2;Respuesta_3  = Problema_5_Respuesta_Correcta;Respuesta_4 = Problema_5_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_8_Respuesta_Falsa_1;Respuesta_2  = Problema_8_Respuesta_Falsa_2;Respuesta_3  = Problema_8_Respuesta_Falsa_3;Respuesta_4  = Problema_8_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_8_Respuesta_Falsa_3;Respuesta_2  = Problema_8_Respuesta_Falsa_1;Respuesta_3  = Problema_8_Respuesta_Falsa_2;Respuesta_4  = Problema_8_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 6:Respuesta_1  = Problema_8_Respuesta_Falsa_2;Respuesta_2  = Problema_8_Respuesta_Falsa_1;Respuesta_3  = Problema_8_Respuesta_Falsa_3;Respuesta_4  = Problema_8_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_8_Respuesta_Correcta;Respuesta_2 = Problema_8_Respuesta_Falsa_3;Respuesta_3  = Problema_8_Respuesta_Falsa_2;Respuesta_4  = Problema_8_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_5_Respuesta_Correcta;Respuesta_2 = Problema_8_Respuesta_Falsa_2;Respuesta_3  = Problema_8_Respuesta_Falsa_1;Respuesta_4  = Problema_8_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_8_Respuesta_Correcta;Respuesta_2 = Problema_8_Respuesta_Falsa_3;Respuesta_3  = Problema_8_Respuesta_Falsa_1;Respuesta_4  = Problema_8_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_8_Respuesta_Falsa_2;Respuesta_2  = Problema_8_Respuesta_Falsa_1;Respuesta_3  = Problema_8_Respuesta_Correcta;Respuesta_4 = Problema_8_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 11:Respuesta_1 = Problema_8_Respuesta_Falsa_2;Respuesta_2  = Problema_8_Respuesta_Falsa_3;Respuesta_3  = Problema_8_Respuesta_Correcta;Respuesta_4 = Problema_8_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_8_Respuesta_Falsa_2;Respuesta_2  = Problema_8_Respuesta_Falsa_3;Respuesta_3  = Problema_8_Respuesta_Falsa_1;Respuesta_4  = Problema_8_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_8_Respuesta_Falsa_1;Respuesta_2  = Problema_8_Respuesta_Correcta;Respuesta_3 = Problema_8_Respuesta_Falsa_3;Respuesta_4  = Problema_8_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_8_Respuesta_Correcta;Respuesta_2 = Problema_8_Respuesta_Falsa_2;Respuesta_3  = Problema_8_Respuesta_Falsa_3;Respuesta_4  = Problema_8_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_8_Respuesta_Correcta;Respuesta_2 = Problema_8_Respuesta_Falsa_1;Respuesta_3  = Problema_8_Respuesta_Falsa_3;Respuesta_4  = Problema_8_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_8_Respuesta_Falsa_1;Respuesta_2  = Problema_8_Respuesta_Falsa_3;Respuesta_3  = Problema_8_Respuesta_Correcta;Respuesta_4 = Problema_8_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_8_Respuesta_Falsa_1;Respuesta_2  = Problema_8_Respuesta_Falsa_3;Respuesta_3  = Problema_8_Respuesta_Falsa_2;Respuesta_4  = Problema_8_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_8_Respuesta_Falsa_2;Respuesta_2  = Problema_8_Respuesta_Correcta;Respuesta_3 = Problema_8_Respuesta_Falsa_1;Respuesta_4  = Problema_8_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_8_Respuesta_Falsa_2;Respuesta_2  = Problema_8_Respuesta_Correcta;Respuesta_3 = Problema_8_Respuesta_Falsa_3;Respuesta_4  = Problema_8_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_8_Respuesta_Falsa_3;Respuesta_2  = Problema_8_Respuesta_Falsa_1;Respuesta_3  = Problema_8_Respuesta_Correcta;Respuesta_4 = Problema_8_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_8_Respuesta_Falsa_3;Respuesta_2  = Problema_8_Respuesta_Falsa_2;Respuesta_3  = Problema_8_Respuesta_Correcta;Respuesta_4 = Problema_8_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_8_Respuesta_Falsa_3;Respuesta_2  = Problema_8_Respuesta_Falsa_2;Respuesta_3  = Problema_8_Respuesta_Falsa_1;Respuesta_4  = Problema_8_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_8_Respuesta_Falsa_3;Respuesta_2  = Problema_8_Respuesta_Correcta;Respuesta_3 = Problema_8_Respuesta_Falsa_1;Respuesta_4  = Problema_8_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_8_Respuesta_Falsa_3;Respuesta_2  = Problema_8_Respuesta_Correcta;Respuesta_3 = Problema_8_Respuesta_Falsa_2;Respuesta_4  = Problema_8_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
          }
        //}
      break;
      case 9:
        //if(Identificador_de_Problema[8]==0)
        //{
          Identificador_de_Problema[8]=1;
          Problema = Problema_9;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_9_Respuesta_Correcta;Respuesta_2 = Problema_9_Respuesta_Falsa_1;Respuesta_3  = Problema_9_Respuesta_Falsa_2;Respuesta_4  = Problema_9_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_9_Respuesta_Falsa_1;Respuesta_2  = Problema_9_Respuesta_Correcta;Respuesta_3 = Problema_9_Respuesta_Falsa_2;Respuesta_4  = Problema_9_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_9_Respuesta_Falsa_1;Respuesta_2  = Problema_9_Respuesta_Falsa_2;Respuesta_3  = Problema_9_Respuesta_Correcta;Respuesta_4 = Problema_9_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_9_Respuesta_Falsa_1;Respuesta_2  = Problema_9_Respuesta_Falsa_2;Respuesta_3  = Problema_9_Respuesta_Falsa_3;Respuesta_4  = Problema_9_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_9_Respuesta_Falsa_3;Respuesta_2  = Problema_9_Respuesta_Falsa_1;Respuesta_3  = Problema_9_Respuesta_Falsa_2;Respuesta_4  = Problema_9_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 6:Respuesta_1  = Problema_9_Respuesta_Falsa_2;Respuesta_2  = Problema_9_Respuesta_Falsa_1;Respuesta_3  = Problema_9_Respuesta_Falsa_3;Respuesta_4  = Problema_9_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_9_Respuesta_Correcta;Respuesta_2 = Problema_9_Respuesta_Falsa_3;Respuesta_3  = Problema_9_Respuesta_Falsa_2;Respuesta_4  = Problema_9_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_9_Respuesta_Correcta;Respuesta_2 = Problema_9_Respuesta_Falsa_2;Respuesta_3  = Problema_9_Respuesta_Falsa_1;Respuesta_4  = Problema_9_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_9_Respuesta_Correcta;Respuesta_2 = Problema_9_Respuesta_Falsa_3;Respuesta_3  = Problema_9_Respuesta_Falsa_1;Respuesta_4  = Problema_9_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_9_Respuesta_Falsa_2;Respuesta_2  = Problema_9_Respuesta_Falsa_1;Respuesta_3  = Problema_9_Respuesta_Correcta;Respuesta_4 = Problema_9_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 11:Respuesta_1 = Problema_9_Respuesta_Falsa_2;Respuesta_2  = Problema_9_Respuesta_Falsa_3;Respuesta_3  = Problema_9_Respuesta_Correcta;Respuesta_4 = Problema_9_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_9_Respuesta_Falsa_2;Respuesta_2  = Problema_9_Respuesta_Falsa_3;Respuesta_3  = Problema_9_Respuesta_Falsa_1;Respuesta_4  = Problema_9_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_9_Respuesta_Falsa_1;Respuesta_2  = Problema_9_Respuesta_Correcta;Respuesta_3 = Problema_9_Respuesta_Falsa_3;Respuesta_4  = Problema_9_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_9_Respuesta_Correcta;Respuesta_2 = Problema_9_Respuesta_Falsa_2;Respuesta_3  = Problema_9_Respuesta_Falsa_3;Respuesta_4  = Problema_9_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_9_Respuesta_Correcta;Respuesta_2 = Problema_9_Respuesta_Falsa_1;Respuesta_3  = Problema_9_Respuesta_Falsa_3;Respuesta_4  = Problema_9_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_9_Respuesta_Falsa_1;Respuesta_2  = Problema_9_Respuesta_Falsa_3;Respuesta_3  = Problema_9_Respuesta_Correcta;Respuesta_4 = Problema_9_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_9_Respuesta_Falsa_1;Respuesta_2  = Problema_9_Respuesta_Falsa_3;Respuesta_3  = Problema_9_Respuesta_Falsa_2;Respuesta_4  = Problema_9_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_9_Respuesta_Falsa_2;Respuesta_2  = Problema_9_Respuesta_Correcta;Respuesta_3 = Problema_9_Respuesta_Falsa_1;Respuesta_4  = Problema_9_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_9_Respuesta_Falsa_2;Respuesta_2  = Problema_9_Respuesta_Correcta;Respuesta_3 = Problema_9_Respuesta_Falsa_3;Respuesta_4  = Problema_9_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_9_Respuesta_Falsa_3;Respuesta_2  = Problema_9_Respuesta_Falsa_1;Respuesta_3  = Problema_9_Respuesta_Correcta;Respuesta_4 = Problema_9_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_9_Respuesta_Falsa_3;Respuesta_2  = Problema_9_Respuesta_Falsa_2;Respuesta_3  = Problema_9_Respuesta_Correcta;Respuesta_4 = Problema_9_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_9_Respuesta_Falsa_3;Respuesta_2  = Problema_9_Respuesta_Falsa_2;Respuesta_3  = Problema_9_Respuesta_Falsa_1;Respuesta_4  = Problema_9_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_9_Respuesta_Falsa_3;Respuesta_2  = Problema_9_Respuesta_Correcta;Respuesta_3 = Problema_9_Respuesta_Falsa_1;Respuesta_4  = Problema_9_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_9_Respuesta_Falsa_3;Respuesta_2  = Problema_9_Respuesta_Correcta;Respuesta_3 = Problema_9_Respuesta_Falsa_2;Respuesta_4  = Problema_9_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
          }
        //}
      break;
      case 10:
        //if(Identificador_de_Problema[9]==0)
        //{
          Identificador_de_Problema[9]=1;
          Problema = Problema_10;
          switch(Numero_Random_24)
          {
            case 1:Respuesta_1  = Problema_10_Respuesta_Correcta;Respuesta_2 = Problema_10_Respuesta_Falsa_1;Respuesta_3  = Problema_10_Respuesta_Falsa_2;Respuesta_4  = Problema_10_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 2:Respuesta_1  = Problema_10_Respuesta_Falsa_1;Respuesta_2  = Problema_10_Respuesta_Correcta;Respuesta_3 = Problema_10_Respuesta_Falsa_2;Respuesta_4  = Problema_10_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 3:Respuesta_1  = Problema_10_Respuesta_Falsa_1;Respuesta_2  = Problema_10_Respuesta_Falsa_2;Respuesta_3  = Problema_10_Respuesta_Correcta;Respuesta_4 = Problema_10_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 4:Respuesta_1  = Problema_10_Respuesta_Falsa_1;Respuesta_2  = Problema_10_Respuesta_Falsa_2;Respuesta_3  = Problema_10_Respuesta_Falsa_3;Respuesta_4  = Problema_10_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 5:Respuesta_1  = Problema_10_Respuesta_Falsa_3;Respuesta_2  = Problema_10_Respuesta_Falsa_1;Respuesta_3  = Problema_10_Respuesta_Falsa_2;Respuesta_4  = Problema_10_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 6:Respuesta_1  = Problema_10_Respuesta_Falsa_2;Respuesta_2  = Problema_10_Respuesta_Falsa_1;Respuesta_3  = Problema_10_Respuesta_Falsa_3;Respuesta_4  = Problema_10_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 7:Respuesta_1  = Problema_10_Respuesta_Correcta;Respuesta_2 = Problema_10_Respuesta_Falsa_3;Respuesta_3  = Problema_10_Respuesta_Falsa_2;Respuesta_4  = Problema_10_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 8:Respuesta_1  = Problema_10_Respuesta_Correcta;Respuesta_2 = Problema_10_Respuesta_Falsa_2;Respuesta_3  = Problema_10_Respuesta_Falsa_1;Respuesta_4  = Problema_10_Respuesta_Falsa_3;La_Respuesta_es  = 1;break;
            case 9:Respuesta_1  = Problema_10_Respuesta_Correcta;Respuesta_2 = Problema_10_Respuesta_Falsa_3;Respuesta_3  = Problema_10_Respuesta_Falsa_1;Respuesta_4  = Problema_10_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 10:Respuesta_1 = Problema_10_Respuesta_Falsa_2;Respuesta_2  = Problema_10_Respuesta_Falsa_1;Respuesta_3  = Problema_10_Respuesta_Correcta;Respuesta_4 = Problema_10_Respuesta_Falsa_3;La_Respuesta_es  = 3;break;
            case 11:Respuesta_1 = Problema_10_Respuesta_Falsa_2;Respuesta_2  = Problema_10_Respuesta_Falsa_3;Respuesta_3  = Problema_10_Respuesta_Correcta;Respuesta_4 = Problema_10_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 12:Respuesta_1 = Problema_10_Respuesta_Falsa_2;Respuesta_2  = Problema_10_Respuesta_Falsa_3;Respuesta_3  = Problema_10_Respuesta_Falsa_1;Respuesta_4  = Problema_10_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 13:Respuesta_1 = Problema_10_Respuesta_Falsa_1;Respuesta_2  = Problema_10_Respuesta_Correcta;Respuesta_3 = Problema_10_Respuesta_Falsa_3;Respuesta_4  = Problema_10_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 14:Respuesta_1 = Problema_10_Respuesta_Correcta;Respuesta_2 = Problema_10_Respuesta_Falsa_2;Respuesta_3  = Problema_10_Respuesta_Falsa_3;Respuesta_4  = Problema_10_Respuesta_Falsa_1;La_Respuesta_es  = 1;break;
            case 15:Respuesta_1 = Problema_10_Respuesta_Correcta;Respuesta_2 = Problema_10_Respuesta_Falsa_1;Respuesta_3  = Problema_10_Respuesta_Falsa_3;Respuesta_4  = Problema_10_Respuesta_Falsa_2;La_Respuesta_es  = 1;break;
            case 16:Respuesta_1 = Problema_10_Respuesta_Falsa_1;Respuesta_2  = Problema_10_Respuesta_Falsa_3;Respuesta_3  = Problema_10_Respuesta_Correcta;Respuesta_4 = Problema_10_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 17:Respuesta_1 = Problema_10_Respuesta_Falsa_1;Respuesta_2  = Problema_10_Respuesta_Falsa_3;Respuesta_3  = Problema_10_Respuesta_Falsa_2;Respuesta_4  = Problema_10_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 18:Respuesta_1 = Problema_10_Respuesta_Falsa_2;Respuesta_2  = Problema_10_Respuesta_Correcta;Respuesta_3 = Problema_10_Respuesta_Falsa_1;Respuesta_4  = Problema_10_Respuesta_Falsa_3;La_Respuesta_es  = 2;break;
            case 19:Respuesta_1 = Problema_10_Respuesta_Falsa_2;Respuesta_2  = Problema_10_Respuesta_Correcta;Respuesta_3 = Problema_10_Respuesta_Falsa_3;Respuesta_4  = Problema_10_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;
            case 20:Respuesta_1 = Problema_10_Respuesta_Falsa_3;Respuesta_2  = Problema_10_Respuesta_Falsa_1;Respuesta_3  = Problema_10_Respuesta_Correcta;Respuesta_4 = Problema_10_Respuesta_Falsa_2;La_Respuesta_es  = 3;break;
            case 21:Respuesta_1 = Problema_10_Respuesta_Falsa_3;Respuesta_2  = Problema_10_Respuesta_Falsa_2;Respuesta_3  = Problema_10_Respuesta_Correcta;Respuesta_4 = Problema_10_Respuesta_Falsa_1;La_Respuesta_es  = 3;break;
            case 22:Respuesta_1 = Problema_10_Respuesta_Falsa_3;Respuesta_2  = Problema_10_Respuesta_Falsa_2;Respuesta_3  = Problema_10_Respuesta_Falsa_1;Respuesta_4  = Problema_10_Respuesta_Correcta;La_Respuesta_es = 4;break;
            case 23:Respuesta_1 = Problema_10_Respuesta_Falsa_3;Respuesta_2  = Problema_10_Respuesta_Correcta;Respuesta_3 = Problema_10_Respuesta_Falsa_1;Respuesta_4  = Problema_10_Respuesta_Falsa_2;La_Respuesta_es  = 2;break;
            case 24:Respuesta_1 = Problema_10_Respuesta_Falsa_3;Respuesta_2  = Problema_10_Respuesta_Correcta;Respuesta_3 = Problema_10_Respuesta_Falsa_2;Respuesta_4  = Problema_10_Respuesta_Falsa_1;La_Respuesta_es  = 2;break;

          }
        //}
      break;
    }
  }
}

void Tiempo()
{
    milisegundo++;
      if(milisegundo == 10)
      {
        segundo++;
        milisegundo=0;
      }

      if(segundo == 60)
      {
        minuto++;
        segundo=0;
      }

      if(minuto == 60)
      {
        hora++;
        minuto=0;
      }
    }


void Registro()
{
	while ( !salida_Registro )
  {
    textprintf(screen,font,180,110,palette_color[10],"%d", Puntuacion );
    //******************************************[ACEPTAR]************************************************//
    if ( mouse_x > 230 && mouse_x < 325 &&
    mouse_y > 273 && mouse_y < 296)
    {
      blit(Registrar_Aceptar, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        escribir(); // manda a llamar a funcion escribir del archivo "funciones.h"
        //total=win+lose; // saca la suma de la spartidas ganadas y perdidas
        insertar(&inicio_nodo,&empiezo_nodo,id,nick,Puntuacion); // las manda a insertar una funcion que se encuentra aqui hasta a abjo
        REGISTRAR(inicio_nodo); // se registran en el archivo, de igualmare es una fuincion que sta en "funciones.h"
        //id++; // todas las variables se convierten en 0para el nueo jugador




        salida_Registro = true;
        confirmar= true;
      }
    }
    //******************************************[CANCELAR]************************************************//

    else if ( mouse_x > 53 && mouse_x < 148 &&
    mouse_y > 273 && mouse_y < 296)
    {
      if(Permite_Cancelar_Registro == false)
      {
        blit(Registrar_Cancelar, buffer, 0, 0, 0, 0, ANCHO, ALTO);
        if ( mouse_b & 1 )
        {
          salida_Registro = true;
        }
      }
    }


    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Registrar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    //printf("X: [%d] | Y: [%d] \n",mouse_x,mouse_y);
    // se muestra todo por pantalla
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    //clear(buffer);

  }
    salida_Registro = false;
}

//______________________________________________________________________________________________________________




















void Jugar_Alto()
{
  Problema_1 = load_bitmap("Img/Problemas/problema_21/Problema.bmp",NULL);
    Problema_1_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_21/Correcta.bmp",NULL);
    Problema_1_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_21/Falsa_1.bmp",NULL);
    Problema_1_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_21/Falsa_2.bmp",NULL);
    Problema_1_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_21/Falsa_3.bmp",NULL);

  Problema_2 = load_bitmap("Img/Problemas/problema_22/Problema.bmp",NULL);
    Problema_2_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_22/Correcta.bmp",NULL);
    Problema_2_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_22/Falsa_1.bmp",NULL);
    Problema_2_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_22/Falsa_2.bmp",NULL);
    Problema_2_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_22/Falsa_3.bmp",NULL);

  Problema_3 = load_bitmap("Img/Problemas/problema_23/Problema.bmp",NULL);
    Problema_3_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_23/Correcta.bmp",NULL);
    Problema_3_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_23/Falsa_1.bmp",NULL);
    Problema_3_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_23/Falsa_2.bmp",NULL);
    Problema_3_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_23/Falsa_3.bmp",NULL);

  Problema_4 = load_bitmap("Img/Problemas/problema_24/Problema.bmp",NULL);
    Problema_4_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_24/Correcta.bmp",NULL);
    Problema_4_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_24/Falsa_1.bmp",NULL);
    Problema_4_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_24/Falsa_2.bmp",NULL);
    Problema_4_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_24/Falsa_3.bmp",NULL);

  Problema_5 = load_bitmap("Img/Problemas/problema_25/Problema.bmp",NULL);
    Problema_5_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_25/Correcta.bmp",NULL);
    Problema_5_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_25/Falsa_1.bmp",NULL);
    Problema_5_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_25/Falsa_2.bmp",NULL);
    Problema_5_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_25/Falsa_3.bmp",NULL);

  Problema_6 = load_bitmap("Img/Problemas/problema_26/Problema.bmp",NULL);
    Problema_6_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_26/Correcta.bmp",NULL);
    Problema_6_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_26/Falsa_1.bmp",NULL);
    Problema_6_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_26/Falsa_2.bmp",NULL);
    Problema_6_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_26/Falsa_3.bmp",NULL);

  Problema_7 = load_bitmap("Img/Problemas/problema_27/Problema.bmp",NULL);
    Problema_7_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_27/Correcta.bmp",NULL);
    Problema_7_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_27/Falsa_1.bmp",NULL);
    Problema_7_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_27/Falsa_2.bmp",NULL);
    Problema_7_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_27/Falsa_3.bmp",NULL);

  Problema_8 = load_bitmap("Img/Problemas/problema_28/Problema.bmp",NULL);
    Problema_8_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_28/Correcta.bmp",NULL);
    Problema_8_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_28/Falsa_1.bmp",NULL);
    Problema_8_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_28/Falsa_2.bmp",NULL);
    Problema_8_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_28/Falsa_3.bmp",NULL);

  Problema_9 = load_bitmap("Img/Problemas/problema_29/Problema.bmp",NULL);
    Problema_9_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_29/Correcta.bmp",NULL);
    Problema_9_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_29/Falsa_1.bmp",NULL);
    Problema_9_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_29/Falsa_2.bmp",NULL);
    Problema_9_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_29/Falsa_3.bmp",NULL);

  Problema_10 = load_bitmap("Img/Problemas/problema_30/Problema.bmp",NULL);
    Problema_10_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_30/Correcta.bmp",NULL);
    Problema_10_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_30/Falsa_1.bmp",NULL);
    Problema_10_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_30/Falsa_2.bmp",NULL);
    Problema_10_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_30/Falsa_3.bmp",NULL);

  Generar_Imagenes_Random();

  while ( !salida_Nivel_Alto )
  {
    printf("Num 10:%d - Num 24:%d - R:%d - Cont:%d \n",Numero_Random_10, Numero_Random_24, La_Respuesta_es, Contador_Entrada_Funcion );
    textprintf(screen,font,263,25,palette_color[10],"%d:", minuto );
    textprintf(screen,font,279,25,palette_color[10],"%d", segundo );

    textprintf(screen,font,109,25,palette_color[10],"%d", Puntuacion );
    //******************************************[FUNCION DE TERMINAR JUEGO]************************************************//
    if(Contador_Entrada_Funcion == 6)
    {
      Permite_Cancelar_Registro = true;
      Registro();
        if(confirmar == true)
        {
            salida_Nivel_Alto = true;
        }
      }
    //******************************************[OPCION SALIR]************************************************//
    if ( mouse_x > 347 && mouse_x < 370 &&
    mouse_y > 552 && mouse_y < 575)
    {
      blit(Jugar_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Registro();
        if(confirmar == true)
        {
            salida_Nivel_Alto = true;
        }
      }
    }
    //******************************************[IZQUIERDA ARRIBA (1)]************************************************//
    else if ( mouse_x > 76 && mouse_x < 173 &&
    mouse_y > 388 && mouse_y < 452)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 1)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[DERECHA ARRIBA (2)]************************************************//
    else if ( mouse_x > 196 && mouse_x < 292 &&
    mouse_y > 388 && mouse_y < 452)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 2)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[IZQUIERDA ABAJO (3)]************************************************//
    else if ( mouse_x > 76 && mouse_x < 173 &&
    mouse_y > 465 && mouse_y < 534)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 3)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[DERECHA ABAJO (4)]************************************************//
    else if ( mouse_x > 196 && mouse_x < 292 &&
    mouse_y > 465 && mouse_y < 534)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 4)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }

        //rest(20);
        cont++;
        if(cont==2)
        {
          Tiempo();
          cont=0;
        }

    draw_sprite(buffer,Problema, 23,70);

    draw_sprite(buffer,Respuesta_1, 77,388);

    draw_sprite(buffer,Respuesta_2, 195,388);

    draw_sprite(buffer,Respuesta_3, 77,469);

    draw_sprite(buffer,Respuesta_4, 195,469);

    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);

    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
  }
  salida_Nivel_Bajo = false;
  salida_Nivel_Medio = false;
  salida_Nivel_Alto = false;
  confirmar = false;
  Contador_Entrada_Funcion = 0;
  Permite_Cancelar_Registro = false;
  Puerta_Entrada = false;
}











//______________________________________________________________________________________________________________
void Jugar_Medio()
{
  Problema_1 = load_bitmap("Img/Problemas/problema_11/Problema.bmp",NULL);
    Problema_1_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_11/Correcta.bmp",NULL);
    Problema_1_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_11/Falsa_1.bmp",NULL);
    Problema_1_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_11/Falsa_2.bmp",NULL);
    Problema_1_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_11/Falsa_3.bmp",NULL);

  Problema_2 = load_bitmap("Img/Problemas/problema_12/Problema.bmp",NULL);
    Problema_2_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_12/Correcta.bmp",NULL);
    Problema_2_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_12/Falsa_1.bmp",NULL);
    Problema_2_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_12/Falsa_2.bmp",NULL);
    Problema_2_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_12/Falsa_3.bmp",NULL);

  Problema_3 = load_bitmap("Img/Problemas/problema_13/Problema.bmp",NULL);
    Problema_3_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_13/Correcta.bmp",NULL);
    Problema_3_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_13/Falsa_1.bmp",NULL);
    Problema_3_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_13/Falsa_2.bmp",NULL);
    Problema_3_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_13/Falsa_3.bmp",NULL);

  Problema_4 = load_bitmap("Img/Problemas/problema_14/Problema.bmp",NULL);
    Problema_4_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_14/Correcta.bmp",NULL);
    Problema_4_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_14/Falsa_1.bmp",NULL);
    Problema_4_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_14/Falsa_2.bmp",NULL);
    Problema_4_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_14/Falsa_3.bmp",NULL);

  Problema_5 = load_bitmap("Img/Problemas/problema_15/Problema.bmp",NULL);
    Problema_5_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_15/Correcta.bmp",NULL);
    Problema_5_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_15/Falsa_1.bmp",NULL);
    Problema_5_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_15/Falsa_2.bmp",NULL);
    Problema_5_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_15/Falsa_3.bmp",NULL);

  Problema_6 = load_bitmap("Img/Problemas/problema_16/Problema.bmp",NULL);
    Problema_6_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_16/Correcta.bmp",NULL);
    Problema_6_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_16/Falsa_1.bmp",NULL);
    Problema_6_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_16/Falsa_2.bmp",NULL);
    Problema_6_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_16/Falsa_3.bmp",NULL);

  Problema_7 = load_bitmap("Img/Problemas/problema_17/Problema.bmp",NULL);
    Problema_7_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_17/Correcta.bmp",NULL);
    Problema_7_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_17/Falsa_1.bmp",NULL);
    Problema_7_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_17/Falsa_2.bmp",NULL);
    Problema_7_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_17/Falsa_3.bmp",NULL);

  Problema_8 = load_bitmap("Img/Problemas/problema_18/Problema.bmp",NULL);
    Problema_8_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_18/Correcta.bmp",NULL);
    Problema_8_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_18/Falsa_1.bmp",NULL);
    Problema_8_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_18/Falsa_2.bmp",NULL);
    Problema_8_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_18/Falsa_3.bmp",NULL);

  Problema_9 = load_bitmap("Img/Problemas/problema_19/Problema.bmp",NULL);
    Problema_9_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_19/Correcta.bmp",NULL);
    Problema_9_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_19/Falsa_1.bmp",NULL);
    Problema_9_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_19/Falsa_2.bmp",NULL);
    Problema_9_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_19/Falsa_3.bmp",NULL);

  Problema_10 = load_bitmap("Img/Problemas/problema_20/Problema.bmp",NULL);
    Problema_10_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_20/Correcta.bmp",NULL);
    Problema_10_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_20/Falsa_1.bmp",NULL);
    Problema_10_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_20/Falsa_2.bmp",NULL);
    Problema_10_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_20/Falsa_3.bmp",NULL);

  Generar_Imagenes_Random();

  while ( !salida_Nivel_Medio )
  {
    printf("Num 10:%d - Num 24:%d - R:%d - Cont:%d \n",Numero_Random_10, Numero_Random_24, La_Respuesta_es, Contador_Entrada_Funcion );
    textprintf(screen,font,263,25,palette_color[10],"%d:", minuto );
    textprintf(screen,font,279,25,palette_color[10],"%d", segundo );

    textprintf(screen,font,109,25,palette_color[10],"%d", Puntuacion );
    //******************************************[FUNCION DE TERMINAR JUEGO]************************************************//
    if(Contador_Entrada_Funcion == 6)
    {
      Permite_Cancelar_Registro = true;
      Registro();
        if(confirmar == true)
        {
            salida_Nivel_Medio = true;
        }
      }
    //******************************************[OPCION SALIR]************************************************//
    if ( mouse_x > 347 && mouse_x < 370 &&
    mouse_y > 552 && mouse_y < 575)
    {
      blit(Jugar_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Registro();
        if(confirmar == true)
        {
            salida_Nivel_Medio = true;
        }
      }
    }
    //******************************************[IZQUIERDA ARRIBA (1)]************************************************//
    else if ( mouse_x > 76 && mouse_x < 173 &&
    mouse_y > 388 && mouse_y < 452)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 1)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[DERECHA ARRIBA (2)]************************************************//
    else if ( mouse_x > 196 && mouse_x < 292 &&
    mouse_y > 388 && mouse_y < 452)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 2)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[IZQUIERDA ABAJO (3)]************************************************//
    else if ( mouse_x > 76 && mouse_x < 173 &&
    mouse_y > 465 && mouse_y < 534)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 3)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[DERECHA ABAJO (4)]************************************************//
    else if ( mouse_x > 196 && mouse_x < 292 &&
    mouse_y > 465 && mouse_y < 534)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 4)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }

        //rest(20);
        cont++;
        if(cont==2)
        {
          Tiempo();
          cont=0;
        }

    draw_sprite(buffer,Problema, 23,70);

    draw_sprite(buffer,Respuesta_1, 77,388);

    draw_sprite(buffer,Respuesta_2, 195,388);

    draw_sprite(buffer,Respuesta_3, 77,469);

    draw_sprite(buffer,Respuesta_4, 195,469);

    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);

    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);

  }
  salida_Nivel_Bajo = false;
  salida_Nivel_Medio = false;
  salida_Nivel_Alto = false;
  confirmar = false;
  Contador_Entrada_Funcion = 0;
  Permite_Cancelar_Registro = false;
  Puerta_Entrada = false;
}


























//______________________________________________________________________________________________________________
void Jugar_Bajo()
{
  Problema_1 = load_bitmap("Img/Problemas/problema_1/Problema.bmp",NULL);
    Problema_1_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_1/Correcta.bmp",NULL);
    Problema_1_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_1/Falsa_1.bmp",NULL);
    Problema_1_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_1/Falsa_2.bmp",NULL);
    Problema_1_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_1/Falsa_3.bmp",NULL);

  Problema_2 = load_bitmap("Img/Problemas/problema_2/Problema.bmp",NULL);
    Problema_2_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_2/Correcta.bmp",NULL);
    Problema_2_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_2/Falsa_1.bmp",NULL);
    Problema_2_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_2/Falsa_2.bmp",NULL);
    Problema_2_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_2/Falsa_3.bmp",NULL);

  Problema_3 = load_bitmap("Img/Problemas/problema_3/Problema.bmp",NULL);
    Problema_3_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_3/Correcta.bmp",NULL);
    Problema_3_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_3/Falsa_1.bmp",NULL);
    Problema_3_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_3/Falsa_2.bmp",NULL);
    Problema_3_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_3/Falsa_3.bmp",NULL);

  Problema_4 = load_bitmap("Img/Problemas/problema_4/Problema.bmp",NULL);
    Problema_4_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_4/Correcta.bmp",NULL);
    Problema_4_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_4/Falsa_1.bmp",NULL);
    Problema_4_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_4/Falsa_2.bmp",NULL);
    Problema_4_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_4/Falsa_3.bmp",NULL);

  Problema_5 = load_bitmap("Img/Problemas/problema_5/Problema.bmp",NULL);
    Problema_5_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_5/Correcta.bmp",NULL);
    Problema_5_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_5/Falsa_1.bmp",NULL);
    Problema_5_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_5/Falsa_2.bmp",NULL);
    Problema_5_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_5/Falsa_3.bmp",NULL);

  Problema_6 = load_bitmap("Img/Problemas/problema_6/Problema.bmp",NULL);
    Problema_6_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_6/Correcta.bmp",NULL);
    Problema_6_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_6/Falsa_1.bmp",NULL);
    Problema_6_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_6/Falsa_2.bmp",NULL);
    Problema_6_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_6/Falsa_3.bmp",NULL);

  Problema_7 = load_bitmap("Img/Problemas/problema_7/Problema.bmp",NULL);
    Problema_7_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_7/Correcta.bmp",NULL);
    Problema_7_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_7/Falsa_1.bmp",NULL);
    Problema_7_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_7/Falsa_2.bmp",NULL);
    Problema_7_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_7/Falsa_3.bmp",NULL);

  Problema_8 = load_bitmap("Img/Problemas/problema_8/Problema.bmp",NULL);
    Problema_8_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_8/Correcta.bmp",NULL);
    Problema_8_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_8/Falsa_1.bmp",NULL);
    Problema_8_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_8/Falsa_2.bmp",NULL);
    Problema_8_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_8/Falsa_3.bmp",NULL);

  Problema_9 = load_bitmap("Img/Problemas/problema_9/Problema.bmp",NULL);
    Problema_9_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_9/Correcta.bmp",NULL);
    Problema_9_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_9/Falsa_1.bmp",NULL);
    Problema_9_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_9/Falsa_2.bmp",NULL);
    Problema_9_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_9/Falsa_3.bmp",NULL);

  Problema_10 = load_bitmap("Img/Problemas/problema_10/Problema.bmp",NULL);
    Problema_10_Respuesta_Correcta = load_bitmap("Img/Problemas/problema_10/Correcta.bmp",NULL);
    Problema_10_Respuesta_Falsa_1 = load_bitmap("Img/Problemas/problema_10/Falsa_1.bmp",NULL);
    Problema_10_Respuesta_Falsa_2 = load_bitmap("Img/Problemas/problema_10/Falsa_2.bmp",NULL);
    Problema_10_Respuesta_Falsa_3 = load_bitmap("Img/Problemas/problema_10/Falsa_3.bmp",NULL);

  Generar_Imagenes_Random();

  while ( !salida_Nivel_Bajo )
  {
    printf("Num 10:%d - Num 24:%d - R:%d - Cont:%d \n",Numero_Random_10, Numero_Random_24, La_Respuesta_es, Contador_Entrada_Funcion );
    textprintf(screen,font,263,25,palette_color[10],"%d:", minuto );
    textprintf(screen,font,279,25,palette_color[10],"%d", segundo );

    textprintf(screen,font,109,25,palette_color[10],"%d", Puntuacion );
    //******************************************[FUNCION DE TERMINAR JUEGO]************************************************//
    if(Contador_Entrada_Funcion == 6)
    {
      Permite_Cancelar_Registro = true;
      Registro();
        if(confirmar == true)
        {
            salida_Nivel_Bajo = true;
        }
      }
    //******************************************[OPCION SALIR]************************************************//
    if ( mouse_x > 347 && mouse_x < 370 &&
    mouse_y > 552 && mouse_y < 575)
    {
      blit(Jugar_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Registro();
        if(confirmar == true)
        {
            salida_Nivel_Bajo = true;
        }
      }
    }
    //******************************************[IZQUIERDA ARRIBA (1)]************************************************//
    else if ( mouse_x > 76 && mouse_x < 173 &&
    mouse_y > 388 && mouse_y < 452)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 1)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[DERECHA ARRIBA (2)]************************************************//
    else if ( mouse_x > 196 && mouse_x < 292 &&
    mouse_y > 388 && mouse_y < 452)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 2)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[IZQUIERDA ABAJO (3)]************************************************//
    else if ( mouse_x > 76 && mouse_x < 173 &&
    mouse_y > 465 && mouse_y < 534)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 3)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[DERECHA ABAJO (4)]************************************************//
    else if ( mouse_x > 196 && mouse_x < 292 &&
    mouse_y > 465 && mouse_y < 534)
    {
      if ( mouse_b & 1 )
      {
        Puerta_Entrada = false;
        if(La_Respuesta_es == 4)
        {
          printf("Correcta");
          Puntuacion = Puntuacion + 10;
          Generar_Imagenes_Random();
        }
      }
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Jugar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }

        //rest(20);
        cont++;
        if(cont==2)
        {
          Tiempo();
          cont=0;
        }

    draw_sprite(buffer,Problema, 23,70);

    draw_sprite(buffer,Respuesta_1, 77,388);

    draw_sprite(buffer,Respuesta_2, 195,388);

    draw_sprite(buffer,Respuesta_3, 77,469);

    draw_sprite(buffer,Respuesta_4, 195,469);

    //masked_blit(Problema, buffer, 0, 0, 23, 70, 333,219);

    //masked_blit(Respuesta_1, buffer, 0, 0, 77, 388, 99,66); //izquiera arriba

    //masked_blit(Respuesta_2, buffer, 0, 0, 195, 388, 99,66); /// derechea arriba  //ya

    //masked_blit(Respuesta_3, buffer, 0, 0, 77, 469, 99,66);  // izuierda  abajo

    //masked_blit(Respuesta_4, buffer, 0, 0, 195, 469, 99,66);  //derecha abajo

    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);

    //textprintf(buffer, font, 146, 25, makecol(255, 0, 0), "%d:", minuto);
    //textprintf(buffer, font, 150, 25, makecol(255, 0, 0), "  %d",  segundo);


    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    //clear(buffer);
  }
  salida_Nivel_Bajo = false;
  salida_Nivel_Medio = false;
  salida_Nivel_Alto = false;
  confirmar = false;
  Contador_Entrada_Funcion = 0;
  Permite_Cancelar_Registro = false;
  Puerta_Entrada = false;
}


























//______________________________________________________________________________________________________________
void Seleccionar()
{
  while ( !salida_Seleccionar )
  {
  //******************************************[OPCION SALIDA]************************************************//
    if ( mouse_x > 347 && mouse_x < 370 &&
    mouse_y > 552 && mouse_y < 575)
    {
      blit(Seleccionar_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        salida_Seleccionar = true;
      }
    }
    //******************************************[NIVEL ALTO]************************************************//
    else if ( mouse_x > 129 && mouse_x < 247 &&
    mouse_y > 108 && mouse_y < 138)
    {
      blit(Seleccionar_Alto, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Jugar_Alto();
        salida_Seleccionar = true;
    }
    //******************************************[NIVEL MEDIO]************************************************//
    else if ( mouse_x > 129 && mouse_x < 247 &&
    mouse_y > 153 && mouse_y < 181)
    {
      blit(Seleccionar_Medio, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Jugar_Medio();
        salida_Seleccionar = true;
      }
    }
    //******************************************[NIVEL BAJO]************************************************//
    else if ( mouse_x > 129 && mouse_x < 247 &&
    mouse_y > 200 && mouse_y < 232)
    {
      blit(Seleccionar_Bajo, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Jugar_Bajo();
        salida_Seleccionar = true;
      }
      //if (salida_Seleccionar==true)
        //{
          //Menu();
        //}
    }
    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Seleccionar_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);
  }
  salida_Seleccionar = false;
}
//______________________________________________________________________________________________________________
void Tablero()
{
  while ( !salida_Tablero )
  {
    if ( mouse_x > 347 && mouse_x < 370 &&
    mouse_y > 552 && mouse_y < 575)
    {
      blit(Tablero_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        salida_Tablero = true;
      }
    }
    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Tablero_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      CARGAR();

    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);
  }
  salida_Tablero = false;
}

//______________________________________________________________________________________________________________//
void Ayuda()
{
  while ( !salida_Ayuda )
  {
  //***************************************************[OPION SALIR]************************************************//
  if ( mouse_x > 347 && mouse_x < 370 &&
  mouse_y > 552 && mouse_y < 575)
    {
      blit(Ayuda_Salir, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        salida_Ayuda = true;
      }
    }
    //******************************************[NO SELECCIONO NADA]************************************************//
    else
    {
      blit(Ayuda_Normal, buffer, 0, 0, 0, 0, ANCHO, ALTO);
    }
    masked_blit(Puntero, buffer, 0, 0, mouse_x, mouse_y, 13,22);
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);
  }
  salida_Ayuda = false;
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

  Seleccionar_Alto = load_bitmap("Img/Seleccionar/Seleccionar_Alto.bmp",NULL);
  Seleccionar_Medio = load_bitmap("Img/Seleccionar/Seleccionar_Medio.bmp",NULL);
  Seleccionar_Bajo = load_bitmap("Img/Seleccionar/Seleccionar_Bajo.bmp",NULL);
  Seleccionar_Normal = load_bitmap("Img/Seleccionar/Seleccionar_Normal.bmp",NULL);
  Seleccionar_Salir = load_bitmap("Img/Seleccionar/Seleccionar_Salir.bmp",NULL);
  while ( !salida )
	{
    //*****************************************************[JUGAR]*********************************************//
    if ( mouse_x > 162 && mouse_x < 334 &&
    mouse_y > 228 && mouse_y < 257)
    {
      blit(Menu_Jugar, buffer, 0, 0, 0, 0, ANCHO, ALTO);
      if ( mouse_b & 1 )
      {
        Seleccionar();
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
    //printf("X: [%d] | Y: [%d] \n",mouse_x,mouse_y);
    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
    clear(buffer);
  }
}

int main()
{
  srand(time(NULL)); // reinicia la semilla del numero random para que este no sea igual ada vez que se ejecute.
    Ajustar_Arrays();

    Inicio();

    Menu();

    Final();
}
END_OF_MAIN();




// aqui se iniciaiza la memoria dinamica
int esvacia(NODOPTR ptr){//esto nos permite saer si la primera hubicacion de lammoria diamica es Null
  return ptr==NULL;
}

void insertar(NODOPTR*ptr,NODOPTR *eptr,int id,char *nick,int Puntuacion)//aqui resive todos los valores que previamente le mandamos
{
  NODOPTR nuevo,actual,antes;// crea 3 punteros
  nuevo=(NODO *)malloc(sizeof(NODO)); // crea el tamaño de la memoria dinamica
  if(nuevo == NULL)// si la memoria dinamica no se creo bien dara el siguinete mensaje de error
     textprintf_ex(screen,font,650, 0,0xffffff, -1,"valor no insertado");
  else{

    if(esvacia(*ptr)){ // aqui verifica si la primera posiciones nula los datos se insertaran
      //aqui todos los datos sealamcenaran a al memoria dinamica
      nuevo->id=id;

      strcpy(nuevo->nick,nick); // strcpy copia una cadea de caracteres a otra
      strcpy(temporal.nick,nuevo->nick);

      nuevo->Puntuacion=Puntuacion; //esto funciona solo para los valores enteros y flotantes



      *ptr= nuevo; // ase un paso de informacion esperando que resiva nueva informacion
      *eptr=*ptr;
      nuevo->next=*ptr; //avansa de posicion la memoria dinamica
    }
    else{// si la primera posicion de la memori dinamica esta ocupada entrara aqui
      // se hace lo mismo que arriba
      nuevo->id=id;
      strcpy(nuevo->nick,nick);
      strcpy(temporal.nick,nuevo->nick);
      nuevo->Puntuacion=Puntuacion;
      antes=NULL;
      actual= *eptr;
      //puntuaciones


    while(actual != NULL && id>actual -> Puntuacion) //aqui es donde  se empiesa a recorrer la memoria dinamica.
    {

      antes= actual;
      actual = nuevo->next;
    }
    if(antes == NULL){
      nuevo->next =*eptr;
      *ptr=nuevo;
    }
    else{
      antes->next=nuevo;
      nuevo->next= actual;
      nuevo->next =*eptr;

      }

  }
  }
 }

