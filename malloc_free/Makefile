CC = gcc
CFLAGS = -Wall -Werror -pedantic 


PROGRAM_NAME = 1-strdup
TASK_NUMBER = $(shell echo $(PROGRAM_NAME) | sed 's/[^0-9]*\([0-9]\+\).*/\1/')

# Define the object files needed for the final executable.
OBJECTS = $(PROGRAM_NAME).o $(TASK_NUMBER)-main.o _putchar.o
SRC = $(PROGRAM_NAME).c $(TASK_NUMBER)-main.c _putchar.c
DRIVER = $(TASK_NUMBER)-main.c

TEST_OUTPUT_PASSES = ~/c_test/c_test   
TEST_OUTPUT_FAILS= ~/c_test/c_test_expect_fail   

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


build: clean $(PROGRAM_NAME) test

# Phony targets execute even if target exists in file system.
.PHONY: clean test edit debug vim push test_case main malloc_failure_driver
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


TEST_OUTPUT_PASSES = ~/c_test/c_test 
TEST_OUTPUT_FAILS= ~/c_test/c_test_expect_fail 

TEST_OUTPUT_TARGETS := $(shell grep -oP "^test_that.*?(?=:)" Makefile)
DIVIDER = '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'


define ARRANGE_INPUT
@echo BEFORE
cat $(DRIVER)
sed -i.bak 's/Duplicated/$(1)/' $(DRIVER) ; \
echo AFTER
cat $(DRIVER)
rm $(PROGRAM_NAME)
$(CC) -g $(CC_FLAGS) $(DRIVER) $(PROGRAM_NAME).c -o $(PROGRAM_NAME) ; \
mv $(DRIVER).bak $(DRIVER)  
echo RESTORED
cat 1-main.c
endef

define PRINT
	 echo $(DIVIDER) ; \
	 echo $(1)
endef

define TEST_OUTPUT
	$(TEST_OUTPUT_PASSES) $(PROGRAM_NAME) $(1)
endef

list_tests:
	@echo $(TEST_OUTPUT_TARGETS)



test:   clean $(PROGRAM_NAME) $(TEST_OUTPUT_TARGETS)
	@echo 		TEST_OUTPUTING COMPLETED
	@echo -----------------------------------------


test_that_duplicates_character: returns_single_character
	@echo $(DIVIDER) 
	@echo "\n"$@ 
	@$(TEST_OUTPUT_PASSES) $(PROGRAM_NAME) 'a' 
	

returns_single_character:
	@sed -i.bak 's/Duplicated/a/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(DRIVER) $(PROGRAM_NAME).c -o $(PROGRAM_NAME)
	@mv $(DRIVER).bak $(DRIVER)

test_that_duplicates_character_alternative:
	@$(call PRINT,$@)
	@$(call ARRANGE_INPUT,'a')
	@$(call TEST_OUTPUT,'a')	


test_that_duplicates_three_characters:
	@$(call PRINT,$@)
	@$(call ARRANGE_INPUT,'aaa')
	@$(call TEST_OUTPUT,'aaa')	

test_that_duplicates_number:
	@$(call PRINT,$@)
	@$(call ARRANGE_INPUT,'1')
	@$(call TEST_OUTPUT,'1')

test_that_duplicates_two_characters:
	@echo $(DIVIDER) 
	@echo "\n"$@ 
	
# 	Arrange
	@sed -i.bak 's/Duplicated/aa/' $(DRIVER)
	
# 	Act
	@$(CC) -g $(CC_FLAGS) $(DRIVER) $(PROGRAM_NAME).c -o $(PROGRAM_NAME).bk
	
# 	Assert
	@$(TEST_OUTPUT_PASSES) $(PROGRAM_NAME) 'aa' 

# 	Teardown
	@mv $(DRIVER).bak $(DRIVER)


test_that_holberton_test_case_works: 
	@echo $(DIVIDER) 
	@echo "\n"$@ 
	@$(TEST_OUTPUT_PASSES) $(PROGRAM_NAME) dummy < tests/$(PROGRAM_NAME)
	

test_that_allocates_memory:
	@echo $(DIVIDER)
	@echo "\n"$@
	@$(TEST_OUTPUT_FAILS) $(PROGRAM_NAME) 'failed to allocate memory'

test_that_malloc_failure_handled: malloc_failure_driver
	@echo $(DIVIDER)
	@echo "\n"$@
	@$(TEST_OUTPUT_PASSES) $(PROGRAM_NAME).bk 'failed to allocate memory'
	@rm $(PROGRAM_NAME).bk

malloc_failure_driver:
	@sed -i.bak '/int main/ivoid* malloc(size_t size) { return (NULL); }' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(DRIVER) $(PROGRAM_NAME).c -o $(PROGRAM_NAME).bk
	@mv $(DRIVER).bak $(DRIVER)
