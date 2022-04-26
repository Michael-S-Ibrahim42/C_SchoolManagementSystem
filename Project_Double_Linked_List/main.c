/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    main source file.
*/

/* Including header files */
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "double_linked_list.h"
#include "school_system.h"

/* Declaration of enum type */
enum options{Main_Menu = 1, Exit};

/* The main Fn */
int main(){
    /* Variables Definitions */
    enum options Choice;
    listSt School;
    scoreList ScoreList;

    /* Initializing info and scores lists */
    CreateListI(&School);
    CreateListS(&ScoreList);
    do{
        system("cls");
        printf("\t\t\tWelcome to our School Management System\n");
        printf("Plz enter your option number from the following:\n");
        printf("1- Main Menu\n2- Exit\n");
        fflush(stdin);
        scanf("%u", &Choice);
        if(Choice == Main_Menu){
            EnterMainMenu(&School, &ScoreList);
        }
    }while(Choice != Exit);//do..while for welcome window
    system("cls");
    printf("\t\t\tGood Bye\n");

    /* Indicates successful termination */
    return(0);
}//main
