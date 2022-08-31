#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string S, T; cin >> S >> T;
    vector<int> A(26, 0), B(26, 0);
    int N = S.size(), M = T.size();
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (S[i] == T[j]) ++j;
        ++i;
    }
    if (j == M) { cout << "automaton\n"; return 0; }
    for (char s : S) A[s - 'a']++;
    for (char t : T) B[t - 'a']++;
    for (int i = 0; i < 26; ++i) {
        if (B[i] > A[i]) { cout << "need tree\n"; return 0; }
    }
    if (N == M) cout << "array\n";
    else cout << "both\n";
}

/**
 *  One More better Solution.
    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        string a,b;
        cin >> a >> b;
        map<char,int> m1,m2;
            for(char i: a)m1[i]++;
        for(char i: b)m2[i]++;
        for(auto i: m2)if(m1[i.first] < i.second)return printf("need tree"),0;
        for(int i = 0, j = 0; i < a.size(); ++i){
            j += a[i] == b[j];
            if(j == b.size())return printf("automaton"),0;
        }
        a.size() == b.size() ? printf("array") : printf("both");
        return 0;
    }
**/