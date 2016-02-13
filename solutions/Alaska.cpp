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
typedef vector<vi> vvi;
//typedef vector<vii> vvii;

string trip( vi &v )
{
	int next = 200 , c = 0 , slast = 0;
	sort( v.begin() , v.end() );
	int i;
	for ( i = 0; i < 1422 ; ++i )
	{
		if ( (c<v.size() && i == v[ c ]) && slast <= 200 )
		{
			c++; slast = 0;
		}
		else if ( slast > 200 ) return "IMPOSSIBLE";
		else ++slast;
	}
	if (i!=1422 || slast>100)
		return "IMPOSSIBLE";
	return "POSSIBLE";
}

int main()
{
	ios::sync_with_stdio( false );
	int n;
	while ( cin >> n && n )
	{
		vi v( n );
		for ( int i = 0; i < n; ++i )
			cin >> v[ i ];
		cout << "\n" << trip( v );
	}
	return 0;
}