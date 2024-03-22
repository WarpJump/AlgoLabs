#!/bin/bash

gcc test_gen/random_generator.c -o test_gen/random_gen
gcc test_gen/ans_generator.c -o test_gen/qsort_checker

if [ -d tests ]; then rm -r tests; fi

MAX_RAND=2147483647

#signature : <output_dir> <min test size> <max test size>  <step> <max number in test> <number of such tests>
test_gen/test_generator.sh tests/very_small_tests 1 150 1 $MAX_RAND 5

test_gen/test_generator.sh tests/small_tests 0 1000 50 $MAX_RAND 5

test_gen/test_generator.sh tests/big_tests 0 1000000 10000 $MAX_RAND 1

test_gen/test_generator.sh tests/test_most_dublicates 0 1000000 10000 $MAX_RAND 1

rm test_gen/random_gen
rm test_gen/qsort_checker
