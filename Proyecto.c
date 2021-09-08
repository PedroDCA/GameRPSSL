//Autores: Pedro Calderon y Matthew Solano
//Fecha: 27/10
//Descripcion: Este algoritmo realiza el juego el cual es piedra, papel, tijera, lagarto, spock. Se puede seleccionar hasta cuantos puntos para ganar o si 1 o 2 jugadores
#include <stdio.h>
void main() //Funcion principal, se escoge a cuantos puntos es para ganar
{
    int turn=0;
    printf("Bienvenido a Piedra, Papel, Tijera, Lagarto, Spock\n");
    do
    {
        printf("Escriba 1 para ganar a los tres puntos, 2 para ganar a los cinco puntos o 3 para salir\n");
        scanf("%i",&turn);
        if (turn==1 || turn==2)
        {
            system("cls");

            play(turn);
        }
        if (turn<1 || turn>3)
        {
            system("cls");
            printf("Digite una opcion valida\n");
        }
    } while (turn!=3);
    printf("Gracias por jugar");
}
void play(int turn) //Funcion para escoger cuantos jugadores.
{
    int esc;
    if (turn==1)
        {
            turn=3;
        }else
        {
            turn=5;
        }
    do
    {
        printf("Escriba 1 para un jugador o 2 para dos jugadores\n");
        scanf("%i",&esc);
        if (esc==1 || esc==2)
        {
            system("cls");
            Jug(esc,turn,0,0);
        }else
        {
            system("cls");
            printf("Digite una opcion valida\n");
        }
    } while (esc!=1 && esc!=2);
}

void Jug(int esc,int turn,int gan1, int gan2) //Funcion para escoger la opcion de cada jugador.
{
    int opc[2];
    do
    {
        printf("Jugador 1\nDigite 1 para piedra, 2 para papel, 3 para tijera, 4 para lagarto o 5 para spock\n");
        scanf("%i",&opc[0]);
        if (opc[0]<1 || opc[0]>5)
        {
            system("cls");
            printf("Digite una opcion valida\n");
        }
    }while (opc[0]<1 || opc[0]>5);
    system("cls");
    if (esc==2)
    {
        do
        {
            printf("Jugador 2\nDigite 1 para piedra, 2 para papel, 3 para tijera, 4 para lagarto o 5 para spock\n");
            scanf("%i",&opc[1]);
            if (opc[1]<1 || opc[1]>5)
            {
                system("cls");
                printf("Digite una opcion valida\n");
            }
        }while (opc[1]<1 || opc[1]>5);
    }else
    {
        opc[1]=rand()%5+1;
        printf("%i\n",opc[1]);
    }
    system("cls");
    juego(esc,turn,opc,gan1,gan2);
}

 void juego(int esc, int turn,int opc[2],int gan1,int gan2) //Funcion para ver cual de los dos gano el enfrentamiento, o si hubo empate
{
    int f,c=1;
    for (f=0;f<2;f++)
    {
        switch (opc[f])
        {
            case 1: printf("Piedra ");
            break;
            case 2: printf("Papel ");
            break;
            case 3: printf("Tijeras ");
            break;
            case 4: printf("Lagarto ");
            break;
            case 5: printf("Spock ");
            break;
        }
        if (f==0)
        {
            printf("vs ");
        }
    }
    printf("\n");
    for (f=0,c=1;f<2;f++,c--) //Ciclo para ver el ganador, y si no hay, fue empate
    {
        switch (opc[f])
        {
        case 1:
            {
                if (opc[c]==3 || opc[c]==4)
                {
                    printf("Gana piedra\n\n\n");
                    if (f==0)
                    {
                        gan1++;
                    } else
                    {
                        gan2++;
                    }
                }
            }
            break;
        case 2:
            {
                if (opc[c]==1 || opc[c]==5)
                {
                    printf("Gana papel\n\n\n");
                    if (f==0)
                    {
                        gan1++;
                    } else
                    {
                        gan2++;
                    }
                }
            }break;
        case 3:
            {
                if (opc[c]==2 || opc[c]==4)
                {
                    printf("Gana tijeras\n\n\n");
                    if (f==0)
                    {
                        gan1++;
                    } else
                    {
                        gan2++;
                    }
                }
            }break;
        case 4:
            {
                if (opc[c]==2 || opc[c]==5)
                {
                    printf("Gana lagarto\n\n\n");
                    if (f==0)
                    {
                        gan1++;
                    } else
                    {
                        gan2++;
                    }
                }
            }break;
        case 5:
            {
                if (opc[c]==1 || opc[c]==3)
                {
                    printf("Gana spock\n\n\n");
                    if (f==0)
                    {
                        gan1++;
                    } else
                    {
                        gan2++;
                    }
                }
            }break;
        }
    }
    if (opc[f-1]==opc[c+1])
    {
        printf("Empate\n\n\n");
    }
    if (gan1==turn || gan2==turn) //If para ver si hubo un ganador de toda la partida, si no, reiniciar hasta la funcion Jug
    {
        ganador(gan1,gan2);
    } else
    {
        Jug(esc,turn,gan1,gan2);
    }
}

void ganador(int gan1, int gan2)  //Funcion que imprime el ganador de la partida y devuelve al menu de inicio
{
    system("cls");
    printf("El ganador es...\n");

    if (gan1<gan2)
    {
        printf("El jugador 2!!!\n");
    }else
    {
        printf("El jugador 1!!!\n");
    }
    printf("\n\n\n");
}
