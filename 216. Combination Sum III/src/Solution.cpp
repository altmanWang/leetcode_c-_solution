#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        if(n <=0)
            return res;
        for(int i = 1; i <= 9; i++){
            path.push_back(i);
            combinationSum(k - 1, n - i, i + 1, &path, &res);
            path.pop_back();
        }
        return res;
    }
    void combinationSum(int k, int target, int start, vector<int> * path, vector<vector<int>> * res){
        if(target < 0)
            return;
        if(k == 0){
            if(target == 0){
                vector<int> tmp;
                tmp.insert(tmp.begin(), (*path).begin(), (*path).end());
                (*res).push_back(tmp);
            }
            return;
        }
        for(int i = start; i <= 9; i++){
            (*path).push_back(i);
            combinationSum(k - 1, target - i, i + 1, path, res);
            (*path).pop_back();
        }
        return;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> res = sol.combinationSum3(3, 15);
    for(auto path : res){
        for(auto i : path){
            cout << i << " ";
        }
        cout << "" << endl;
    }
}