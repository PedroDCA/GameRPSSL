#include <stdio.h>
void main()
{
    int turn=0;
    printf("Welcome to Rock, Paper, Scissors, Spock, Lizard\n");
    do
    {
        printf("Type 1 to make a 3-Points game, 2 to make a 5-Points game or 3 to exit\n");
        scanf("%i",&turn);
        if (turn==1 || turn==2)
        {
            system("cls");

            play(turn);
        }
        if (turn<1 || turn>3)
        {
            system("cls");
            printf("Type a valid option\n");
        }
    } while (turn!=3);
    printf("Thanks for playing!");
}
void play(int turn)
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
        printf("Type 1 to make an 1-Player game or 2 to make a 2-Players game\n");
        scanf("%i",&esc);
        if (esc==1 || esc==2)
        {
            system("cls");
            Jug(esc,turn,0,0);
        }else
        {
            system("cls");
            printf("Type a valid option\n");
        }
    } while (esc!=1 && esc!=2);
}

void Jug(int esc,int turn,int gan1, int gan2) //Funcion para escoger la opcion de cada jugador.
{
    int opc[2];
    do
    {
        printf("Player 1\nType 1 for rock, 2 for paper, 3 for scissors, 4 for lizard o 5 for spock\n");
        scanf("%i",&opc[0]);
        if (opc[0]<1 || opc[0]>5)
        {
            system("cls");
            printf("Type a valid option\n");
        }
    }while (opc[0]<1 || opc[0]>5);
    system("cls");
    if (esc==2)
    {
        do
        {
            printf("Player 2\nType 1 for rock, 2 for paper, 3 for scissors, 4 for lizard o 5 for spock\n");
            scanf("%i",&opc[1]);
            if (opc[1]<1 || opc[1]>5)
            {
                system("cls");
                printf("Type a valid option\n");
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

 void juego(int esc, int turn,int opc[2],int gan1,int gan2)
{
    int f,c=1;
    for (f=0;f<2;f++)
    {
        switch (opc[f])
        {
            case 1: printf("Rock ");
            break;
            case 2: printf("Paper ");
            break;
            case 3: printf("Scissors ");
            break;
            case 4: printf("Lizard ");
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
    for (f=0,c=1;f<2;f++,c--)
    {
        switch (opc[f])
        {
        case 1:
            {
                if (opc[c]==3 || opc[c]==4)
                {
                    printf("Rock won\n\n\n");
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
                    printf("Paper won\n\n\n");
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
                    printf("Scissors won\n\n\n");
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
                    printf("Lizard won\n\n\n");
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
                    printf("Spock won\n\n\n");
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
        printf("Tie\n\n\n");
    }
    if (gan1==turn || gan2==turn)
    {
        ganador(gan1,gan2);
    } else
    {
        Jug(esc,turn,gan1,gan2);
    }
}

void ganador(int gan1, int gan2)
{
    system("cls");
    printf("The winner is...\n");

    if (gan1<gan2)
    {
        printf("The player 2!!!\n");
    }else
    {
        printf("The player 1!!!\n");
    }
    printf("\n\n\n");
}
