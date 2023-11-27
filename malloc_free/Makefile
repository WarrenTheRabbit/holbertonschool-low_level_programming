CC = gcc
CFLAGS = -Wall -Werror -pedantic 


PROGRAM_NAME = 2-str_concat
TASK_NUMBER = $(shell echo $(PROGRAM_NAME) | sed 's/[^0-9]*\([0-9]\+\).*/\1/')
DRIVER = $(TASK_NUMBER)-main.c


# Define the object files needed for the final executable.
OBJECTS = $(PROGRAM_NAME).o $(TASK_NUMBER)-main.o _putchar.o strlen.o
SRC = $(PROGRAM_NAME).c $(TASK_NUMBER)-main.c _putchar.c strlen.c
DRIVER = $(TASK_NUMBER)-main.c


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


# Pattern rule to create object files from corresponding source files
%.o: %.c
	@echo Compiling '$<' to object code...
	@$(CC) -g $(CFLAGS) -c $< -o $@


build: clean $(PROGRAM_NAME)

# Phony targets execute even if target exists in file system.
.PHONY: clean test edit debug vim push test_case main malloc_failure_driver
clean:
	@echo Cleaning...
	@rm -f $(OBJECTS) $(PROGRAM_NAME)
	@echo 		CLEANING COMPLETED

debug:  $(PROGRAM_NAME)
	@echo Debugging.. 

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

ASSERT_OUTPUT_IS_PASSES = ./ctest 
ASSERT_OUTPUT_IS_FAILS= ./ctest_fail 

TEST_TARGETS := $(shell grep -oP "^test_that.*?(?=:)" Makefile)

DIVIDER = '~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'


define ARRANGE_TEST_HARNESS
sed -i.bak '14s/(.*/($(2), $(3));' $(1) \
rm $(PROGRAM_NAME) ; \
$(CC) -g $(CC_FLAGS) $(1) $(PROGRAM_NAME).c -o $(PROGRAM_NAME)
endef

define PRINT_TEST_NAME
	 echo $(DIVIDER) ; \
	 echo $(1)
endef

define ASSERT_OUTPUT_IS
	$(ASSERT_OUTPUT_IS_PASSES) $(PROGRAM_NAME) $(1)
endef

define ASSERT_OUTPUT_NOT
	$(ASSERT_OUTPUT_IS_FAILS) $(PROGRAM_NAME) $(1)
endef

define TEARDOWN_TEST_HARNESS
	mv $(DRIVER).bak $(1)  
endef


list_tests:
	@echo $(ASSERT_OUTPUT_IS_TARGETS)

test:   clean $(PROGRAM_NAME) $(TEST_TARGETS)

test_that_str_concat_passes_example_case:
	@$(call PRINT_TEST_NAME,$@)
	@sed -i.bak '14s/(.*/("Best ", "School");/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME)
	@$(call ASSERT_OUTPUT_IS,'Best School')
	@$(call TEARDOWN_TEST_HARNESS,$(DRIVER))

test_that_strdup_joins_empty_strings:
	@$(call PRINT_TEST_NAME,$@)
	@sed -i.bak '14s/(.*/("", "");/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME)
	@$(call ASSERT_OUTPUT_IS,'')
	@$(call TEARDOWN_TEST_HARNESS,$(DRIVER))

test_that_str_concat_joins_when_first_argument_null:
	@$(call PRINT_TEST_NAME,$@)
	@sed -i.bak '14s/(.*/(NULL, "hello");/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME)
	@$(call ASSERT_OUTPUT_IS,'hello')
	@$(call TEARDOWN_TEST_HARNESS,$(DRIVER))

test_that_str_concat_joins_when_second_argument_null:
	@$(call PRINT_TEST_NAME,$@)
	@sed -i.bak '14s/(.*/("hello", NULL);/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME)
	@$(call ASSERT_OUTPUT_IS,'hello')
	@$(call TEARDOWN_TEST_HARNESS,$(DRIVER))

test_that_str_concat_joins_characters:
	@$(call PRINT_TEST_NAME,$@)
	@sed -i.bak '14s/(.*/("a", "b");/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME)
	@$(call ASSERT_OUTPUT_IS,'ab')	
	@$(call TEARDOWN_TEST_HARNESS,$(DRIVER))

test_that_str_concat_joins_strings:
	@$(call PRINT_TEST_NAME,$@)
	@sed -i.bak '14s/(.*/("abc", "def");/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME)
	@$(call ASSERT_OUTPUT_IS,'abcdef')	
	@$(call TEARDOWN_TEST_HARNESS,$(DRIVER))

test_that_str_concat_joins_number:
	@$(call PRINT_TEST_NAME,$@)
	@sed -i.bak '14s/(.*/("1", "2");/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME)
	@$(call ASSERT_OUTPUT_IS,'12')
	@$(call TEARDOWN_TEST_HARNESS,$(DRIVER))

test_that_strdup_allocates_memory:
	@$(call PRINT_TEST_NAME,$@)
	@sed -i.bak '14s/(.*/("Best ", "School");/' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME)
	@$(call ASSERT_OUTPUT_NOT,'failed')
	@$(call TEARDOWN_TEST_HARNESS,$(DRIVER))

malloc_failure_driver:
	@sed -i.bak '/int main/ivoid* malloc(size_t size) { return (NULL); }' $(DRIVER)
	@$(CC) -g $(CC_FLAGS) $(SRC) -o $(PROGRAM_NAME).bk
	@mv $(DRIVER).bak $(DRIVER)
