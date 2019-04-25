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
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> path;
        bool used[nums.size()] = {false};
        permuteUnique(nums,  nums.size(), res, path, used);
        return res;

    }
    void permuteUnique(vector<int> & nums, int size, vector<vector<int>> & res, vector<int> & path, bool * used){
        if(path.size() == size){
            res.push_back(path);
            return;
        }
        for(int i = 0; i != size; i++){
            if(used[i] == true)
                continue;
            if(i > 0 && !used[i-1] && nums[i-1] == nums[i])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            permuteUnique(nums,size, res, path, used);
            path.pop_back();

            used[i] = false;
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