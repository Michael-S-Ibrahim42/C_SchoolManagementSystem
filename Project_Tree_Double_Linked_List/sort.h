/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    Sorting Algorithm header file.
*/

/* The header file guard */
#ifndef SORT_H
#define SORT_H
#include "config.h"
#if (IMP == TREE)
    void QuickSort(scoresSt **Scores, s8 Low, s8 High);
    s8 Partition(scoresSt **Scores, s8 Low, s8 High);
    void SwapNode(scoresSt *Entry1, scoresSt *Entry2);
#elif IMP == DOUBLE_LINKED_LIST

    /* ============ Info List Fns Prototypes ============= */
    /*
        Pre  : Entries must be exist
        Post : swaping 2 listEntry items
    */
    void SwapInfoNode(listEntry *Entry1, listEntry *Entry2);
    /*
        Pre  : Nodes must be exist
        Post : put the last node at its right ordered position
    */
    listNode* PartitionInfo(listNode *Low, listNode *High);
    /*
        Pre  : Nodes must be exist
        Post : sorting the list using the partitionInfo Fn
    */
    void QuickSortInfo(listNode *Low, listNode *High);
    /*
        Pre  : List must be exist
        Post : Get the head and the tail and start the quick sorting
    */
    void BeginSortingInfo(listSt *InfoP);

    /* ============ Scores List Fns Prototypes ============= */
    /*
        Pre  : Entries must be exist
        Post : swaping 2 listEntry items
    */
    void SwapScoreNode(scoreEntry *Entry1, scoreEntry *Entry2);
    /*
        Pre  : Nodes must be exist
        Post : put the last node at its right ordered position
    */
    scoreNode* PartitionScore(scoreNode *Low, scoreNode *High);
    /*
        Pre  : Nodes must be exist
        Post : sorting the list using the partitionInfo Fn
    */
    void QuickSortScores(scoreNode *Low, scoreNode *High);
    /*
        Pre  : List must be exist
        Post : Get the head and the tail and start the quick sorting
    */
    void BeginScoresSorting(scoreList *ScoreP);
#endif
#endif

