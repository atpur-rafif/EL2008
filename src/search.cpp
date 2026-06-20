#include "search.h"

void searchBarang(struct List* list, int id, struct Barang** result){
	struct List* current = list;
	while(current != NULL){
		if(current->barang->id == id){
			*result = current->barang;
			return;
		}
		current = current->next;
	}

	*result = NULL;
}
