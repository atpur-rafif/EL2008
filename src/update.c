#include "update.h"

void addBarang(struct List** list, struct Barang* barang) {
    struct List* new = (struct List*) malloc(sizeof(struct List));
    struct List* current = *list;

    new->barang = barang;
    new->next = NULL;

    if (current == NULL) {
        (*list) = new;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
}

void updateStatus(struct List* list, int id, int status, struct Barang** item) {
    searchBarang(list, id, item);

    if (*item == NULL) {
        return;
    }

    (*item)->status = status;
}