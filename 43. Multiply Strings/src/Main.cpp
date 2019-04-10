#include<iostream>
using std::string;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() < num2.size())
            return multiply(num2, num1);
        string res;
        int tmp[num1.size() + num2.size()] = {0};
        int p,n;
        for(int i = num2.size() - 1; i >=0; i--){
            n = 0;
            for(int j = num1.size() - 1; j >= 0; j--){
                p = (num2[i] - '0') * (num1[j] - '0') + n + tmp[i + j + 1];
                n = p / 10;
                tmp[i + j + 1] = p %10;
            }
            if(n != 0){
                tmp[i] +=n;
            }
        }

        for(auto i : tmp){
            res.push_back(i + '0');
        }
        while(res.size() > 1 && res[0] == '0')
            res = res.substr(1);
        return res;
    }
};

int main(){
    string num1 = "9113";
    string num2 = "0";

    Solution solution;

    std::cout<< solution.multiply(num1, num2) << std::endl;

    return 0;
}