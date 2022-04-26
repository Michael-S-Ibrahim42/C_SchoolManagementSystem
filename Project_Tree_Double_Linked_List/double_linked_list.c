/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    Double Linked List source file.
*/
#include "config.h"
#if (IMP == DOUBLE_LINKED_LIST)
/* Including Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "double_linked_list.h"

/* ============= Info List Fns ============= */
/*
    Pre     :   Info list struct variable defined
    Post    :   Initialize variable members
*/
void CreateListI(listSt *ListP){
    ListP->Count = 0;
    ListP->CurrentPos = -1;
    ListP->Current = NULL;
}//CreateListI
/*
    Pre     :   Info List exist and position is valid
    Post    :   Deleting the required node
*/
void DeleteNodeI(listSt *ListP, s32 Position){
    /* Variables Definitions */
    listNode *TempP = NULL;
    TempP = ListP->Current;
    if(ListP->Count == 1){
        ListP->Current = NULL;
        ListP->CurrentPos = -1;
    }//if
    /* Delete the last node */
    else if(Position == ListP->Count-1){
        ListP->Current->Prev->Next = NULL;
        ListP->Current = ListP->Current->Prev;
        ListP->CurrentPos--;
    }//if
    /* Delete the first node */
    else if(Position == 0){
        ListP->Current = ListP->Current->Next;
        TempP->Next->Prev = NULL;
    }//else if
    /* Delete at middle */
    else{
        ListP->Current->Next->Prev = ListP->Current->Prev;
        ListP->Current->Prev->Next = ListP->Current->Next;
        ListP->Current = ListP->Current->Next;
    }//else
    free(TempP);
    ListP->Count--;
}//DeleteNodeI
/*
    Pre     :   Info List is exist
    Post    :   Checking if the list is empty
*/
u8 IsEmptyI(listSt *ListP){
    return(!(ListP->Count));
}//IsEmptyI
/*
    Pre     :   students Info list initialized
    Post    :   Getting the right position to your need and update the current pointer and counter
*/
s32 GetPositionI(listSt *ListP, listEntry Entry){
    s32 Position;
    /* Empty Case */
    if(IsEmptyI(ListP)){
        Position = 0;
    }//if
    else{
        /* Not Empty */
        while(strcmpi(ListP->Current->Data.Name, Entry.Name) > 0){
            /* Position is the first position */
            if(ListP->Current->Prev == NULL){
                break;
            }//if
            else{
                ListP->Current = ListP->Current->Prev;
                ListP->CurrentPos--;
            }//else
        }//while
        while(strcmpi(ListP->Current->Data.Name, Entry.Name) < 0){
            /* Position is the last position */
            if(ListP->Current->Next == NULL){
                break;
            }//if
            else{
                ListP->Current = ListP->Current->Next;
                ListP->CurrentPos++;
            }//else
        }//while
        Position = ListP->CurrentPos;
    }//else
    return(Position);
}//GetPositionI
/*
    Pre     :   Info List exist
    Post    :   Inserting the node at the right position w.r.t passed position of the Info list
*/
void InsertNodeI(listSt *ListP, listEntry Entry, s32 Position){
    listNode *NodeP = (listNode *)malloc(sizeof(listNode));
    if(NodeP != NULL){
        /* Empty Case */
        NodeP->Data = Entry;
        NodeP->Next = NULL;
        NodeP->Prev = NULL;
        /* Empty and insert at beginning */
        if((Position == 0) && (IsEmptyI(ListP))){
            ListP->Current = NodeP;
            ListP->CurrentPos = 0;
        }//if
        /* Not Empty and insert at beginning */
        else if((Position == 0) && (strcmpi(ListP->Current->Data.Name, Entry.Name) >= 0)){
            ListP->Current->Prev = NodeP;
            NodeP->Next = ListP->Current;
            (ListP->CurrentPos)++;
        }//else if
        /* Not Empty and insert at end */
        else if((Position == ListP->Count-1) && (strcmpi(ListP->Current->Data.Name, Entry.Name) < 0)){
            ListP->Current->Next = NodeP;
            NodeP->Prev = ListP->Current;
            ListP->Current = NodeP;
            ListP->CurrentPos++;
        }//else if
        /* Not empty and insert in middle */
        else{
            /* earlier links */
            ListP->Current->Prev->Next = NodeP;
            NodeP->Prev = ListP->Current->Prev;
            /* The later links */
            NodeP->Next = ListP->Current;
            ListP->Current->Prev = NodeP;
            ListP->CurrentPos++;
        }
        ListP->Count++;
    }//if
}//InsertNodeI
/*
    Pre     :   Info List exist.
    Post    :   Printing the Info list.
*/
void PrintListI(listSt *ListP){
    if(IsEmptyI(ListP)){
        printf("List is empty.\n");
    }//if
    else{
        if(ListP->CurrentPos > 0){
            for(;ListP->CurrentPos != 0; ListP->CurrentPos--){
                if(ListP->Current->Prev != NULL){
                    ListP->Current = ListP->Current->Prev;
                }//if
            }//for
        }//if
        printf("============================================================================================================================================\n");
        printf("%-12s| %-30s| %-12s| %-12s| %-60s", "ID", "Name", "Birthday", "Phone", "Address");
        printf("\n============================================================================================================================================\n");
        while(ListP->CurrentPos < (ListP->Count)){
            //printf("==============================================\n");
            //printf("Student Number %d\n", ListP->CurrentPos+1);
            printf("%-12s| " ,ListP->Current->Data.ID);
            printf("%-30s| "  ,ListP->Current->Data.Name );
            printf("%-12s| "  ,ListP->Current->Data.BirthDay );
            printf("%-12llu| ",ListP->Current->Data.Phone );
            printf("%-60s\n"  ,ListP->Current->Data.Address );

            if(ListP->Current->Next == NULL){
                printf("============================================================================================================================================\n");
                break;
            }//if
            printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
            ListP->Current = ListP->Current->Next;
            (ListP->CurrentPos)++;
        }//while

    }//else
}//PrintListI

