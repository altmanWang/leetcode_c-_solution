#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using std::set;
using std::sort;
using std::vector;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permuteUnique(nums, 0, nums.size(), res);
        return res;

    }
    void permuteUnique(vector<int> & nums, int begin, int size, vector<vector<int>> & res){
        if(begin == size){
            res.push_back(nums);
            return;
        }
        int tmp;
        set<int> apperaed;
        for(int i = begin; i != size; i++){
            if(apperaed.find(nums[i]) == apperaed.end()){
                apperaed.insert(nums[i]);
                tmp = nums[begin];
                nums[begin] = nums[i];
                nums[i] = tmp;

                permuteUnique(nums, begin + 1, size, res);

                tmp = nums[begin];
                nums[begin] = nums[i];
                nums[i] = tmp;
            }
        }
    }
};


int main(){


    vector<int> nums = {2,2,1,1};
    Solution solutoin;
    vector<vector<int>> res = solutoin.permuteUnique(nums);
    
    for(auto path : res){
        for(auto i : path){
            std::cout << i << " ";
        }
        std::cout << "" <<std::endl;
    }
    return 0;
}