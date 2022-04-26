/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    Tree header file.
*/

#ifndef TREE_H
#define TREE_H
#include "config.h"
#if (IMP == TREE)
    enum editOptions{Return, ID, Name, BirthDay, Address, Phone};

    typedef struct birth{
        u8 Day;
        u8 Month;
        u32 Year;
    }birthDay;
    typedef struct student{
        u8        ID[ID_SIZE];
        u8        Name[NAME_SIZE];
        birthDay  BirthDay;
        u8        Address[ADDRESS_SIZE];
        u64       Phone;
        s8        ComputerScience;
    }treeEntry;
    typedef struct node{
        struct node* Right;
        treeEntry    Data;
        struct node* Left;
    }treeNode;
    typedef treeNode* treeNodePtr;
    typedef struct scores{
        u8 Name[NAME_SIZE];
        s8 ComputerScience;
    }scoresSt;

    void CreateTree(treeNodePtr *NodePtrP, u8 *SizeP);
    u8   IsEmpty(treeNodePtr NodePtr);
    void InsertNode(treeNodePtr *NodePtrP,  treeEntry *EntryPtr);
    void TravInOrder(treeNodePtr *NodePtrP);
    treeNodePtr* GetMinValue(treeNodePtr* NodePtrP);
    void DeleteNode(treeNodePtr *NodePtrP, u8 Name[]);
    void EditStudentRecord(treeNodePtr *NodePtrP, u8 Name[]);
    void FillScores(treeNodePtr *NodePtrP, u8 *SizeP, scoresSt **ScoresArr, u8 *IterP);
#endif
#endif
