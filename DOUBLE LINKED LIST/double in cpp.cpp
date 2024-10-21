#include<iostream>
#include <iomanip> 
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef struct STUDREC {
    char studname[25];
    char studno[15];
    char studcrsyr[15];
    float GWA;
    struct STUDREC* next;
    struct STUDREC* prev;
} STUDREC;

void MainMenu();
void CreateDLL(STUDREC **HEAD,STUDREC **TAIL);
void TravHead(STUDREC **HEAD);
void TravTail(STUDREC **TAIL);
void AddHead(STUDREC **HEAD, STUDREC **TAIL);
void AddTail(STUDREC **HEAD, STUDREC **TAIL);
void AddBef(STUDREC **HEAD);
void AddAft(STUDREC **HEAD, STUDREC **TAIL);
void DelHead(STUDREC **HEAD, STUDREC **TAIL);
void DelTail(STUDREC **HEAD, STUDREC **TAIL);
void DelVal(STUDREC **HEAD, STUDREC **TAIL, char *value);
void DelBef(STUDREC **HEAD);
void DelAft(STUDREC **HEAD, STUDREC **TAIL, char *studno);
void gotoxy(int x, int y);
void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

int main(){
    STUDREC *HEAD,*TAIL;
    int choice;
    char deletevalue[15];
    HEAD=TAIL=NULL;
    
    while (true) {
        MainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                CreateDLL(&HEAD, &TAIL);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
                
            case 2:
                TravHead(&HEAD);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
            
            case 3:
                TravTail(&TAIL);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
            
            case 4: 
                AddHead(&HEAD, &TAIL);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
                
            case 5: 
                AddTail(&HEAD, &TAIL);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
            
            case 6:
                AddBef(&HEAD);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
            
            case 7:
                AddAft(&HEAD,&TAIL);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
            
            case 8:
                DelHead(&HEAD,&TAIL);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
                
            case 9:
                DelTail(&HEAD,&TAIL);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
            
            case 10:
                cout << "Enter Student No. to delete: ";
                cin >> deletevalue;
                DelVal(&HEAD, &TAIL, deletevalue); 
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;

            case 11:
                DelBef(&HEAD);
                cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
                cout << "Press any key to return to main menu...";
                cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
                getch();
                break;
            
            case 12:
                if (HEAD == NULL){
                    cout << "--------------------------------------------------------------\n";
                    cout << "The Student Record is EMPTY!!!\n";
                    cout << "--------------------------------------------------------------\n";
                    getch();
                    break;
                }
                
                char studno[15];
                cout << "--------------------------------------------------------------\n";
                cout << "Enter Student No. after which you want to delete the node: ";
                cin >> studno;
                DelAft(&HEAD, &TAIL, studno);
                getch();
                break;
                
            case 13:
                return 0;
            
            default:
                cout << "Invalid Choice!!!";
                getch();
                break;
        }
    }
    return 0;
}

void MainMenu() {
    system("cls"); 
    system("COLOR F1"); 
    
    cout << "\n================================================== MAIN MENU ===========================================================\n";
    gotoxy(36, 4);
    cout << "Student Record (Doubly Linked List) ";
    gotoxy(40, 5);
    cout << "by DSA Group 4 (Searching)\n";
    cout << "\n========================================================================================================================\n";
    gotoxy(4, 9);
    cout << "[1] Create a Student Record";
    gotoxy(4, 11);    
    cout << "[2] Traverse Student Record (HEAD - from top to bottom)";
    gotoxy(4, 13);
    cout << "[3] Traverse Student Record (TAIL - from bottom to top)";
    gotoxy(4, 15);
    cout << "[4] Adding of Node in Student Record (at the head)";
    gotoxy(4, 17);
    cout << "[5] Adding of Node in Student Record (at the tail)";
    gotoxy(4, 19);
    cout << "[6] Adding of Node in Student Record (Before a Value)";
    gotoxy(62, 9);
    cout << "[7] Adding of Node in Student Record (After a Value)";
    gotoxy(62, 11);
    cout << "[8] Deletion of Node at the Head";
    gotoxy(62, 13);
    cout << "[9] Deletion of Node at the Tail";
    gotoxy(62, 15);
    cout << "[10] Deletion of Node by Value";
    gotoxy(62, 17);
    cout << "[11] Deletion of Node Before a Node";
    gotoxy(62, 19);
    cout << "[12] Deletion of Node After a Node";
    gotoxy(62, 21);
    cout << "[13] Exit";
    gotoxy(0, 23);
    cout << "========================================================================================================================";
    gotoxy(0, 25);
    cout << "========================================================================================================================";
}

