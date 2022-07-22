
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

void traverseList(ListNode *head) {
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}






class Solution {
public:
    ListNode*solve(ListNode* A) {
        if (!A or !A->next) return A;
        ListNode *even_head = A->next , *odd_head = A;
        ListNode *even_list = A->next, *odd_list = A;

        ListNode* current = A->next->next;
        int current_pos = 1;
        while (current) {
            if (current_pos % 2 == 0) {
                even_head->next = current;
                even_head = even_head->next;
            }
            else {
                odd_head->next = current;
                odd_head = odd_head->next;
            }
            current = current->next;
            current_pos ++;
        }

        even_head->next = NULL;
        odd_head->next = NULL;
        even_head = even_list, odd_head = odd_list;
        ListNode *prev = NULL , *future = NULL;
        current = even_list;

        while (current) {
            future = current->next;
            current->next = prev;
            prev = current;
            current = future;
        }
        even_list = prev;


        // merge the two lists

        even_head = even_list, odd_head = odd_list;

        current_pos = 1;
        ListNode dum(0);
        prev = &dum;
        while (even_head and odd_head) {
            if (current_pos % 2 == 0) {
                prev->next = even_head;
                even_head = even_head->next;
            }
            else {
                prev->next = odd_head;
                odd_head = odd_head ->next;
            }
            current_pos++;
            prev = prev->next;
        }
        if (even_head) prev->next = even_head;
        if (odd_head) prev->next = odd_head;
        return dum.next;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, num;
        cin >> n;

        ListNode *head, *tail;
        cin >> num;
        head = tail = new ListNode(num);

        for (int i = 0; i < n - 1; i++) {
            cin >> num;
            tail->next = new ListNode(num);
            tail = tail->next;
        }
        Solution ob;
        ListNode *newHead = ob.solve(head);
        traverseList(newHead);
    }
    return 0;
}