#include<iostream>
#include<vector>

using std::max;
using std::vector;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int length = A.size();
        double sum[length + 1] = {0};
        for(int i = 0; i != length; i++){
            sum[i + 1] = sum[i] + A[i]; 
        }
        double dp[K][length] = {0};
        for(int i = 0; i != length; i++){
            dp[0][i] = (sum[length] - sum[i]) / (length - i);
        }
        for(int k = 1; k != K ; k++){
            for(int i = 0; i != length - 1; i++){
                for(int j = i; j != length; j++){
                    dp[k][i] = max(dp[k][i], dp[k - 1][j] + (sum[j] - sum[i]) / (j - i));
                } 
            }
        }
        return dp[K - 1][0];
    }
};

int main(){
    vector<int> nums{9,1,2,3,9};
    Solution solution;
    double res = solution.largestSumOfAverages(nums, 3);
    std::cout << res << std::endl;
    return 0;
}