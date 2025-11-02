#include <stdio.h>
#include "patient.h"

int main() {
    int choice, id, priority;
    char name[100];

    while (1) {
        printf("\n==============================\n");
        printf(" Hospital Queue Management\n");
        printf("==============================\n");
        printf("1. Add Patient\n");
        printf("2. Treat Next Patient\n");
        printf("3. Display Queue\n");
        printf("4. Search by ID\n");
        printf("5. Search by Name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Priority (1 = normal, higher = emergency): ");
                scanf("%d", &priority);
                addPatient(id, name, priority);
                break;

            case 2:
                treatPatient();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchByID(id);
                break;

            case 5:
                printf("Enter Name to search: ");
                scanf("%s", name);
                searchByName(name);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
