##
## 27/03/2020 Paris
## Makefile
## File description:
## Adrien Colombier
##

all:
	@make -C library --no-print-directory
	@make re -C test --no-print-directory

clean:
	@make clean -C library --no-print-directory
	@make clean -C test --no-print-directory

fclean:
	@make fclean -C library --no-print-directory
	@make fclean -C test --no-print-directory

re:
	@make re -C library --no-print-directory
	@make re -C test --no-print-directory

.PHONY: all clean fclean re