void CreateDLL(STUDREC **HEAD,STUDREC **TAIL){
    STUDREC *NewNode,*Prev;
    char Resp;
    int ctr=1;
    system("cls");
    NewNode=(STUDREC*)malloc(sizeof(STUDREC));
    *HEAD=NewNode;
    *TAIL=NewNode;
    (*HEAD)->prev=NULL;
    
    cout << "\n------------------  CREATING A STUDENT RECORD  ------------------\n";
    do{
        cout << "\nStudent #" << ctr << " Number\t\t: ";
        cin >> NewNode->studno;
        
        cout << "\nStudent #" << ctr << " Name\t\t\t: ";
        cin.ignore();
        cin.getline(NewNode->studname, 25);
        
        cout << "\nCourse and Year\t\t\t: ";
        cin.getline(NewNode->studcrsyr, 15);
        
        cout << "\nGWA\t\t\t\t: ";
        cin >> NewNode->GWA;
        
        cout << "\n------------------------------------------------------------------\n\n";
        cout << "Add another record? [Y/N]: ";
        cin >> Resp;
        cout << "\n------------------------------------------------------------------\n\n";
        
        if(toupper(Resp) == 'Y'){
            ctr++;
            NewNode->next=(STUDREC*)malloc(sizeof(STUDREC));
            NewNode->next->prev=NewNode;
            NewNode=NewNode->next;
            *TAIL=NewNode;
        }
        
    } while(toupper(Resp) == 'Y');
    (*TAIL)->next=NULL;
    NewNode=NULL;
}

void TravHead(STUDREC **HEAD){
    STUDREC *TravNode;
    int ctr=1;
    system("cls");
    TravNode=*HEAD;
    cout << "\n------------------------------- STUDENT RECORD (HEAD - from top to bottom) ------------------------------\n";
    if(TravNode==NULL){
        cout << "\n Student Record is empty!\n";
        return;
    }
    
    else{
        gotoxy(10,5);
        cout << "Student No.";
        
        gotoxy(40,5);
        cout << "Student Name";
        
        gotoxy(70,5);
        cout << "Course & Year";
        
        gotoxy(100,5);
        cout << "GWA\n\n";
        do{
            cout << setw(1) << ctr;
            cout << setw(17) << TravNode->studno;
            cout << setw(35) << TravNode->studname;
            cout << setw(25) << TravNode->studcrsyr;
            cout << fixed << setprecision(2) << setw(25) << TravNode->GWA << endl << endl;
            TravNode=TravNode->next;
            ctr++;
        }while(TravNode!=NULL);
    }
}

void TravTail(STUDREC **TAIL){
    STUDREC *TravNode;
    int ctr=1;
    system("cls");
    TravNode=*TAIL;
    cout << "\n------------------------------- STUDENT RECORD (TAIL - from bottom to top) ------------------------------\n";
    if(TravNode==NULL){
        cout << "\n Student Record is empty!\n";
        cout << "\n--------------------------------------------------------\n\n";
        cout << "Press any key to return to main menu...";
        cout << "\n\n--------------------------------------------------------";
        getch();
        return;
    }
    else{
        gotoxy(10, 5);
        cout << "Student No.";
        
        gotoxy(40, 5);
        cout << "Student Name";
        
        gotoxy(70, 5);
        cout << "Course & Year";
        
        gotoxy(100, 5);
        cout << "GWA\n\n";
        do{
            cout << setw(1) << ctr;
            cout << setw(17) << TravNode->studno;
            cout << setw(35) << TravNode->studname;
            cout << setw(25) << TravNode->studcrsyr;
            cout << fixed << setprecision(2) << setw(25) << TravNode->GWA << endl << endl;
            TravNode=TravNode->prev;
            ctr++;
        } while(TravNode != NULL);
    }
}

