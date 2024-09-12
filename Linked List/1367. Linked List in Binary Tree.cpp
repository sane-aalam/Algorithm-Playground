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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool helper(ListNode* head, TreeNode* root){
        // linked list Node is present into binary Tree
        // linked List Node is not present into binary Tree

        // List List head reached into nullptr (last node of linked)
        // Which means you have found all node into Binary Tree return TRUE;
        if(head == nullptr) return true;
        if(root == nullptr) return false;
        if(head->val != root->val) return false;

        // recursive leaf of faith 
        bool left = helper(head->next,root->left);
        bool right = helper(head->next,root->right);
        bool result = left or right;
        return result; 
        // can be true / false
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
         if(root == nullptr) return false;
         // call for solve(root)
         // call for solve(root->left)
         // call for solve(root->right)
         // DFS calls simple 
         // anyone return true 
         // which means you got the linked list into binary Tree
         return helper(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};







