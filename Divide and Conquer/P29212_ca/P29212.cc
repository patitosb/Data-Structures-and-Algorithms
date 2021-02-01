#include <iostream>
#include <cmath>
using namespace std;

unsigned long calcula_mod(unsigned long n, unsigned long k, int m)
{

    if (k == 0)
        return 1;

    else if (k % 2 == 0)
    {
        int mult = calcula_mod(n, k / 2, m) * calcula_mod(n, k / 2, m);
        return mult % m;
    }
    else
    {

        return ((n % m) * calcula_mod(n, k - 1, m)) % m;
    }
}
int main()
{

    int n, k, m;

    while (cin >> n >> k >> m)
    {
        cout << calcula_mod(n, k, m) << endl;
    }
}