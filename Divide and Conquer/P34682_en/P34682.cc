#include <iostream>
#include <vector>
using namespace std;

int fixed_points(vector<int> &S, int a, int esq, int dre, int pos)
{

    if (esq <= dre)
    {

        int i = (esq + dre) / 2;

        if (S[i] + a == i + 1 || (i != 0 && S[i - 1] + a == i))
        {

            if (i + 1 < pos)
                pos = i + 1;

            return fixed_points(S, a, esq, i - 1, pos);
        }
        if (S[i] + a < i + 1)
        {

            return fixed_points(S, a, i + 1, dre, pos);
        }

        else if (S[i] + a > i + 1)
        {
            return fixed_points(S, a, esq, i - 1, pos);
        }
    }
    return pos;
}

int main()
{

    int n;
    int i = 1;
    while (cin >> n)
    {
        vector<int> S(n);
        int m, a, res;

        for (int i = 0; i < S.size(); ++i)
            cin >> S[i];

        cin >> m;
        cout << "Sequence #" << i << endl;
        for (int j = 0; j < m; ++j)
        {
            cin >> a;
            res = fixed_points(S, a, 0, S.size(), 10000000);

            if (res == 10000000 || res == -1)
                cout << "no fixed point for " << a << endl;
            else
                cout << "fixed point for " << a << ": " << res << endl;
        }

        ++i;
        cout << endl;
    }
}