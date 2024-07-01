#include "../include/list.h"
#include "../include/allocator.h"
#include <string.h>

void init_list (struct list *l) {
	/* We allocate memory for the head */
	l->head = allocate_node (list);
	
	/* Size is zero, tail = head */
	l->tail = l->head;
}

void _init_list_node (struct list_node *n, void *data, unsigned long data_size) {
	n = allocate_node (list);
	memcpy (n->data, data, data_size);
}

void _push_front (struct list *l, struct list_node *n) {
	n->next = l->head;

#ifdef LIST_CIRCULAR
	l->tail->next = n;
	
	#ifdef LIST_DOUBLY
		n->prev = l->tail;
	#endif
#endif

#ifdef LIST_DOUBLY
	l->head->prev = n;
#endif

	l->head = n;
}

void _push_back (struct list *l, struct list_node *n) {
	l->tail->next = n;

#ifdef LIST_CIRCULAR
	#ifdef LIST_DOUBLY
		l->head->prev = n;
	#endif
#endif

#ifdef LIST_DOUBLY
	n->prev = l->tail;
#endif

	l->tail = n;
}

/* Inserts a node to the list after the node at position 'pos' */
void _insert (struct list *l, int pos, struct list_node *n) {
	struct list_node **cur;
	int i;
	
	if (pos > l->size) pos = l->size;
	if (pos < 0) pos = 0;

	i = 0;
	cur = &l->head;
	while (i < pos - 1) {
		cur = &(*cur)->next;
		++i;
	}

	n->next = (*cur)->next;
	(*cur)->next = n;

#ifdef LIST_DOUBLY
	n->prev = *cur;
	if (n->next) n->next->prev = n;
#endif
}

/* Clears the list and deallocates reserved memory */
void list_clear (struct list *l) {
	struct list_node *current;
		
	current = l->head;
	
	/* We iterate the list, deallocating each node */
	while (l->size > 0) {
		current = current->next;
		free (l->head);
		l->head = current;
		l->size--;
	}

	l->head = l->tail = NULL;
}

/* Sorts the list in the order determined by the compare function 'cmp'.
   This function must take two void pointers to data, and return: 1 if
   'a' is greater than 'b', -1 if 'b' is greater than 'a' and 0 if they are equal */
void list_sort (struct list *l, int (*cmp) (void *a, void *b)) {

}