#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    cin >> n;
    int num = (n * (n + 1)) / 2;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        num -= x;
    }
    cout << num << endl;
}

#undef int
int main()
{
    solve();
}