CC = gcc
CFLAGS = -g -Wall -Werror -pedantic 


PROGRAM_NAME = 1-strdup
TASK_NUMBER = $(shell echo $(PROGRAM_NAME) | sed 's/[^0-9]*\([0-9]\+\).*/\1/')

# Define the object files needed for the final executable.
OBJECTS = $(PROGRAM_NAME).o $(TASK_NUMBER)-main.o _putchar.o
SRC = $(PROGRAM_NAME).c $(TASK_NUMBER)-main.c _putchar.c

TEST_PASSES = ~/c_test/c_test   
TEST_FAILS= ~/c_test/c_test_expect_fail   

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


TEST_PASSES = ~/c_test/c_test 
TEST_FAILS= ~/c_test/c_test_expect_fail 
TEST_TARGETS = \
	#test_that_allocates_memory \
	#test_that_malloc_failure_handled

list_tests:
	@echo $(TEST_TARGETS)

test:   $(TEST_TARGETS)
	@echo "\n"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	@echo Integration Test
	@$(TEST_PASSES) $(PROGRAM_NAME) dummy < tests/$(PROGRAM_NAME)
	@echo 		TESTING COMPLETED
	@echo -----------------------------------------

test_that_allocates_memory:
	@echo ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	@echo "\n"$@
	@$(TEST_FAILS) $(PROGRAM_NAME) 'failed to allocate memory'

test_that_malloc_failure_handled: malloc_failure_driver
	@echo "\n"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	@echo $@
	# Run test.
	@$(TEST_PASSES) $< 'Returns NULL when malloc fails.'
	# Teardown: delete test executable.
	@rm $<

malloc_failure_driver:
	@echo "\n"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	@echo Building $@...
	# Setup: put function in test harness.
	@sed -i '19s/.*/	char *array = _strdup("Unimportant");/' $@.c
	# Compile test driver.
	@$(CC) -g $(CC_FLAGS) $@.c $(PROGRAM_NAME).c -o $@
