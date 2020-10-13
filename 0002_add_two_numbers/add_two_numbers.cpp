#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* build_list(int* A, int len){
    ListNode *head = new ListNode(A[0]);
    ListNode *node = head;
    for (int i=0; i<len; i++){
        node->val = A[i];
        if (i<len-1){
            ListNode *next_node = new ListNode(0);
            node->next = next_node;
            node = next_node;
        }
    }
    return head;
}

void print_node(ListNode * head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *node = head;
        int residual = 0;
        while(l1 != nullptr || l2 != nullptr || residual>0){
            int l1_val = (l1) ? l1->val : 0;
            int l2_val = (l2) ? l2->val : 0;
            int residual = (l1_val + l2_val + node->val) / 10;
            node->val = (l1_val + l2_val + node->val) % 10;
          
            if (l1 != nullptr){
                l1 = l1->next;
            }
            if (l2 != nullptr){
                l2 = l2->next;
            }

            if (l1 != nullptr || l2 != nullptr || residual>0){
                ListNode *next_node = new ListNode(residual);
                node->next = next_node;
                node = node->next;
            }
        }
        return head;
    }
};

int main(){
    Solution sol;

    int A[3] = {2, 4, 3};
    int B[3] = {5, 6, 4};
    ListNode* l1 = build_list(A, 3);
    ListNode* l2 = build_list(B, 3);
    ListNode *res = sol.addTwoNumbers(l1, l2);
    print_node(res);

    return 0;
}