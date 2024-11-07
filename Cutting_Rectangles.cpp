#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll int
ll mod = 998244353;
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
 
vvll dp(501, vll (501, 0));

void solve(){
    int a,b;
    cin>>a>>b;

    for(int i=1;i<501;i++)
    {
        for(int j=i+1;j<501;j++)
        {
            ll tp=1e8;
            for(int k=1;k<=i/2;k++)
            {
                tp=min(tp, dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<=j/2;k++)
            {
                tp=min(tp, dp[i][k]+dp[i][j-k]+1);
            }
            dp[i][j]=dp[j][i]=tp;
        }
    }

    cout<<dp[b][a]<<"\n";
 
    return;
}
 
 
int main(){
    startt;
    ll t=1;
   // cin>>t;
    while(t--) solve();
 
    return 0;
}