#!/bin/bash
# FOR CROSS PLATFORM BUILDS AND RUNS:

cd build && rm -rf * | cmake .. && cd ..

# FOR LOCAL BUILDS AND RUNS

rm ./build/longestSequence
cd build && cmake --build . && cd ..
# clear

# python3 ./tests/run_test.py | ./build/longestSequence >> ./tests/results.txt
# python3 ./tests/read_test.py
# rm ./tests/results.txt

./build/longestSequence ./tests/test_1 ./tests/test_2 ./tests/test_3 ./tests/test_4