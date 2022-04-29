#include <bits/stdc++.h>

using namespace std;
#define ll long long int

float A[4][4], B[4], X[4], ADJ[4][4], det;

void multiply(){
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            X[i] += ADJ[i][j] * B[j];
        }
    }
}

/*
A[1][1] A[1][2] A[1][3]
A[2][1] A[2][2] A[2][3]
A[3][1] A[3][2] A[3][3]
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> A[i][j];
        }
        cin >> B[i];
    }

    //X = A^-1B
    //A^-1 = ADJ(A)/DET(A)

    //DETERMINANT OF A
    det = A[1][1] * (A[2][2] * A[3][3] - A[2][3] * A[3][2]) - A[1][2] * (A[2][1] * A[3][3] - A[2][3] * A[3][1]) + A[1][3] * (A[2][1] * A[3][2] - A[3][1] * A[2][2]);

    //FINDING ADJOINT OF MATRIX A
    ADJ[1][1] = A[2][2] * A[3][3] - A[2][3] * A[3][2];
    ADJ[2][1] = -(A[2][1] * A[3][3] - A[2][3] * A[3][1]);
    ADJ[3][1] = A[2][1] * A[3][2] - A[3][1] * A[2][2];

    ADJ[1][2] = -(A[1][2] * A[3][3] - A[3][2] * A[1][3]);
    ADJ[2][2] = A[1][1] * A[3][3] - A[3][1] * A[1][3];
    ADJ[3][2] = -(A[1][1] * A[3][2] - A[3][1] * A[1][2]);

    ADJ[1][3] = A[1][2] * A[2][3] - A[2][2] * A[1][3];
    ADJ[2][3] = -(A[1][1] * A[2][3] - A[2][1] * A[1][3]);
    ADJ[3][3] = A[1][1] * A[2][2] - A[2][1] * A[1][2];

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cout << ADJ[i][j] << " ";
        }
        cout << "\n";
    }

    cout << det << "\n";

    //A^(-1)B
    multiply();

    //SCALAR MULTIPLICATION
    for(int i = 1; i <= 3; i++){
        X[i] *= (1 / det);
    }

    for(int i = 1; i <= 3; i++){
        cout << X[i] << " ";
    }

}
