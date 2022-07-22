#include<bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int> &A) {
    int element = 0;

    int n = A.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0)
            element = A[i];

        if (A[i] == element)
            count++;

        else    count--;
    }

    return element;
}
// Very good question