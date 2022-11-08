// solve https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};
 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      
        ListNode start(0); // dummy start, the actual head of the list is start.next :)
        // It's called officially a sentinel node - https://en.wikipedia.org/wiki/Sentinel_node
        ListNode* tail = &start;

        while (list1 != nullptr || list2 != nullptr) {
            if (list1 != nullptr  // are we finished with list1
               && // and are we finished with list 2 or is list1 elemnt smaller
                (list2 == nullptr || list1->val < list2->val)) {
                tail->next = list1; 
                list1 = list1->next; 
            } else { // either list1 is finished or list2 element is smaller.
                tail->next = list2; 
                list2 = list2->next; 
            }
            tail = tail->next;
        }
        return start.next;
    }
};

 