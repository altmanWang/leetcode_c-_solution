#include<iostream>
#include<vector>
using std::vector;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int nums[A.size()];
        int l = 0;
        int r = A.size() - 1;
        for(int i = 0; i != A.size(); i++){
            if(A[i] % 2 == 0){
                nums[l++] = A[i];
            }else{
                nums[r--] = A[i];
            }
        }

        vector<int> res(nums, nums + A.size());
        return res;
    }
};
int main(){
    vector<int> nums = {3,1,2,4};
    Solution solution;
    vector<int> res = solution.sortArrayByParity(nums);
    for(auto i : res){
        std::cout << i << std::endl;
    }
    return 0;
}