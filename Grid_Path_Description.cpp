#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 7;
int ans = 0;
string s;
bool visited[8][8];

void dfs(int x, int y, int ind)
{
    if (x == 7 && y == 1)
    {
        if (ind == 48)
            ans++;
        return;
    }
    if (ind >= 48)
        return;

    visited[x][y] = true;

    int dx[] = {1, 0, -1, 0}; // D, R, U, L
    int dy[] = {0, 1, 0, -1};
    char dir[] = {'D', 'R', 'U', 'L'};

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny])
        {
            if (s[ind] == '?' || s[ind] == dir[d])
            {
                dfs(nx, ny, ind + 1);
            }
        }
    }

    visited[x][y] = false;
}

#undef int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    dfs(1, 1, 0);
    cout << ans << "\n";
}
