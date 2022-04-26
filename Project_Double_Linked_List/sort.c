
/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    Sorting Algorithm source file.
*/

/* Including Header Files */
#include <stdio.h>
#include "STD_TYPES.h"
#include "sort.h"

/* ============ Info List Fns Prototypes ============= */
/*
    Pre  : Entries must be exist
    Post : swaping 2 listEntry items
*/
void SwapInfoNode(listEntry *Entry1, listEntry *Entry2){
    listEntry Temp;
    /* Put date of Entry1 in Temp */
    strcpy(Temp.ID, Entry1->ID);
    strcpy(Temp.Name, Entry1->Name);
    strcpy(Temp.BirthDay, Entry1->BirthDay);
    strcpy(Temp.Address, Entry1->Address);
    Temp.Phone = Entry1->Phone;
    /* Put date of Entry2 in Entry1 */
    strcpy(Entry1->ID, Entry2->ID);
    strcpy(Entry1->Name, Entry2->Name);
    strcpy(Entry1->BirthDay, Entry2->BirthDay);
    strcpy(Entry1->Address, Entry2->Address);
    Entry1->Phone = Entry2->Phone;
    /* Put date of Temp in Entry2 */
    strcpy(Entry2->ID, Temp.ID);
    strcpy(Entry2->Name, Temp.Name);
    strcpy(Entry2->BirthDay, Temp.BirthDay);
    strcpy(Entry2->Address, Temp.Address);
    Entry2->Phone = Temp.Phone;
}//SwapInfoNode
/*
    Pre  : Nodes must be exist
    Post : put the last node at its right ordered position
*/
listNode* PartitionInfo(listNode *Low, listNode *High){
    /* Choosing last node as pivot */
    u8 Pivot[50];
    strcpy(Pivot, High->Data.Name);
    listNode *i = Low->Prev;

    for(listNode *j = Low; j != High; j = j->Next){
        if(strcmpi(j->Data.Name,Pivot) <= 0){
           i = (i == NULL)? Low : i->Next;
           SwapInfoNode(&(i->Data), &(j->Data));
        }//if
    }//for
    i = (i == NULL)? Low : i->Next;
    SwapInfoNode(&(i->Data), &(High->Data));
    return(i);
}//PartitionInfo
/*
    Pre  : Nodes must be exist
    Post : sorting the list using the partitionInfo Fn
*/
void QuickSortInfo(listNode *Low, listNode *High){
    listNode *P;
    if((High != NULL) && (Low != High) && (Low != High->Next)){
        P = PartitionInfo(Low, High);
        QuickSortInfo(Low, P->Prev);
        QuickSortInfo(P->Next, High);
    }//if
}//QuickSortInfo
/*
    Pre  : List must be exist
    Post : Get the head and the tail and start the quick sorting
*/
void BeginSortingInfo(listSt *InfoP){
    listNode *Low;
    listNode *High;
    /* Finding Head Node */
    for(; InfoP->Current->Prev != NULL; InfoP->CurrentPos--){
        InfoP->Current = InfoP->Current->Prev;
    }//for
    Low = InfoP->Current;
    /* Finding Last Node */
    for(; InfoP->Current->Next != NULL; InfoP->CurrentPos++){
        InfoP->Current = InfoP->Current->Next;
    }//for
    High = InfoP->Current;
    QuickSortInfo(Low, High);
}//BeginSortingInfo

/* ================== Scores List Fns =========================== */
/*
    Pre  : Entries must be exist
    Post : swaping 2 listEntry items
*/
void SwapScoreNode(scoreEntry *Entry1, scoreEntry *Entry2){
    scoreEntry Temp;
    /* Put date of Entry1 in Temp */
    strcpy(Temp.Name, Entry1->Name);
    Temp.Grade = Entry1->Grade;
    /* Put date of Entry2 in Entry1 */
    strcpy(Entry1->Name, Entry2->Name);
    Entry1->Grade = Entry2->Grade;
    /* Put date of Temp in Entry2 */
    strcpy(Entry2->Name, Temp.Name);
    Entry2->Grade = Temp.Grade;
}//SwapScoreNode
/*
    Pre  : Nodes must be exist
    Post : put the last node at its right ordered position
*/
scoreNode* PartitionScore(scoreNode *Low, scoreNode *High){
    /* Choosing last node as pivot */
    s8 Pivot = High->Score.Grade;
    scoreNode *i = Low->Prev;

    for(scoreNode *j = Low; j != High; j = j->Next){
        if(j->Score.Grade >= Pivot){
           i = (i == NULL)? Low : i->Next;
           SwapScoreNode(&(i->Score), &(j->Score));
        }//if
    }//for
    i = (i == NULL)? Low : i->Next;
    SwapScoreNode(&(i->Score), &(High->Score));
    return(i);
}//PartitionScore
/*
    Pre  : Nodes must be exist
    Post : sorting the list using the partitionInfo Fn
*/
void QuickSortScores(scoreNode *Low, scoreNode *High){
    scoreNode *P;
    if((High != NULL) && (Low != High) && (Low != High->Next)){
        P = PartitionScore(Low, High);
        QuickSortScores(Low, P->Prev);
        QuickSortScores(P->Next, High);
    }//if
}//QuickSortScores
/*
    Pre  : List must be exist
    Post : Get the head and the tail and start the quick sorting
*/
void BeginScoresSorting(scoreList *ScoreP){
    scoreNode *Low;
    scoreNode *High;
    /* Finding Head Node */
    for(; ScoreP->Current->Prev != NULL; ScoreP->CurrentPos--){
        ScoreP->Current = ScoreP->Current->Prev;
    }//for
    Low = ScoreP->Current;
    /* Finding Last Node */
    for(; ScoreP->Current->Next != NULL; ScoreP->CurrentPos++){
        ScoreP->Current = ScoreP->Current->Next;
    }//for
    High = ScoreP->Current;
    QuickSortScores(Low, High);
}//BeginScoresSorting
