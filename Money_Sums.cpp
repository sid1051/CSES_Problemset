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
 
vll dp(1e5+1,0);

void solve(){
    int n;
    cin>>n;

    vll l(n+1,0);

    for(int i=1;i<=n;i++) cin>>l[i];

    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        vll tp(1e5+1,0);
        for(int j=0;j<=1e5;j++) tp[j]=dp[j];
        for(int j=1;j<=1e5;j++)
        {
            if(j-l[i]>=0 && tp[j-l[i]]) dp[j]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=1e5;i++) if(dp[i]) ans++;
    cout<<ans<<"\n";
    for(int i=1;i<=1e5;i++) if(dp[i]) cout<<i<<" ";

 
    return;
}
 
 
int main(){
    startt;
    ll t=1;
   // cin>>t;
    while(t--) solve();
 
    return 0;
}