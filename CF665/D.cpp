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
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
ll gcd(ll a,ll b){if(a==0 || b == 0) return max(a,b);if(a == 1 || b == 1)return 1;return gcd(max(a,b)%min(a,b),min(a,b));}


vi adj[100005];
vl ccount(100005,0);


void dfs(int v,int p)
{
    ccount[v] = 1;
    for(auto u : adj[v])
    {
        if(u != p)
        {
            dfs(u,v);
            ccount[v] += ccount[u];
        }
    }
}

void solve()
{
    forn(i,100005)
    adj[i].clear();
    ccount.clear();
    ll n;
    cin>>n;
    int m;
    vpi edges;
    ll ans = 0;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].pb(q);
        adj[q].pb(p);
        edges.pb(mp(p,q));
    }
    cin>>m;
    vl prime_factors(m,0);
    forn(i,m)
    cin>>prime_factors[i];
    dfs(1,0);
    vl coll;
    for(auto u : edges)
    {
        ll curr = 1ll*min(ccount[u.F],ccount[u.S]);
        curr *= 1ll*(n-curr);
        coll.pb(curr);
    }
    sort(coll.rbegin(),coll.rend());
    sort(prime_factors.rbegin(),prime_factors.rend());
    while(m < n-1)
    {
        prime_factors.pb(1);
        m++;
    }
    if(m > n-1)
    {
        ll temp = coll[0]%mod;
        for(int i = 0 ; i < m+2-n ; i++)
        {
            temp *= prime_factors[i]%mod;
            temp %= mod;    
        }
        ans += temp;
        for(int i = m+2-n ; i < m ; i++)
        {
            ans += (1ll*(coll[i+n-m-1]%mod)*(prime_factors[i]%mod))%mod;
            ans %= mod;
        }
    }
    else
    {
        for(int i = 0 ; i < n-1 ; i++)
        ans += (1ll*(coll[i]%mod)*(prime_factors[i]%mod))%mod;
        ans %= mod;
    }
    ans %= mod;
    cout<<ans<<endl;
    cout<<endl;
}



int main()
{
    fast();
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
 