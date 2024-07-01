#include <stdlib.h>

#define allocate_node(ds) (struct ds##_node *) \
		malloc (sizeof (struct ds##_node))
