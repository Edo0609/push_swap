#! /bin/bash
make

valgrind --leak-check=yes ./push_swap 0 2 00000000000000000000000000000001

valgrind --leak-check=yes ./push_swap 0 2 1

valgrind --leak-check=yes ./push_swap 0 2 2

valgrind --leak-check=yes ./push_swap 0 2 ++1

valgrind --leak-check=yes ./push_swap 0 2 --1

valgrind --leak-check=yes ./push_swap 0 2 +-1

valgrind --leak-check=yes ./push_swap 0 2 -+1

valgrind --leak-check=yes ./push_swap 0 2"0" 1

valgrind --leak-check=yes ./push_swap 0 "2" "1"

valgrind --leak-check=yes ./push_swap "0 2 1"

valgrind --leak-check=yes ./push_swap 0 1999999999999999999999999999 2

valgrind --leak-check=yes ./push_swap 0 2 -19999999999999999999999999999

valgrind --leak-check=yes ./push_swap -0 2 1

valgrind --leak-check=yes ./push_swap +0 2 1

valgrind --leak-check=yes ./push_swap 0 2 1 ""

valgrind --leak-check=yes ./push_swap 0 2 1 "    "

valgrind --leak-check=yes ./push_swap 0 2 "" 1

valgrind --leak-check=yes ./push_swap 0 2 "     " 1

valgrind --leak-check=yes ./push_swap 0 2"" 1

valgrind --leak-check=yes ./push_swap 0 2"    " 1

valgrind --leak-check=yes ./push_swap 0 2+7 1

valgrind --leak-check=yes ./push_swap 0 -2+3 1

valgrind --leak-check=yes ./push_swap 0 '2' 1

valgrind --leak-check=yes ./push_swap ""

valgrind --leak-check=yes ./push_swap "   " ""

valgrind --leak-check=yes ./push_swap 0 '2' -

valgrind --leak-check=yes ./push_swap "13 -1230 55 4 5 -7 - "