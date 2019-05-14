#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = 1;
        int i = 0;
        while(i!=A.size()){
            if(A[i] % 2 == 0){
                res[l] = A[i];
                l +=2;
            }else{
                res[r] = A[i];
                r +=2;
            }
            i++;
        }
        return res;
    }
};

int main(){
    vector<int> nums{4,2,5,7};
    Solution solution;
    vector<int> res = solution.sortArrayByParityII(nums);
    for(auto i : res){
        std::cout << i << std::endl;
    }
    return 0;
}