#include <iostream>
#include <vector>
#include <array>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector A(N, array<int, 5> {});

    for (auto& a : A) for (int& i : a) cin >> i;

    int lo = 0, hi = 1000000001;


    auto check = [&](int x) -> bool {

        set<int> s;
        for (auto& a : A)
        {
            int bit = 0;
            for (int& i : a)
            {
                bit <<= 1;
                bit |= i >= x;
            }
            s.insert(bit);
        }

        for (int x : s)
            for (int y : s)
                for (int z : s)
                {
                    if ((x | y | z) == 31) return 1;
                }
        return 0;
    };


    while (hi >= lo)
    {
        int mid = lo + (hi - lo) / 2;

        if (check(mid))
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << lo - 1 << endl;
}


/**
If we try to search all combinations of teammates, the number of choices can be at most
4.5×10^9, so you will get TLE.

Problems of the form of “maximum value of minimum value” can sometimes be solved easily by boiling it down to a yes-no problem of “can the answer be more than 'x'?” and do binary search for the answer.
Now we will consider the yes-no problem.

We are only interested in whether or not each parameter is more than 'x', so we can compress each parameter to
    1
    or
    0
depending on whether it exceeds 'x'or not. Then, there are at most 2^5 = 32
kinds of tuples of parameters, so one can check exhaustively for all possible choices of three members out of the deduplicated members.

Complexity is - O((N*M + 2^(M*K))log(X))
N - Number of participants
M - Number of parameters for each participant.
K - No. of teams to select.
X - Upper limit of the binary search.
*/