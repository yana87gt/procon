#!/bin/sh
echo "which problem?"
read problem
if eval "g++-5 -O3 -std=c++11 -Wall -Wextra -Wshadow -fsanitize=undefined -fsanitize=address $problem.cpp" ;then
    echo "compiled!!"
    for i in `seq 1 4`
    do
        eval "./a.out < $problem$i.in > $problem$i.res"
        echo "--- difference in $problem$i.in ---"
        echo "  your answer | correct answer"
        eval "diff -y -w --suppress-common-lines -W30 $problem$i.res $problem$i.diff"
    done
fi