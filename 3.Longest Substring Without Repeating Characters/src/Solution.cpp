#include<iostream>
#include<string>

using std::string;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        int res = 0;
        int left = 0;
        int positions[256]= {};
        for(int i = 0; i < s.length(); i++){
            int index = int(s[i]);
            if(positions[index] == 0 || positions[index] < left){
                if(i - left + 1 > res){
                    res = i - left + 1;
                }
            }else{
                left = positions[index];
            }
            positions[index] = i + 1;
        }
        return res;
    }
};
int main(){
    string str = "abcabcbb";
    Solution solution;
    int res = solution.lengthOfLongestSubstring(str);
    std::cout << res << std::endl;
}