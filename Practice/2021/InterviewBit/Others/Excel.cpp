#include <bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

string convertToTitle(int A) {
    int base = 26 , temp = A;
    string str;
    map<int, char> alpha;
    char ch = 'A';

    alpha[0] = 'Z';
    for (int i = 1; i <= 25; i++) {
        alpha[i] = ch++;
    }
    cout << alpha << endl;

    string result = "";

    while (A > 0) {
        int index = (A - 1) % 26;
        result = char(index + 'A') + result;
        A = (A - 1) / 26;
    }
    A = temp;
    while (A) {
        int rem = A % base;
        cout << rem << endl;
        str.push_back(alpha[rem]);
        A /= base;
    }
    cout << str.size() << endl;
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    int N;
    cin >> N;
    string str = convertToTitle(N);
    cout << str << endl;
}