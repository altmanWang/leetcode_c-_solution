#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int left, right, tmp;
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i != nums.size(); i++){
            left = i + 1;
            right = nums.size() - 1;
            while(left < right){
                tmp = nums[i] + nums[left] + nums[right];
                if(tmp == target)
                    return target;
                if(abs(target - tmp) < abs(target - res)){
                    res = tmp;
                }
                if(tmp < target)
                    left +=1;
                else
                    right -=1;
            }
        }
        return res;
    }
};