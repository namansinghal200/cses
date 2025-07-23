#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    cin >> n;

    vector<int> count(1000001);
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        count[x]++;
        maxi = max(maxi, x);
    }

    vector<int> multiples(maxi + 1);
    for (int i = 1; i <= maxi; i++)
    {
        for (int j = i; j <= maxi; j += i)
        {
            if (count[j])
            {
                multiples[i] += count[j];
            }
        }
    }

    for (int i = maxi; i >= 0; i--)
    {
        if (multiples[i] >= 2)
        {
            cout << i << endl;
            return;
        }
    }
}
#undef int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}