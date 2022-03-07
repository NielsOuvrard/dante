##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## un makefile de qualité
##

all:
		@cp ./lib/my/my.h include/my.h
		@gcc -c lib/my/*.c
		@ar rc lib/my/libmy.a *.o
		@cp ./lib/my/libmy.a lib/libmy.a

		@gcc -o generator_ -g src_generator/*.c -I./include/ -L./lib/my/ -lmy -g3
		mv generator_ generator/generator

		@gcc -o solver_ -g src_solver/*.c -I./include/ -L./lib/my/ -lmy -g3
		mv solver_ solver/solver

		@chmod 777 maze
		@make clean

clean:
		@rm -f *.o

fclean:
		@rm lib/my/libmy.a
		@rm lib/libmy.a
		@rm maze

re:	fclean all

auteur:
	echo $(USER) > auteur

push:
		git add .
		git status
		git commit -m "push automatique"
		git push

.PHONY: all clean fclean re push
