/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
	int t , n  ;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf( "%d" , &n );
		printf("\n%d",( n - 1 ) - ( n / 2 - 1 ));
	}
	return 0;
}






