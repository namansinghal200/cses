#include <bits/stdc++.h>
using namespace std;
#define int long long int

// int RabinKarp(string text, string pat)
// {
//     int d1 = 31, mod1 = 1000000007;
//     int d2 = 37, mod2 = 1000000009;
//     int n = text.size(), m = pat.size();
//     if (n < m)
//         return 0;
//     int ppow1 = 1, ppow2 = 1;
//     for (int i = 1; i < m; i++)
//     {
//         ppow1 = (ppow1 * d1) % mod1;
//         ppow2 = (ppow2 * d2) % mod2;
//     }

//     int p1 = 0, t1 = 0, p2 = 0, t2 = 0;
//     for (int i = 0; i < m; i++)
//     {
//         p1 = (d1 * p1 + (pat[i] - 'a' + 1)) % mod1;
//         t1 = (t1 * d1 + (text[i] - 'a' + 1)) % mod1;
//         p2 = (d2 * p2 + (pat[i] - 'a' + 1)) % mod2;
//         t2 = (t2 * d2 + (text[i] - 'a' + 1)) % mod2;
//     }
//     int count = 0;

//     for (int i = 0; i <= n - m; i++)
//     {
//         if (p1 == t1 && p2 == t2)
//         {
//             bool flag = 1;
//             for (int j = 0; j < m; j++)
//             {
//                 if (text[i + j] != pat[j])
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag)
//                 count++;
//         }
//         if (i < n - m)
//         {
//             t1 = (d1 * (t1 - ((text[i] - 'a' + 1) * ppow1) % mod1 + mod1) + (text[i + m] - 'a' + 1)) % mod1;
//             t2 = (d2 * (t2 - ((text[i] - 'a' + 1) * ppow2) % mod2 + mod2) + (text[i + m] - 'a' + 1)) % mod2;
//         }
//         if (t1 < 0)
//             t1 = t1 + mod1;
//         if (t2 < 0)
//             t2 = t2 + mod2;
//     }
//     return count;
// }

void constructLps(string &pat, vector<int> &lps)
{

    // len stores the length of longest prefix which
    // is also a suffix for the previous index
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.length())
    {

        // If characters match, increment the size of lps
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else
        {
            if (len != 0)
            {

                // Update len to the previous lps value
                // to avoid reduntant comparisons
                len = lps[len - 1];
            }
            else
            {

                // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(string &pat, string &txt)
{
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    int res = 0;

    constructLps(pat, lps);

    // Pointers i and j, for traversing
    // the text and pattern
    int i = 0;
    int j = 0;

    while (i < n)
    {

        // If characters match, move both pointers forward
        if (txt[i] == pat[j])
        {
            i++;
            j++;

            // If the entire pattern is matched
            // store the start index in result
            if (j == m)
            {
                res++;

                // Use LPS of previous index to
                // skip unnecessary comparisons
                j = lps[j - 1];
            }
        }

        // If there is a mismatch
        else
        {

            // Use lps value of previous index
            // to avoid redundant comparisons
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << KMP(s2, s1) << endl;
}
#undef int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}