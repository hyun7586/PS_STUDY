#include <bits/stdc++.h>
using namespace std;

int lcs[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    // create lcs matrix
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            // s1[i] == s2[j] : LCS[i][j]=LCS[i-1][j-1]+1
            if (s1[i - 1] == s2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }

            // s1[i] != s2[j] : LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1])
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    // find the max from the matrix
    int result = lcs[1][1];

    for (int i = 1; i <= s1.length(); i++)
        for (int j = 1; j <= s2.length(); j++)
            result = max(result, lcs[i][j]);

    cout << result;

    return 0;
}