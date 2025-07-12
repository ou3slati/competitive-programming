//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=205;
int A,B,C;
vi a(MX),b(MX),c(MX);

int memo[MX][MX][MX];

int solve(int i, int j, int k){
	int nb=0;
	if(i==A) nb++; if(j==B) nb++; if(k==C) nb++;
	if(nb>=2) return 0;
	if(memo[i][j][k]!=-1) return memo[i][j][k];
	int ans=0;
	if(i!=A && j!=B) ans=max(ans,solve(i+1,j+1,k)+a[i]*b[j]);
	if(i!=A && k!=C) ans=max(ans,solve(i+1,j,k+1)+a[i]*c[k]);
	if(j!=B && k!=C) ans=max(ans,solve(i,j+1,k+1)+b[j]*c[k]);
	return memo[i][j][k]=ans;
}

int32_t main(){
   boost;
   IO();
		
	memset(memo,-1,sizeof(memo));
	cin>>A>>B>>C;
	for(int i=0; i<A; i++) cin>>a[i];
	for(int i=0; i<B; i++) cin>>b[i];
	for(int i=0; i<C; i++) cin>>c[i];

	sort(rall(a));
	sort(rall(b));
	sort(rall(c));

	cout << solve(0,0,0) << endl;


   return 0;
}

