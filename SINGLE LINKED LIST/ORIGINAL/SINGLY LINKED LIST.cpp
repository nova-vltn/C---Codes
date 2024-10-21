#include<iostream>
#include<iomanip>
#include<memory>
#include<string>
#include<conio.h>
#include <stdlib.h>
#include<windows.h>
using namespace std;
typedef struct node{
	char studno[15];
	char studname[25];
	char studcrsyr[15];
	float GWA;
	struct node *next;
}node;

void MainMenu();
void CreateList(node **START);
void DisplayList(node **START);
void AddBef(node **START);
void AddAft(node **START);
void DelVal(node **START);
void gotoxy(int x, int y){
    printf("%c[%d;%df",0x1B,y,x);
}

int main(){
	node *START;
	int choice;
	char back;
	START=NULL;
	
	menu:
	MainMenu();
	gotoxy(10,21);
	cout <<"Enter your choice: ";
	cin >>choice;	
	switch(choice){
		case 1:
			CreateList(&START);
			goto menu;
	
		case 2:
			DisplayList(&START);
			cout <<"\tPress any key to return to main menu...";
			cout <<"\n\n========================================================================================================================\n\n";
			getch();
			goto menu;
			
		case 5:
			AddBef(&START);
			cout << "\tPress any key to return to main menu...";
			cout <<"\n\n========================================================================================================================\n\n";			getch();
			goto menu;
		
		case 6:
			AddAft(&START);
			cout << "\tPress any key to return to main menu...";
			cout <<"\n\n========================================================================================================================\n\n";
			getch();
			goto menu;
			
		case 9: 
			DelVal(&START);
			goto menu;
			
		case 10:
			return 0;
			
		default: 
			gotoxy(10,22);
			cout <<"Invalid Choice!!!";
			getch();
			goto menu;
	}
}

void MainMenu(){
	system("cls");
	system("COLOR F1");
	cout <<"\n================================================== MAIN MENU ===========================================================\n";
	gotoxy(36, 4);
	cout <<"Student Record (Singly Linked List) ";
	gotoxy(40, 5);
	cout <<"by DSA Group 4 (Searching)\n";
	cout <<"\n====================================================	====================================================================\n";		
	gotoxy(10,9);
	cout <<"[1] Create a Student Record";
	gotoxy(10,11);	
	cout <<"[2] Display Student Record";	
	gotoxy(10,13);
	cout <<"[3] Add a New Record at the Start";	
	gotoxy(10,15);
	cout <<"[4] Add a New Record at the End";	
	gotoxy(10,17);
	cout <<"[5] Add/Insert a New Record Before a Data";	
	gotoxy(60,9);
	cout <<"[6]  Add/Insert a New Record After a Data";	
	gotoxy(60,11);
	cout <<"[7]  Deletion of Node at the Start";
	gotoxy(60,13);
	cout <<"[8]  Deletion of Node at the End";
	gotoxy(60,15);
	cout <<"[9]  Deletion of Node by Value";	
	gotoxy(60,17);
	cout <<"[10] Exit";
	gotoxy(0,19);
	cout <<"========================================================================================================================";
	gotoxy(0,23);
	cout <<"========================================================================================================================";
}

void CreateList(node **START){
	node *NewNode,*temp;
	int ctr=1;
	char choice2;
	system("cls");
	*START=NULL;
	NewNode = NULL;
    cout << "========================================================================================================================\n";
	gotoxy(40,3);
	cout << "CREATING A STUDENT RECORD\n";
	cout << "\n========================================================================================================================\n";
	do{
    	NewNode=(node*)malloc(sizeof(node));
		if (NewNode == NULL) {
            cout <<"Memory allocation failed!\n";
            exit(1);
        }	
		cout << "\n\tStudent #" << ctr << " Number\t\t: ";
		cin >> NewNode->studno;
		cout << "\n\tStudent #" << ctr << " Name\t\t\t: ";
		cin.ignore();
		cin.getline(NewNode->studname,25); 	
		cout << "\n\tCourse and Year\t\t\t: ";
		cin.getline(NewNode->studcrsyr,15); 	
		cout << "\n\tGWA\t\t\t\t: ";
		cin >> NewNode->GWA;	
		cout << "\n========================================================================================================================\n\n";
		cout << "\tAdd another record? [Y/N]: ";
		cin >> choice2;
		cout << "\n========================================================================================================================\n\n";	
		
		NewNode->next = NULL;
        if (*START == NULL){
            *START = NewNode;
        } else{
            temp->next = NewNode;
        }
        temp = NewNode;
        ctr++;
    }while (toupper(choice2) == 'Y');
}	

void DisplayList(node **START){
	node *Current;
	int ctr=1;
	system("cls");
	cout << "\n=============================================  STUDENT'S GWA REPORT  ===================================================\n\n";
    Current = *START;
	if (Current==NULL) {
		gotoxy(45,5);
		cout << "Student Record is empty!\n" << "";
		cout << "\n\n========================================================================================================================\n\n";
    } else{
    	gotoxy(10,4);
    	cout << "Student No."; 	
    	gotoxy(40,4);
    	cout << "Student Name";	
    	gotoxy(70,4);
    	cout << "Course & Year";	
    	gotoxy(100,4);
    	cout << "GWA\n\n";
    	
		int i=5;
    	while(Current!=NULL){
    		gotoxy(0,i);
			cout << ctr;			
    		gotoxy(10,i);
			cout << Current->studno;			
			gotoxy(40,i);
    		cout << Current->studname;   		
    		gotoxy(70,i);
    		cout << Current->studcrsyr;   		
    		gotoxy(100,i);
    		cout << Current->GWA;
    		
			i++;
			Current=Current->next;
    		ctr++;
		}
		cout << "\n\n========================================================================================================================\n\n";
    }
}

