number=2
define revers 
	task1: task2.c	
		$(CC) $< -o $@
		@echo $(1)
endef

all: $(call revers 2)

task1a: task1a.c
	$(CC) $< -o $@

task1b: task1b.c
	$(CC) $< -o $@

#task2: task2.c
#	$(CC) $< -o $@
	
task3: task3.c
	$(CC) $< -o $@