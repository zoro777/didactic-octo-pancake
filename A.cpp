#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define eps 1e-9
#define all(a)   a.begin(),a.end()
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define sz size()
#define rd(inp) scanf("%lld",&inp)
#define rd2(inp1, inp2) scanf("%lld %lld",&inp1, &inp2)
#define rl(inp) scanf("%d",&inp)
#define pf(out) printf("%lld\n", out);

const long long linf = 1e18+5;
const ll mod = 1000000007;
const int inf = 1000000000;


ll fpow(ll base,ll power){
	ll result = 1;
	while (power > 0){
		if (power%2 == 1) result=(result*base);
  		base = (base*base);
  		power /= 2;
  	}
	return result;
}

#define maxn 8 * 100001

ll dp[maxn];
ll a[maxn];

void solve(){

	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	
	ll n, i, j;
	ll here = -1;

	rd(n);

	for ( i = 0 ; i < n ; i ++ ){
		rd(a[i]);
		dp[a[i]] = 1;
		here = max(here, a[i]);
	}

	sort(a, a + n);

	for ( i = 0 ; i < n ; i ++ ){
		for ( j = 2 ; j * a[i] < here + 1 ; j ++ ){
			dp[j*a[i]] = (dp[j*a[i]]%mod + dp[a[i]]%mod) % mod;
			dp[j*a[i]] %= mod;
			while ( dp[j*a[i]] < 0 ) dp[j*a[i]] += mod;
		}
	}
	ll ans = 0;
	for ( i = 0 ; i < n ; i ++ ){
		ans = (ans%mod + dp[a[i]]%mod) % mod;
		while ( ans < 0 ) ans += mod;
	}
	printf("%lld\n", ans);
	
}

int main(){
 	int t;
 	scanf("%d",&t);
 	while( t-- ){
 		solve();
 	} 
	return 0;
}
