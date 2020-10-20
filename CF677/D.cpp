#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int> > 
#define vl vector<long long>
#define vc vector<char> 
#define vvc vector<vector<char> > 
#define vpi vector<pair<int,int> >
#define ll long long 
#define sz(a) int(a.size())
#define forn(i,n) for(int i = 0 ; i < int(n) ; i++)
#define all(x) x.begin(),x.end()
#define vpl vector<pair<long long,long long> > 
#define F first
#define S second
#define mp make_pair
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pci pair<char,int>
#define vpii vector<pii> 
#define vpll vector<pll> 
#define len(s) s.length()
#define un unsigned
# define M_PI           3.14159265358979323846  /* pi */
#define modulo 998244353ll
#define mod 1000000007ll
#define MAXN  1000001 
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
ll gcd(ll a,ll b){if(a==0 || b == 0) return max(a,b);if(a == 1 || b == 1)return 1;return gcd(max(a,b)%min(a,b),min(a,b));}



void solve() 
{
	int n;
	cin>>n;
	vl a(n,0);
	int count = 0;
	forn(i,n)
	{
		cin>>a[i];
		if(i > 0 && a[i] != a[i-1])
		count++;
	}
	if(count == 0)
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	int temp = a[0];
	int first = -1;
	forn(i,n)
	{
		if(a[i] != temp)
		{
			first = i;
			break;
		}
	}
	for(int i = 1 ; i < n ; i++)
	{
		if(a[i] != temp)
		cout<<1<<" "<<i+1<<endl;
	}
	for(int i = 1 ; i < n ; i++)
	{
		if(a[i] == temp)
		{
			cout<<first+1<<" "<<i+1<<endl;
		}
	}
}


int main()    
{
    fast();
    int t;
    t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}



 