#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

Patient* head = NULL;   // queue head

// Add new patient based on priority
void addPatient(int id, char name[], int priority) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (!newPatient) {
        printf("Memory allocation failed!\n");
        return;
    }

    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->priority = priority;
    newPatient->next = NULL;

    if (!head || priority < head->priority) {
        newPatient->next = head;
        head = newPatient;
    } else {
        Patient* temp = head;
        while (temp->next && temp->next->priority <= priority)
            temp = temp->next;

        newPatient->next = temp->next;
        temp->next = newPatient;
    }

    printf("Patient added successfully!\n");
}

// Remove next patient
void treatPatient() {
    if (!head) {
        printf("No patients in queue!\n");
        return;
    }

    Patient* temp = head;
    head = head->next;

    printf(" Treating patient: %s (ID: %d, Priority: %d)\n",
           temp->name, temp->id, temp->priority);

    free(temp);
}

// Display 
void displayQueue() {
    if (!head) {
        printf("No patients waiting.\n");
        return;
    }

    printf("\n--- Current Queue ---\n");

    Patient* temp = head;
    while (temp) {
        printf("ID: %d | Name: %s | Priority: %d\n",
               temp->id, temp->name, temp->priority);
        temp = temp->next;
    }

    printf("---------------------\n");
}

// Search by ID
Patient* searchByID(int id) {
    Patient* temp = head;

    while (temp) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Search by Name
Patient* searchByName(char name[]) {
    Patient* temp = head;

    while (temp) {
        if (strcmp(temp->name, name) == 0)
            return temp;

        temp = temp->next;
    }

    return NULL;
}
