#include<iostream>
using namespace std;
int main(){
	int row,col;
	cout<<"Enter a row size:";
	cin>>row;
	cout<<"Enter a col. size:";
	cin>>col;
	
	
	int hk[row][col];
	for(int i=0;i<=row;i++){
		for(int j=0;j<=col;j++){
			cout<<"hk["<<i <<"]["<< j<<"]";
			cin>>hk[i][j];
		}
	}
	
	int l=hk[0][0];
	for(int i=0;i<=row;i++){
		for(int j=0;j<=col;j++){
			if(hk[i][j] > l)
			l = hk[i][j];
		}
	}
	cout<<"The largest element is:"<<l;
}
//debug
/*
row 2       col 2
ex= value is : 
hk[0][0] = 11
hk[0][1] = 12
hk[0][2] =-11
hk[1][0] = 100
hk[1][1] =1152
hk[1][2] = 1
hk[2][0] =0
hk[2][1] =12
hk[2][2] =15

1. i=0 0<=2....true, than j=0 0<=2 true, than if(11 > 11) false 
2. i=0 1<=2....true, than j=1 1<=2 true, than if(12 > 11) true than l= 12
3. i=0 0<=2....true, than j=2 2<=2 true, than if(-11 > 12) false  
4. i=0 0<=2....true, than j=3 3<=2 false 
5. i=1 1<=2....true, than j=0 0<=2 true, than if(100 > 12) true than l=100
6. i=1 1<=2....true, than j=1 1<=2 true, than if(1152 > 100) true than l=1152
7. i=1 1<=2....true, than j=2 2<=2 true, than if(1 > 1152) false
8. i=1 1<=2....true, than j=3 3<=2 false
9. i=2 2<=2....true, than j=0 0<=2 true, than if(0 > 1152) false
10. i=2 2<=2....true, than j=1 1<=2 true, than if(12 > 1152) false
11. i=2 2<=2....true, than j=2 2<=2 true, than if(15 > 1152) false
12. i=2 2<=2....true, than j=3 3<=2 false
13. i=3 3<=2....false
largest is 1152
*/
