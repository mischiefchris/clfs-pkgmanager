#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int length;
int width;
int i;
int j;
char invisible_board[100][100];   // dynamically allocate....
char player_board[100][100];   // dynamically allocate....


void board_setup(int *rows, int *columns){  
    for (i = 0; i < *rows; i++){
        for (j = 0; j < *columns; j++){
            invisible_board[i][j] = '.';    //Sets all elements in hidden board to water
        }       
    }

    for (i = 0; i < *rows; i++){
        for (j = 0; j < *columns; j++){
            player_board[i][j] = '.';
        }
    }
}

void display(int *rows, int *columns){

    printf("   ");
    for (i=1; i < *rows +1;i++){
        printf("%d  ",i);
    }
    printf("\n");                       //Prints top row of co-ordinates

    for (i=1; i < *columns+1;i++){
        printf("%d ",i);
        for (j=0;j < *columns;j++){         //Prints left column of co-    ordinates and rows of game board
            printf(" %c ",invisible_board[i-1][j]);
        }
        printf("\n");
    }

}

int main(void){

    printf("Please enter the amount of rows in your board\n");
    scanf("%d",&length);
    printf("Please enter the amount of columns in your board\n");
    scanf("%d",&width);

    board_setup(&length,&width);
    display(&length,&width);

    return (0);
}
