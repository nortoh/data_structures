main: driver.c single_linked_list.c
		gcc -g -ggdb -o main driver.c single_linked_list.c double_linked_list.c

clean:
		rm -rf *.o main