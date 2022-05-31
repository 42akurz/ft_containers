#!/bin/bash

c++ -Wall -Werror -Wextra ENDBOSS.cpp -o ft_container
./ft_container > out1

c++ -Wall -Werror -Wextra -DSTD ENDBOSS.cpp -o std_container
./std_container > out2

rm ft_container std_container

diff out1 out2 > diff.txt

rm out1 out2

exit 0