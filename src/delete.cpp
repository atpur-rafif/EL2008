#include "delete.h"

void deleteBarang(struct List** list, int id, struct Barang** barang){
	if(*list == NULL){
		*barang = NULL;
		return;
	}

	struct List* current = *list;
	if(current->barang->id == id){
		*barang = current->barang;
		*list = current->next;
		return;
	}

	while(current->next != NULL && current->next->barang->id != id)
		current = current->next;

	if (current->next == NULL) {
		*barang = NULL;
		return;
	}

	struct List* item = current->next;
	current->next = item->next;
	*barang = item->barang;
	free(item);
}
