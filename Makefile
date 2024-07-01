export cc 			:= gcc
export cflags 		:= -Wall
export src-root		:= $(CURDIR)
export target		:= $(MAKECMDGOALS)
export include-dir	:= $(src-root)/include
export libname		:= ds
export libname-ar	:= lib$(libname).a

export tests-dir	:= $(src-root)/tests
export build-dir	:= $(src-root)/build

linked-list-dir		:= $(src-root)/linked-list
linked-list-obj		:= $(linked-list-dir)/list.o
linked-list-deps	:= $(include-dir)/list.h

all-obj		:= $(linked-list-obj)
all-deps	:= $(linked-list-deps)

ifeq ($(strip $(target)),)
	target 	:= all
endif

ifneq ($(target), clean)
$(info Building target $(target))
$(info =========================)
endif

define build-lib-$(target)
	ar rcs $(libname-ar) $($(target)-obj)
endef

all: $(all-obj) $(all-deps) | $(build-dir)
	$(build-lib-$@)
	mv $(all-obj) $(libname-ar) $(build-dir)
	$(MAKE) $(target) -C $(tests-dir)

linked-list: $(linked-list-obj) $(linked-list-deps) | $(build-dir)
	$(build-lib-$@)
	mv $(linked-list-obj) $(libname-ar) $(build-dir)
	$(MAKE) $(target) -C $(tests-dir)

.PHONY: all clean

$(build-dir):
	mkdir $(build-dir)

clean: | $(build-dir)
	rm -rf $(build-dir)
	$(MAKE) clean -C $(tests-dir)