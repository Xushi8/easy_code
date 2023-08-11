// 2023/08/11 10:28:11
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int nex[N];

void get_next(const string& s)
{
    nex[0] = -1;
    for (int i = 0, j = -1; i < (int)s.size(); )
    {
        if (j == -1 || s[i] == s[j])
        {
            i++; j++;
            nex[i] = j;
        }
        else
        {
            j = nex[j];
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    int Case = 1;
    while (cin >> n && n != 0)
    {
        cin >> s;
        get_next(s);

        cout << "Test case #" << Case++ << '\n';
        // vector<int> arr;
        // int t = (int)s.size() - 1;
        // while (t != -1)
        // {
        //     if (s[t] == s.back())
        //         arr.emplace_back(t + 1);
        //     t = nex[t];
        // }

        // vector<int> tmp(arr.rbegin(), arr.rend());
        // for (int x : tmp)
        // {
        //     if (x == 1)
        //         continue;
            
        //     cout << x << ' ' << s.size() / x << '\n';
        // }

        for (int i = 2; i <= n; i++)
        {
            int tmp = i - nex[i];
            if (i % tmp == 0 && nex[i] != 0)
            {
                cout << i << ' ' << i / tmp << '\n';
            }
        }
        cout << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}