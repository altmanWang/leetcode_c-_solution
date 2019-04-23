#include<iostream>
#include<vector>
using std::vector;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k,nullptr);
        if(nullptr == root)
            return res;
        int length = getLengthOfList(root);
        int n = length / k;
        ListNode * index = root;
        ListNode * next;
        if(n == 0){
            for(int i = 0; i != length; i++){
                next = index->next;
                index->next = nullptr;
                res[i] = index;
                index = next;
            }
        }else{
            ListNode * head;
            int cnt = length % k;
            for(int i = 0; i != k; i++){
                head = index;
                int l = 1;
                while(l != n){
                    l +=1;
                    index = index->next;
                }
                if(cnt != 0){
                    cnt -=1;
                    index = index->next;
                }
                next = index->next;
                index->next = nullptr;
                res[i] = head;
                index = next;
            }
        }
        return res;
        
    }
    int getLengthOfList(ListNode * root){
        ListNode * index = root;
        int length = 0;
        while(nullptr != index){
            index = index->next;
            length +=1;
        }
        return length;
    }
};