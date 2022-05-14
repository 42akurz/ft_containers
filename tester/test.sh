#!/bin/bash

clang++ -Wall -Wextra -Werror -DUSING_STD vector_tests.cpp -o real_vec
./real_vec > real_out.txt

clang++ -Wall -Wextra -Werror vector_tests.cpp -o my_vec
./my_vec > my_out.txt

rm real_vec my_vec

diff real_out.txt my_out.txt > diff.txt

exit 0