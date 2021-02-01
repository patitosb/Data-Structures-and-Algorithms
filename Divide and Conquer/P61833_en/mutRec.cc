#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> filas;
typedef vector<filas> matrix;

void escribir_M(const matrix &M)
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (j != 0)
                cout << ' ';
            cout << M[i][j];
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

void mult_M(const matrix &aux1, const matrix &aux2, matrix &E, int m)
{
    E = matrix(2, vector<int>(2, 0));

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                // cout<< " E["<< i<< "]["<< j << "] =" <<  E[i][j] << endl;
                //cout<< "aux1["<< i << "]["<< k<<"]= " << aux1[i][k] << " aux2["<< k <<" ][" << j << "]= " << aux2[k][j] << endl;
                E[i][j] += aux1[i][k] * aux2[k][j];
            }

            E[i][j] %= m;
            //  cout<< "valor de E[i][j]"<< E[i][j] << endl;
        }
    }
    //escribir_M(E);
}

void exp_M(const matrix &M, matrix &E, int n, int m)
{
    if (n == 0)
    {
         
        E[0][0] = E[1][1] = 1;
        E[0][1] = E[1][0] = 0;
    }

    else if (n == 1)
    {
      
        E[0][0] = M[0][0] % m;
        E[0][1] = M[0][1] % m;
        E[1][0] = M[1][0] % m;
        E[1][1] = M[1][1] % m;
     
    }
    else if (n % 2 == 0)
    {
        matrix aux(2, vector<int>(2));

        exp_M(M, aux, n / 2, m);
      
        mult_M(aux, aux, E, m);
       
    }

    else
    {
        matrix aux(2, vector<int>(2));
     
        exp_M(M, aux, n - 1, m);
    
        mult_M(M, aux, E, m);
       
    }
}

int main()
{
    matrix M(2, vector<int>(2));

    /*while (*/cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1];//)
   // {
        int n, m;
        cin >> n >> m;

        matrix E(2, vector<int>(2));
        exp_M(M, E, n, m);
        //escribir_M(E);
   // }
}