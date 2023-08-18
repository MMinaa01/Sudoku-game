#include <stdio.h>
#include <stdlib.h>

void SudokuPrint(int arr[9][9]);



int main()
{
    //system("COLOR ");
    int choice;
    int x; //press any key to continue
    int arrr[9][9]={{0,0,7,0,0,6,4,5,0},
                    {0,2,5,3,4,0,0,0,8},
                    {0,6,0,0,0,1,0,7,0},
                    {0,5,3,0,0,0,0,2,9},
                    {6,1,0,0,0,9,8,0,0},
                    {0,0,0,6,0,2,0,0,7},
                    {0,0,1,0,9,3,2,0,0},
                    {0,0,8,0,0,0,0,0,0},
                    {0,4,0,0,7,8,5,9,1}};
    int arrr_answers[9][9]={{1,3,7,9,8,6,4,5,2},
                            {9,2,5,3,4,7,1,6,8},
                            {8,6,4,5,2,1,9,7,3},
                            {7,5,3,8,1,4,6,2,9},
                            {6,1,2,7,3,9,8,4,5},
                            {4,8,9,6,5,2,3,1,7},
                            {5,7,1,4,9,3,2,8,6},
                            {2,9,8,1,6,5,7,3,4},
                            {3,4,6,2,7,8,5,9,1}};
    int arrr_status[9][9]={0};
    while(1)
    {
        int win;
        arrayPrint_2D(arrr);
        arr_status_sit(arrr,arrr_status);
        printf("press\n 1-to add numbers\n 2-for hint \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            sudoku_add(arrr,arrr_answers,arrr_status);
            break;

            case 2:
                sudoku_hint(arrr,arrr_answers);
                break;

            default:
                printf("wrong answer\n");
                printf("press any key to continue..");
                scanf("%d",&x);
                break;

        }
        win = sudoku_win(arrr,arrr_answers);
        if(win==1)
        {
            system("cls");
            printf("\033[34m\033[47m        Congratulations,YOU WON         \033[0m \n");
            arrayPrint_2D(arrr);

            break;
        }


        system("cls");
    }



    return 0;
}
