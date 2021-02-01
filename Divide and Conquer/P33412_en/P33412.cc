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
        if (x == v[pos]|| (v[pos-1]== x && pos>= esq) || (v[pos+1]==x && pos+1 <=dre))
            return pos;
        else if (x <v[pos])
            return posicio(x, v, esq, pos - 1);
        else 
            return posicio(x, v, pos + 1, dre);
    }
}

bool resistant_search(double x, const vector<double> &v)
{
    int res = posicio(x, v, 0, v.size() - 1);
    if (res != -1)
        return true;
    else return false;
}

int main()
{
    int n;
    cin >> n;

    vector<double> v(n);

    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];

    int x;
    cin >> x;

    if (resistant_search(x, v))
    {

        cout << " esta " << endl;
    }
    else
        cout << "no esta" << endl;
}