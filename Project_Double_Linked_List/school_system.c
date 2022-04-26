/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    School System source file.
*/
/* Including header files */
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "double_linked_list.h"
#include "school_system.h"
#include "sort.h"

/*
    Pre  : Info and scores lists initialized
    Post : Entering Main Menu to let user select what to do in the program
*/
void EnterMainMenu(listSt *SchoolP,scoreList *ScoreP){
    /* Variables Definitions */
    u8 Return;
    student S;
    enum menuOptions Choice;

    do{
        system("cls");
        printf("========Main Menu========\n");
        printf("1-Add New Student Account\n2-Delete Student Account\n3-Display Students List\n");
        printf("4-Edit Student Account\n5-Rank Students\n6-Update Student Score\n0-Return Welcome Window\n");
        fflush(stdin);
        scanf("%d", &Choice);
        switch(Choice){
            case Add_Student:
                AddNewStudent(SchoolP, ScoreP);
                do{
                    fflush(stdin);
                    printf("Press 'R' to return to Main Menu:");
                    scanf("%c", &Return);
                }while((Return != 'R') && (Return != 'r'));
                break;
            case Delete_Student:
                fflush(stdin);
                printf("Plz enter full student name:");
                scanf("%[^\n]%*c", &(S.Name));
                DeleteStudent(SchoolP, ScoreP, S);
                do{
                    fflush(stdin);
                    printf("Press 'R' to return to Main Menu:");
                    scanf("%c", &Return);
                }while((Return != 'R') && (Return != 'r'));
                break;
            case Display_List:
                DisStudentList(SchoolP);
                do{
                    fflush(stdin);
                    printf("Press 'R' to return to Main Menu:");
                    scanf("%c", &Return);
                }while((Return != 'R') && (Return != 'r'));
                break;
            case Edit_Student:
                fflush(stdin);
                printf("Plz enter full student name:");
                scanf("%[^\n]%*c", &(S.Name));
                EditStudent(SchoolP, ScoreP, S);
                do{
                    fflush(stdin);
                    printf("Press 'R' to return to Main Menu:");
                    scanf("%c", &Return);
                }while((Return != 'R') && (Return != 'r'));
                break;
            case Rank_Students:
                RankStudent(ScoreP);
                do{
                    fflush(stdin);
                    printf("Press 'R' to return to Main Menu:");
                    scanf("%c", &Return);
                }while((Return != 'R') && (Return != 'r'));
                break;
            case Update_Score:
                fflush(stdin);
                printf("Plz enter full student name:");
                scanf("%[^\n]%*c", &(S.Name));
                UpdateStudentScore(ScoreP, S.Name);
                do{
                    fflush(stdin);
                    printf("Press 'R' to return to Main Menu:");
                    scanf("%c", &Return);
                }while((Return != 'R') && (Return != 'r'));
        }
    }while(Choice != Return_Welcome_Window);
}//EnterMainMenu
/*
    Pre  :  Info and scores lists initialized
    Post :  Adding new student record
*/
void AddNewStudent(listSt *SchoolP, scoreList *ScoreP){
    /* Variables Definitions */
    s32 Pos;
    student S;
    scoreEntry Entry;
    /* The Info List Part */
    system("cls");
    fflush(stdin);
    printf("Plz enter the ID        :");
    scanf("%[^\n]%*c", &(S.ID));
    printf("Plz enter the Name      :");
    scanf("%[^\n]%*c", &(S.Name));
    printf("Plz enter the Birthday  :");
    scanf("%[^\n]%*c", &(S.BirthDay));
    printf("Plz enter the Address   :");
    scanf("%[^\n]%*c", &(S.Address));
    printf("Plz enter the Phone     :");
    scanf("%llu", &(S.Phone));
    Pos = GetPositionI(SchoolP, S);
    InsertNodeI(SchoolP, S, Pos);
    /* The Scores List Part */
    strcpy(Entry.Name, S.Name);
    Entry.Grade = 0;
    fflush(stdin);
    Pos = SetPositionS(ScoreP, Entry.Grade);
    InsertNodeS(ScoreP, Entry, Pos);
}//AddNewStudent
/*
    Pre  : Info and scores lists initialized and not empty
    Post : delete passed student name
*/
void DeleteStudent(listSt *SchoolP, scoreList *ScoreP, student S){
    s32 Pos;
    if(!IsEmptyI(SchoolP)){//checking if the list is not empty
        Pos = GetPositionI(SchoolP, S);
        if(strcmpi(SchoolP->Current->Data.Name, S.Name) == 0){
            DeleteNodeI(SchoolP, Pos);
            Pos = GetPositionS(ScoreP, S.Name);
            DeleteNodeS(ScoreP, Pos);
        }//if
        else{
            printf("Student record is not exist.\n");
        }//else
    }//if
}//DeleteStudent
/*
    Pre  : Info list initialized
    Post : Display the list in order and displaying the list size
*/
void DisStudentList(listSt *SchoolP){
    PrintListI(SchoolP);
    printf("Number of students is %d\n", SchoolP->Count);
}//DisStudentList
/*
    Pre  : Info list initialized
    Post : Edit student information list
*/
void EditStudent(listSt *SchoolP, scoreList *ScoreP, student S){
    /* Variables Definitions */
    s32 Pos1, Pos2;
    enum editOptions Selection;

    Pos1 = GetPositionI(SchoolP, S);
    if(strcmpi(SchoolP->Current->Data.Name, S.Name) == 0){
        do{
            printf("Plz select the specific field to edit:\n");
            printf("1-ID\n2-Name\n3-BirthDay\n4-Address\n5-Phone\n0-Return\n");
            fflush(stdin);
            scanf("%d", &Selection);
            switch(Selection){
                case ID:
                    fflush(stdin);
                    printf("Plz enter new ID:");
                    scanf("%[^\n]%*c", &(S.ID));
                    strcpy(SchoolP->Current->Data.ID, S.ID);
                    break;
                case Name:
                    Pos2 = GetPositionS(ScoreP, S.Name);
                    fflush(stdin);
                    printf("Plz enter new Name:");
                    scanf("%[^\n]%*c", &(S.Name));
                    strcpy(SchoolP->Current->Data.Name, S.Name);
                    strcpy(ScoreP->Current->Score.Name, S.Name);
                    break;
                case BirthDay:
                    fflush(stdin);
                    printf("Plz enter new Birthday:");
                    scanf("%[^\n]%*c", &(S.BirthDay));
                    strcpy(SchoolP->Current->Data.BirthDay, S.BirthDay);
                    break;
                case Address:
                    fflush(stdin);
                    printf("Plz enter new Adress:");
                    scanf("%[^\n]%*c", &(S.Address));
                    strcpy(SchoolP->Current->Data.Address, S.Address);
                    break;
                case Phone:
                    fflush(stdin);
                    printf("Plz enter new Phone:");
                    scanf("%llu", &(S.Phone));
                    SchoolP->Current->Data.Phone = S.Phone;
                    break;
                case Return:
                    break;
                default:
                    printf("Wrong Choice!\n");
            }//switch
        }while(Selection != Return);
        /* Resort the Info list */
        BeginSortingInfo(SchoolP);
    }//if
    else{
        printf("Student record is not exist, please select add student if you've entered the name correct.\n");
    }//else
}//EditStudent
/*
    Pre  :  scores list initialized
    Post :  display stored students grades in order
*/
void RankStudent(scoreList *ScoreP){
    PrintListS(ScoreP);
    printf("Number of students is %d\n", ScoreP->Count);
}//RankStudent
/*
    Pre  :  scores list initialized
    Post :  update specific student computer science score
*/
void UpdateStudentScore(scoreList *ScoreP, u8 Name[]){
    /* Variables Definitions */
    s32 Pos;
    scoreEntry Entry;

    fflush(stdin);
    printf("Plz enter the grade:");
    scanf("%d", &Entry.Grade);
    strcpy(Entry.Name, Name);
    Pos = GetPositionS(ScoreP, Name);
    if(Pos == -1){
        printf("Student name is not exist.\n");
    }//if
    else{
        ScoreP->Current->Score.Grade = Entry.Grade;
        BeginScoresSorting(ScoreP);
    }//else
}//UpdateStudentScore
