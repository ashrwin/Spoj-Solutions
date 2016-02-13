/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
vector<string> v( 20000 );

class trie
{
	class tnode
	{
	public:
		bool word;
		tnode *children[ 11 ];
		tnode( bool w = false )
		{
			word = w;
			for ( int i = 0; i < 11; ++i )
				children[ i ] = NULL;
		}
		~tnode()
		{
			for ( int i = 0; i < 11; ++i )
				delete children[i];
		}
	};
	tnode *root;

	tnode* insert( tnode *root , string key , int l )
	{
		if ( root == NULL ) 
			root = new tnode();
		if ( l == key.size() )
			root->word = true;
		else root->children[ key[ l ] - '0' ] = insert( root->children[ key[ l ] - '0' ] , key , l + 1 );
		return root;
	}

	void collect( tnode *root , string key , vector<string> &v )
	{
		if ( root == NULL ) return ;
		if ( root->word ) v.push_back( key );
		for ( int i = 0; i < 10; ++i )
			if ( root->children[ i ] != NULL )
				collect( root->children[ i ] , key + char( i + '0' ) , v );
	}

	bool check( tnode *root )
	{
		if ( root == NULL ) 
			return false;
		if ( root->word )
		{
			for ( int i = 0; i < 10; ++i )
				if ( root->children[ i ] != NULL )
					return true;
			return false;
		}
		for ( int i = 0; i < 10; ++i )
			if ( check( root->children[ i ] ) )
				return true;
		return false;
	}

public:
	
	trie()
	{
		root = NULL;
	}
	void insert( string key )
	{
		root = insert( root , key , 0 );
	}

	vector<string> collect()
	{
		vector<string> v;
		collect( root ,"", v );
		return v;
	}

	bool checkPrefix()
	{
		return check( root );
	}

};
int main()
{
	ios::sync_with_stdio( false );
	int t,n;
	cin >> t;
	while ( t-- )
	{
		trie tr;
		cin >> n;
		string k;
		for ( int i = 0; i < n; ++i )
		{
			cin >> k;
			tr.insert( k );
		}
		if ( tr.checkPrefix() )
			cout << "\nNO";
		else cout << "\nYES";
	}
	return 0;
}

