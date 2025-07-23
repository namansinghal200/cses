#include <bits/stdc++.h>
using namespace std;
#define int long long int

int mod_exp(int base, int exp, int mod)
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
        int a, b, c;
        cin >> a >> b >> c;
        int num1 = mod_exp(b, c, 1e9 + 6);
        cout << mod_exp(a, num1, 1e9 + 7) << endl;
    }
}
#undef int
int main()
{
    solve();
}