#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct studrec {
    char studname[50];
    char studno[25];
    char studcrsyr[25];
    float GWA;
    struct studrec* next;
} studrec;

void MainMenu();
void createstack(studrec **top);
void travstack(studrec **top);
void addstack(studrec **top);
void delstack(studrec **top);
void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "f";
}

int main() {
    studrec *top = NULL;
    int choice;
    menu:
        MainMenu();
        gotoxy(0, 25);
        cout << "=========================================================================================================";
        gotoxy(10, 23);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createstack(&top);
                goto menu;

            case 2:
                travstack(&top);
                goto menu;

            case 3:
                addstack(&top);
                goto menu;

            case 4:
                delstack(&top);
                goto menu;

            case 5:
                return 0;

            default:
                gotoxy(10, 27);
                cout << "WARNING: Invalid Choice!!!\n";
                cout << "\n=========================================================================================================\n\n";
                cin.ignore(); 
                cin.get(); 
                goto menu;
        }
    return 0;
}

void MainMenu() {
    system("cls");
    system("COLOR F1");
    cout << "\n========================================== MAIN MENU ====================================================\n";
    gotoxy(37, 4);
    cout << "Student Record (Stacks) ";
    gotoxy(36, 5);
    cout << "by DSA Group 1 (Searching)\n";
    cout << "\n=========================================================================================================\n";
    gotoxy(10, 10);
    cout << "[1] Create a Student Record\n";
    gotoxy(10, 12);
    cout << "[2] Traverse Student Record";
    gotoxy(10, 14);
    cout << "[3] Add Student Record\n";
    gotoxy(10, 16);
    cout << "[4] Delete Student Record\n";
    gotoxy(10, 18);
    cout << "[5] Exit Program\n";
    gotoxy(10, 20);
    cout << "\n=========================================================================================================\n";
}

void createstack(studrec **top) {
    studrec *PushNode;
    char Resp;
    int ctr = 1;
    system("cls");

    PushNode = new studrec;
    PushNode->next = NULL;
    *top = PushNode;

    cout << "\n=========================================================================================================\n";
    gotoxy(40, 4);
    cout << "CREATING A STUDENT RECORD\n";
    cout << "\n=========================================================================================================\n";
    do {
        cout << "\n\tStudent #" << ctr << " Number\t\t: ";
        cin >> PushNode->studno;

        cout << "\n\tStudent #" << ctr << " Name\t\t\t: ";
        cin.ignore();
        cin.getline(PushNode->studname, 50);

        cout << "\n\tCourse and Year\t\t\t: ";
        cin.getline(PushNode->studcrsyr, 25);

        cout << "\n\tGWA\t\t\t\t: ";
        cin >> PushNode->GWA;

        cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
        cout << "\tAdd another record? [Y/N]\t: ";
        cin >> Resp;
        cout << "\n---------------------------------------------------------------------------------------------------------\n\n";

        if (toupper(Resp) == 'Y') {
            ctr++;
            PushNode = new studrec;
            PushNode->next = *top;
            *top = PushNode;
        }
    } while (toupper(Resp) == 'Y');
    PushNode = NULL;
    cout << "\tPress any key to return to main menu...";
    cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
    cin.ignore(); 
    cin.get(); 
}

void travstack(studrec **top) {
    int ctr = 1;
    system("cls");
    studrec *PopNode = *top, *TempTop = NULL;
    cout << "\n=========================================================================================================\n";
    gotoxy(40, 4);
    cout << "STUDENT RECORD\n";
    cout << "\n=========================================================================================================\n";

    if (PopNode == NULL) {
        gotoxy(35, 8);
        cout << "Student Record is empty!\n";
        cout << "\n=========================================================================================================\n";
        cin.get();
    } else {
        studrec *TempTop = *top;
        gotoxy(10, 8);
        cout << "Student No.";

        gotoxy(40, 8);
        cout << "Student Name";

        gotoxy(70, 8);
        cout << "Course & Year";

        gotoxy(100, 8);
        cout << "GWA\n\n";
        while (TempTop != NULL) {
            cout << left << setw(9) << ctr;
            cout << left << setw(30) << TempTop->studno;
            cout << left << setw(30) << TempTop->studname;
            cout << left << setw(30) << TempTop->studcrsyr;
            cout << fixed << setprecision(2) << TempTop->GWA << endl << endl;
            TempTop = TempTop->next;
            ctr++;
        }
    }
    cout << "\n---------------------------------------------------------------------------------------------------------\n\n";
    cout << "\tPress any key to return to main menu...";
    cout << "\n\n---------------------------------------------------------------------------------------------------------\n";
    cin.ignore(); 
    cin.get(); 
}

void addstack(studrec **top) {
    studrec *PushNode;
    system("cls");
    PushNode = new studrec;
    cout << "\n=========================================================================================================\n";
    gotoxy(40, 4);
    cout << "ADDING OF STUDENT RECORD IN STACK\n";
    cout << "\n=========================================================================================================\n";

    if (*top == NULL) {
        gotoxy(45, 8);
        cout << "Student Record is empty!\n";
        cout << "\n=========================================================================================================\n";
        cin.get();
        return;
    }
    cout << "\n\tStudent Number\t\t: ";
    cin >> PushNode->studno;

    cout << "\n\tStudent Name\t\t: ";
    cin.ignore();
    cin.getline(PushNode->studname, 50);

    cout << "\n\tCourse & Year\t\t: ";
    cin.getline(PushNode->studcrsyr, 25);

    cout << "\n\tGWA\t\t\t: ";
    cin >> PushNode->GWA;
    PushNode->next = NULL;

    if (*top == NULL) {
        *top = PushNode;
    } else {
        PushNode->next = *top;
        *top = PushNode;
    }
    cout << "\n=========================================================================================================\n";
    gotoxy(40, 18);
    cout << "Record successfully added!\n";
    cout << "\n=========================================================================================================\n";
    cin.ignore(); 
    cin.get(); 
}

void delstack(studrec **top) {
    studrec *PopNode = *top;
    if (PopNode == NULL) {
        gotoxy(10, 24);
        cout << "Student Record is Empty!";
    } else {
        *top = (*top)->next;
        gotoxy(10, 24);
        cout << "Record successfully deleted!\n";
    }
    delete PopNode;
    PopNode = NULL;
    cout << "\nPress any key to return to main menu...";
    cin.ignore(); 
    cin.get(); 
}



