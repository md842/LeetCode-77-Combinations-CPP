# LeetCode #77: Combinations (Daily Challenge 08/01/2023)
This repository contains a C++ solution to the LeetCode daily challenge #77 for 08/01/2023. https://leetcode.com/problems/combinations/

This solution beats 100.00% of users in runtime (0 ms) and 99.56% of users in memory usage (8.80 MB). 

I discuss the solution here: https://leetcode.com/problems/combinations/solutions/3850667/iterative-c-python3-solution-beats-100-runtime-99-56-memory/.

I also have a C solution here that seems to work perfectly on my end, but LeetCode seems have a bug in their access of **returnColumnSizes that I don't have control over. I've tested it extensively and triple checked the memory accesses, so I am not sure what is going wrong in their black box.

## Running
Navigate to the directory containing the extracted implementation, then simply run `make` with the included Makefile.
```
cd LeetCode-77-Combinations-CPP
make
```

The exact commands run by `make` are as follows:

```
g++ -Wall -O0 -pipe -fno-plt -fPIC combinations.cpp -o combinations
```

To run the C implementation instead, run `make combinations`. You'll need to run `make clean` to switch between implementations.

The exact commands run by `make combinations` are as follows:

```
cc -std=gnu17 -Wall -O0 -pipe -fno-plt -fPIC combinations.c -o combinations
```

There are no arguments; the test cases are hard-coded into the C++/C files.

## Cleaning up
Navigate to the directory containing the extracted implementation, then simply run `make clean` with the included Makefile. This will work regardless of whether the C or C++ implementation was built.

```
cd LeetCode-77-Combinations-CPP
make clean
```

The exact commands run by make clean are as follows:

```
rm -f combinations
```
