#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    cin >> n;
    if (n == 3 || n == 2)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
    cout << endl;
}

#undef int
int main()
{
    solve();
}