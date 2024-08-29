class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL){ // Checks For Null
        fast = fast->next->next; // Increment by 2
        slow = slow->next;// Increment by 1
        if(slow == fast){ // we found the cycle and we say that it will inside the cycle
            int count = 1; // now start counting by 1
            slow = slow->next; // we have to increase slow because slow is already pointed fast
            while(slow != fast){//it will rotate and count till slow cant't reach fast
                count++;
                slow = slow->next;
            }
            return count;
        }
    }
   
   return 0;
    }
};