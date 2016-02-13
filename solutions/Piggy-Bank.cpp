#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

struct coin
{
	int value , weight;
	coin( int v , int w )
	{
		value = v;
		weight = w;
	}
};

string piggy( int w , int n , vector< coin > &v )
{
	vector<int> dp( w + 1 ,1000000);
	dp[ 0 ] = 0;
	for ( int i = 1; i <= w; ++i )
	{
		for ( int j = 0; j < v.size(); ++j )
		{
			coin c = v[ j ];
			if (i-c.weight >=0 )
				dp[ i ] = min( dp[i-c.weight]+c.value , dp[i]   );
			//else dp[ i ] = dp[ i - 1 ];
		}
		//cout << "\n DP " << i << "  -> " << dp[ i ];
	}
	stringstream ss;
	if ( dp[w]!= 1000000 )
		ss << "The minimum amount of money in the piggy-bank is " << dp[ w ]<<".";
	else ss << "This is impossible.";
	return ss.str();
}


int main()
{
	int t,e,f,n;
	cin >> t;
	for ( int i = 0; i < t; ++i )
	{
		cin >> e >> f;
		cin >> n;
		vector< coin  > v;
		for ( int j = 0; j < n; ++j )
		{
			int x , y;
			cin >> x >> y;
			v.push_back( coin(x,y) );
		}
		cout << "\n" << piggy( f-e , n , v );
	}

	return 0;
}
