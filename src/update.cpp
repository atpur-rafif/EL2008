#include "update.h"

void addBarang(struct List** list, struct Barang* barang) {
    struct List* item = (struct List*) malloc(sizeof(struct List));
    if (item == NULL) {
        Serial.println("Memori penuh");
        return;
    }

    struct List* current = *list;

    item->barang = barang;
    item->next = NULL;

    if (current == NULL) {
        (*list) = item;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = item;
}

void updateStatus(struct List* list, int id, int status, struct Barang** item) {
    searchBarang(list, id, item);

    if (*item == NULL) {
        return;
    }

    (*item)->status = status;
}
