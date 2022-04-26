/* ************************************* */
/* Author   :   Michael S. Barsoum       */
/* Date     :   July 3, 2021             */
/* Version  :   V01                      */
/* ************************************* */
/* Description:-
    =================== School Management System =======================
    School System header file.
*/

/* The header file guard */
#ifndef SCHOOL_SYSTEM_H
#define SCHOOL_SYSTEM_H

    /* Declaration of enum type */
    enum menuOptions{Return_Welcome_Window, Add_Student, Delete_Student, Display_List, Edit_Student, Rank_Students, Update_Score};
    enum editOptions{Return, ID, Name, BirthDay, Address, Phone};
    /* Fns Prototypes */
    /*
        Pre  : Info and scores lists initialized
        Post : Entering Main Menu to let user select what to do in the program
    */
    void EnterMainMenu(listSt *SchoolP,scoreList *ScoreP);
    /*
        Pre  :  Info and scores lists initialized
        Post :  Adding new student record
    */
    void AddNewStudent(listSt *SchoolP, scoreList *ScoreP);
    /*
        Pre  : Info and scores lists initialized and not empty
        Post : delete passed student name
    */
    void DeleteStudent(listSt *SchoolP, scoreList *ScoreP, student S);
    /*
        Pre  : Info list initialized
        Post : Display the list in order and displaying the list size
    */
    void DisStudentList(listSt *SchoolP);
    /*
        Pre  : Info list initialized
        Post : Edit student information list
    */
    void EditStudent(listSt *SchoolP, scoreList *ScoreP, student S);
    /*
        Pre  :  scores list initialized
        Post :  display stored students grades in order
    */
    void RankStudent(scoreList *ScoreP);
    /*
        Pre  :  scores list initialized
        Post :  update specific student computer science score
    */
    void UpdateStudentScore(scoreList *ScoreP, u8 *Name);
#endif

