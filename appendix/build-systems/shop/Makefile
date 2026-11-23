shop: main.o discount.o
	g++ main.o discount.o -o shop

main.o: main.cpp discount.h
	g++ -std=c++20 -Wall -Wextra -c main.cpp

discount.o: discount.cpp discount.h
	g++ -std=c++20 -Wall -Wextra -c discount.cpp