/* ============= Scores List Fns ============= */
/*
    Pre     :   Scores list struct variable defined
    Post    :   Initialize variable members
*/
void CreateListS(scoreList *ListP){
    ListP->Count = 0;
    ListP->CurrentPos = -1;
    ListP->Current = NULL;
}//CreateListS
/*
    Pre     :   Scores List exist and position is valid
    Post    :   Deleting the required node
*/
void DeleteNodeS(scoreList *ListP, s32 Position){
    /* Variables Definitions */
    scoreNode *TempP = NULL;
    TempP = ListP->Current;
    if(ListP->Count == 1){
        ListP->Current = NULL;
        ListP->CurrentPos = -1;
    }//if
    /* Delete the last node */
    else if(Position == ListP->Count-1){
        ListP->Current->Prev->Next = NULL;
        ListP->Current = ListP->Current->Prev;
        ListP->CurrentPos--;
    }//if
    /* Delete the first node */
    else if(Position == 0){
        ListP->Current = ListP->Current->Next;
        TempP->Next->Prev = NULL;
    }//else if
    /* Delete at middle */
    else{
        ListP->Current->Next->Prev = ListP->Current->Prev;
        ListP->Current->Prev->Next = ListP->Current->Next;
        ListP->Current = ListP->Current->Next;
    }//else
    free(TempP);
    ListP->Count--;
}//DeleteNodeS
/*
    Pre     :   Scores List is exist
    Post    :   Checking if the list is empty
*/
u8 IsEmptyS(scoreList *ListP){
    return(!(ListP->Count));
}//IsEmptyS
/*
    Pre     :   students Scores list initialized
    Post    :   Getting the right position to fetch with the name is passed or -1 if the name is not exist
                The current node pointer and counter are on the needed node or at last node if name is not exist.
*/
s32 GetPositionS(scoreList *ListP, u8 Name[]){
    s32 Position;
    /* Empty Case */
    if(IsEmptyS(ListP)){
        Position = -1;
    }//if
    else{
        if(ListP->CurrentPos > 0){
            for(;ListP->CurrentPos != 0; ListP->CurrentPos--){
                if(ListP->Current->Prev != NULL){
                    ListP->Current = ListP->Current->Prev;
                }//if
            }//for
        }//if
        /* Not Empty */
        while((strcmpi(ListP->Current->Score.Name, Name) != 0) && (ListP->Current->Next != NULL)){
            ListP->Current = ListP->Current->Next;
            ListP->CurrentPos++;
        }//while
        if(strcmpi(ListP->Current->Score.Name, Name) == 0){
            Position = ListP->CurrentPos;
        }
        else{
            Position = -1;
        }
    }//else
    return(Position);
}//GetPositionS
/*
    Pre     :   students Scores list initialized
    Post    :   set the current pointer and current counter at the right relative position to insert with the grade passed and return the current counter value.
*/
s32 SetPositionS(scoreList *ListP, s8 Grade){
    s32 Position;
    /* Empty Case */
    if(IsEmptyS(ListP)){
        Position = 0;
    }//if
    else{
        /* Not Empty */
        while(ListP->Current->Score.Grade > Grade){
            /* Position is the first position */
            if(ListP->Current->Prev == NULL){
                break;
            }//if
            else{
                ListP->Current = ListP->Current->Prev;
                ListP->CurrentPos--;
            }//else
        }//while
        while(ListP->Current->Score.Grade < Grade){
            /* Position is the last position */
            if(ListP->Current->Next == NULL){
                break;
            }//if
            else{
                ListP->Current = ListP->Current->Next;
                ListP->CurrentPos++;
            }//else
        }//while
        Position = ListP->CurrentPos;
    }//else
    return(Position);
}//SetPositionS
/*
    Pre     :   Scores List exist
    Post    :   Inserting the node at the right position w.r.t passed position
*/
void InsertNodeS(scoreList *ListP, scoreEntry Entry, s32 Position){
    scoreNode *NodeP = (scoreNode *)malloc(sizeof(scoreNode));
    if(NodeP != NULL){
        /* Empty Case */
        NodeP->Score = Entry;
        NodeP->Next = NULL;
        NodeP->Prev = NULL;
        /* Empty and insert at beginning */
        if((Position == 0) && (IsEmptyS(ListP))){
            ListP->Current = NodeP;
            ListP->CurrentPos = 0;
        }//if
        /* Not Empty and insert at beginning */
        else if((Position == 0) && (ListP->Current->Score.Grade >= Entry.Grade)){
            ListP->Current->Prev = NodeP;
            NodeP->Next = ListP->Current;
            (ListP->CurrentPos)++;
        }//else if
        /* Not Empty and insert at end */
        else if((Position == ListP->Count-1) && (ListP->Current->Score.Grade < Entry.Grade)){
            ListP->Current->Next = NodeP;
            NodeP->Prev = ListP->Current;
            ListP->Current = NodeP;
            ListP->CurrentPos++;
        }//else if
        /* Not empty and insert in middle */
        else{
            /* earlier links */
            ListP->Current->Prev->Next = NodeP;
            NodeP->Prev = ListP->Current->Prev;
            /* The later links */
            NodeP->Next = ListP->Current;
            ListP->Current->Prev = NodeP;
            ListP->CurrentPos++;
        }
        ListP->Count++;
    }//if
}//InsertNodeS
/*
    Pre     :   Scores List exist.
    Post    :   Printing the Scores list.
*/
void PrintListS(scoreList *ListP){
    if(IsEmptyS(ListP)){
        printf("List is empty.\n");
    }//if
    else{
        if(ListP->CurrentPos > 0){
            for(;ListP->CurrentPos != 0; ListP->CurrentPos--){
                if(ListP->Current->Prev != NULL){
                    ListP->Current = ListP->Current->Prev;
                }//if
            }//for
        }//if
        while(ListP->CurrentPos < (ListP->Count)){
            printf("=====================================================================================\n");
            printf("Student Number %d\n", ListP->CurrentPos+1);
            printf("Student Name                    : %s\n"  ,ListP->Current->Score.Name);
            printf("Student Computer Science Score  : %d\n",ListP->Current->Score.Grade);
            if(ListP->Current->Next == NULL){
                break;
            }//if
            ListP->Current = ListP->Current->Next;
            (ListP->CurrentPos)++;
        }//while
        printf("=====================================================================================\n");
    }//else
}//PrintListS
#endif
