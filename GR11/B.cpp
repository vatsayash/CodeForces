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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int w_count = 0;
    vi coll1;
    vi coll2;
    pii curr;
    curr.F = -1;
    curr.S = -1;
    forn(i,n)
    {
        if(s[i] == 'W')
        w_count++;
        if(s[i] == 'L' && curr.F == -1)
        {
            curr.F = i;
        }
        if(s[i] == 'W' && curr.F != -1)
        {
            curr.S = i-1;
            if(curr.F != 0)
            coll1.pb(curr.S-curr.F+1);
            else
            {
                coll2.pb(curr.S+1);
            }
            curr.F = -1;
            curr.S = -1;
        }
    }
    if(w_count == 0)
    {
        cout<<max(2*min(n,k)-1,0)<<endl;
        return;
    }
    if(curr.F != -1)
    {
        curr.S = n-1;
        coll2.pb(curr.S-curr.F+1);
    }  
    sort(all(coll1));
    sort(all(coll2));
    int left = k;
    ll ans = 0;
    for(auto u : coll1)
    {
        if(u <= left)
        {
            left -= u;
            ans += 2*u + 1;
        }
        else
        {
            ans += 2*left;  
            left = 0;
            break;
        }
    }
    for(auto u : coll2)
    {
        if(u <= left)
        {
            left -= u;
            ans += 2*u;
        }
        else 
        {
            ans += 2*left;
            left = 0;
            break;   
        }
    }
    if(s[0] == 'W')
    ans++;
    for(int i = 1 ; i < n ; i++)
    {
        if(s[i] == 'W' && s[i-1] == 'W')
        ans += 2;
        else if(s[i] == 'W')
        ans++;
    }
    cout<<ans<<endl;
}

int main()    
{
    fast();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}



 