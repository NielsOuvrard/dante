##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## un makefile de qualité
##

all:
		@cp ./../lib/my/my.h ../include/my.h
		@gcc -c ../lib/my/*.c
		@ar rc ../lib/my/libmy.a *.o
		@gcc -o solver -g ../src_solver/*.c\
		-I./../include/ -L./../lib/my/ -lmy -g3
		@chmod 777 solver
		@make clean

clean:
		@rm -f *.o

fclean:
		@rm solver

re:	fclean all

auteur:
	echo $(USER) > auteur

push:
		git add .
		git status
		git commit -m "push automatique"
		git push

.PHONY: all clean fclean re push
