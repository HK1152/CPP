#include<iostream>
using namespace std;
int main()
{
	int hk=5,i,j;
	for(i=1;i<=hk;i++)
	{
		for(j=1;j<=hk-i;j++)
		{
			cout<<" ";
		}
		for(j=1;j<=i;j++) cout<<j;
		for(j=i-1;j>=1;j--)
		{
			cout<<j;
		}
		
		cout<<"\n";
	}
	return 0;
}
