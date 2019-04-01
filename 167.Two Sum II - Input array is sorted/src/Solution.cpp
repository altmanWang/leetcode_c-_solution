#include<vector>
using std::vector;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                res[0] = left + 1;
                res[1] = right + 1;
                break;
            }
            if(numbers[left] + numbers[right] < target)
                left +=1;
            else
                right -=1;
        }
        return res;
    }
};