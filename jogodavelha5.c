#include <stdio.h>
int main (void)
{
    int pulo1=0,fim,jogada, c, l, x, contjogadas, jogador;
    int matriz [3][3], mjogador1[8][3], mjogador2[8][3], mjogada[3][3];
    void iniciamatriz(int [8][3]);
    void printmatriz(int [][3]);
    void matrizprincipal(int [][3]);
    void marca (int mjogador[][3], int jogada,int jogador,int* ppulo1);
    int* ppulo1;
    int repete (int);

fim=10;
ppulo1=&pulo1;
while (fim)
{
    //zerando a matriz jogada
  for(l=0;l<3;l++)
  {
        for(c=0;c<3;c++)
        {
            mjogada[l][c]=0;
        }
  }

  //iniciando as matrizes mjogador 1 e 2

  iniciamatriz(mjogador1);
  iniciamatriz(mjogador2);
    //preenchendo a matriz jogo da velha com valores de 1 a 9
    matrizprincipal(matriz);

    for(pulo1=0,jogador=1,contjogadas=0;contjogadas<9;contjogadas++,jogador++)
    {
    if(jogador==3)
    {
        jogador=1;
    }

        printf("\n\njogador %d\t",jogador);
        scanf("%d",&jogada);
        while(jogada<1||jogada>9)
        {
            printf("\njogada invalida, insira um numero entre 1 e 9\n");
            scanf("%d",&jogada);
        }
        jogada=jogada-1;
        l=jogada/3;
        c=jogada%3;
        while(mjogada[l][c]!=0)
        {
            printf("\njogada invalida, insira um numero entre 1 e 9 que ainda nao foi usado\n");
            scanf("%d",&jogada);
            jogada=jogada-1;
            l=jogada/3;
            c=jogada%3;
        }
        mjogada[l][c]=jogador;

    printf("\n");
    printf("\n     |     |     ");
    printf("\n %d   |  %d  |  %d   ",mjogada[0][0],mjogada[0][1],mjogada[0][2]);
    printf("\n_____|_____|_____");
    printf("\n     |     |     ");
    printf("\n %d   |  %d  |   %d  ",mjogada[1][0],mjogada[1][1],mjogada[1][2]);
    printf("\n_____|_____|_____");
    printf("\n     |     |     ");
    printf("\n %d   |  %d  |   %d  ",mjogada[2][0],mjogada[2][1],mjogada[2][2]);
    printf("\n     |     |     ");

printf("\n");

    if(jogador==1)
   {marca (mjogador1,jogada,jogador,ppulo1);}
    if(jogador==2)
    {marca (mjogador2,jogada,jogador,ppulo1);}
    if(pulo1==1)
    {
        break;
    }
    }
    if(contjogadas==9)
    {printf("\nnao houve vencedor\n");}
    fim=repete(fim);
}
    return 0;
}

int repete (int fim)
{
    printf("\ndeseja jogar outra vez(1-s/0-n)");
    scanf("%d",&fim);
    return fim;
}

void iniciamatriz(int matriz[][3])
{
    int l,c,x;
    //linhas 1 2 3
for(l=0,x=1;l<3;l++)
    {
        for(c=0;c<3;c++,x++)
        {
            matriz[l][c]=x;
        }
    }
//linhas 4 5 6
  for(l=3,x=1;l<6;l++)
    {
        if(l>3)
        {x=x-8;}
        for(c=0;c<3;c++)
        {
            matriz[l][c]=x;
            x=x+3;
        }
    }
//linhas 7 e 8
    for(x=1,c=0;c<3;c++)
    {
        matriz[6][c]=x;
        x=x+4;
    }
    for(x=3,c=0;c<3;c++)
    {
        matriz[7][c]=x;
        x=x+2;
    }
    return;
}
void marca (int mjogador[][3], int jogada,int jogador,int* ppulo1)
{
    int l,c;
    jogada++;
for(l=0;l<8;l++)
        {
            for(c=0;c<3;c++)
            {
                if(jogada==mjogador[l][c])
                {mjogador[l][c]=0;}
            }
        }
        for(l=0;l<8;l++)
        {
        if(mjogador[l][0]==0&&mjogador[l][1]==0&&mjogador[l][2]==0)
            {
            printf("parabens jogador %d, voce venceu",jogador);
            *ppulo1=1;
            }
        }
}
void printmatriz(int matriz[][3])
{
    int l,c;
   for(l=0;l<8;l++)
    {
        for(c=0;c<3;c++)
        {
            printf("\t%d",matriz[l][c]);
        }
        printf("\n");
    }
}
void matrizprincipal(int matriz[][3])
{
    int l,c,x;
for(l=0,x=1;l<3;l++)
    {
        for(c=0;c<3;c++,x++)
        {
            matriz[l][c]=x;
        }
    }
    //mostrando a matriz jogo da velha
    printf("\n");
    printf("\n     |     |     ");
    printf("\n %d   |  %d  |  %d   ",matriz[0][0],matriz[0][1],matriz[0][2]);
    printf("\n_____|_____|_____");
    printf("\n     |     |     ");
    printf("\n %d   |  %d  |   %d  ",matriz[1][0],matriz[1][1],matriz[1][2]);
    printf("\n_____|_____|_____");
    printf("\n     |     |     ");
    printf("\n %d   |  %d  |   %d  ",matriz[2][0],matriz[2][1],matriz[2][2]);
    printf("\n     |     |     ");
    return;
}

