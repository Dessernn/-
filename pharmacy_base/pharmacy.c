#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pharmacy.h"
void loadDatabase(const char *filename, Drug **drugs, int *size) {
    FILE *file = fopen(filename, "rb");
    if (!file){
        *drugs = NULL;
        *size = 0;
        return;
    }
    fread(size, sizeof(int), 1, file);
    *drugs = malloc(*size * sizeof(Drug));
    fread(*drugs, sizeof(Drug), *size, file);
    fclose(file);
}
void saveDatabase(const char *filename, Drug *drugs, int size) {
    FILE *file = fopen(filename, "wb");
    fwrite(&size, sizeof(int), 1, file);
    fwrite(drugs, sizeof(Drug), size, file);
    fclose(file);
}
void displayDrugs(Drug *drugs, int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d | %s | Категория: %s | Цена: %.2f | Кол-во: %d | В упаковке: %d\n",
               drugs[i].id, drugs[i].name, drugs[i].category, drugs[i].price, 
               drugs[i].quantity, drugs[i].inPack);
    }
    if (size == 0) printf("База данных пуста.\n");
}
void addDrug(Drug **drugs, int *size, int *nextId) {
    *drugs = realloc(*drugs, (++*size) * sizeof(Drug));
    Drug *newDrug=&(*drugs)[*size - 1];
    newDrug->id=(*nextId)++;
    printf("Название: ");
    scanf("%s",newDrug->name);
    printf("Категория назначения (например, 'антибиотик'): ");
    scanf("%s",newDrug->category);
    printf("Цена: ");
    scanf("%f", &newDrug->price);
    printf("Количество на складе: ");
    scanf("%d", &newDrug->quantity);
    printf("Количество в упаковке: ");
    scanf("%d", &newDrug->inPack);
    printf("Товар добавлен.\n");
}
void deleteDrug(Drug **drugs, int *size, int id) {
    for (int i = 0; i < *size; i++) {
        if ((*drugs)[i].id == id) {
            for (int j = i; j < *size - 1; j++) (*drugs)[j] = (*drugs)[j + 1];
            *drugs = realloc(*drugs, (--*size) * sizeof(Drug));
            printf("Удалено.\n");
            return;
        }
    }
    printf("Не найдено.\n");
}
void editDrug(Drug *drugs, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (drugs[i].id == id) {
            printf("Новое название: ");
            scanf("%s", drugs[i].name);
            printf("Новая категория: ");
            scanf("%s", drugs[i].category);
            printf("Новая цена: ");
            scanf("%f", &drugs[i].price);
            printf("Новое количество на складе: ");
            scanf("%d", &drugs[i].quantity);
            printf("Новое количество в упаковке: ");
            scanf("%d", &drugs[i].inPack);
            printf("Товар обновлен.\n");
            return;
        }
    }
    printf("Не найдено.\n");
}
void searchDrug(Drug *drugs, int size) {
    char query[50];
    printf("Введите название или категорию: ");
    scanf("%s", query);
    for (int i = 0; i < size; i++) {
        if (strstr(drugs[i].name, query) || strstr(drugs[i].category, query)) {
            printf("ID: %d | %s | Категория: %s | Цена: %.2f | Кол-во: %d | В упаковке: %d\n",
                   drugs[i].id, drugs[i].name, drugs[i].category, drugs[i].price,
                   drugs[i].quantity, drugs[i].inPack);
        }
    }
}
