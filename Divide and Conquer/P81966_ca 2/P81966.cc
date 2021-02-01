#include <iostream>
#include <vector>
using namespace std;

//int posicio(double x, const vector<double>& v, int esq, int dre);

int posicio(double x, const vector<double> &v, int esq, int dre)
{
    if(esq > dre) return -1;
    int pos = (esq+dre)/2;
    if(x < v[pos]) return posicio(x,v,esq,pos-1);
    if(x> v[pos]) return posicio(x,v, pos+1,dre);

    return pos;
}

int main()
{
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int x;
    bool fuera = true;
    while(fuera){
        cin>> x ;
        if (x == -1) fuera = false;
        cout <<posicio(x, v, 0, n-1) << endl;
    }
}