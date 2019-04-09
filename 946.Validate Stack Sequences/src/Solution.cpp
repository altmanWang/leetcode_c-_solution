#include<vector>
#include<iostream>
#include<list>
using std::list;
using std::vector;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size())
            return false;
        if(pushed.size() == 0)
            return true;
        int stack[pushed.size()] = {0};
        int front_idx = pushed.size();
        int idx = 0;
        for(auto val : pushed){
            stack[--front_idx] = val;
            while(front_idx != pushed.size() && stack[front_idx] == popped[idx]){
                idx+=1;
                front_idx +=1;
            }
        }
        while(idx != popped.size()){
            if(popped[idx++] != stack[front_idx++])
                return false;
        }
        return true;    
    }
};
int main(){
    vector<int> pushed{1,2,3,4,5};
    vector<int> popped{4,3,5,1,2};
    Solution solution;

    std::cout << solution.validateStackSequences(pushed, popped) << std::endl;
    return 0;
}