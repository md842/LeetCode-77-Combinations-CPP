/*
 * Leetcode 77: Combinations https://leetcode.com/problems/combinations/.

 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 
 * You may return the answer in any order.
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> outVec;

  if (k == 1){ // k = 1; just return all [1, n] individually wrapped.
    for (int i = 0; i < n; i++){
      std::vector<int> sub_vec;
      sub_vec.push_back(i + 1);
      outVec.push_back(sub_vec);
    }
    return outVec;
  }

  // Initial list
  std::vector<int> initVec;
  for (int i = 0; i < k; i++){
    initVec.push_back(i + 1);
  }
  outVec.push_back(initVec); // Add a copy of it to outVec

  // Expand the initial vector
  int pos = k - 1; // pos is the position in the sublist we're working on expanding

  while(pos > 0){
    while (initVec.at(k - 1) < n){ // Last item in the list isn't at n yet
      initVec.at(k - 1)++; // Increment it
      outVec.push_back(initVec);
    }
    pos -= 1; // Backtrack to the previous item in the list
    if (initVec.at(pos) < (n - k + pos + 1)){ // Check if it's at its maximum
      // (The maximum is based on its position in the list)
      initVec.at(pos)++; // If not, increment it
      for (int i = pos + 1; i < k; i++){ // Reset rest of list accordingly
	      initVec.at(i) = initVec.at(pos) + i - pos;
      }
      outVec.push_back(initVec);
      pos = k - 1; // Reset position back to last item
    }
  }
  return outVec;
}

void test(int n, int k){
  std::vector<std::vector<int>> received_output = combine(n, k);

  for (int row = 0; row < received_output.size(); row++){
    std::cout << "[ ";
    for (int col = 0; col < k; col++){
      std::cout << received_output.at(row).at(col) << " ";
    }
    std::cout << "]";
  }
  std::cout << std::endl;
}

int main(){
  // Test cases
  test(4, 2);
  test(4, 3);
  return 0;
}
