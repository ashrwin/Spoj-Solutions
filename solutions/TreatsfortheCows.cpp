#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
int m[ 2001 ][ 2001 ] = { 0 };
int treat( const vector<int> &v , int start , int end , int age=1 )
{
	if ( m[start][end]!=0 )
		return m[start][end];

	if ( start == end )
		return v[ start ] * age;
	int sol = max( v[ start ] * age + treat( v , start + 1 , end , age + 1 ) ,
		v[ end ] * age + treat( v , start , end - 1 , age + 1 )
		);
	m[start ][end] = sol;
	return sol;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v( n );
	for ( int i = 0; i < n; ++i )
		cin >> v[ i ];
	cout << "\n" << treat( v , 0 , v.size() - 1  ) << endl;
	return 0;
}