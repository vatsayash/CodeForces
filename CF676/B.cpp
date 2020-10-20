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
    vector<vector<char> > grid(n,vector<char> (n,0));
    forn(i,n)
    {
        forn(j,n)
        cin>>grid[i][j];
    }
    vpii one;
    vpii zero;
    if(grid[0][1] == '1')
    {
        one.pb(mp(1,2));
    }
    else
    {
        zero.pb(mp(1,2));
    }
    if(grid[1][0] == '1')
    {
        one.pb(mp(2,1));
    }
    else
    {
        zero.pb(mp(2,1));
    }
    if(grid[n-1][n-2] == '1')
    {
        one.pb(mp(n,n-1));
    }
    else
    {
        zero.pb(mp(n,n-1));
    }
    if(grid[n-2][n-1] == '1')
    {
        one.pb(mp(n-1,n));
    }
    else
    {
        zero.pb(mp(n-1,n));
    }
    if(one.size() == 4 || zero.size() == 4)
    {
        cout<<2<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<1<<endl;
        return;
    }
    else if(one.size() == 2)
    {
        // cout<<2<<endl;
        if(one[0].S == one[1].F && one[0].F == one[1].S)
        {
            cout<<0<<endl;
            return;
        }
        else
        {
            cout<<2<<endl;
            for(auto u : one)
            {
                if((u.F == 1 && u.S == 2) || (u.F == 2 && u.S == 1))
                cout<<u.F<<" "<<u.S<<endl;
            }
            for(auto u : zero)
            {
                if((u.F == n && u.S == n-1) || (u.F == n-1 && u.S == n))
                cout<<u.F<<" "<<u.S<<endl;
            }
        }
        
    }
    else if(one.size() == 1 || zero.size() == 1)
    {
        if(one.size() == 1)
        {
            cout<<1<<endl;
            cout<<one[0].S<<" "<<one[0].F<<endl;
        
        }
        else
        {
            cout<<1<<endl;
            cout<<zero[0].S<<" "<<zero[0].F<<endl;
        }
        return;
    }
    return;
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




