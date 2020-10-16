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

vector<vector<ll> > a(100005,vector<ll> (3,0));

bool compatible(int i,int j)
{
    ll d = abs(a[i][1]-a[j][1]) + abs(a[i][2] - a[j][2]);
    if(d <= abs(a[i][0] - a[j][0]))
    {
        // cout<<i<<" "<<j<<endl;
        return true;
    }
    return false;
}

void solve()
{
    ll r,n;
    cin>>r>>n;
    vl dp(n+1,0);
    vl max_so_far(n+1,0);
    a[0][0] = 0;
    a[0][1] = 1;
    a[0][2] = 1;
    forn(i,n)
    {
        forn(j,3)
        cin>>a[i+1][j];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(compatible(i,0))
        dp[i] = 1;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = i-1 ; (i-j) < 2*r && j >= 1 ; j--)
        {
            if(compatible(i,j) && dp[j])
            dp[i] = max(dp[j]+1,dp[i]);
        }
        if(i-2*r >= 0)
        dp[i] = max(1+max_so_far[i-2*r],dp[i]);
        max_so_far[i] = max(max_so_far[i-1],dp[i]);
        // cout<<dp[i]<<endl;
    }
    cout<<max_so_far[n]<<endl;
}

int main()    
{
    fast();
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}



 