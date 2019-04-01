#include<iostream>
#include<vector>
#include <map>  
#include<algorithm>
#include<string>
using std::sort;
using std::vector;
using std::map;
using std::pair;
using std::string;
class Solution {
    static bool cmp(pair<int, int> &p1, pair<int, int>& p2){
        return p1.second > p2.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> freqs;
        for(auto i : nums){
            freqs[i] +=1;
        }
        vector<pair<int, int>> sortedVector(freqs.begin(), freqs.end());
        sort(sortedVector.begin(), sortedVector.end(), cmp);
        for(int i = 0; i < k; i++){
            res.push_back(sortedVector[i].first);
        }
        return res;
    }
};
int main(){

    vector<int> elements;
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(3);
    Solution solution;
    vector<int> res = solution.topKFrequent(elements, 2);
    for(auto iter : res){
        std::cout << iter << std::endl;
    }  
    return 0;
}