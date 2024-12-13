#include <stdio.h>
#include <stdlib.h>
#include "pharmacy.h"

#define FILENAME "pharmacy.db"
int main() {
    Drug *drugs = NULL;
    int size = 0, nextId = 1, choice, id;
    loadDatabase(FILENAME, &drugs, &size);
    if (size > 0) nextId = drugs[size - 1].id + 1;

    while (1) {
        printf("\n1. Показать товары\n2. Добавить товар\n3. Удалить товар\n4. Редактировать товар\n5. Поиск\n6. Выход\nВыбор: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: displayDrugs(drugs, size); break;
            case 2: addDrug(&drugs, &size, &nextId); break;
            case 3:
                printf("ID для удаления: ");
                scanf("%d", &id);
                deleteDrug(&drugs, &size, id);
                break;
            case 4:
                printf("ID для редактирования: ");
                scanf("%d", &id);
                editDrug(drugs, size, id);
                break;
            case 5: searchDrug(drugs, size); break;
            case 6:
                saveDatabase(FILENAME, drugs, size);
                free(drugs);
                return 0;
            default: printf("Неверный ввод.\n");
        }
    }
}
