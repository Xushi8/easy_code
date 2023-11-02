// 2023/11/01 15:24:31
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
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int fuhao[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    do
    {
        for (int i = 0; i < 9; i++)
        {
            cout << fuhao[i] << ' ';
        }
        cout << '\n';
        }while(next_permutation(fuhao, fuhao + 9));

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}