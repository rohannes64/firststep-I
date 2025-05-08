#include <stdio.h>
#include <stdlib.h>
void display(char arr[3][3]) {
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        printf("%c ", arr[i][j]);
                }
                printf("\n");
        }
}
int checkfordraw(char arr[3][3]) {
        int count = 0;
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        if (arr[i][j] != '#') {
                                count++;
                        }
                }
        }
        if (count == 9) {
                return 1;
        }
        return 0;
}
char checkforwin(char arr[3][3]) {
        for (int i = 0; i < 3; i++) {
                if (arr[i][0] == arr[i][1] && arr[i][1] ==  arr[i][2] && arr[i][0] != '#')
                        return arr[i][0];
                if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != '#')
                        return arr[0][i];
        }
        if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) && arr[0][0] != '#')
                return arr[0][0];
        else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != '#')
                return arr[1][1];
        return '#';
}
int main(void) {
        char board[3][3];
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        board[i][j] = '#';
                }
        }
        int choice = 0;
        printf("Hello, and Welcome to my tic-tac-toe game!\n\nBefore you start the game there are 3 rules.\n\n1.The format for each input is ROW COLUMN\t(thats your row number (1-3) space separated with column number (1-3)\n\n2.Overlapping of inputs is possible in this version so adhere to the OG tic-tac-toe rules\t(DO NOT OVERLAP)\n\n3.Have fun or something, i guess.\n\n");
        printf("Press 1 to Start: ");
        scanf("%d", &choice);
        display(board);
             while (choice != 0) {
                     int row1, col1, row2, col2;
                     printf("Player 1, Enter your choice: ");
                     scanf("%d %d",&row1, &col1);
                     board[row1-1][col1-1] = 'X';
                display(board);
                     if (checkforwin(board) != '#') {
                             printf("Player %c, Win!\n",checkforwin(board));
                                choice = 0;
                             break;
                     }
                     if (checkfordraw(board)) {
                        printf("It's a DRAW");
                        choice = 0;
                                 break;
        }
                     printf("Player 2, Enter your choice: ");
                     scanf("%d %d",&row2, &col2);
                     board[row2-1][col2-1] = 'O';
                display(board);
                     if (checkforwin(board) != '#') {
                             printf("Player %c, Win!\n",checkforwin(board));
                             choice = 0;
                             break;
                     }
                     if (checkfordraw(board)) {
                             printf("It's a DRAW");
                             choice = 0;
                                break;
        }
        }
        if (choice == 0) {
                printf("See you Next Time!\n");
                system("pause");
                return 0;
        }
}
