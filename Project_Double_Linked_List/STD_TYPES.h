/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    Defined Types header file.
*/

/* The header file guard */
#ifndef STD_TYPES_H
#define STD_TYPES_H

    #define ID_SIZE                  16
    #define NAME_SIZE                50
    #define BIRTH_SIZE               15
    #define ADD_SIZE                 70
    /* Defining Types */
    typedef unsigned char            u8;
    typedef signed char              s8;
    typedef unsigned int             u32;
    typedef signed int               s32;
    typedef unsigned long long int   u64;
    /* Students Info List */
    typedef struct st{
        u8  ID[ID_SIZE];
        u8  Name[NAME_SIZE];
        u8  BirthDay[BIRTH_SIZE];
        u8  Address[ADD_SIZE];
        u64 Phone;
    }student;
    typedef student listEntry;
    typedef struct node{
        listEntry Data;
        struct node* Next;
        struct node* Prev;
    }listNode;
    typedef struct listst{
        s32 Count;
        s32 CurrentPos;
        listNode *Current;
    }listSt;
    /* Students Scores List */
    typedef struct scoreentry{
        u8  Name[NAME_SIZE];
        s8  Grade;
    }scoreEntry;
    typedef struct scorenode{
        scoreEntry  Score;
        struct scorenode *Next;
        struct scorenode *Prev;
    }scoreNode;
    typedef struct scorelist{
        s32 Count;
        s32 CurrentPos;
        scoreNode *Current;
    }scoreList;
#endif
