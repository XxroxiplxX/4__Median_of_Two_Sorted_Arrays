#include <iostream>
#include "vector"
using namespace std;

int binary_search(vector<int> nums, int p, int q, int target) {
    if (q == p) {
        return q;
    }
    if (q - p == 1) {
        return q;
    }
    int mid = (q + p)/2;
    if (nums[mid] < target) {
        return binary_search(nums, mid, q, target);
    } else if (nums[mid] > target) {
        return binary_search(nums, p, mid, target);
    } else return mid;
}
int searchInsert(vector<int>& nums, int target) {
    int end = nums.size() - 1;
    return binary_search(nums, 0, end, target);
}

int main() {
    vector<int> vec = {1,3,6,9,12,15,56};
    std::cout << binary_search(vec,0, 6,13) << std::endl;
    return 0;
}
