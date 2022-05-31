#!bin/bash

c++ -Wall -Wextra -Werror main.cpp -o real
c++ -Wall -Wextra -Werror -DFT main.cpp -o mine

./real > real.txt
./mine > mine.txt

diff real.txt mine.txt > diff.txt

rm real mine