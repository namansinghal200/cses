#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007;

int mod_exp(int base, int exp)
{
    int res = 1;

    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (res * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << mod_exp(a, b) << endl;
    }
}
#undef int
int main()
{
    solve();
}