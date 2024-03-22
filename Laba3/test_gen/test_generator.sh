#!/bin/bash

output_folder=$1
from=$2
to=$3
step=$4
max_elem=$5
NUM_OF_TESTS=$6

mkdir -p $output_folder

for ((size = $from; size <= $to; size += $step)); do
    for ((k = 0; k < NUM_OF_TESTS; k++)); do
        ./test_gen/random_gen $size $max_elem >$output_folder/${size}_${k}.in
        ./test_gen/qsort_checker <$output_folder/${size}_${k}.in >$output_folder/${size}_${k}.out
    done
done
