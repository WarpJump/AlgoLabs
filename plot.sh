#!/bin/bash

mkdir -p temp

> temp/temp_data.txt

echo -e "set terminal png \n set output 'outputs/graph.png' \n set xlabel 'Число операций push/pop' \n set ylabel 'Временные затраты (microsec)'" >> temp/temp_data.txt
echo "plot 'outputs/LIST_time.txt' with lines title 'График для стека на списке', 'outputs/ARR_time.txt' with lines title 'График для стека на массива'" >> temp/temp_data.txt

gnuplot temp/temp_data.txt

rm -r temp