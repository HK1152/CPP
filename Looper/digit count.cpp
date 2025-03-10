#include<iostream>
using namespace std;
int main(){
	int hk,k=0;
	cout<<"Enter a value:";
	cin>>hk;
	if(hk!=0)
	{
		while(hk!=0)
		{
			hk /=10;
			k++;
			
		}
	}
	else 
	{
		k=1;
	}
	cout<<"Total number of digit :"<<k;
	return 0;
}
