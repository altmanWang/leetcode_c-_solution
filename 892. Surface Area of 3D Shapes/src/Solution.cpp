#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        int size = grid.size();
        for(int i = 0; i != size; i++){
            for(int j = 0; j != size; j++){
                res += area(grid[i][j]);
                if(i > 0){
                    res -= (grid[i - 1][j] < grid[i][j] ? grid[i - 1][j]: grid[i][j]) * 2;
                }
                if(j > 0){
                    res -= (grid[i][j - 1] < grid[i][j] ? grid[i][j - 1]: grid[i][j]) * 2;
                }
            }
        }
        return res;
    }
    int area(int num){
        if(num == 0)
            return 0;
        else if(num == 1)
            return 6;
        else if(num == 2)
            return 10;
        return 10 + (num - 2) * 4;
    }
};

int main(){
    vector<vector<int>> grid;
    vector<int> line1{2};
    grid.push_back(line1);
    Solution solution;
    std::cout << solution.surfaceArea(grid) <<std::endl;
    return 0;
}