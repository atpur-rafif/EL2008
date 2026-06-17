#include <stdio.h>
#include <string.h>
#include "output.h"

void getCategStr(int cat, char* cate) {
    switch (cat) {
        case 1: strcpy(cate, "Sensor");
        case 2: strcpy(cate, "Mikrokontroler");
        case 3: strcpy(cate, "Lainnya");
        default: strcpy(cate, "Undefined");
    }
}

void getStatusStr(int sta, char* stat) {
    switch (sta) {
        case 0: strcpy(stat, "Habis");
        case 1: strcpy(stat, "Tersedia");
        case 2: strcpy(stat, "Dipinjam");
        case 3: strcpy(stat, "Rusak");
        default: strcpy(stat, "Undefined");
    }
}

void displayAll(struct List* list) {
    struct List* head = list;

    if (head == NULL) {
        printf("Data barang masih kosong\n");
        return;
    }

    char currCateg[MAX_STRING];
    char currStat[MAX_STRING];
    getCategStr(head->barang->category, currCateg);
    getStatusStr(head->barang->status, currStat);

    while (head != NULL) {
        printf("Seluruh Data Barang:\n");
        printf("ID Barang: %d\n", head->barang->id);
        printf("Nama     : %s\n", head->barang->name);
        printf("Kategori : %s\n", currCateg);
        printf("Lokasi   : %s\n", head->barang->location);
        printf("Status   : %s\n", currStat);
        printf("PIC      : %s\n", head->barang->pic);

        head = head->next;
    }
}

void summarizeAll(struct List* list) {
    struct List* head = list;
    int countCateg1 = 0;
    int countCateg2 = 0;
    int countCateg3 = 0;
    int countBarang = 0;

    if (head == NULL) {
        printf("Data barang masih kosong\n");
        return;
    }

    while (head != NULL) {
            countBarang++;
            switch (head->barang->category) {
                case 1: countCateg1++; break;
                case 2: countCateg2++; break;
                case 3: countCateg3++; break;
                default: break;
            }
    }

    printf("Ringkasan Inventaris:\n");
    printf("Total Semua Barang: %d item\n", countBarang);
    printf(" - Sensor         : %d item\n", countCateg1);
    printf(" - Mikrokontroler : %d item\n", countCateg2);
    printf(" - Lainnya        : %d item\n", countCateg3);
}
