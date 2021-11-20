main: driver.c single_linked_list.c circular_linked_list.c
		gcc -g -ggdb -o main stack.c driver.c circular_linked_list.c single_linked_list.c double_linked_list.c

clean:
		rm -rf *.o main