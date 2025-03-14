#include<iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the array's row size: ";
    cin >> rows;
    cout << "Enter the array's column size: ";
    cin >> cols;
    
    int hk[rows][cols];

    cout << "Enter array's elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> hk[i][j];
        }
    }

    int rowno;
    cout << "Enter row number: ";
    cin >> rowno;


    int rhk = 0;
    cout << "Elements of row " << rowno << ": ";
    for (int j = 0; j<cols; j++) {
        cout << hk[rowno][j] << " ";
        rhk += hk[rowno][j];
    }
    cout << "\nThe sum of row " << rowno << ": " << rhk << endl;


    int colno;
    cout << "Enter column number: ";
    cin >> colno;


  int chk = 0;
    cout << "Elements of column " << colno << ": ";
    for (int i = 0; i < rows; i++) {
        cout << hk[i][colno] <<" ";
        chk += hk[i][colno];
    }
    cout << "\nThe sum of column " << colno << ": " << chk << endl;
    return 0;
}

//debug
/*
row 2       col 2     rowno 1
ex= value is : 
hk[0][0] = 1
hk[0][1] = 1
hk[1][0] = 5
hk[1][1] = 2 

row............
rhk=0    rowno 1
1, j=0 0<2.....true, than print:- hk[1][0].. means 5 ..... after rhk = 0 + 5 =5 
2, j=1 1<2.....true, than print:- hk[1][1].. means 2..... after rhk = 5 + 2 =7
3, j=2 2<2.....false 

col........
row............
rhk=0    rowno 1
1, i=0 0<2.....true, than print:- hk[0][1].. means 1..... after rhk = 0 + 1 =1 
2, i=1 1<2.....true, than print:- hk[1][1].. means 1..... after rhk = 1 + 2 =3
3, i=2 2<2.....false 

*/
