#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

/**
 * * Started at : 6:27 pm
 * * Debug - 6:40pm - 6:54pm
 * * Status - AC
*/

void adding_reverse(string &a, string &b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }

    string res;
    int sum = 0, carry = 0, len = b.size();

    for (int i = 0; i < len; i++) {

        sum = (int)a[i] - '0' + (int)b[i] - '0' + carry;
        carry = sum / 10;
        sum = sum % 10;

        char c = sum + '0';
        res.push_back(c);
    }

    int start = len;
    while (start < a.size()) {
        sum = a[start] + carry - '0';
        carry = sum / 10;
        sum = sum % 10;

        char c = sum + '0';
        res.push_back(c);
        start++;
    }
    if (carry == 1) {
        res.push_back(1 + '0');
    }
    int pos = res.find_first_not_of('0');
    res = res.substr(pos, res.size() - pos + 1);
    cout << res << endl;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string a, b;
        cin >> a >> b;
        adding_reverse(a, b);
    }
}