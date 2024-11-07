#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
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


void solve(){
    ll n,k;
    cin>>n>>k;

    vvll dp(n+1, vll (102, 0));
    vll l(n+2,0);

    for(ll i=1;i<n+1;i++) {cin>>l[i]; if(l[i]!=0) dp[i][l[i]]=1;}

    if(l[1]==0) for(ll i=1;i<=k;i++) dp[1][i]=1;
    else dp[1][l[1]]=1;

    for(ll i=2;i<=n;i++)
    {
        if(l[i]==0)
        {
            for(ll j=1;j<=k;j++) dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
        }
    }

    ll ans=1;

    for(ll i=2;i<=n;i++)
    {
        if(l[i]!=0 && l[i-1]==0)
        {
            ll tp = (dp[i-1][l[i]-1]+dp[i-1][l[i]]+dp[i-1][l[i]+1])%mod;
            ans = (ans*tp)%mod;
        }
    }

    if(l[n]==0)
    {
        ll tp=0;
        for(ll i=1;i<=k;i++) tp+=dp[n][i];
        ans = (ans*tp)%mod;
    }

    ll fg=0;
    for(int i=1;i<n;i++) if(l[i]!=0 && l[i+1]!=0 && abs(l[i+1]-l[i])>1) fg=1;
    
    if(fg) ans=0;
    cout<<ans;
 
    return;
}


int main(){
    startt;
    ll t=1;
    //cin>>t;
    while(t--) solve();

    return 0;
}
