// ClassWork_2_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Vedit rozmir kv matrici: ";
    cin >> n;
    int** A = new int* [n];
    for (int i = 1; i <= n; i++) {
        A[i] = new int[n];
    }
    cout << "elementy masivy: "<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "A[" << i << "," << j << "]=";
            cin>> A[i][j];            
        }
    }
    for (int j = 1; j <= n; j++) {
       int s = 0;
       int i = 1;
       while (A[i][j] >= 0 && i <= n) {
           s = s + A[i][j];
           i = i + 1;
       }
       if (i == n + 1) cout << "suma v stovpci " << j << ": " << s<<endl;
    }
    int s ;
    int min = abs(A[1][1]);
    for (int i = 2; i < n; i++) {
        s = 0;
        for (int j = 1; j <= i; j++) {
            s = s + abs(A[i + 1 - j][j]);
        }
        
        if (s < min) min = s;

    }
    for (int i = 2; i <= n; i++) {
        s = 0;
        int k = 2;
        for (int j = n; j >= i; j--) {
            s = s + abs(A[n + k - j][j]);
        }
        
        if (s < min) min = s;
        k = k + 1;
    }
    cout << "min_sum: " << min;
}

