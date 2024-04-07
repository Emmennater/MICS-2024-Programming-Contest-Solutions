all: highly-recursive-function top-of-the-heap farkel-roll letter-scaling valley-sort kudok-16 weather-forcast secret-code

top-of-the-heap:
	g++ top-of-the-heap.cpp -ggdb3 -o top-of-the-heap

highly-recursive-function:
	g++ highly-recursive-function.cpp -ggdb3 -o highly-recursive-function

farkel-roll:
	g++ farkel-roll.cpp -ggdb3 -o farkel-roll

letter-scaling:
	g++ letter-scaling.cpp -ggdb3 -o letter-scaling

secret-code:
	g++ secret-code.cpp -ggdb3 -o secret-code

weather-forcast:
	g++ weather-forcast.cpp -ggdb3 -o weather-forcast

kudok-16:
	g++ kudok-16.cpp -ggdb3 -o kudok-16

valley-sort:
	g++ valley-sort.cpp -ggdb3 -o valley-sort

.PHONY: all
