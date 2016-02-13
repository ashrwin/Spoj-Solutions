#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#include<map>
#include<set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
int m[ 2600 ][ 2600 ][ 3 ];
int hm ;
int die( int H , int A , int P )
{
	if ( P == 0 ){
		H += 3;
		A += 2;
	}
	else if ( P == 1 ) {
		H -= 5;
		A -= 10;
	}
	else {
		H -= 20;
		A += 5;
	}

	if ( H <= 0 || A <= 0 )
		return 0;
	if ( m[ H ][ A ][ P ] != -10000 )
		return m[ H ][ A ][ P ];
	if ( P == 0 )
		return m[ H ][ A ][ P ] = max( die( H , A , 1 ) , die( H , A , 2 ) ) + 1;
	if ( P == 1 )
		return m[ H ][ A ][ P ] = max( die( H , A , 0 ) , die( H , A , 2 ) ) + 1;
	else return m[ H ][ A ][ P ] = max( die( H , A , 0 ) , die( H , A , 1 ) ) + 1;
}



int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		int h , a;
		cin >> h >> a;
		rep( i , 0 , 2600 ) rep( j , 0 , 2600 ) rep( k , 0 , 3 )
			m[ i ][ j ][ k ] = -10000;
		cout << "\n" << die( h , a , 0 );
	}
	return 0;

}