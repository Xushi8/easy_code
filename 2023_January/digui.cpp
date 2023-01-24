#include<iostream>
#include<algorithm>
using namespace std;

// int n;
// int func(int arr[][100], int i, int j);

// int main()
// {
//     cin >> n;
//     int arr[100][100];
//     int i, j;
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j <= i; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     int ans = func(arr, 0, 0);
//     cout << ans << endl;

//     return 0;
// }

// int func(int arr[][100], int i, int j)
// {
//     if (i == n - 1) return arr[i][j];

//     return max(func(arr, i + 1, j), func(arr, i + 1, j + 1)) + arr[i][j];
// }

//改进版
// int n;
// int func(int arr[][100], int i, int j);
// int rec[100][100];

// int main()
// {
//     cin >> n;
//     int arr[100][100];
//     int i, j;
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j <= i; j++)
//         {
//             cin >> arr[i][j];
//             rec[i][j] = -1;
//         }
//     }

//     int ans = func(arr, 0, 0);
//     cout << ans << endl;

//     return 0;
// }

// int func(int arr[][100], int i, int j)
// {
//     if (i == n - 1) return arr[i][j];

//     if (rec[i][j] != -1)
//     {
//         return rec[i][j];
//     }
//     else
//     {
//         rec[i][j] = max(func(arr, i + 1, j), func(arr, i + 1, j + 1)) + arr[i][j];
//         return rec[i][j];
//     }
// }


// int price[100];
// int love[100];
// int rec[100][100];
// int func(int n, int money)
// {
//     if (n == -1)
//     {
//         return 0;
//     }

//     if (rec[n][money] > 0)
//     {
//         return rec[n][money];
//     }

//     if (price[n] > money)
//     {
//         rec[n][money] = func(n - 1, money);
//         return rec[n][money];
//     }
//     else
//     {
//         rec[n][money] = max(func(n - 1, money), func(n - 1, money - price[n]) + love[n]);
//         return rec[n][money];
//     }
// }
// int main()
// {
//     int i, n;
//     int money;
//     cin >> n;
//     cin >> money;
//     for (i = 0; i < n; i++)
//     {
//         cin >> price[i] >> love[i];
//     }

//     cout << func(n-1, money);

//     return 0;
// }