void AddBef(node **START){
    system("cls");
    cout << "\n=================================  ADDING A NEW RECORD BEFORE A GIVEN STUDENT RECORD  ==================================\n\n\n";
    if (*START == NULL) {
		gotoxy(45,5);
		cout << "Student Record is empty!\n";
		cout << "\n\n========================================================================================================================\n\n";
    	getch();
		return;
	}

    char studentNoToFind[15];
    cout << "\tEnter the Student Number before which you want to add the new record: ";
    cin >> studentNoToFind;
	cout << "\n\n========================================================================================================================\n\n";

    node *current = *START;
    node *prev = NULL;

    while (current != NULL && strcmp(current->studno, studentNoToFind) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "\tError: The specified student record not found.\n";
        cout << "\n========================================================================================================================\n\n";
        getch();
		return;
    }

    node *newRecord = (node*)malloc(sizeof(node));
    if (newRecord == NULL) {
        cout << "\tError: Memory allocation failed.\n";
        exit(1);
    }
	cout << "\n===============================================  INSERT THE NEW RECORD  ================================================\n\n\n";
	cout << "\n\tStudent Number\t\t\t: ";
	cin >> newRecord->studno;	
	cout << "\n\tStudent Name\t\t\t: ";
	cin.ignore();
	cin.getline(newRecord->studname,25); 
	cout << "\n\tCourse and Year\t\t\t: ";
	cin.getline(newRecord->studcrsyr,15); 
	cout << "\n\tGWA\t\t\t\t: ";
	cin >> newRecord->GWA;
	cout << "\n========================================================================================================================\n\n";
	if (prev == NULL) {
        newRecord->next = *START;
        *START = newRecord;
    } else {
        newRecord->next = current;
        prev->next = newRecord;
    }
    cout << "\tNew Student Record has been added before the specified Student Number.\n";
	cout << "\n========================================================================================================================\n\n";
    getch();
}

void AddAft(node **START){
    system("cls");
    cout << "\n=================================  ADDING A NEW RECORD AFTER A GIVEN STUDENT RECORD  ===================================\n\n\n";
    if (*START == NULL) {
        gotoxy(45,5);
		cout << "Student Record is empty!\n";
		cout << "\n\n========================================================================================================================\n\n";
        getch();
		return;
    }

    char studentNoToFind[15];
    cout << "\tEnter the Student Number after which you want to add the new record: ";
    cin >> studentNoToFind;
	cout << "\n\n========================================================================================================================\n\n";

    node *current = *START;
    while (current != NULL && strcmp(current->studno, studentNoToFind) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "\tError: The specified student record not found.\n";
		cout <<"\n========================================================================================================================\n\n";
        getch();
		return;
    }

    node *newRecord = (node*)malloc(sizeof(node));
    if (newRecord == NULL) {
        cout << "\tError: Memory allocation failed.\n";
        exit(1);
    }

	cout <<"\n===============================================  INSERT THE NEW RECORD  ================================================\n\n\n";
    cout << "\n\tStudent Number\t\t\t: ";
	cin >> newRecord->studno;		
	cout << "\n\tStudent Name\t\t\t: ";
	cin.ignore();
	cin.getline(newRecord->studname,25); 	
	cout << "\n\tCourse and Year\t\t\t: ";
	cin.getline(newRecord->studcrsyr,15); 	
	cout << "\n\tGWA\t\t\t\t: ";
	cin >> newRecord->GWA;
	cout <<"\n========================================================================================================================\n\n";
    
	newRecord->next = current->next;
    current->next = newRecord;
    cout << "\tNew Student Record has been added after the specified Student Number.\n";
	cout <<"\n========================================================================================================================\n\n";
    getch();
}

void DelVal(node **START){
    char Del_Val[15];
    int Flag = 0;
    node *DelNode, *Previous = NULL, *temp;
    system("cls");
    cout << "\n=========================================  DELETION OF NODE BY VALUE  ==================================================\n\n";
    cout << "\tEnter Student No.\t\t: ";
    cin >> Del_Val;
	cout <<"\n========================================================================================================================\n\n";

    Previous = NULL;
	DelNode = *START;
    while (DelNode != NULL) {
        if (strcmp(Del_Val, DelNode->studno) == 0) {
            Flag = 1;
            break;
        }
        Previous = DelNode;
        DelNode = DelNode->next;
    }
    if (Flag == 0) {
        cout << "\tStudent Record Not Found!";
		cout <<"\n\n========================================================================================================================\n\n";
        cout << "\tPress any key to return to main menu...\n";
		cout <<"\n========================================================================================================================\n\n";
        getch();
    } else{
        if (Previous == NULL) {
            *START = (*START)->next;
        } else {
            Previous->next = DelNode->next;
        }
        cout << "\tNode with Student No. " << Del_Val << " deleted successfully." << endl;
		cout <<"\n========================================================================================================================\n\n";
        cout << "\tPress any key to return to main menu...\n";
		cout <<"\n========================================================================================================================\n\n";
        free(DelNode);
        getch();
    }
}
