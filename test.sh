#!/bin/bash
g++ -std=c++11 rand.cpp -o rand
./rand > in
g++ -std=c++11 a.cpp -o a
g++ -std=c++11 b.cpp -o b

while true;do
	./rand >in
	./a <in >outa
	./b <in >outb
	diff outa outb
	if [ $? -ne 0 ]; then break; fi
done

