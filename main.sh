#!/bin/bash

mkdir -p outputs

> outputs/base_tests.txt

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
             execution_time=$(temp/main.out)

            total_time=$((total_time + execution_time))
        done

        average_time=$(($total_time / $NUM_OF_TESTS))

        echo "Average list execution time for target $target $method: $average_time microsec"

        echo "Average list execution time for target $target $method: $average_time microsec" >> outputs/base_tests.txt
        make clean
    done
echo -e "\n" >> outputs/base_tests.txt
done




for method in ARR LIST
do

    make TEST4 $method
    > outputs/${method}_time.txt

    for((i = 1000; i <=1000000; i += 1000))
    do
            execution_time=$(temp/main.out $i)

            echo -e "$i $execution_time" >> outputs/${method}_time.txt
    done
    make clean
done


./plot.sh