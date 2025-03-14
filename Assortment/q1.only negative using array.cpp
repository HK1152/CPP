#include<iostream>
using namespace std;
int main(){
	int size; // create array
	
	cout<<"Enter the array's size:";
	cin>>size;
	int hk[size];
	
	cout<<"Enter array's elements:"<<endl;
	for(int a=0;a<size;a++)// data get
	{
		cout<<"a["<<a+1<<"]=";
		cin>>hk[a];
	}
	
	cout<<"Negative elements from an array:";
	for(int i=0;i<=size;i++) // create for loop
	{
		if(hk[i]<0) // create if statement
		{
			cout<<hk[i]<<"\t";
		}
	}

	return 0;
}
//debug
/*
ex: data is hk[5] = {1,-1,2,-2,3,-3};
1. i=0, or 0<=5.....true, than... if(hk[0]<=0) means if(1<=0).....false
2. i=1, of 1<=5.....true, than.....if(hk[1]<=0) means if(-1<=0).....true, than print -1
3. i=2, or 2<=5.....true, than... if(hk[2]<=0) means if(2<=0).....false
4. i=3, of 3<=5.....true, than.....if(hk[3]<=0) means if(-2<=0).....true, than print -2
5. i=4, or 4<=5.....true, than... if(hk[4]<=0) means if(3<=0).....false
6. i=5, of 5<=5.....true, than.....if(hk[5]<=0) means if(-3<=0).....true, than print -3
7. i=6, or 6<=5.....false
*/

