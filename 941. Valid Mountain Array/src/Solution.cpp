#include<vector>
using std::vector;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int length = A.size();
        if(length < 3)
            return false;
        bool flag = false;
        if(A[0] > A[1] || A[length - 2] < A[length - 1])
            return false;
        for(int i = 0; i < length - 1; i++){
            if(A[i] == A[i + 1])
                return false;
            if(!flag){
                if(A[i] > A[i + 1])
                    flag = true;
            }else{
                if(A[i] < A[i + 1])
                    return false;
            }
        }
        return true;
    }
};