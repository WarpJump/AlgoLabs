# FirstAlgoLaba
## Reruirements
gcc
bash
gnuplot https://archlinux.org/packages/extra/x86_64/gnuplot/

## Running tests
TL;DR - запустить main.sh, тесты запустятся и построится график outputs/graph.png
Склонировать репозиторий, запустить main.sh. main.sh автоматически собирает тесты с первого по четвёртый, запускает их и сохраняет время работы в папку outputs, затем запускает скрипт plot.sh, который строит график по данным из outputs при помощи утилиты gnuplot
