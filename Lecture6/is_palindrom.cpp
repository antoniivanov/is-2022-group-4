// Solve https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) { 
        auto copy = copy_list(head); // or copy_list_recursive
        copy = reverse(copy);
        auto is_palindrom = compare(copy, head);
        delete_list(copy);
        return is_palindrom;

        /**
        alternative solution:
        It requires less memory (no need to copy the list) 
        but modifies inplace the linked list so it may not be suitable for multi-threaded code.
        

        mid = find_middle(head);
        reversed_second_part = reverse(mid);
        compare(head, mid, reversed_second_part);
        reverse(reversed_second_part);
        ]*/

         /**
        alternative solution:
        String s1 = to_string(head);
        String s2 = to_string_reversed(head);
        return s1 == s2 
        ]*/
    }

private :

    ListNode* copy_list_recursive(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* new_node = new ListNode(head->val);
        new_node->next = copy_list_recursive(head->next);
        return new_node;
    }

    ListNode* copy_list(ListNode* head) {
        ListNode start(0);
        ListNode* prev = &start;
        while(head != nullptr) {
            auto new_node = new ListNode(head->val);
            prev->next = new_node;
            prev = new_node;
            head = head->next;
        }
        return start.next;
    }

    void delete_list(ListNode* head) {
        while(head != nullptr) {
            auto prev = head;
            head = head->next;
            delete prev;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while(head != nullptr) {
            auto next = head->next;
            head->next = prev; 
            prev = head; 
            head = next;
        }
        return prev;
    }


    bool compare(ListNode* lhs, ListNode* rhs) {
        while (lhs != nullptr && rhs != nullptr && lhs->val == rhs->val) {
            lhs = lhs->next;
            rhs = rhs->next;
        }
        return lhs == nullptr && rhs == nullptr;
    }
  
};

 
