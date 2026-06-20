#ifndef UPDATE_H
#define UPDATE_H

#include <Arduino.h>

#include <stdio.h>
#include "struct.h"
#include "search.h"

void addBarang(struct List** list, struct Barang* barang);
void updateStatus(struct List* list, int id, int status, struct Barang** item);

#endif