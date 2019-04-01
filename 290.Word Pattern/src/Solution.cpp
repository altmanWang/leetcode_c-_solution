#include<iostream>
#include<map>
#include<vector>
using std::vector;
using std::string;
class Solution {
public:
    vector<string> split(const string & str, string pattern){
        vector<string> res;
        int idx = 0;
        for(int i = 0; i < str.size(); i++){
            idx = str.find(pattern, i);
            if(idx  > 0){
                res.push_back(str.substr(i, idx - i));
                i = idx + pattern.size() - 1;
            }else{
                res.push_back(str.substr(i, str.size() - 1));
                break;
            }
        }
        return res;
    }
    bool wordPattern(string pattern, string str) {
        std::map<char, string> pattern2str;
        std::map<string, char> str2pattern;
        vector<string> splited_str = split(str, " ");
        if(pattern.size() != splited_str.size())
            return false;
        char c;
        for(int i = 0; i < pattern.size(); i++){
            c = pattern[i];
            if(pattern2str.find(pattern[i]) == pattern2str.end() && str2pattern.find(splited_str[i]) == str2pattern.end()){
                pattern2str[pattern[i]] = splited_str[i];
                str2pattern[splited_str[i]] = pattern[i];
            }else{
                if(pattern2str[pattern[i]] != splited_str[i])
                    return false;
            }
        }
        return true;
    }
};

int main(){
    string pattern = "abba";
    string str = "dog dog cat dog";
    Solution solution;
    std::cout << solution.wordPattern(pattern, str) <<std::endl;
}