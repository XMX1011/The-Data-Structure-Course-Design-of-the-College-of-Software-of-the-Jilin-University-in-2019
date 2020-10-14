#include "stdc++.h"
using namespace std;
vector<int> getNext(string T)
{
    vector<int> next(T.size(), 0);
    next[0] = -1;
    int k = 0;
    for (int j = 2; j < T.size(); ++j)
    {
        while (k > 0 && T[j - 1] != T[k])
            k = next[k];
        if (T[j - 1] == T[k])
            k++;
        next[j] = k;
    }
    return next;
}
void KMP(string S, string T)
{
    vector<int> next = getNext(T);
    int i = 0, j = 0, s = 0;
    while (S[i] != '\0')
    {
        j = 0;
        if (i + s < S.length())
            i += s;
        while (S[i] != '\0' && T[j] != '\0')
        {
            if (S[i] == T[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
            if (j == -1)
            {
                ++i;
                ++j;
            }
        }
        if (T[j] == '\0')
            cout << i - j << ' ';
        s = i - j;
    }
}
int main()
{
    string S, T;
    cin >> S >> T;
    KMP(S, T);
    system("pause");
    return 0;
}