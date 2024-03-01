#!/bin/bash

> time.txt

NUM_OF_TESTS=5

for target in TEST1 TEST2 TEST3
do 
    echo "Running iterations for target $target"

    for method in ARR LIST
    do
        total_time=0
        make $target $method

        for i in {1..$NUM_OF_TESTS}
        do
            start_time=$(date +%s%3N)
            temp/main.out
            end_time=$(date +%s%3N)
            
            execution_time=$((end_time - start_time))
            
            total_time=$((total_time + execution_time))
        done

        average_time=$((total_time / $NUM_OF_TESTS))

        echo "Average list execution time for target $target $method: $average_time ms"

        echo -e "Average list execution time for target $target $method: $average_time ms\n" >> time.txt
        make clean
    done
done