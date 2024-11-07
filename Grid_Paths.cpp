#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll int
ll mod = 1e9+7;
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pair<ll, ll>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvvll vector<vvll>
#define f(i, n) for (ll i = 1; i <= n; i++)
#define pb push_back
#define ff first
#define ss second
#define mkp make_pair
#define endl "\n"
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ind_set;
typedef tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update> ind_set1;
 
#define startt                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
 
ll gcd(ll a, ll b){if (b == 0) return a; else return gcd(b, a % b);}
ll lcm(ll a, ll b){return a * b / gcd(a, b); }
ll madd(ll a, ll b, ll m) {return (a % m + b % m) % m;}
ll msub(ll a, ll b, ll m) {return (a % m - b % m + m) % m;}
ll mmul(ll a, ll b, ll m){return (a % m * b % m) % m;}
ll mexpo(ll a, ll b, ll m){if (b==0) return 1; ll res=mexpo(a, b/2, m); res=mmul(res, res, m); if(b%2==1) res=mmul(res, a, m); return res;}
ll minv(ll a, ll m){return mexpo(a, m - 2, m);}
ll mdiv(ll a, ll b, ll m){return mmul(a, minv(b, m), m);}
ll min(ll i, ll j){return i<j?i:j;}
ll max(ll i, ll j){return i>j?i:j;}
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
 
vvll dp(1001, vll (1001, 0));

void solve(){
    int n;
    cin>>n;

    vector<string> l(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>l[i-1];
    }

    if(l[0][0]=='.') dp[0][1]=1;

    for(int i=1;i<=1000;i++)
    {
        for(int j=i;j<=1000;j++)
        {
            if(i<n+1 && j<n+1 && l[i-1][j-1]!='*') dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            if(i<n+1 && j<n+1 && l[j-1][i-1]!='*') dp[j][i]=(dp[j-1][i]+dp[j][i-1])%mod;
        }
    }
    cout<<dp[n][n];

    return;
}
 
 
int main(){
    startt;
    ll t=1;
   // cin>>t;
    while(t--) solve();
 
    return 0;
}