void AddHead(STUDREC **HEAD, STUDREC **TAIL){
    STUDREC *NewNode;
    system("cls");
    NewNode=(STUDREC*)malloc(sizeof(STUDREC));
    
    cout << "\n---------------------------------------------------------\n";
    cout << "Adding of Node in Student Record (at the head)";
    cout << "\n---------------------------------------------------------\n";
    
    cout << "Enter Student No.: ";
    cin >> NewNode->studno;
    
    cout << "\nEnter Student Name: ";
    cin.ignore();
    cin.getline(NewNode->studname, 25);
    
    cout << "\nEnter Course & Year: ";
    cin.getline(NewNode->studcrsyr, 15);
    
    cout << "\nEnter GWA: ";
    cin >> NewNode->GWA;
    
    cout << "\n---------------------------------------------------------\n";
    NewNode->next=*HEAD;
    NewNode->prev=NULL;
    
    if (*HEAD!=NULL)
        (*HEAD)->prev=NewNode;
    *HEAD=NewNode;
    
    if(*TAIL==NULL)
        *TAIL=NewNode;
}

void AddTail(STUDREC **HEAD, STUDREC **TAIL){
    STUDREC *NewNode;
    system("cls");
    NewNode=(STUDREC*)malloc(sizeof(STUDREC));
    
    cout << "\n---------------------------------------------------------\n";
    cout << "Adding of Node in Student Record (at the tail)";
    cout << "\n---------------------------------------------------------\n";
    
    cout << "Enter Student No.: ";
    cin >> NewNode->studno;
    
    cout << "\nEnter Student Name: ";
    cin.ignore();
    cin.getline(NewNode->studname, 25);
    
    cout << "\nEnter Course & Year: ";
    cin.getline(NewNode->studcrsyr, 15);
    
    cout << "\nEnter GWA: ";
    cin >> NewNode->GWA;
    
    cout << "\n---------------------------------------------------------\n";
    NewNode->next=NULL;
    NewNode->prev=*TAIL;
    
    if (*TAIL!=NULL)
        (*TAIL)->next=NewNode;
    *TAIL=NewNode;
    
    if(*HEAD==NULL)
        *HEAD=NewNode;
}

void AddBef(STUDREC **HEAD){
    STUDREC *NewNode, *temp;
    char value[15];
    system("cls");
    temp = *HEAD;
    NewNode = (STUDREC*)malloc(sizeof(STUDREC));
    
    cout << "\n---------------------------------------------------------\n";
    cout << "Adding of Node in Student Record (Before a Value)";
    cout << "\n---------------------------------------------------------\n";
    cout << "Enter the Student No. of the node before which you want to add: ";
    cin >> value;
    
    while(temp != NULL && strcmp(temp->studno, value) != 0)
        temp = temp->next;
    
    if(temp == NULL){
        cout << "\nNode with Student No. " << value << " not found!";
        getch();
        return;
    }
    
    cout << "\nEnter Student No.: ";
    cin >> NewNode->studno;
    
    cout << "\nEnter Student Name: ";
    cin.ignore();
    cin.getline(NewNode->studname, 25);
    
    cout << "\nEnter Course & Year: ";
    cin.getline(NewNode->studcrsyr, 15);
    
    cout << "\nEnter GWA: ";
    cin >> NewNode->GWA;
    
    cout << "\n---------------------------------------------------------\n";
    NewNode->next = temp;
    NewNode->prev = temp->prev;
    
    if(temp->prev != NULL)
        temp->prev->next = NewNode;
    else
        *HEAD = NewNode;
    
    temp->prev = NewNode;
}

void AddAft(STUDREC **HEAD, STUDREC **TAIL){
    STUDREC *NewNode, *temp;
    char value[15];
    system("cls");
    temp = *HEAD;
    NewNode = (STUDREC*)malloc(sizeof(STUDREC));
    
    cout << "\n---------------------------------------------------------\n";
    cout << "Adding of Node in Student Record (After a Value)";
    cout << "\n---------------------------------------------------------\n";
    cout << "Enter the Student No. of the node after which you want to add: ";
    cin >> value;
    
    while(temp != NULL && strcmp(temp->studno, value) != 0)
        temp = temp->next;
    
    if(temp == NULL){
        cout << "\nNode with Student No. " << value << " not found!";
        getch();
        return;
    }
    
    cout << "\nEnter Student No.: ";
    cin >> NewNode->studno;
    
    cout << "\nEnter Student Name: ";
    cin.ignore();
    cin.getline(NewNode->studname, 25);
    
    cout << "\nEnter Course & Year: ";
    cin.getline(NewNode->studcrsyr, 15);
    
    cout << "\nEnter GWA: ";
    cin >> NewNode->GWA;
    
    cout << "\n---------------------------------------------------------\n";
    NewNode->next = temp->next;
    NewNode->prev = temp;
    
    if(temp->next != NULL)
        temp->next->prev = NewNode;
    else
        *TAIL = NewNode;
    
    temp->next = NewNode;
}

