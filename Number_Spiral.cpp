#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int maxi = max(x, y);
        if (maxi % 2)
        {
            if (x > y)
            {
                cout << (maxi - 1) * (maxi - 1) + y << endl;
            }
            else
            {
                cout << maxi * maxi - (x - 1) << endl;
            }
        }
        else
        {
            if (x < y)
            {
                cout << (maxi - 1) * (maxi - 1) + x << endl;
            }
            else
            {
                cout << maxi * maxi - (y - 1) << endl;
            }
        }
    }
}

#undef int
int main()
{
    solve();
}