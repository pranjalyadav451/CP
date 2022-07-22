
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


ListNode* reverse(ListNode** head, ListNode**tail, int cnt) {
    ListNode *prev = NULL, *future = NULL, *current = *head;
    while (current and cnt > 0) {
        future = current->next;
        current->next = prev;
        if (prev == NULL) *tail = current;
        prev = current;
        current = future;
        cnt--;
    }
    if (!current) { cout << "current: NULL" << endl;}
    *head = current;
    return prev;
}




class Solution {
public:
    ListNode*solve(ListNode* A, int B) {
        if (!A or !A->next) return A;

        ListNode *current = A, *prev = NULL, *future = NULL;

        ListNode *rev_tail = NULL , *rev_head = NULL, *last_order = NULL;

        bool to_rev = true;
        A = NULL;

        while (current) {
            if (to_rev) {
                rev_head = reverse(&current, &rev_tail, B);

                if (!A) A = rev_head;
                if (last_order) {
                    last_order->next = rev_head;
                }
            }
            else {
                rev_tail->next = current;
                for (int i = 0; i < B - 1 && current; i++) {
                    current = current->next;
                }
                last_order = current;
                current = current->next;
            }
            to_rev = !to_rev;
        }
        return A;
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
        int B; cin >> B;
        Solution ob;
        ListNode *newHead = ob.solve(head, B);

        bool over = false;
        cout << "NEdl:" << endl;
        while (newHead) {
            if (n < 0) {
                over = true;
                break;
            }
            cout << newHead->val << " ->";
            n--;
            newHead = newHead->next;
        }
        if (over) cout << "over" << endl;
        cout << endl;
    }
    return 0;
}