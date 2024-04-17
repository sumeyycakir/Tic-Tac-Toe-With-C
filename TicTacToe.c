#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char arr[10] = {'o','1','2','3','4','5','6','7','8','9'};

void showBoard();
int checkForWin();

int main() {
    int player = 1;
    int choice, i;
    char mark; // X ya da O

    do {
        showBoard();
        player = (player % 2) ? 1 : 2;
        printf("Player %d turn : ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && arr[choice] == choice + '0')
            arr[choice] = mark;
        else {
            printf("Invalid value\n");
            player--;
            getch();
        }   

        i = checkForWin();
        player++;
    } while (i == -1);

    showBoard();
    if (i == 1)
        printf("Player %d Won\n", --player);
    else
        printf("Game Draw\n");

    getch();
    return 0;
}

void showBoard() { 
    printf("TIC TAC TOE\n");
    printf("      |      |     \n");
    printf("      |      |     \n");
    printf("   %c  |   %c  |   %c  \n", arr[1], arr[2], arr[3]);
    printf("------|------|------\n");
    printf("      |      |     \n");
    printf("   %c  |   %c  |   %c  \n", arr[4], arr[5], arr[6]);
    printf("      |      |     \n");
    printf("------|------|------\n");
    printf("      |      |     \n");
    printf("   %c  |   %c  |   %c  \n", arr[7], arr[8], arr[9]);
    printf("      |      |     \n");
}

int checkForWin() {
    //Satır
    if (arr[1] == arr[2] && arr[2] == arr[3])
        return 1;
    else if (arr[4] == arr[5] && arr[5] == arr[6])
        return 1; 
    else if (arr[7] == arr[8] && arr[8] == arr[9])
        return 1;

    //Sütun
    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;
    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;
    else if (arr[3] == arr[6] && arr[6] == arr[9])
        return 1;

    //Çapraz
    else if (arr[1] == arr[5] && arr[5] == arr[9])
        return 1;
    else if (arr[3] == arr[5] && arr[5] == arr[7])
        return 1;

    //Beraberlik
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' &&
             arr[4] != '4' && arr[5] != '5' && arr[6] != '6' &&
             arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
        return 0;

    else
        return -1;
}
