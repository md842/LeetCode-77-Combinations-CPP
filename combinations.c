/*
 * Leetcode 77: Combinations https://leetcode.com/problems/combinations/.

 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 
 * You may return the answer in any order.
 
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_arr(int* arr_to_print, int num_items){
  printf("Debug array print: %p [ ", arr_to_print);
  for (int i = 0; i < num_items; i++){
    printf("%d ", arr_to_print[i]);
  }
  printf("]\n");
}

void print_2d_arr(int** arr_to_print, int num_rows, int num_cols){
  printf("Debug 2D array print: %p [", arr_to_print);
  for (int row = 0; row < num_rows; row++){
    printf("[ ");
    for (int col = 0; col < num_cols; col++){
      printf("%d ", arr_to_print[row][col]);
    }
    printf("]");
  }
  printf("]\n");
}

void deepcopy(int* source, int* destination, int copySize){
  // printf("Beginning deepcopy from %p to %p\n", source, destination);
  for (int i = 0; i < copySize; i++){
    destination[i] = source[i];
  }
  // printf("Completed deepcopy from %p to %p\n", source, destination);
  // print_arr(destination, copySize);
}

int fact(int n){
  int f = 1;
  for(int i = 1; i <= n; i++)
    f *= i;
  return f;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
  int num_items = fact(n) / (fact(k) * fact(n - k));
  
  *returnSize = num_items * k * sizeof(int);
  
  int** out_arr = (int**)malloc(*returnSize);
  *returnColumnSizes = (int*)malloc(num_items * sizeof(int));
  
  for (int i = 0; i < num_items; i++){
    out_arr[i] = (int*)malloc(k * sizeof(int));
    (*returnColumnSizes)[i] = k;
  }
  
  int cur = 0;
  if (k == 1){ // k = 1; just return all [1, n] individually wrapped.
    for (int i = 0; i < n; i++){
      out_arr[i][0] = i + 1;
    }
    return out_arr;
  }

  // Initial list
  int init_arr[k];
  for (int i = 0; i < k; i++){
    init_arr[i] = i + 1;
  }
  
  deepcopy(init_arr, out_arr[cur], k);
  cur++;

  // Expand the initial list
  int pos = k - 1; // pos is the position in the sublist we're working on expanding
  int max_pos = 0; // the limit (first item of sub_arr represented as negative index)

  while(pos > max_pos){
    while (init_arr[k - 1] < n){ // Last item in the list isn't at n yet
      init_arr[k - 1]++; // Increment it
      deepcopy(init_arr, out_arr[cur], k); // List slicing has the effect of deepcopy here, but is much faster.
      cur++;
    }

    pos -= 1; // Backtrack to the previous item in the list
    if (init_arr[pos] < (n - k + pos + 1)){ // Check if it's at its maximum
      // (The maximum is based on its position in the list)
      init_arr[pos]++; // If yes, increment it
      for (int i = pos + 1; i < k; i++){ // Reset rest of list accordingly
	init_arr[i] = init_arr[pos] + i - pos;
      }
      deepcopy(init_arr, out_arr[cur], k);
      cur++;
      pos = k - 1; // Reset position back to last item
    }
  }
  return out_arr;
}


int main(){
  // Test cases
  int n = 6;
  int k = 5;
  const int expectedCombinations = 6;

  int returnSize = expectedCombinations * k * sizeof(int);
  
  int* returnColumnSizes = 0;
  int** received_output = combine(n, k, &returnSize, &returnColumnSizes);
  
  printf("Received output (size %d): ", returnSize);

  for (int row = 0; row < expectedCombinations; row++){
    printf("[ ");
    for (int col = 0; col < k; col++){
      printf("%d ", received_output[row][col]);
    }
    printf("]");
  }
  printf("\n");

  printf("Return column sizes: [ ");
  for (int i = 0; i < expectedCombinations; i++){
    printf("%d ", *(returnColumnSizes));
  }
  printf("]\n");

  for (int i = 0; i < expectedCombinations; i++){
    free(received_output[i]);
  }
  free(received_output);
  free(returnColumnSizes);
  
  return 0;
}
