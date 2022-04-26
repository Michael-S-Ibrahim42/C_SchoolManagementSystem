/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    Double Linked List header file.
*/

/* The header file guard */
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "config.h"
#if(IMP == DOUBLE_LINKED_LIST)
    /* Fns Prototypes */
    /* ============= Info List Fns ============= */
    /*
        Pre     :   Info list struct variable defined
        Post    :   Initialize variable members
    */
    void CreateListI(listSt *ListP);
    /*
        Pre     :   Info List exist and position is valid
        Post    :   Deleting the required node
    */
    void DeleteNodeI(listSt *ListP, s32 Position);
    /*
        Pre     :   Info List is exist
        Post    :   Checking if the list is empty
    */
    u8 IsEmptyI(listSt *ListP);
    /*
        Pre     :   students Info list initialized
        Post    :   Getting the right relative position to your need and update the current pointer and counter
    */
    s32 GetPositionI(listSt *ListP, listEntry Entry);
    /*
        Pre     :   Info List exist
        Post    :   Inserting the node at the right position w.r.t passed position of the Info list
    */
    void InsertNodeI(listSt *ListP, listEntry Entry, s32 Position);
    /*
        Pre     :   Info List exist.
        Post    :   Printing the Info list.
    */
    void PrintListI(listSt *ListP);

    /* ============= Scores List Fns ============= */
    /*
        Pre     :   Scores list struct variable defined
        Post    :   Initialize variable members
    */
    void CreateListS(scoreList *ListP);
    /*
        Pre     :   Scores List exist and position is valid
        Post    :   Deleting the required node
    */
    void DeleteNodeS(scoreList *ListP, s32 Position);
    /*
        Pre     :   Scores List is exist
        Post    :   Checking if the list is empty
    */
    u8 IsEmptyS(scoreList *ListP);
    /*
        Pre     :   students Scores list initialized
        Post    :   Getting the right relative position to fetch with the name is passed
    */
    s32 GetPositionS(scoreList *ListP, u8 *Name);
    /*
        Pre     :   students Scores list initialized
        Post    :   set the current pointer and current counter at the right relative position to insert with the grade is passed
    */
    s32 SetPositionS(scoreList *ListP, s8 Grade);
    /*
        Pre     :   Scores List exist
        Post    :   Inserting the node at the right position w.r.t passed position
    */
    void InsertNodeS(scoreList *ListP, scoreEntry Entry, s32 Position);
    /*
        Pre     :   Scores List exist.
        Post    :   Printing the Scores list.
    */
    void PrintListS(scoreList *ListP);
#endif
#endif

