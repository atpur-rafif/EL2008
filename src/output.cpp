#include "output.h"
#include "Arduino.h"
#include <string.h>

void getCategStr(int cat, char* cate) {
    switch (cat) {
        case 1: strcpy(cate, "Sensor"); break;
        case 2: strcpy(cate, "Mikrokontroler"); break;
        case 3: strcpy(cate, "Lainnya"); break;
        default: strcpy(cate, "Undefined"); break;
    }
}

void getStatusStr(int sta, char* stat) {
    switch (sta) {
        case 0: strcpy(stat, "Habis"); break;
        case 1: strcpy(stat, "Tersedia"); break;
        case 2: strcpy(stat, "Dipinjam"); break;
        case 3: strcpy(stat, "Rusak"); break;
        default: strcpy(stat, "Undefined"); break;
    }
}

void displayAll(struct List* list) {
    struct List* head = list;

    if (head == NULL) {
        Serial.println("Data barang masih kosong");
        return;
    }

    while (head != NULL) {
        char currCateg[MAX_STRING];
        char currStat[MAX_STRING];
        
        getCategStr(head->barang->category, currCateg);
        getStatusStr(head->barang->status, currStat);

        Serial.print("ID: "); Serial.print(head->barang->id);
        Serial.print(" | Nama: "); Serial.print(head->barang->name);
        Serial.print(" | Kategori: "); Serial.print(currCateg);
        Serial.print(" | Lokasi: "); Serial.print(head->barang->location);
        Serial.print(" | Status: "); Serial.print(currStat);
        Serial.print(" | PIC: "); Serial.println(head->barang->pic);

        head = head->next;
    }
}

void summarizeAll(struct List* list) {
    struct List* head = list;
    int countCateg1 = 0, countCateg2 = 0, countCateg3 = 0, countBarang = 0;

    if (head == NULL) {
        Serial.println("Data barang masih kosong");
        return;
    }

    while (head != NULL) {
        countBarang++;
        switch (head->barang->category) {
            case 1: countCateg1++; break;
            case 2: countCateg2++; break;
            case 3: countCateg3++; break;
        }
        head = head->next; 
    }

    Serial.println("Ringkasan Inventaris:");
    Serial.print("Total Semua Barang: "); Serial.print(countBarang); Serial.println(" item");
    Serial.print(" - Sensor         : "); Serial.print(countCateg1); Serial.println(" item");
    Serial.print(" - Mikrokontroler : "); Serial.print(countCateg2); Serial.println(" item");
    Serial.print(" - Lainnya        : "); Serial.print(countCateg3); Serial.println(" item");
}
