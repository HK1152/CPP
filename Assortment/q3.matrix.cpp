#include<iostream>
using namespace std;

int main() {
	
    int row, col;
    cout << "Enter row size: ";
    cin >> row;
    cout<<"Enter col. size:";
    cin>>col;

    int hk[row][col];

    cout << "Enter array's elements:" << endl;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cout << "a["<<i <<"]["<<j <<"]=";
            cin>>hk[i][j];
        }
    }

    // matrix
    cout << "The transpose matrix of an array:" << endl;
    for (int j=0; j<col; j++) {
        for (int i=0; i<row; i++) {
            cout<<hk[i][j]<<"\t";
        }
        cout << endl; 
    }

    return 0;
}
//debug
/*
row 2       col 2
ex= value is : 
hk[0][0] = 11
hk[0][1] = 12
hk[1][0] = 100
hk[1][1] =1152


1, j=0 0<2.....true,than i=0 0<2 print:- 11 
2, j=0 0<2.....true,than i=1 1<2 print:- 11 12
3, j=0 0<2.....true,than i=2 2<2 false
2, j=1 1<2.....true,than i=0 0<2 print:- 11 12 \n 100
2, j=1 1<2.....true,than i=1 1<2 print:- 11 12 \n 100 1152 
2, j=1 1<2.....true,than i=2 2<2 false
2, j=2 2<2.....false


*/
