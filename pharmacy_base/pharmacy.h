#ifndef PHARMACY_H
#define PHARMACY_H

typedef struct{
    int id;
    char name[50];
    char category[50];
    float price;
    int quantity;
    int inPack;
} Drug;

void loadDatabase(const char *filename, Drug **drugs, int *size);
void saveDatabase(const char *filename, Drug *drugs, int size);
void displayDrugs(Drug *drugs, int size);
void addDrug(Drug **drugs, int *size, int *nextId);
void deleteDrug(Drug **drugs, int *size, int id);
void editDrug(Drug *drugs, int size, int id);
void searchDrug(Drug *drugs, int size);

#endif
