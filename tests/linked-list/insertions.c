#include "../../include/list.h"
#include <stdio.h>
#include <stdlib.h>

#define BATCH_SIZE 10

int list_compare (struct list *l, int *expected) {
	int i;
	struct list_node *cur;

	cur = l->head;
	while (i < l->size) {
		if (*((int *) cur->data) != expected[i]) { 
			return 0;
		}
		++i;
		cur = cur->next;
	}

	return 1;
}

int main () {
	struct list my_list;
	int i, assert_batch_1[BATCH_SIZE], assert_batch_2[2 * BATCH_SIZE], assert_batch_3[2 * BATCH_SIZE];

	init_list (&my_list);

	/* We push back some items */
	for (i = 0; i < BATCH_SIZE; ++i)
		_push_back (&my_list, (void *) &i);

	/* Check if items were inserted correctly */
	if (list_compare (&my_list, assert_batch_1)) {
		printf ("List does not contain the correct items after push back\n");
		exit (1);
	}

	/* We push some items to the front */
	for (i = 0; i < BATCH_SIZE; ++i)
		_push_front (&my_list, (void *) &i);

	/* Check if items were inserted correctly */
	if (list_compare (&my_list, assert_batch_2)) {
		printf ("List does not contain the correct items after push_front\n");
	}

	/* We clear the list */
	list_clear (&my_list);
}
