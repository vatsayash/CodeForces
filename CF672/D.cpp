#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
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
#define len(s) s.length()
#define un unsigned
# define M_PI           3.14159265358979323846  /* pi */
#define modulo 998244353ll
#define mod 1000000007ll
#define MAXN  1000001 
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll power(ll a,ll b){return b?power(a*a%modulo,b/2)*(b%2?a:1)%modulo:1;}
ll gcd(ll a,ll b){if(a==0 || b == 0) return max(a,b);if(a == 1 || b == 1)return 1;return gcd(max(a,b)%min(a,b),min(a,b));}

ll f[300001];

ll InverseEuler(ll n) 
{ 
 return power(n,modulo-2); 
} 
  
ll C(ll n, ll r) 
{ 
  
 return (f[n]*((InverseEuler(f[r]) * InverseEuler(f[n-r])) % modulo)) % modulo; 
} 


void solve()
{   
    int n,k;
    cin>>n>>k;
    map<int,int> m;
    vector<pair<ll,ll> > coll1,coll;
    set<int> indices;
    ll ans = 0;
    forn(i,n)   
    {
        ll l,r;
        cin>>l>>r;
        coll1.pb(mp(l,r));
    }
    sort(all(coll1));
    vector<pair<ll,ll> > left,right;
    forn(i,n)
    {
        left.pb(mp(coll1[i].F,i+1));
        right.pb(mp(coll1[i].S,i+1));    
    }
    sort(all(left));
    sort(all(right));
    int i = 0;
    int j = 0;
    while(i < n && j < n)
    {
        if(left[i].F <= right[j].F)
        {
            indices.insert(left[i].S);
            i++;
        }    
        else
        {
            int x = indices.size();
            if(x >= k)
            {
                ans += C(x-1,k-1);
                ans %= modulo;
            }
            int curr = right[j].S;
            j++;
            auto it = indices.find(curr);
            indices.erase(it);
        }
    }
    int x = indices.size();
    if(x >= k)
    {
        ans += C(x,k);
        ans %= modulo;
    }
    ans %= modulo;
    cout<<ans<<endl;
}


int main()
{
    int t = 1;
    // cin>>t;
    f[0] = 1; 
	for(int i = 1 ; i <= 300000 ; i++) 
	f[i] = (f[i-1]*i)%modulo;
    while(t--)
    {
        solve();
    }
    return 0;
}       