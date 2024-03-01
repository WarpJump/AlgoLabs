#!/bin/bash

> base_tests.txt

NUM_OF_TESTS=7

for target in TEST1 TEST2 TEST3
do 
    echo "Running iterations for target $target"

    for method in ARR LIST
    do
        total_time=0
        make $target $method

        for ((i=1;i<=NUM_OF_TESTS;i++))
        do
            start_time=$(date +%s%3N)
            temp/main.out
            end_time=$(date +%s%3N)
            
            execution_time=$((end_time - start_time))
            
            total_time=$((total_time + execution_time))
        done

        average_time=$(($total_time / $NUM_OF_TESTS))

        echo "Average list execution time for target $target $method: $average_time ms"

        echo "Average list execution time for target $target $method: $average_time ms" >> base_tests.txt
        make clean
    done
echo -e "\n" >> base_tests.txt
done


> time.txt


for method in ARR LIST
do

    make TEST4 $method
    for((i = 1000; i <=1000000; i += 1000))
    do
            start_time=$(date +%s%3N)
            temp/main.out $i
            end_time=$(date +%s%3N)
            
            execution_time=$((end_time - start_time))
            echo -e "$method $i $execution_time" >> time.txt
    done
    make clean
done