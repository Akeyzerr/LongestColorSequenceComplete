#!/bin/bash
# FOR CROSS PLATFORM BUILDS AND RUNS:
cd build && rm -rf * | cmake .. && cd ..

# rm ./build/lcs
cd build && cmake --build . && cd ..

valgrind --leak-check=full ./build/longestSequence ./tests/test_004