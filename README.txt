Hospital Patient Queue Management System
----------------------------------------
Language: C
Date: November 2025
Developed by: Abhiram M N S.

Description:
A system to manage patients in a hospital waiting room based on their priority.
Emergency patients (priority 1) are treated before normal (2) and low (3) priority ones.

Files:
- patient.h     : Structure and function declarations
- patient.c     : Function implementations
- main.c        : Program control (menu-driven)
- Makefile      : Compilation automation

Compile and Run:
> make
> ./hospital

Features:
- Add patient with ID, name, and priority
- Treat next patient based on priority
- Display current queue
- Search by ID or Name
- Handles memory safely and avoids global variables
