.PHONY: 21_decimal.a test clean cppcheck format
all: s21_decimal.a test 

binary_s := $(shell find ./binary -maxdepth 1 -iname "*.c" )
comparison_s := $(shell find ./comparison -maxdepth 1 -iname "*.c" )
conversion_s := $(shell find ./conversion -maxdepth 1 -iname "*.c" )
helpers_s := $(shell find ./helpers -maxdepth 1 -iname "*.c" )
math_ops_s := $(shell find ./math_ops -maxdepth 1 -iname "*.c" )

all := $(shell find ./ -iname "*.c" )
test_f := $(shell find ./tests/ -iname "*.c" )

ifeq ($(shell uname -s),Darwin)
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@.a -lcheck -lpthread -lm 
else
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@.a -lcheck -lgcov -lpthread -lm 
endif

s21_decimal.a: ${binary_s} ${helpers_s} ${math_ops_s} ${conversion_s} ${comparison_s}
	gcc -g -c $^
	ar rc $@  *.o
	ranlib $@

test: ${test_f} ${binary_s} ${helpers_s} ${math_ops_s} ${conversion_s} ${comparison_s}
	gcc -g $(TEST_FLAGS)
	./$@.a

gcov_report: test
	gcov ${binary_s} ${helpers_s} ${math_ops_s} ${conversion_s} ${comparison_s} || true
	# rm -rf test*.gcda test*.gcno main.gcda main.gcno
	find ./ -type f -iname '*.gcda'
	lcov --directory ./ --capture --output-file postgresql.info
	mkdir cov-report || true
	genhtml -o ./cov-report/ postgresql.info

cppcheck: $(all) 
	cppcheck $^;

format: $(all)
	clang-format -i -style=google $^;

clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.dSYM
	-rm -rf lib* && rm -rf test
	-rm -rf test_*
