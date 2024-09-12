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

//** Algorithm used to solve this problem --- 
// Step 1: Calculate the total length of the list
// Step 2: Determine the size of each part
//Step 3: Move to the end of the current part
// Step 4: Break the link for the current part
class Solution {
public:
    // acoording to problem statement ):
    // Jo Do nodes hai (possible dale ne hai ) wo put kar do
    // Baki 1 Remaining bhi put kar na hai
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
          
        // step-1 length of linked list
        ListNode* temp = head;
        int totalLengthList  = 0;
        while(temp != nullptr){
            temp = temp->next;
            totalLengthList ++;
        }
        
        // step-2
        int partSize = totalLengthList / k;
        int extraNodes = totalLengthList % k;
        // step-3

        vector<ListNode*> result(k, nullptr);
        ListNode * curr = head;
        for(int i = 0; i<k && curr != nullptr; i++){

            // bluid connect with newNode ):
            result[i] = curr;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            // reduce the extra nodes by 1 
            extraNodes --;

            for(int j = 1; j<currentPartSize; j++){
                // move to end of current part linked list node
                curr = curr->next;
            }

            // store nextpart(remaining list)
            ListNode * nextPart = curr->next;
            curr->next = nullptr;
            // maintain the next part of linked List
            curr = nextPart ;
        }
        return result;
    }
};

