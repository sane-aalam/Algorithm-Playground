/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*
 The goal is to insert a new node with the greatest common divisor (GCD) between every 
 two consecutive nodes in a singly linked list. My initial thought was to traverse the linked list, 
 calculate the GCD of consecutive nodes, and insert a new node holding this value in between them. 
 
This operation can be performed while iterating through the linked list.
__gcd(val1,val2) = to calculate the gcd between to elements 

 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * temp = head;
        while(head->next != nullptr){
            // prev store for future
            ListNode * prev = head->next;
            // STL provide method (__gcd to calculate the common divisor between two element)
            ListNode * dummy = new ListNode(__gcd(head->val,head->next->val));
            head->next = dummy;
            dummy->next = prev;
            // update the head pointer using prev-head
            head = prev;
        }
        return temp;
    }
};












