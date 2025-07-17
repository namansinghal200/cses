#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    map<char, int> m;
    for (auto i : s)
        m[i]++;
    string ans = "";
    string mid = "";
    int flag = 0;
    for (auto i : m)
    {
        if (i.second % 2)
        {
            if (s.size() % 2 == 0 || flag)
            {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            else
            {
                mid = i.first;
                flag = 1;
            }
        }
        for (int j = 0; j < i.second / 2; j++)
        {
            ans += i.first;
        }
    }
    string st2 = ans;
    reverse(st2.begin(), st2.end());
    cout << ans + mid + st2 << endl;
}