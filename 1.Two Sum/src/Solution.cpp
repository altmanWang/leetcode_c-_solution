#include<map>
#include<vector>
#include<iostream>
using std::cout;
using std::endl;
using std::map;
using std::vector;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> maps;
        map<int, int>::iterator iter;
        for(int i = 0; i != nums.size(); i++){
            iter = maps.find(target - nums[i]);
            if(maps.find(target - nums[i]) == maps.end()){
                maps[nums[i]] = i;
            }else{
                res.push_back(maps[target - nums[i]]);
                res.push_back(i);
                break;
            }
        }
        return res;    
    }
};

int main(int argc, char const *argv[]){
    Solution tool;
    vector<int> nums = {3,2,4};
    vector<int> res = tool.twoSum(nums, 6);
    cout << res[0] << res[1] << endl;
    return 0;
}