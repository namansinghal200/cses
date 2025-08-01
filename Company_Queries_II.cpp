#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> ansc;
vector<int> depth;
void preprocess(int node, int par, vector<vector<int>> &adj)
{
    ansc[node][0] = par;
    for (int i = 1; i <= 20; i++)
    {
        if (ansc[node][i - 1] != -1)
        {
            ansc[node][i] = ansc[ansc[node][i - 1]][i - 1];
        }
    }
    for (auto i : adj[node])
    {
        depth[i] = depth[node] + 1;
        preprocess(i, node, adj);
    }
}
int get(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = 20; i >= 0; i--)
    {
        if (depth[a] - (1 << i) >= depth[b])
        {
            a = ansc[a][i];
        }
    }
    if (a == b)
        return a;
    for (int i = 20; i >= 0; i--)
    {
        if (ansc[a][i] != ansc[b][i])
        {
            a = ansc[a][i];
            b = ansc[b][i];
        }
    }
    return ansc[a][0];
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    ansc.resize(n + 1, vector<int>(21, -1));
    depth.resize(n + 1);
    depth[1] = 0;

    preprocess(1, -1, adj);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << get(a, b) << endl;
    }
}

#undef int
int main()
{
    solve();
}