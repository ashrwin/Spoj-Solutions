#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#define mp make_pair
#define pb push_back
#define MAX (1<<30)
using namespace std;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

inline string palin(const string &s)
{
	for ( int i = 0 , j = s.size() - 1; i < j; ++i , --j )
		if ( s[ i ] != s[ j ] )
			return "NO";
	return "YES";
}
int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	string s;
	while ( t-- )
	{
		cin >> s;
		cout << "\n" << palin( s );
	}

	return 0;
}