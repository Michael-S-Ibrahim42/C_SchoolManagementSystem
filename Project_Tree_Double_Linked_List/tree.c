/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    Tree source file.
*/
#include "config.h"
#if (IMP == TREE)
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "tree.h"

void CreateTree(treeNodePtr *NodePtrP, u8 *SizeP){
    *NodePtrP = NULL;
    *SizeP = 0;
}//CreateTree
u8   IsEmpty(treeNodePtr NodePtr){
    return(!NodePtr);
}//IsEmpty
void InsertNode(treeNodePtr *NodePtrP,  treeEntry *EntryPtr){
    if(!(*NodePtrP)){
        *NodePtrP = (treeNodePtr) malloc(sizeof(treeNode));

        (*NodePtrP)->Data = *EntryPtr;
        (*NodePtrP)->Right = NULL;
        (*NodePtrP)->Left  = NULL;
    }//if
    else if((strcmpi((*NodePtrP)->Data.Name, EntryPtr->Name)) < 0){
        InsertNode(&((*NodePtrP)->Right), EntryPtr);
    }//else if
    else if((strcmpi((*NodePtrP)->Data.Name, EntryPtr->Name)) > 0){
        InsertNode(&((*NodePtrP)->Left), EntryPtr);
    }//else
}//InsertNode
void TravInOrder(treeNodePtr *NodePtrP){
    if((*NodePtrP) != NULL){
                TravInOrder(&(*NodePtrP)->Left);
                printf("%-12s| ",(*NodePtrP)->Data.ID);
                printf("%-30s| ",(*NodePtrP)->Data.Name);
                printf("%-2u/%-2u/%-6u| ",(*NodePtrP)->Data.BirthDay.Day, (*NodePtrP)->Data.BirthDay.Month, (*NodePtrP)->Data.BirthDay.Year );
                printf("%-12llu| ",(*NodePtrP)->Data.Phone);
                printf("%-60s\n"  ,(*NodePtrP)->Data.Address);
                printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
                TravInOrder(&(*NodePtrP)->Right);
    }//if
}//TravInOrder
treeNodePtr* GetMinValue(treeNodePtr* NodePtrP){
    while((*NodePtrP)->Left != NULL){
        NodePtrP = &((*NodePtrP)->Left);
    }//while
    return(NodePtrP);
}//GetMinValue
void DeleteNode(treeNodePtr *NodePtrP, u8 Name[]){
    treeNodePtr *TempPP;
    treeNodePtr TempP;
    if(!(*NodePtrP)){
        printf("Student name is not exist!\n");
    }//if
    else{
        if(strcmpi((*NodePtrP)->Data.Name, Name) < 0){
            DeleteNode(&((*NodePtrP)->Right), Name);
        }//if
        else if(strcmpi((*NodePtrP)->Data.Name, Name) > 0){
            DeleteNode(&((*NodePtrP)->Left), Name);
        }//else if
        else{
            if(!((*NodePtrP)->Left)){
                TempP = (*NodePtrP)->Right;
                free(*NodePtrP);
                (*NodePtrP) = TempP;
            }//if
            else if(!((*NodePtrP)->Right)){
                TempP = (*NodePtrP)->Left;
                free(*NodePtrP);
                (*NodePtrP) = TempP;
            }//else if
            else{
                TempPP = GetMinValue(&((*NodePtrP)->Right));
                (*NodePtrP)->Data = (*TempPP)->Data;
                DeleteNode(&((*NodePtrP)->Right), (*NodePtrP)->Data.Name);
            }//else
        }//else
    }//else
}//DeleteNode
void EditStudentRecord(treeNodePtr *NodePtrP, u8 Name[]){
    treeNodePtr TempP;
    enum editOptions Selection;
    if(!(*NodePtrP)){
        printf("Student name is not exist!");
    }//if
    else{
        if(strcmpi((*NodePtrP)->Data.Name, Name) > 0){
            EditStudentRecord(&((*NodePtrP)->Left), Name);
        }//if
        else if(strcmpi((*NodePtrP)->Data.Name, Name) < 0){
            EditStudentRecord(&((*NodePtrP)->Right), Name);
        }//else if
        else{
            do{
                printf("Plz select the specific field to edit:\n");
                printf("1-ID\n2-Name\n3-BirthDay\n4-Address\n5-Phone\n0-Return\n");
                fflush(stdin);
                scanf("%d", &Selection);
                switch(Selection){
                    case ID:
                        fflush(stdin);
                        printf("Plz enter new ID:");
                        scanf("%[^\n]%*c", &((*NodePtrP)->Data.ID));
                        break;
                    case 2:
                        fflush(stdin);
                        printf("Plz enter new Name:");
                        scanf("%[^\n]%*c", &((*NodePtrP)->Data.Name));
                        break;
                    case BirthDay:
                        fflush(stdin);
                        printf("Plz enter new Birthday:");
                        scanf("%u %u %u", &((*NodePtrP)->Data.BirthDay.Day), &((*NodePtrP)->Data.BirthDay.Month), &((*NodePtrP)->Data.BirthDay.Year));
                        break;
                    case Address:
                        fflush(stdin);
                        printf("Plz enter new Adress:");
                        scanf("%[^\n]%*c", &((*NodePtrP)->Data.Address));
                        break;
                    case Phone:
                        fflush(stdin);
                        printf("Plz enter new Phone:");
                        scanf("%llu", &((*NodePtrP)->Data.Phone));
                        break;
                    case Return:
                        break;
                    default:
                        printf("Wrong Choice!\n");
                }//switch
            }while(Selection != Return);
        }//else
    }//else
}//EditStudentRecord
void FillScores(treeNodePtr *NodePtrP, u8 *SizeP, scoresSt **ScoresArr, u8 *IterP){
    if(((*NodePtrP) != NULL) && (*IterP < *SizeP)){
        FillScores(&((*NodePtrP)->Left), SizeP, ScoresArr, IterP);
        strcpy(((*ScoresArr)+(*IterP))->Name, (*NodePtrP)->Data.Name);
        ((*ScoresArr)+(*IterP))->ComputerScience = (*NodePtrP)->Data.ComputerScience;
        (*IterP)++;
        FillScores(&((*NodePtrP)->Right), SizeP, ScoresArr, IterP);
    }//if
}//TravInOrder
#endif