void DelHead(STUDREC **HEAD, STUDREC **TAIL){
    STUDREC *temp;
    system("cls");
    cout << "\n---------------------------------------------------------\n";
    cout << "Deleting of Node at the Head";
    cout << "\n---------------------------------------------------------\n";
    
    if(*HEAD == NULL){
        cout << "\nStudent Record is empty!";
        getch();
        return;
    }
    
    temp = *HEAD;
    *HEAD = (*HEAD)->next;
    
    if(*HEAD != NULL)
        (*HEAD)->prev = NULL;
    else
        *TAIL = NULL;
    
    free(temp);
    cout << "\nNode at the head deleted successfully!";
    getch();
}

void DelTail(STUDREC **HEAD, STUDREC **TAIL){
    STUDREC *temp;
    system("cls");
    cout << "\n---------------------------------------------------------\n";
    cout << "Deleting of Node at the Tail";
    cout << "\n---------------------------------------------------------\n";
    
    if(*TAIL == NULL){
        cout << "\nStudent Record is empty!";
        getch();
        return;
    }
    
    temp = *TAIL;
    *TAIL = (*TAIL)->prev;
    
    if(*TAIL != NULL)
        (*TAIL)->next = NULL;
    else
        *HEAD = NULL;
    
    free(temp);
    cout << "\nNode at the tail deleted successfully!";
    getch();
}

void DelVal(STUDREC **HEAD, STUDREC **TAIL, char *value){
    STUDREC *temp;
    system("cls");
    cout << "\n---------------------------------------------------------\n";
    cout << "Deleting of Node by Value";
    cout << "\n---------------------------------------------------------\n";
    
    if(*HEAD == NULL){
        cout << "\nStudent Record is empty!";
        getch();
        return;
    }
    
    temp = *HEAD;
    while(temp != NULL && strcmp(temp->studno, value) != 0)
        temp = temp->next;
    
    if(temp == NULL){
        cout << "\nNode with Student No. " << value << " not found!";
        getch();
        return;
    }
    
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *HEAD = temp->next;
    
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        *TAIL = temp;
    
    free(temp);
    cout << "\nNode with Student No. " << value << " deleted successfully!";
    getch();
}

void DelBef(STUDREC **HEAD){
    STUDREC *temp;
    char value[15];
    system("cls");
    cout << "\n---------------------------------------------------------\n";
    cout << "Deleting of Node Before a Value";
    cout << "\n---------------------------------------------------------\n";
    cout << "Enter the Student No. of the node before which you want to delete: ";
    cin >> value;
    
    if(*HEAD == NULL){
        cout << "\nStudent Record is empty!";
        getch();
        return;
    }
    
    temp = *HEAD;
    while(temp->next != NULL && strcmp(temp->next->studno, value) != 0)
        temp = temp->next;
    
    if(temp->next == NULL){
        cout << "\nNode with Student No. " << value << " not found!";
        getch();
        return;
    }
    
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    else
        *HEAD = temp->next;
    
    free(temp);
    cout << "\nNode before the node with Student No. " << value << " deleted successfully!";
    getch();
}

void DelAft(STUDREC **HEAD, STUDREC **TAIL, char *studno){
    STUDREC *temp;
    system("cls");
    cout << "\n---------------------------------------------------------\n";
    cout << "Deleting of Node After a Node";
    cout << "\n---------------------------------------------------------\n";
    
    if(*HEAD == NULL){
        cout << "\nStudent Record is empty!";
        getch();
        return;
    }
    
    temp = *HEAD;
    while(temp != NULL && strcmp(temp->studno, studno) != 0)
        temp = temp->next;
    
    if(temp == NULL || temp->next == NULL){
        cout << "\nNo node exists after the given node!";
        getch();
        return;
    }
    
    STUDREC *delNode = temp->next;
    temp->next = delNode->next;
    
    if(delNode->next != NULL)
        delNode->next->prev = temp;
    else
        *TAIL = temp;
    
    free(delNode);
    cout << "\nNode after the node with Student No. " << studno << " deleted successfully!";
    getch();
}

