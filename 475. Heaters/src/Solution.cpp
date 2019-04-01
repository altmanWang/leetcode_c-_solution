#include<iostream>
#include<vector>
#include <algorithm>   
#include <cmath> 
using std::abs;
using std::sort;
using std::vector;

/*
1.遍历每个房子时，找到与其距离最近的heater，距离记作d
2.将局部的距离d与全局的最小半径距离max_radius进行比较，选择较大的一个，因为只有较大的才可以满足约束条件，即所有的房子都要在heater的范围内。
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int max_radius = 0, cur = 0;
        for(int i = 0; i < houses.size(); i++){
            while(cur + 1 < heaters.size() && abs(heaters[cur] - houses[i]) >= abs(heaters[cur + 1] - houses[i]))
                cur +=1;
            max_radius = max_radius > abs(heaters[cur] - houses[i]) ? max_radius : abs(heaters[cur] - houses[i]);
        }
        return max_radius;
    }
};

int main(){
    vector<int> houses = {1,2,3,4};
    vector<int> positions = {1,4};
    Solution solution;
    int res = solution.findRadius(houses, positions);
    std::cout << res << std::endl;
    return 0;
}
