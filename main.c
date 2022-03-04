#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
char end(char si, char (*ptab)[3]){
    if( (ptab[0][0]==si&&ptab[0][1]==si&&ptab[0][2]==si)||(ptab[1][0]==si&&ptab[1][1]==si&&ptab[1][2]==si)||(ptab[2][0]==si&&ptab[2][1]==si&&ptab[2][2]==si)||(ptab[0][0]==si&&ptab[1][0]==si&&ptab[2][0]==si)||(ptab[0][1]==si&&ptab[1][1]==si&&ptab[2][1]==si)||(ptab[0][2]==si&&ptab[1][2]==si&&ptab[2][2]==si)||(ptab[0][0]==si&&ptab[1][1]==si&&ptab[2][2]==si)||(ptab[0][2]==si&&ptab[1][1]==si&&ptab[2][0]==si))
       {return si;}
}
void print_the_board(char (*ptab)[3]){
        printf("\n-------------\n");
        printf("| %c | %c | %c |\n", ptab[0][0], ptab[0][1], ptab[0][2]);
        printf("-------------\n");
        printf("| %c | %c | %c |\n", ptab[1][0], ptab[1][1], ptab[1][2]);
        printf("-------------\n");
        printf("| %c | %c | %c |\n", ptab[2][0], ptab[2][1], ptab[2][2]);
        printf("-------------\n");
}
struct Player {
   char  name[30];
   char  symbol;
   int   wins;
};
int main()
{
    struct Player Player1;
    struct Player Player2;

    char x = 'X', o = 'O', p = ' ';
    char winer, symbol, first_player[30], *pfirst_player, table[3][3] = {{p,p,p},{p,p,p},{p,p,p}}, *ptable, new_game[30], now_play[30], *pnow_play, no[] = "no";
    int value, game, row, column, i, draw = 0;
    pfirst_player = &first_player[0];
    ptable = &table[0];

    printf("Do you want to play? (yes/no)\n");
    scanf("%s", &new_game);
    if(strcmp(new_game,no)) game = 1; else return 0;

    printf("Enter name first player\n");
    scanf("%s", Player1.name);
    printf("Enter name second player\n");
    scanf("%s", Player2.name);
    pfirst_player = Player1.name;
    pnow_play = &now_play[0];

    Player1.symbol = x;
    Player1.wins = 0;

    Player2.symbol = o;
    Player2.wins = 0;

    while(game == 1){
        pnow_play = &pfirst_player[0];
        symbol = x;
        for(i = 0; i<9; i++){
            while(1){
                printf("%s, enter the row and column where you want to put %c ? \n\n", pnow_play, symbol);
                scanf("%d %d", &row, &column);
                row = row-1;
                column = column-1;

                if(row>=0&&row<=2&&column>=0&&column<=2&&table[row][column] == p){
                    table[row][column] = symbol;
                    break;}
                else{
                    printf("Try again...\n");}
            }
            print_the_board(ptable);
            winer = end(symbol, ptable);
            if(winer == symbol){
                printf("\nWinnnn.\n");

                if(symbol == x){Player1.wins+=1;}
                if(symbol == o){Player2.wins+=1;}
                break;
            }
            if(i == 8){ printf("\n\n Draw!!\n\n"); draw++;}
            //change player
            if(strcmp(Player1.name,pnow_play)){ pnow_play = Player1.name; symbol = Player1.symbol;} else {pnow_play = Player2.name ; symbol = Player2.symbol;}
        }
        printf("\n%s won %d times. \n", Player1.name, Player1.wins);
        printf("%s won %d times. \n", Player2.name, Player2.wins);
        printf("Draw %d times. \n", draw);
        // change first player
        if(strcmp(Player1.name,pfirst_player)) pfirst_player = Player1.name; else pfirst_player = Player2.name;

        printf("Do you want to play again? (yes/no)\n");
        scanf("%s", &new_game);
        if(strcmp(new_game,no)) game = 1; else game = 0;
    }
    return 0;
}
