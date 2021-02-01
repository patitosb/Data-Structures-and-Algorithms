#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double> &v, int esq, int dre)
{
    if (esq > dre)
        return -1;
    else
    {
        int pos = (esq + dre) / 2;
        if (x == v[pos] && x != v[pos-1])
            return pos;
        else if (x <= v[pos])
            return posicio(x, v, esq, pos - 1);
        else if (x > v[pos])
            return posicio(x, v, pos + 1, dre);
    }
}

int first_occurrence(double x, const vector<double> &v)
{
    int res = posicio(x, v, 0, v.size() - 1);
    return res;
}

int main()
{
    int n;
    cout << " Entra el tamaó del vector: " << endl;
    cin >> n;
    vector<double> v(n);
    cout << " Inicializacion vector:" << endl;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    double x;
    cout << "Entra elemento a buscar " << endl;
    cin >> x;
    cout << " " << first_occurrence(x, v) << endl;
}