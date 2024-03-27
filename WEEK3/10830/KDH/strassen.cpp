/*
하..... 문제 조건을 잘못 읽고 있었다....
strassen algorithm은 n이 2의 제곱수일 때만 적용 가능하다........
*/
#include <bits/stdc++.h>
using namespace std;

int N, threshold = 1;
long long b;
int **arr;

int **InitializeMat(int n);
void strassen(int n, int **A, int **B, int **&C);
int **add(int **M1, int **M2, int n);
int **subtract(int **M1, int **M2, int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> b;

    arr = new int *[N];
    for (int i = 0; i < N; i++)
        arr[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    int **result = InitializeMat(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][j] = arr[i][j];

    for (long long x = 0; x < b - 1; x++)
    {
        int **temp = InitializeMat(N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                temp[i][j] = result[i][j];

        strassen(N, arr, temp, result);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << result[i][j] << " ";

        cout << '\n';
    }

    return 0;
}

void strassen(int n, int **A, int **B, int **&C)
{
    if (n <= threshold)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
    else
    {
        // memory allocation
        int **A11 = InitializeMat(n / 2);
        int **A12 = InitializeMat(n / 2);
        int **A21 = InitializeMat(n / 2);
        int **A22 = InitializeMat(n / 2);
        int **B11 = InitializeMat(n / 2);
        int **B12 = InitializeMat(n / 2);
        int **B21 = InitializeMat(n / 2);
        int **B22 = InitializeMat(n / 2);

        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][n / 2 + j];
                A21[i][j] = A[n / 2 + i][j];
                A22[i][j] = A[n / 2 + i][n / 2 + j];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][n / 2 + j];
                B21[i][j] = B[n / 2 + i][j];
                B22[i][j] = B[n / 2 + i][n / 2 + j];
            }

        // 재귀 호출
        int **M1 = InitializeMat(n / 2);
        int **M2 = InitializeMat(n / 2);
        int **M3 = InitializeMat(n / 2);
        int **M4 = InitializeMat(n / 2);
        int **M5 = InitializeMat(n / 2);
        int **M6 = InitializeMat(n / 2);
        int **M7 = InitializeMat(n / 2);

        strassen(n / 2, add(A11, A22, n / 2), add(B11, B22, n / 2), M1);
        strassen(n / 2, add(A21, A22, n / 2), B11, M2);
        strassen(n / 2, A11, subtract(B12, B22, n / 2), M3);
        strassen(n / 2, A22, subtract(B21, B11, n / 2), M4);
        strassen(n / 2, add(A11, A12, n / 2), B22, M5);
        strassen(n / 2, subtract(A21, A11, n / 2), add(B11, B12, n / 2), M6);
        strassen(n / 2, subtract(A12, A22, n / 2), add(B21, B22, n / 2), M7);

        // 결과 행렬 C를 합치기
        int **C11 = add(subtract(add(M1, M4, n / 2), M5, n / 2), M7, n / 2);
        int **C12 = add(M3, M5, n / 2);
        int **C21 = add(M2, M4, n / 2);
        int **C22 = add(subtract(add(M1, M3, n / 2), M2, n / 2), M6, n / 2);

        // 결과 행렬 C를 합치기
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++)
            {
                C[i][j] = C11[i][j];
                C[i][n / 2 + j] = C12[i][j];
                C[n / 2 + i][j] = C21[i][j];
                C[n / 2 + i][n / 2 + j] = C22[i][j];
            }

        // 메모리 해제
        for (int i = 0; i < n / 2; i++)
        {
            delete[] A11[i];
            delete[] A12[i];
            delete[] A21[i];
            delete[] A22[i];
            delete[] B11[i];
            delete[] B12[i];
            delete[] B21[i];
            delete[] B22[i];
            delete[] M1[i];
            delete[] M2[i];
            delete[] M3[i];
            delete[] M4[i];
            delete[] M5[i];
            delete[] M6[i];
            delete[] M7[i];
            delete[] C11[i];
            delete[] C12[i];
            delete[] C21[i];
            delete[] C22[i];
        }

        delete[] A11;
        delete[] A12;
        delete[] A21;
        delete[] A22;
        delete[] B11;
        delete[] B12;
        delete[] B21;
        delete[] B22;
        delete[] M1;
        delete[] M2;
        delete[] M3;
        delete[] M4;
        delete[] M5;
        delete[] M6;
        delete[] M7;
        delete[] C11;
        delete[] C12;
        delete[] C21;
        delete[] C22;
    }
}

int **InitializeMat(int n)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
        temp[i] = new int[n];

    return temp;
}

int **add(int **M1, int **M2, int n)
{
    int **temp = InitializeMat(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

int **subtract(int **M1, int **M2, int n)
{
    int **temp = InitializeMat(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}