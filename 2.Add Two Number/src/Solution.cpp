#include<iostream>

using std::cout;
using std::endl;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head;
        ListNode *index = new ListNode(0);

        head = index;

        int tmp = 0;
        while(NULL != l1 || NULL != l2){
            tmp /= 10;
            if(NULL != l1 && NULL != l2){
                tmp += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }else if(NULL == l1){
                tmp += l2->val;
                l2 = l2->next;
            }else{
                tmp += l1->val;
                l1 = l1->next;
            }
            index->next = new ListNode(tmp % 10);
            index = index->next;
        }
        if(tmp >= 10){
           index->next = new ListNode(tmp / 10); 
        }
        return head->next;
    }
};


int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution tool;
    ListNode *res = tool.addTwoNumbers(l1,l2);
    while(NULL != res){
        cout << res->val;
        res = res->next;
    }
}