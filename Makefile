number=2
define revers 
	task1: task2.c	
		$(CC) $< -o $@
		@echo $(1)
endef

all: task4

task1a: task1a.c
	$(CC) $< -o $@

task1b: task1b.c
	$(CC) $< -o $@

#task2: task2.c
#	$(CC) $< -o $@
	
task4: task4.c
	$(CC) $< -o $@