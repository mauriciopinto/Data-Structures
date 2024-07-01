linked-list-tests-dir 	:= $(tests-dir)/linked-list
linked-list-tests 		:= insertions deletions
linked-list-obj			:= $(foreach test, $(linked-list-tests), $(linked-list-tests-dir)/$(test).o)
linked-list-deps		:= $(include-dir)/list.h $(include-dir)/allocator.h

all-tests	:= $(linked-list-tests)
all-obj		:= $(linked-list-obj)

cflags += -l$(libname) -L$(build-dir) -I$(include-dir)

all: $(obj)
	

linked-list: $(linked-list-tests)

$(linked-list-tests): $(linked-list-obj)
	$(cc) -o $@ $< $(cflags)

.PHONY: clean

clean:
	rm $(linked-list-tests) $(linked-list-obj)