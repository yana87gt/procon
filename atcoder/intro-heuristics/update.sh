#!/bin/bash

python tester/generator.py 12345 > tester/input.txt
time ./a.out < tester/input.txt > tester/output.txt
python tester/tester.py tester/input.txt tester/output.txt