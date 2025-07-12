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

int N,M;
vector<vi> g;
vi vec[8];
int memo[1000000][8];

int cnt(int j, int m){
	int ans=0;
	for(int i=0; i<N; i++){
		if(((m)&((1)<<(i)))==0 && g[i][j]==1) ans++;
		if(((m)&((1)<<(i))) && g[i][j]==0) ans++;
	}
	//cout << j<< ' ' << m << ' ' << ans << endl;
	return ans;
}

int solve(int i, int m){
	if(i==M-1) return 0;
	if(memo[i][m]!=-1) return memo[i][m];
	int ans=INF;
	for(auto it: vec[m]) ans=min(ans,solve(i+1,it)+cnt(i+1,it));
	return memo[i][m]=ans;
}

bool check(int m, int mm){
	int a=0,b=0;
	if(m%2==1) a++; if(mm%2==1) a++;
	m/=2; mm/=2;
	if(m%2==1){a++; b++;} if(mm%2==1){a++;b++;}
	m/=2; mm/=2;
	if(m%2==1) b++; if(mm%2==1) b++;
	return (a%2==1 && b%2==1);
}

int32_t main(){
   boost;
   IO();
   memset(memo,-1,sizeof(memo));
   cin>>N>>M;
   g.assign(N,vi(M));
   for(int i=0; i<N; i++){
   	char c;
   	for(int j=0; j<M; j++){
   		cin>>c; g[i][j]=c-'0';
   	}
   }

	if(min(N,M)>3){cout << -1 << endl; return 0;}

	for(int m=0; m<8; m++){
		for(int mm=0; mm<8; mm++){
			if(check(m,mm)) vec[m].pb(mm);
		}
	}

	//for(int i=0; i<8; i++){for(auto x: vec[i]) cout << x << ' '; cout << endl;}

	int ans=INF;
	for(int m=0; m<((1)<<(N)); m++){
		ans=min(ans,solve(0,m)+cnt(0,m));
	}
	cout << ans << endl;

	

   return 0;
}

