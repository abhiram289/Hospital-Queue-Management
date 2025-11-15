#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

void printHeader() {
    printf("\n===============================================\n");
    printf("          HOSPITAL QUEUE MANAGEMENT SYSTEM  \n");
    printf("===============================================\n");
}

void printMenu() {
    printf("\n--------------- MAIN MENU ----------------\n");
    printf("1. Add Patient\n");
    printf("2. Treat Next Patient\n");
    printf("3. Display Queue\n");
    printf("4. Search Patient by ID\n");
    printf("5. Search Patient by Name\n");
    printf("6. Exit\n");
    printf("-------------------------------------------\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, id, priority;
    char name[NAME_LEN];
    Patient* found;

    while (1) {
        printHeader();
        printMenu();

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n--------------- ADD PATIENT ----------------\n");
                printf("Enter Patient ID: ");
                scanf("%d", &id);

                printf("Enter Patient Name: ");
                scanf(" %[^\n]", name);

                printf("Enter Priority (1 = Emergency, 2 = Normal, 3 = Low): ");
                scanf("%d", &priority);

                addPatient(id, name, priority);
                printf("---------------------------------------------\n");
                break;

            case 2:
                printf("\n-------------- TREAT PATIENT ----------------\n");
                treatPatient();
                printf("---------------------------------------------\n");
                break;

            case 3:
                printf("\n--------------- CURRENT QUEUE ---------------\n");
                displayQueue();
                printf("---------------------------------------------\n");
                break;

            case 4:
                printf("\n------------- SEARCH BY ID ------------------\n");
                printf("Enter Patient ID: ");
                scanf("%d", &id);

                found = searchByID(id);
                if (found)
                    printf("FOUND -> Name: %s | Priority: %d\n", found->name, found->priority);
                else
                    printf(" Patient not found.\n");

                printf("---------------------------------------------\n");
                break;

            case 5:
                printf("\n------------- SEARCH BY NAME ----------------\n");
                printf("Enter Patient Name: ");
                scanf(" %[^\n]", name);

                found = searchByName(name);
                if (found)
                    printf("FOUND -> ID: %d | Priority: %d\n", found->id, found->priority);
                else
                    printf(" Patient not found.\n");

                printf("---------------------------------------------\n");
                break;

            case 6:
                printf("\n===============================================\n");
                printf("          THANK YOU FOR USING THE SYSTEM       \n");
                printf("===============================================\n");
                return 0;

            default:
                printf("\n Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
