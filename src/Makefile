CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
CHECK_FLAGS = $(shell pkg-config check --cflags --libs)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)

SRC = ./s21_matrix
PROJECT_NAME = s21_matrix
OBJECTS = $(SRC)/*.o

all: clean s21_matrix.a

s21_matrix.a: $(wildcard $(SRC)/*.c)
	$(CC) $(CFLAGS) -c $+
	ar rc $(PROJECT_NAME).a *.o
	ranlib $(PROJECT_NAME).a
	rm -rf *.o

clean:
	rm -rf *.a *.o */*.o *.gcda *.gcno report $(PROJECT_NAME)_gcov_report $(PROJECT_NAME)_test $(PROJECT_NAME)_test_leaks

rebuild: clean s21_matrix.a test

test:
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_matrix_test.c ./s21_matrix_tests/*.c $(PROJECT_NAME).a -o $(PROJECT_NAME)_test $(CHECK_FLAGS)
	./$(PROJECT_NAME)_test
	rm -rf *.gcda *.gcno *.o

gcov_report: $(wildcard $(SRC)/*.c)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $^
	ar rc $(PROJECT_NAME).a *.o
	ranlib $(PROJECT_NAME).a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_matrix_test.c ./s21_matrix_tests/*.c $(PROJECT_NAME).a -o $(PROJECT_NAME)_$@ $(CHECK_FLAGS)
	./$(PROJECT_NAME)_$@
	rm -rf report
	mkdir -p report
	gcovr --html-details -o report/coverage.html --exclude s21_matrix_tests/
	rm -rf *.gcda *.gcno *.o

clang-format:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -n *.c *.h */*.c

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h */*.c */*.h

test_leaks:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) -fsanitize=address $(PROJECT_NAME)_test.c ./s21_matrix_tests/*.c $(PROJECT_NAME).a -o $(PROJECT_NAME)_test_leaks $(CHECK_FLAGS)
	./$(PROJECT_NAME)_test_leaks &
	leaks --atExit -- ./$(PROJECT_NAME)_test_leaks  
else
	$(CC) $(CFLAGS) $(PROJECT_NAME)_test.c $(SRC)_tests/*.c $(PROJECT_NAME).a -o $(PROJECT_NAME)_test_leaks $(CHECK_FLAGS)
	touch valgrind_res.txt
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./$(PROJECT_NAME)_test_leaks
endif