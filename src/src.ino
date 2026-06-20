#include "struct.h"
#include "update.h"
#include "delete.h"
#include "search.h"
#include "output.h"

struct List* items = NULL;

// Helper function to act like scanf() for integers
int readIntFromSerial() {
    while (Serial.available() == 0) { delay(10); } // Wait for input
    int val = Serial.parseInt();
    while (Serial.available() > 0) { Serial.read(); } // Clear trailing newlines
    return val;
}

// Helper function to act like scanf() for strings
String readStringFromSerial() {
    while (Serial.available() == 0) { delay(10); } // Wait for input
    String str = Serial.readStringUntil('\n');
    str.trim(); // Remove \r\n
    return str;
}

void printMenu() {
    Serial.println("\n=== Selamat Datang! Berikut Pilihan Menu ===");
    Serial.println("0. Exit Program (Reset)");
    Serial.println("1. Add Barang");
    Serial.println("2. Delete Barang");
    Serial.println("3. Search ID");
    Serial.println("4. Update Status");
    Serial.println("5. Display All");
    Serial.println("6. Summarize All");
    Serial.print("Pilihan: ");
}

void setup() {
    Serial.begin(115200); // Make sure your Serial Monitor is set to 115200 baud!
    while (!Serial) { delay(10); } // Wait for connection
    Serial.println("Sistem Inventaris Dimulai!");
    printMenu();
}

void loop() {
    if (Serial.available() > 0) {
        int choice = readIntFromSerial();
        Serial.println(choice); // Echo the choice back

        switch (choice) {
            case 1: {
                struct Barang* newItem = (struct Barang*) malloc(sizeof(struct Barang));
                if(newItem == NULL){
                    Serial.print("-> Memori penuh");
                    break;
                }
                
                Serial.println("\n--- Add barang ---");
                Serial.print("ID Barang : ");
                newItem->id = readIntFromSerial(); Serial.println(newItem->id);

                struct Barang* itemSearch = NULL;
                searchBarang(items, newItem->id, &itemSearch);
                if(itemSearch != NULL){
                    Serial.print("-> Duplikat ID");
                    break;
                }
                
                Serial.print("Nama      : ");
                String nameStr = readStringFromSerial(); Serial.println(nameStr);
                nameStr.toCharArray(newItem->name, MAX_STRING);
                
                Serial.print("Kategori (1: sensor, 2: mikrokontroler, 3: lainnya): ");
                newItem->category = readIntFromSerial(); Serial.println(newItem->category);
                
                Serial.print("Lokasi    : ");
                String locStr = readStringFromSerial(); Serial.println(locStr);
                locStr.toCharArray(newItem->location, MAX_STRING);
                
                Serial.print("Status (0: habis, 1: tersedia, 2: dipinjam, 3: rusak): ");
                newItem->status = readIntFromSerial(); Serial.println(newItem->status);
                
                Serial.print("PIC       : ");
                String picStr = readStringFromSerial(); Serial.println(picStr);
                picStr.toCharArray(newItem->pic, MAX_STRING);

                addBarang(&items, newItem);
                Serial.println("-> Barang berhasil ditambahkan!");
                break;
            }
            case 2: {
                int id;
                struct Barang* deletedItem = NULL;
                Serial.print("\nMasukkan ID barang yang ingin dihapus: ");
                id = readIntFromSerial(); Serial.println(id);
                
                deleteBarang(&items, id, &deletedItem);
                
                if (deletedItem != NULL) {
                    Serial.print("-> Barang dengan ID "); Serial.print(deletedItem->id);
                    Serial.println(" berhasil dihapus.");
                    free(deletedItem);
                } else {
                    Serial.println("-> Barang tidak ditemukan.");
                }
                break;
            }
            case 3: {
                int idSearch;
                struct Barang* itemSearch = NULL;

                Serial.print("\nMasukkan ID barang yang ingin dicari: ");
                idSearch = readIntFromSerial(); Serial.println(idSearch);

                searchBarang(items, idSearch, &itemSearch);
                
                if (itemSearch != NULL) {
                    Serial.println("\n--- Barang Ditemukan ---");
                    Serial.print("ID     : "); Serial.println(itemSearch->id);
                    Serial.print("Nama   : "); Serial.println(itemSearch->name);
                    Serial.print("Lokasi : "); Serial.println(itemSearch->location);
                    Serial.print("PIC    : "); Serial.println(itemSearch->pic);
                } else {
                    Serial.println("-> Barang tidak ditemukan.");
                }
                break;
            }
            case 4: {
                int idUpdate, statusUpdate;
                struct Barang* itemUpdate = NULL;

                Serial.print("\nMasukkan ID barang yang ingin di-update: ");
                idUpdate = readIntFromSerial(); Serial.println(idUpdate);
                
                Serial.print("Masukkan status baru: ");
                statusUpdate = readIntFromSerial(); Serial.println(statusUpdate);

                updateStatus(items, idUpdate, statusUpdate, &itemUpdate);
                if (itemUpdate != NULL) {
                    Serial.println("-> Status berhasil di-update!");
                } else {
                    Serial.println("-> Barang tidak ditemukan.");
                }
                break;
            }
            case 5:
                Serial.println("\n--- Seluruh Data Barang ---");
                displayAll(items);
                break;
            case 6:
                Serial.println();
                summarizeAll(items);
                break;
            case 0:
                Serial.println("\nSistem Reset. Silakan restart Arduino.");
                while(true) { delay(1000); } // Stop program
                break;
            default:
                Serial.println("\nPilihan tidak valid.");
                break;
        }
        delay(500); // Short pause before showing menu again
        if (choice != 0) printMenu();
    }
}
