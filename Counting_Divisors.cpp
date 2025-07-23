#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> factors(1000001);
void precompute()
{
    for (int i = 1; i < factors.size(); i++)
    {
        for (int j = i; j < factors.size(); j += i)
        {
            factors[j]++;
        }
    }
}
void solve()
{
    int n;
    cin >> n;

    precompute();
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cout << factors[x] << endl;
    }
}
#undef int
int main()
{
    solve();
}