#include <stdio.h>
#include <stdlib.h>


void arr_status_sit(int arr[9][9],int arr_status[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j]==0)
            {
                arr_status[i][j]=1;
            }
        }
    }
}

void arrayPrint_2D(int arr[9][9])
{
    int i,j;
    printf("      \033[34m\033[47m1   2   3   4   5   6   7   8   9\033[0m \n"); //columns index
    printf("   ======================================\n");
    for(i=0 ; i<9 ; i++)

    {

        printf("\033[34m\033[47m%d\033[0m  | ",i+1); //rows index
        for(j=0 ; j<9 ; j++)
        {
            if(arr[i][j]==0)
            {
                printf("   |");
            }
            else
            {
                printf("\033[31m%2d\033[0m |",arr[i][j]);
            }


        }
        printf("\n");
        if(i!=8)
        {
            printf("    ------------------------------------\n");
        }



    }
    printf("    =====================================\n");
}


void sudoku_add(int arr[9][9],int arr_answer[9][9],int arr_status[9][9])
{
    int row=100,col=100;
    int number;
    char c;
    int x;

    while((row>9||row<0)||(col>9||col<0))
    {
        printf("enter the number \n");
        fflush(stdin);
        scanf("%d",&number);
        if(number>0 && number<10)
        {
            printf("enter the row \n");
            scanf("%d",&row);
            if(row<10&&row>0)
            {
                printf("enter the column \n");
                scanf("%d",&col);
                if(col<10&&col>0)
                {
                    break;
                }
                else
                {
                    printf("wrong entry you should pick from 1 to 9\n");
                }
            }
            else
            {
                printf("wrong entry you should pick from 1 to 9\n");
            }

        }
        else
        {
            printf("wrong entry try again\n");
        }



    }
    if(arr_status[row-1][col-1]==1)
    {
        arr[row-1][col-1]=number;
    }
    else
    {
        printf("you can not edit this number \n");
        printf("press any key to continue .. \n");
        scanf("%d",&x);
    }

    /*if(number==arr_answer[row-1][col-1])  // and and not repeated
    {
        arr[row-1][col-1]=number;
    }
    else
    {
        printf("this number cant be here \n");
        printf("press any key to continue \n");
        fflush(stdin);
        scanf("%c",&c);
    }*/

}


int sudoku_win(int arr[9][9],int arr_answer[9][9])
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(arr[i][j]==arr_answer[i][j])
            {

            }
            else
            {
                return 0;
            }
        }


    }
    return 1;
}

void sudoku_hint(int arr[9][9],int arr_answer[9][9])
{
    int row,col;
    printf("choose the row you want \n");
    scanf("%d",&row);
    printf("choose the column you want \n");
    scanf("%d",&col);
    arr[row-1][col-1]=arr_answer[row-1][col-1];
}


