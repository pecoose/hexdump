CC := clang
INCLUDE_DIR := -I .
C_FLAGS := -Wall
C_FLAGS += -Werror
C_FLAGS += -pedantic
SRC_DIR := .

PROG := a.out
DEP_SRC := $(wildcard $(SRC_DIR)/*.c)
DEP_OBJ := $(patsubst %.c, %.o, $(DEP_SRC))

.PHONY : $(PROG) clean 

$(PROG) : $(DEP_OBJ)
	$(CC) $(C_FLAGS) -o $@ $^

$(DEP_OBJ) : %.o:%.c
	$(CC) $(INCLUDE_DIR) $(C_FLAGS) -c $^ -o $@

clean : 
	rm $(PROG) $(SRC_DIR)/*.o

