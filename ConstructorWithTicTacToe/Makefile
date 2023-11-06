PROGRAM_NAME = tictactoe
EX_NAME = cons_ex
FILES = $(wildcard *.cpp)
RM = rm -f

ifeq ($(OS),Windows_NT)
	PROGRAM_NAME := $(PROGRAM_NAME).exe
	EX_NAME := $(EX_NAME).exe
	RM = del /q
endif

all: $(PROGRAM_NAME) $(EX_NAME)

$(PROGRAM_NAME): $(FILES)
	g++ -o $@ $^ -g

$(EX_NAME): $(FILES)
	g++ -o $@ $^ -g -D CPP_CONSTRUCTOR_EXAMPLE

clean:
	$(RM) $(PROGRAM_NAME) $(EX_NAME)
