#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "update.h"
#include "delete.h"
#include "search.h"
#include "output.h"

void choiceMenu() {
    int choice;
    struct List* items = NULL; 

    do {
        printf("\nSelamat Datang! Berikut Pilihan Menu:\n");
        printf("0. Exit Program\n");
        printf("1. Add Barang\n");
        printf("2. Delete Barang\n");
        printf("3. Search ID\n");
        printf("4. Update Status\n");
        printf("5. Display All\n");
        printf("6. Summarize All\n");

        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Barang* newItem = (struct Barang*) malloc(sizeof(struct Barang));
                
                printf("\nAdd barang:\n");
                printf("ID Barang : ");
                scanf("%d", &newItem->id);
                printf("Nama      : ");
                scanf("%s", newItem->name);
                printf("Pilihan Kategori (1: sensor, 2: mikrokontroler, 3: lainnya)\n");
                printf("Kategori  : ");
                scanf("%d", &newItem->category);
                printf("Lokasi    : ");
                scanf("%s", newItem->location);
                printf("Pilihan Status (0: habis, 1: tersedia, 2: dipinjam, 3: rusak)\n");
                printf("Status    : ");
                scanf("%d", &newItem->status);
                printf("PIC       : ");
                scanf("%s", newItem->pic);

                addBarang(&items, newItem);
                printf("Barang berhasil ditambahkan!\n");
                break;
            }
            case 2: {
                int id;
                struct Barang* deletedItem = NULL;
                printf("\nMasukkan ID barang yang ingin dihapus: ");
                scanf("%d", &id);
                
                deleteBarang(&items, id, &deletedItem);
                
                if (deletedItem != NULL) {
                    printf("Barang dengan ID %d (%s) berhasil dihapus.\n", deletedItem->id, deletedItem->name);
                    free(deletedItem);
                } else {
                    printf("Barang dengan ID %d tidak ditemukan.\n", id);
                }
                break;
            }
            case 3: {
                int idSearch;
                struct Barang* itemSearch = NULL;

                printf("\nMasukkan ID barang yang ingin dicari: ");
                scanf("%d", &idSearch);

                searchBarang(items, idSearch, &itemSearch);
                
                if (itemSearch != NULL) {
                    printf("\n--- Barang Ditemukan ---\n");
                    printf("ID     : %d\n", itemSearch->id);
                    printf("Nama   : %s\n", itemSearch->name);
                    printf("Lokasi : %s\n", itemSearch->location);
                    printf("PIC    : %s\n", itemSearch->pic);
                } else {
                    printf("Barang tidak ditemukan.\n");
                }
                break;
            }
            case 4: {
                int idUpdate;
                int statusUpdate;
                struct Barang* itemUpdate = NULL;

                printf("\nMasukkan ID barang yang ingin di-update: ");
                scanf("%d", &idUpdate);
                printf("Masukkan status baru (0: habis, 1: tersedia, 2: dipinjam, 3: rusak): ");
                scanf("%d", &statusUpdate);

                updateStatus(items, idUpdate, statusUpdate, &itemUpdate);
                if (itemUpdate != NULL) {
                    printf("Status berhasil di-update!\n");
                } else {
                    printf("Barang tidak ditemukan.\n");
                }
                break;
            }
            case 5:
                printf("\n--- Seluruh Data Barang ---\n");
                displayAll(items);
                break;
            case 6:
                printf("\n");
                summarizeAll(items);
                break;
            case 0:
                printf("Keluar dari program...\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (choice != 0);
}

int main(){
    choiceMenu();
    return 0;
}