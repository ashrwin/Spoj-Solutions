#include<iostream>
#include<map>
using namespace std;



void penny(const int n,const string &s)
{
 map<string,int> m;
m["TTT"]=0;
m["TTH"]=0;
m["THT"]=0;
m["THH"]=0;
m["HTT"]=0;
m["HTH"]=0;
m["HHT"]=0;
m["HHH"]=0;
for(int i=0;i<=s.size()-3 ; ++i )
      m[s.substr(i,3)]++;     

   cout<<"\n"<<n<<" ";
map<string,int>::reverse_iterator it=m.rbegin();
 while(it!=m.rend())
 {
      cout<<it->second<<" ";
      it++;
 }
 
}



int main()
{

    int t;
    cin>>t;
    int n;
    string s;
    for(int i=0;i<t;++i)
    {
         cin>>n;
         cin>>s;
         penny(n,s);   

    }   
return 0;
}
