##
## 27/03/2020 Paris
## Makefile
## File description:
## Adrien Colombier
##

all:
	@make -C library --no-print-directory
	@make re -C app --no-print-directory

clean:
	@make clean -C library --no-print-directory
	@make clean -C app --no-print-directory

fclean:
	@make fclean -C library --no-print-directory
	@make fclean -C app --no-print-directory

re:
	@make re -C library --no-print-directory
	@make re -C app --no-print-directory

.PHONY: all clean fclean re