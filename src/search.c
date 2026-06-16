#include "search.h"

void searchBarang(struct List* list, int id, struct Barang** result){
	if(list == NULL){
		*result = NULL;
		return;
	}

	struct List* first = list;
	struct List* current = list;
	do {
		if(current->barang->id == id){
			*result = current->barang;
			return;
		}
		current = current->next;
	} while (current != first);

	*result = NULL;
}
