#include <stdio.h>
#include "output.h"

const char* getCategStr(int cat) {
    switch (cat) {
        case 1: return "Sensor";
        case 2: return "Mikrokontroler";
        case 3: return "Lainnya";
        default: return "Undefined";
    }
}

const char* getStatusStr(int stat) {
    switch (stat) {
        case 0: return "Habis";
        case 1: return "Tersedia";
        case 2: return "Dipinjam";
        case 3: return "Rusak";
        default: return "Undefined";
    }
}

void displayAll(struct List* list) {
    struct List* head = list;

    if (head == NULL) {
        printf("Data barang masih kosong\n");
        return;
    }

    while (head != NULL) {
        printf("Seluruh Data Barang:\n");
        printf("ID Barang: %d\n", head->barang->id);
        printf("Nama     : %s\n", head->barang->name);
        printf("Kategori : %d\n", getCategStr(head->barang->category));
        printf("Lokasi   : %s\n", head->barang->location);
        printf("Status   : %d\n", getStatusStr(head->barang->status));
        printf("PIC      : %s\n", head->barang->pic);

        head = head->next;
    }
}

void summarizeAll(struct List* list) {
    struct List* head = list;
    int countCateg1 = 0; // sensor
    int countCateg2 = 0; // mikrokontroler
    int countCateg3 = 0; // lainnya
    int countBarang = 0;

    if (head == NULL) {
        printf("Data barang masih kosong\n");
        return;
    }

    while (head != NULL) {
        if (head->barang != NULL) {
            countBarang++;
            switch (head->barang->category) {
                case 1: countCateg1++; break;
                case 2: countCateg2++; break;
                case 3: countCateg3++; break;
                default: break;
            }
        }
        head = head->next;
    }

    printf("Ringkasan Inventaris:\n");
    printf("Total Semua Barang: %d item\n", countBarang);
    printf(" - Sensor         : %d item\n", countCateg1);
    printf(" - Mikrokontroler : %d item\n", countCateg2);
    printf(" - Lainnya        : %d item\n", countCateg3);
}