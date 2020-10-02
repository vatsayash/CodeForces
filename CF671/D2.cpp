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



void solve()
{   
    int n;
    cin>>n;
    multiset<ll> ms;
    vl a(n,0);
    forn(i,n)
    {
        cin>>a[i];
        ms.insert(a[i]);    
    }
    sort(all(a));
    if(n <= 2)
    {
        cout<<0<<endl;
        for(auto u : a)
        cout<<u<<" ";
        cout<<endl;
        return;
    }
    else
    {
        int count = 0;
        int i = 0;
        int j = n/2;
        vl ans;
        while(j < n )
        {
            if(a[j] == a[i])
            j++;
            else if(ans.size() != 0 && ans.back() > a[i])
            {
                count++;
                ans.pb(a[i]);
                ans.pb(a[j]);
                auto it = ms.find(a[i]);
                ms.erase(it);
                it = ms.find(a[j]);
                ms.erase(it);
                i++;
                j++;
            }
            else
            {
                count++;
                ans.pb(a[j]);
                ans.pb(a[i]);
                ans.pb(a[j+1]);
                auto it = ms.find(a[i]);
                ms.erase(it);
                it = ms.find(a[j]);
                ms.erase(it);
                it = ms.find(a[j+1]);
                ms.erase(it);
                i++;
                j += 2;
            }
        }
        cout<<count<<endl;
        for(auto u : ans)
        cout<<u<<" ";
        for(auto u : ms)
        cout<<u<<" ";
        cout<<endl;
    }
    
}


int main()
{
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}       