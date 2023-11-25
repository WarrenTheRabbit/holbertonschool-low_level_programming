CC = gcc
CFLAGS = -g -Wall -Werror -pedantic 


PROGRAM_NAME = 1-strdup
TASK_NUMBER = $(shell echo $(PROGRAM_NAME) | sed 's/[^0-9]*\([0-9]\+\).*/\1/')
DRIVER = $(TASK_NUMBER)-main.c


# Define the object files needed for the final executable.
OBJECTS = $(PROGRAM_NAME).o $(TASK_NUMBER)-main.o _putchar.o
SRC = $(PROGRAM_NAME).c $(TASK_NUMBER)-main.c _putchar.c


all:
	@echo
	@echo Exeuting \'make\' without any arguments shows the current
	@echo project\'s dependencies.
	@echo
	@echo The current project is: '$(PROGRAM_NAME)'
	@echo It has dependencies on:
	@echo '    OBJECTS: $(OBJECTS)'
	@echo '    SOURCE: $(SRC)'
	@echo
	@echo To test the existing build, run \'make test\'.
	@echo To update then test the current build, run \'make update\'.
	@echo To create and test a new full build, run \'make build\'.

# Rule to build the final executable from object files
$(PROGRAM_NAME): $(OBJECTS)
	@echo Linking objects...
	@$(CC) -g $(CFLAGS) $^ -o $@
	@echo 		BUILDING COMPLETED
	@echo -----------------------------------------


# Pattern rule to create object files from corresponding source files
%.o: %.c
	@echo Compiling '$<' to object code...
	@$(CC) -g $(CFLAGS) -c $< -o $@

update: $(PROGRAM_NAME) test
	@echo 		UPDATING COMPLETED
	@echo -----------------------------------------
	@echo If only tests ran, the build is already: up-to-date.

build: clean $(PROGRAM_NAME) test

# Phony targets execute even if target exists in file system.
.PHONY: clean test debug vim push test_case main
clean:
	@echo Cleaning...
	@rm -f $(OBJECTS) $(PROGRAM_NAME)
	@echo 		CLEANING COMPLETED
	@echo -----------------------------------------

debug:  $(PROGRAM_NAME)
	@echo Debugging.. 
	@gdb $< 

workspace:
	@touch $(PROGRAM_NAME).vim
	@vim -S $(PROGRAM_NAME).vim

push:	
	@git add $(SRC)
	@read -p "Enter commit message: " commit_message; \
	git commit -m "$$commit_message"
	@git push

test_case:
	@mkdir -p tests/
	@touch tests/$(PROGRAM_NAME)
	@vim tests/$(PROGRAM_NAME)

main:
	@vim $(TASK_NUMBER)-main.c

program: 
	@vim $(PROGRAM_NAME).c

edit: 
	@vim Makefile


TEST_OUTPUT_PASSES = ./ctest 
TEST_OUTPUT_FAILS= ./ctest_fail 

TEST_OUTPUT_TARGETS := $(shell grep -oP "^test_that.*?(?=:)" Makefile)
DIVIDER = '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'


define ARRANGE_INPUT
sed -i.bak 's/Duplicated/$(1)/' $(DRIVER) ; \
rm $(PROGRAM_NAME) ; \
$(CC) -g $(CC_FLAGS) $(DRIVER) $(PROGRAM_NAME).c -o $(PROGRAM_NAME) ; \
mv $(DRIVER).bak $(DRIVER)  
endef

define PRINT
	 echo $(DIVIDER) ; \
	 echo $(1)
endef

define TEST_OUTPUT
	$(TEST_OUTPUT_PASSES) $(PROGRAM_NAME) $(1)
endef

define TEST_OUTPUT_NOT
	$(TEST_OUTPUT_FAILS) $(PROGRAM_NAME) $(1)
endef
list_tests:
	@echo $(TEST_TARGETS)

test:   clean $(PROGRAM_NAME) $(TEST_OUTPUT_TARGETS)

test_that_passes_holberton_case:
	@$(call PRINT,$@)
	@$(call ARRANGE_INPUT,'Duplicated')
	@$(call TEST_OUTPUT,'Duplicated')

test_that_duplicates_character:
	@$(call PRINT,$@)
	@$(call ARRANGE_INPUT,'a')
	@$(call TEST_OUTPUT,'a')	

test_that_duplicates_three_characters:
	@$(call PRINT,$@)
	@$(call ARRANGE_INPUT,'abc')
	@$(call TEST_OUTPUT,'abc')	

test_that_duplicates_number:
	@$(call PRINT,$@)
	@$(call ARRANGE_INPUT,'1')
	@$(call TEST_OUTPUT,'1')

test_that_allocates_memory:
	@$(call PRINT,$@)
	@$(call ARRANGE_INPUT,'Duplicated')
	@$(call TEST_OUTPUT_NOT,'failed to allocate memory')


test_that_returns_null_when_size_equals_zero: null_driver
	@echo "\n"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	@echo $@
	@$(TEST_PASSES) $< 'Returns NULL when size is 0.'
	@rm $<

test_that_malloc_failure_handled: malloc_failure_driver
	@echo "\n"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	@echo $@
	@$(TEST_PASSES) $< 'Returns NULL when malloc fails.'
	@rm $<

null_driver:
	@echo "\n"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	@echo Building $@...
	@$(CC) -g $(CC_FLAGS) $@.c $(PROGRAM_NAME).c -o $@

malloc_failure_driver:
	@echo "\n"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	@echo Building $@...
	@$(CC) -g $(CC_FLAGS) $@.c $(PROGRAM_NAME).c -o $@
