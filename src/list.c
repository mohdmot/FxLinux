#include "../include/list.h"
#include <gint/std/stdlib.h>
#include <gint/std/string.h>

void List_Init(list_t* list, size_t size) {
	list->size = size;
	list->count = 0;
	list->items = NULL;
}

void List_Destroy(list_t* list) {
	list->size = 0;
	list->count = 0;
	free(list->items);
}

int List_Push(list_t* list, void* item) {
	list->count++;

	if (list->count == 1) {
		list->items = malloc(list->count * list->size);
		if (list->items == NULL) goto fail;
		goto write;
	}

	list->items = realloc(list->items, list->count * list->size);
	if (list->items == NULL) goto fail;

write:
	memcpy((char*) ((char*)(list->items) + (list->count * list->size)) - list->size, item, list->size);
	return 0;

fail:
	return 1;
}

void List_Clear(list_t* list) {
	list->count = 0;
	free(list->items);
}

void* List_Begin(list_t* list) {
	return list->items;
}


void* List_End(list_t* list) {
	int idx = 0;
	for (int i = 0; i<list->count; i+=1) {
		idx=i;
	}
	return List_Get(list,idx);
}



void List_Delete_Last_Chr(list_t* list) {
    if (list->count == 0) {
        // List is empty, nothing to delete
        return;
    }

    // Ensure the item size is at least 1 byte
    size_t effectiveSize = (list->size > 0) ? list->size : 1;

    // Calculate the offset of the last element
    size_t offset = (list->count - 1) * effectiveSize;

    // Ensure the last element is not empty
    if (list->count > 0 && list->items != NULL) {
        // Get the pointer to the last element
        char* lastElement = (char*)list->items + offset;

        // Ensure the element has at least one character
        if (strlen(lastElement) > 0) {
            // Delete the last character
            lastElement[strlen(lastElement) - 1] = '\0';
        }
    }
}


void List_Delete_Last(list_t* list) {
    if (list->count > 0) {
        // Decrement the count of items
        list->count--;

        if (list->count > 0) {
            // Resize the list to remove the last item
            list->items = realloc(list->items, list->count * list->size);

            if (list->items == NULL) {
                // Handle realloc failure
                // You may want to add error handling here
            }
        } else {
            // The list is now empty, free the memory
            free(list->items);
            list->items = NULL;
        }
    }
}


void* List_Get(list_t* list, size_t index) {
    if (index < list->count) {
        return (char*)(list->items) + (index * list->size);
    } else {
        // Handle index out of bounds
        return NULL;
    }
}


int List_Contain(list_t* list, char* elem) {
	int contain = 0;
	for (int i = 0; i<list->count ; i++) {
		if (List_Get(list,i) == elem) {
			contain = 1;
			break;
		}			
	}
	return contain;
}