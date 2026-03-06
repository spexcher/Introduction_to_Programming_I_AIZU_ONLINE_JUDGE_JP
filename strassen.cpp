#include <iostream>
#include <vector>
using namespace std;

// Standard matrix multiplication
template <typename T>
vector<vector<T>> MatrixMultiply(const vector<vector<T>> &a,
                                 const vector<vector<T>> &b,
                                 int n, int l, int m)
{
    vector<vector<T>> c(n, vector<T>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < l; k++)
                c[i][j] += a[i][k] * b[k][j];

    return c;
}

// Strassen's Algorithm
template <typename T>
vector<vector<T>> Strassen(const vector<vector<T>> &a,
                           const vector<vector<T>> &b,
                           int n, int l, int m)
{

    if (n == 1 || l == 1 || m == 1)
        return MatrixMultiply(a, b, n, l, m);

    vector<vector<T>> c(n, vector<T>(m, 0));

    int adjN = (n >> 1) + (n & 1);
    int adjL = (l >> 1) + (l & 1);
    int adjM = (m >> 1) + (m & 1);

    // Initialize submatrices
    vector<vector<vector<vector<T>>>> As(2,
                                         vector<vector<vector<T>>>(2,
                                                                   vector<vector<T>>(adjN, vector<T>(adjL, 0))));

    vector<vector<vector<vector<T>>>> Bs(2,
                                         vector<vector<vector<T>>>(2,
                                                                   vector<vector<T>>(adjL, vector<T>(adjM, 0))));

    // Fill A submatrices
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            for (int i = 0; i < adjN; i++)
                for (int j = 0; j < adjL; j++)
                {
                    int I = i + x * adjN;
                    int J = j + y * adjL;
                    if (I < n && J < l)
                        As[x][y][i][j] = a[I][J];
                }

    // Fill B submatrices
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            for (int i = 0; i < adjL; i++)
                for (int j = 0; j < adjM; j++)
                {
                    int I = i + x * adjL;
                    int J = j + y * adjM;
                    if (I < l && J < m)
                        Bs[x][y][i][j] = b[I][J];
                }

    // Auxiliary matrices S
    vector<vector<vector<T>>> s(10);

    s[0] = vector<vector<T>>(adjL, vector<T>(adjM));
    s[1] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[2] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[3] = vector<vector<T>>(adjL, vector<T>(adjM));
    s[4] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[5] = vector<vector<T>>(adjL, vector<T>(adjM));
    s[6] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[7] = vector<vector<T>>(adjL, vector<T>(adjM));
    s[8] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[9] = vector<vector<T>>(adjL, vector<T>(adjM));

    // Compute S matrices
    for (int i = 0; i < adjL; i++)
        for (int j = 0; j < adjM; j++)
        {
            s[0][i][j] = Bs[0][1][i][j] - Bs[1][1][i][j];
            s[3][i][j] = Bs[1][0][i][j] - Bs[0][0][i][j];
            s[5][i][j] = Bs[0][0][i][j] + Bs[1][1][i][j];
            s[7][i][j] = Bs[1][0][i][j] + Bs[1][1][i][j];
            s[9][i][j] = Bs[0][0][i][j] + Bs[0][1][i][j];
        }

    for (int i = 0; i < adjN; i++)
        for (int j = 0; j < adjL; j++)
        {
            s[1][i][j] = As[0][0][i][j] + As[0][1][i][j];
            s[2][i][j] = As[1][0][i][j] + As[1][1][i][j];
            s[4][i][j] = As[0][0][i][j] + As[1][1][i][j];
            s[6][i][j] = As[0][1][i][j] - As[1][1][i][j];
            s[8][i][j] = As[0][0][i][j] - As[1][0][i][j];
        }

    // P matrices
    vector<vector<vector<T>>> p(7);

    p[0] = Strassen(As[0][0], s[0], adjN, adjL, adjM);
    p[1] = Strassen(s[1], Bs[1][1], adjN, adjL, adjM);
    p[2] = Strassen(s[2], Bs[0][0], adjN, adjL, adjM);
    p[3] = Strassen(As[1][1], s[3], adjN, adjL, adjM);
    p[4] = Strassen(s[4], s[5], adjN, adjL, adjM);
    p[5] = Strassen(s[6], s[7], adjN, adjL, adjM);
    p[6] = Strassen(s[8], s[9], adjN, adjL, adjM);

    // Combine results
    for (int i = 0; i < adjN; i++)
        for (int j = 0; j < adjM; j++)
        {
            if (i < n && j < m)
                c[i][j] = p[4][i][j] + p[3][i][j] - p[1][i][j] + p[5][i][j];

            if (i < n && j + adjM < m)
                c[i][j + adjM] = p[0][i][j] + p[1][i][j];

            if (i + adjN < n && j < m)
                c[i + adjN][j] = p[2][i][j] + p[3][i][j];

            if (i + adjN < n && j + adjM < m)
                c[i + adjN][j + adjM] =
                    p[4][i][j] + p[0][i][j] - p[2][i][j] - p[6][i][j];
        }

    return c;
}

// Example usage
int main()
{
    vector<vector<long double>> A = {{1.0, 2, 3}, {4, 5, 6}};
    vector<vector<long double>> B = {{7, 8}, {9.0, 10}, {11, 12}};

    vector<vector<long double>> C = Strassen(A, B, 2, 3, 2);

    for (auto &row : C)
    {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}