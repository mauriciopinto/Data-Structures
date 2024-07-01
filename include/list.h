#ifndef LIST_H
#define LIST_H

struct list_node {
	void *data;
	struct list_node *next;
#ifdef LIST_DOUBLY
	struct node *prev;
#endif
};

struct list {
	struct list_node *head;
	struct list_node *tail;
	unsigned long size;
};

void init_list (struct list * /* l */);
void _init_list_node (struct list_node * /* n */, void * /* data */, unsigned long /* data_size */);
void _push_front (struct list * /* l */, struct list_node * /* elem */);
void _push_back (struct list * /* l */, struct list_node * /* elem */);
void _insert (struct list * /* l */, int /* pos */, struct list_node * /* elem */);
void _remove (struct list * /* l */, void * /* data */);
void _find (struct list * /* l */, void * /* data */);
void list_clear (struct list * /* l */);
void list_sort (struct list * /* l */, int (*) (void *, void *));

#define init_list_node_ptr(node, data, type) _init_list_node (node, (void *) data, sizeof (type))
#define init_list_node_value(node, data, type) _init_list_node (node, (void *) &data, sizeof (type))

#endif
