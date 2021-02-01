#include <iostream>
#include <vector>

using namespace std;

/*Compute M^n mod m*
 Input Matrix 2x2 and n and m
*/

typedef vector<int> Row;
typedef vector<Row> Matrix;

void print_matrix(Matrix m)
{

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j){
              if(j!= 0) cout<< " ";
              cout << m[i][j];
        }
          
        cout << endl;
    }
    cout<< "----------" << endl;
}

void multip_Mat(const Matrix &matAux1, const Matrix &matAux2, Matrix &mRes, int m)
{
    mRes = Matrix(2, Row(2, 0));
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                mRes[i][j] +=  matAux1[i][k] * matAux2[k][j];
            }
            mRes[i][j] %= m;
        }
    }
}
void power_matrix(const Matrix &M, int n, int m, Matrix &mRes)
{

    if (n == 0)
    {
        mRes[0][0] = 1;
        mRes[1][1] = 1;
    }
    else if (n == 1)
    {
        mRes[0][0] = M[0][0] % m;
        mRes[0][1] = M[0][1] % m;
        mRes[1][0] = M[1][0] % m;
        mRes[1][1] = M[1][1] % m;
    }
    else if (n % 2 == 0)
    {
        Matrix matAux(2, Row(2));
        power_matrix(M, n / 2, m, matAux);
        multip_Mat(matAux, matAux, mRes, m);
    }
    else
    {
        Matrix matAux(2, Row(2));
        power_matrix(M, n - 1, m, matAux);
        multip_Mat(M, matAux, mRes, m);
    }
}

int main()
{

    Matrix M(2, Row(2));

    while (cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1])
    {
        int n, m;
        cin >> n >> m;
        Matrix mRes(2, Row(2));

        power_matrix(M, n, m, mRes);
        print_matrix(mRes);
    }
}