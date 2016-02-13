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
#include<cstdio>
#include<cstring>
#include <ctime>
#include<unordered_set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar
#define pc putchar
#define MAX 1000010
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int cells[ 140 ][ 140 ];
bool vis[ 120 ][ 120 ];
int n;
unordered_set<int> st;
const int dx[] = { -1 , 0 , 1 , 0 } , dy[] = { 0 , 1 , 0 , -1 };
void dfs( int r , int c )
{
	vis[ r ][ c ] = true;
	rep( i , 0 , 4 )
	{
		int R = r + dy[ i ] , C = c + dx[ i ];
		if ( R < 0 || C < 0 || R >= n || C >= n || vis[ R ][ C ] || cells[ R ][ C ] != cells[ r ][ c ] )continue;
		dfs( R , C );
	}
}


bool dfs()
{
	st.clear();
	rep( i , 0 , n )rep( j , 0 , n )
		if ( !vis[ i ][ j ] )
		{
		if ( st.count( cells[ i ][ j ] ) )
			return false;
		dfs( i , j );
		st.insert( cells[ i ][ j ] );
		}
	return true;
}

int main()
{
	while ( cin >> n && n )
	{
		memset( cells , -1 , sizeof cells );
		memset( vis , 0 , sizeof vis );
		cin.get();
		rep( i , 0 , n - 1 )
		{
			string temp;
			getline( cin , temp );
			stringstream ss( temp );
			int x , y;
			while ( ss >> x && ss >> y )
			{
				--x , --y;
				cells[ x ][ y ] = i + 1;
			}
		}
		rep( i , 0 , n )rep( j , 0 , n )if ( cells[ i ][ j ] == -1 )cells[ i ][ j ] = n;
		if ( dfs() )cout << "good";
		else cout << "wrong";
		cout << "\n";
	}
	return 0;
}
