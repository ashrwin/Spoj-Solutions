#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
typedef long long ll;

vector<ll> aux( 600000 );

ll merges( vector<ll> &v , const int lo , const int mid , const int hi )
{ // Merge a[lo..mid] with a[mid+1..hi].
	ll ret = 0;
	int i = lo , j = mid + 1;
	for ( int k = lo; k <= hi; k++ ) // Copy a[lo..hi] to aux[lo..hi].
		aux[ k ] = v[ k ];
	for ( int k = lo; k <= hi; k++ ) // Merge back to a[lo..hi].
	{
		if ( i > mid ) v[ k ] = aux[ j++ ];
		else if ( j > hi ) v[ k ] = aux[ i++ ];
		else if ( aux[ i ] > aux[ j ] ) {
			ret = ret + ( mid - i+1 );
			v[ k ] = aux[ j++ ];
		}
		else v[ k ] = aux[ i++ ];
	}
		return ret;
}

ll mergesort( vector<ll> &a , int low , int high )
{
	ll ret = 0;
	if ( low < high )
	{
		int mid = ( low + high ) / 2;
		ret += mergesort( a , low , mid );
		ret += mergesort( a , mid + 1 , high );
		ret += merges( a , low , mid , high );
		//cout << "\n RET " << ret;
	}
	return ret;
}


int main()
{
	
	int t,n;
	cin >> t;
	for ( int i = 0; i < t;++i )
	{
		cin >> n;
		vector<ll> v(n);
		for ( int j = 0; j < n; j++ )
			cin >> v[ j ];
		cout << "\n" << mergesort( v , 0 , v.size() - 1 );
	}
	
}
