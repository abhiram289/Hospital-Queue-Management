#ifndef PATIENT_H
#define PATIENT_H

#define NAME_LEN 50

// Structure to represent a patient
typedef struct Patient {
    int id;
    char name[NAME_LEN];
    int priority;  // 1 = Emergency, 2 = Normal, 3 = Low
    struct Patient* next;
} Patient;

// Function declarations
void addPatient(int id, char name[], int priority);
void treatPatient();
void displayQueue();
Patient* searchByID(int id);
Patient* searchByName(char name[]);

#endif
