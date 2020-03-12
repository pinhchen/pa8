test: test_heap.run
	valgrind --leak-check=full --undef-value-errors=no ./test_heap.run

test_novg: test_heap.run
	./test_heap.run

test_heap.run: test_heap.c heap.c heap.h
	gcc -g -Wall -o test_heap.run heap.c test_heap.c cutest/CuTest.c

insert: insert.run
	valgrind --leak-check=full --undef-value-errors=no ./insert.run

insert.run: insert.c insert_main.c
	gcc -Wall -g insert.c insert_main.c -o insert.run

match_struct: match_struct.run
	valgrind --leak-check=full --undef-value-errors=no ./match_struct.run

match_struct.run: match_struct.c
	gcc -Wall -g match_struct.c -o match_struct.run
