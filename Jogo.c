#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>

char tabuleiro[11][14]; // jogador
char solucao[11][14];   // solução
int tiros = 0;

void apresentacao ()
{
    printf("  .---.                        \n");
    printf(" /|                                    |   |   .                    \n");
    printf(" ||                                    |   | .'|                    \n");
    printf(" ||                      .|            |   |<  |                    \n");
    printf(" ||  __        __      .' |_     __    |   | | |             __    \n");
    printf(" ||/'__ '.  .:--.'.  .'     | .:--.'.  |   | | | .'''-.   .:--.'.  \n");
    printf(" |:/`  '. '/ |   \\ |'--.  .-'/ |   \\ | |   | | |/.'''. \\ / |   \\ | \n");
    printf(" ||     | |`\" __ | |   |  |  `\" __ | | |   | |  /    | | `\" __ | | \n");
    printf(" ||\\    / ' .'.''| |   |  |   .'.''| | |   | | |     | |  .'.''| | \n");
    printf(" |/\\'..' / / /   | |_  |  '.'/ /   | |_'---' | |     | | / /   | |_ \n");
    printf(" '  `'-'`  \\ \\._,\\ '/  |   / \\ \\._,\\ '/      | '.    | '.\\ \\._,\\ '/\n");
    printf("            `--'  `\"   `'-'   `--'  `\"       '---'   '---'`--'  `\" \n");
    printf("                                          .---.                    \n");
    printf("   _..._          .----.     .----.       |   |                    \n");
    printf(" .'     '.         \\    \\   /    /        |   |                    \n");
    printf(".   .-.   .         '   '. /'   /         |   |                    \n");
    printf("|  '   '  |    __   |    |'    /    __    |   |                    \n");
    printf("|  |   |  | .:--.'. |    ||    | .:--.'.  |   |                    \n");
    printf("|  |   |  |/ |   \\ |'.   `'   .'/ |   \\ | |   |                    \n");
    printf("|  |   |  |`\" __ | | \\        / `\" __ | | |   |                    \n");
    printf("|  |   |  | .'.''| |  \\      /   .'.''| | |   |                    \n");
    printf("|  |   |  |/ /   | |_  '----'   / /   | |_'---'                    \n");
    printf("|  |   |  |\\ \\._,\\ '/           \\ \\._,\\ '/                         \n");
    printf("'--'   '--' `--'  `\"             `--'  `\"                          \n");
    printf("\n \n  \n Realizado por ::     Antónia Meira Firmino    10ºIS     Nº28");
    getchar();
    system("cls");
}
void sobre ()
{
    printf("  .---.                        \n");
    printf(" /|                                    |   |   .                    \n");
    printf(" ||                                    |   | .'|                    \n");
    printf(" ||                      .|            |   |<  |                    \n");
    printf(" ||  __        __      .' |_     __    |   | | |             __    \n");
    printf(" ||/'__ '.  .:--.'.  .'     | .:--.'.  |   | | | .'''-.   .:--.'.  \n");
    printf(" |:/`  '. '/ |   \\ |'--.  .-'/ |   \\ | |   | | |/.'''. \\ / |   \\ | \n");
    printf(" ||     | |`\" __ | |   |  |  `\" __ | | |   | |  /    | | `\" __ | | \n");
    printf(" ||\\    / ' .'.''| |   |  |   .'.''| | |   | | |     | |  .'.''| | \n");
    printf(" |/\\'..' / / /   | |_  |  '.'/ /   | |_'---' | |     | | / /   | |_ \n");
    printf(" '  `'-'`  \\ \\._,\\ '/  |   / \\ \\._,\\ '/      | '.    | '.\\ \\._,\\ '/\n");
    printf("            `--'  `\"   `'-'   `--'  `\"       '---'   '---'`--'  `\" \n");
    printf("                                          .---.                    \n");
    printf("   _..._          .----.     .----.       |   |                    \n");
    printf(" .'     '.         \\    \\   /    /        |   |                    \n");
    printf(".   .-.   .         '   '. /'   /         |   |                    \n");
    printf("|  '   '  |    __   |    |'    /    __    |   |                    \n");
    printf("|  |   |  | .:--.'. |    ||    | .:--.'.  |   |                    \n");
    printf("|  |   |  |/ |   \\ |'.   `'   .'/ |   \\ | |   |                    \n");
    printf("|  |   |  |`\" __ | | \\        / `\" __ | | |   |                    \n");
    printf("|  |   |  | .'.''| |  \\      /   .'.''| | |   |                    \n");
    printf("|  |   |  |/ /   | |_  '----'   / /   | |_'---'                    \n");
    printf("|  |   |  |\\ \\._,\\ '/           \\ \\._,\\ '/                         \n");
    printf("'--'   '--' `--'  `\"             `--'  `\"                          \n");
    printf("\n\n\n\n");
    printf("Batalha Naval é um jogo de estratégia e combate que envolve dois jogadores.\n \nO objetivo é adivinhar as posições dos navios inimigos e afundá-los, enquanto tenta proteger os seus próprios. \nOs jogadores se revezam para chamar coordenadas (como A5 ou B3), e o adversário responde se a coordenada foi um acerto ou erro. \n\nO jogo continua até que todos os navios de um dos jogadores sejam afundados.\n\nÉ um jogo simples, mas que exige raciocínio e tática!\n\n");
    getchar();
    system("cls");
}
void inicio()
{
    for(int l=0; l<11; l++)
    {
        for(int c=0; c<14; c++)
        {
            tabuleiro[l][c] = ' ';
        }
    }

    //HORIZONTAL
    tabuleiro[0][2] = 'A';
    tabuleiro[0][3] = 'B';
    tabuleiro[0][4] = 'C';
    tabuleiro[0][5] = 'D';
    tabuleiro[0][6] = 'E';
    tabuleiro[0][7] = 'F';
    tabuleiro[0][8] = 'G';
    tabuleiro[0][9] = 'H';
    tabuleiro[0][10] = 'I';
    tabuleiro[0][11] = 'J';
    tabuleiro[0][12] = 'K';
    tabuleiro[0][13] = 'L';

    //VERTICAL
    tabuleiro[1][1] = '1';
    tabuleiro[2][1] = '2';
    tabuleiro[3][1] = '3';
    tabuleiro[4][1] = '4';
    tabuleiro[5][1] = '5';
    tabuleiro[6][1] = '6';
    tabuleiro[7][1] = '7';
    tabuleiro[8][1] = '8';
    tabuleiro[9][1] = '9';
    tabuleiro[10][0] = '1';
    tabuleiro[10][1] = '0';

    // barco com 5
    solucao[2][9]  = solucao[3][9] = solucao[4][9] = solucao[5][9] = solucao[6][9]= '#';

    // barco com 1
    solucao[1][5] =  '#';

    // barco com 3
    solucao[4][3] = solucao[4][4] = solucao[4][5] = '#';

    // barco com 1
    solucao[7][5] = '#';

    // barco com 2
    solucao[9][3] = solucao[10][3] = '#';

    // barco com 5
    solucao[9][8] = solucao[9][9] = solucao[9][10] = solucao[9][11] = solucao[9][12] = '#';

    // barco com 2
    solucao[2][13] = solucao[3][13] = '#';
}
void vertabuleiro()
{
    for(int l=0; l<11; l++)
    {
        for(int c=0; c<14; c++)
        {
            if(c<2)
            {
                printf("  ");
            }
            else
            {
                printf(" | ");
            }

            printf("%c",tabuleiro[l][c]);
        }
        printf("\n      -------------------------------------------------\n");
    }
}
void jogo ()
{
    char c;
    int l;
    inicio();


    do
    {
        system("cls");
        vertabuleiro();

        printf("\nEndereço do seu tiro (Linha [1-10] Coluna [A-L]): ");
        scanf("%d %c", &l, &c);

        c = toupper(c) - 63;


        if(solucao[l][c] == '#')
        {
            char debugMsg [1024] = "Tiro!"; // buffer for debug message
            MessageBox (NULL, debugMsg, "Batalha Naval", MB_OK);
            printf("Você acertou um tiro!");
            tabuleiro[l][c] = 'X';
            tiros++;
            if(tiros==19) {
                //end
                MessageBox(NULL,"Parabéns!! Você terminou o jogo","FIM",MB_OK);
            }
        }
        else
        {
            tabuleiro[l][c] = '~';

        }


    }
    while(1);



}
void sair ()
{
    printf("\n\n                  Obrigada por ter jogado!\n");
    printf("                            ");
    for (int i = 0; i < 3; i++)
    {
        printf(".");

        fflush(stdout);
        //printf("\a");
        Beep(750, 300);
        sleep(1);

    }
    printf("\n\n");
    exit (0);

}
void menu ()
{

    char op;
    while (1)
    {
        puts("[1] Jogar");
        puts("[2] Sobre");
        puts("[s] Sair");
        printf("Escolha uma opção: ");
        scanf(" %c", &op);
        getchar();
        system("cls");

        switch (op)
        {
        case '1':
            jogo();
            break;
        case '2':
            sobre();
            break;
        case 's':
        case 'S':
            sair ();
            break;
        default:
            puts("Opção inválida!");
        }
    }

}
int main ()
{
    setlocale (LC_ALL, ("Portuguese"));
    apresentacao();
    inicio();
    while(1)
    {
        menu();
    }
    return 0;
}