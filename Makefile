CFLAGS = -std=gnu17 -Wall -O0 -pipe -fno-plt -fPIC
CPPFLAGS = -Wall -O0 -pipe -fno-plt -fPIC

default: combinations_cpp

combinations: combinations.c
	$(CC) $(CFLAGS) combinations.c -o combinations

combinations_cpp: combinations.cpp
	g++ $(CPPFLAGS) combinations.cpp -o combinations

.PHONY: clean
clean:
	rm -f combinations
