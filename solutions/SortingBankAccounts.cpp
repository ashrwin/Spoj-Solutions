#include <iostream>
#include<numeric>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

string s;
int main()
{
	int t,n;
	cin >> t;
	while ( t-- )
	{
		cin >> n;
		cin.get();
		map<string , int> m;
		for ( int i = 0; i < n; ++i )
		{
			getline( cin , s );
			m[ s ]++;
		}
		for ( map<string , int>::iterator it = m.begin(); it != m.end(); ++it )
			cout << "\n" << it->first << " " << it->second;
	}
	return 0;
}

