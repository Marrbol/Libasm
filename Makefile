##
## EPITECH PROJECT, 2023
## B-ASM-400-REN-4-1-bsasmminilibc-martin.boucault
## File description:
## Makefile
##

SRC = src/strlen.asm  	\
	  src/strchr.asm  	\
	  src/strrchr.asm 	\
	  src/memset.asm	\
	  src/memmove.asm	\
	  src/memcpy.asm	\
	  src/strcmp.asm 	\
	  src/strncmp.asm 	\
	  src/strcasecmp.asm\

SRCTEST		=	test/test.c \

OBJ = $(SRC:.asm=.o)

OBJTEST = $(SRCTEST:.c=.o)

TESTS_FLAG = --coverage -lcriterion

NAME = libasm.so

$(NAME): $(OBJ)
	ld --shared -o $(NAME) $(OBJ)

%.o : %.asm
	nasm -f elf64 $< -o $@

all: $(NAME)

tests_run: cleantest
	gcc $(SRCTEST) -o unit_test $(TESTS_FLAG) -ldl

test: tests_run
	./unit_test
	rm -f $(OBJTEST)
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_test

clean:
	rm -f $(OBJ)

cleantest:
	rm -f $(OBJTEST)
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_test

fclean: clean
	rm -f $(NAME)
	rm -f *.so
	rm -f vgcore.*
	rm -f *~
	rm -f a.out

re: fclean all
