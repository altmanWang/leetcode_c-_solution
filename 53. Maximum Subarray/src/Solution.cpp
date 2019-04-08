#include<vector>
#include<iostream>
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local = 0;
        int res = INT32_MIN;
        for(auto val : nums){
            local = local + val > val ? local + val : val;
            res = res > local ? res : local;
        }
        return res;
    }
};
int main(){
    vector<int> nums = {-1};
    Solution solution;
    int res = solution.maxSubArray(nums);
    std::cout << res << std::endl;
    return 0;
}