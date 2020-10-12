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
#define len(s) s.length()
#define un unsigned
# define M_PI           3.14159265358979323846  /* pi */
#define modulo 998244353ll
#define mod 1000000007ll
#define MAXN  1000001 
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
ll gcd(ll a,ll b){if(a==0 || b == 0) return max(a,b);if(a == 1 || b == 1)return 1;return gcd(max(a,b)%min(a,b),min(a,b));}



ll ans = 0;


void merge(vector<int> &a,int l,int mid,int mid1,int r)
{
    vector<int> p,q;
    for(int i = l ; i <= mid ; i++)
    p.push_back(a[i]);
    for(int i = mid1 ; i <= r ; i++)
    {
        q.push_back(a[i]);
    }
    int i = 0;
    int j = 0;
    int k = l;
    for(auto u : q)
    {
        auto it = upper_bound(all(p),u);
        ans += (p.end()-it);
    }
    while(i < p.size() && j < q.size())
    {
        if(p[i] < q[j])
        a[k++] = p[i++];
        else
        {
            a[k++] = q[j++];
        }
    }
    while(i < p.size())
    a[k++] = p[i++];
    while(j < q.size())
    a[k++] = q[j++];
}

void countInversion(vector<int> &a,int l,int r)
{
    if(r <= l)
    return;
    int mid = (l+r)/2;
    countInversion(a,l,mid);
    countInversion(a,mid+1,r);
    merge(a,l,mid,mid+1,r);
}


void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string s_rev = s;
    reverse(all(s_rev));
    map<char,queue<int> > m;
    for(int i = 0 ; i < n ; i++)
    {
        m[s_rev[i]].push(i);
    }
    vi a(n,0);
    for(int i = 0 ; i < n ; i++)
    {
        a[i] = m[s[i]].front();
        m[s[i]].pop();
    }
    countInversion(a,0,n-1);
    cout<<ans<<endl;
}

int main()    
{
    fast();
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}




