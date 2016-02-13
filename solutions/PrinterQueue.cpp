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
#include<list>
#include<map>
#include<queue>
#include<set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
#define gc getchar
#define MAX 4000
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int printer( priority_queue<ii> &pq , deque<ii> &dq , int mjob )
{
	int ret = 0;
	while ( true )
	{
		ii cur = pq.top();
		while ( dq.front().first != cur.first )
		{
			ii temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}
		ii Z = dq.front();
		dq.pop_front();
		pq.pop();
		ret++;
		if ( Z.second == mjob )
			return ret;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		int n , m;
		cin >> n >> m;
		priority_queue<ii> pq;
		deque<ii> dq;
		rep( i , 0 , n )
		{
			int pri;
			cin >> pri;
			pq.push( mp( pri , i ) );
			dq.push_back( mp( pri , i ) );
		}
		cout << "\n" << printer( pq ,dq, m );
	}
	return 0;
}