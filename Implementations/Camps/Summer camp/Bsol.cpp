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

str s; int N;
int K;
int v[1001];
int memo[1001][1001][2];

int solve(int idx, int x, int st){
	if(idx==N){
		if(x==0) return 0;
		if(v[x]==K-1) return 1;
		return 0;
	}

	if(memo[idx][x][st]!=-1) return memo[idx][x][st];
	int ans=0;
	if(s[idx]=='0'){
		if(st==1){
			ans=(ans+solve(idx+1,x+1,1))%MOD;
		}
		ans=(ans+solve(idx+1,x,st))%MOD;
	}
	else{
		ans=(ans+solve(idx+1,x,st))%MOD;
		ans=(ans+solve(idx+1,x-1,1))%MOD;
	}

	return memo[idx][x][st]=ans;
}

int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));

   int xx=0;
   cin>>s; cin>>K;
   N=sz(s);
   for(int i=0; i<N; i++) if(s[i]=='1') xx++;

   if(K==0){
   	cout << 1 << endl;
   	return 0;
   }

   if(xx==1 && s[sz(s)-1]=='1'){
   	if(K==0) cout << 1 << endl;
   	else cout << 0 << endl;
   	return 0;
   }

   for(int i=1; i<=1000; i++){
   	int cnt=0;
   	int x=i;
   	while(x>1){
   		int nb=0;
   		for(int idx=0; idx<10; idx++) if(x&(1<<(idx))) nb++;
   		x=nb;
   		cnt++;
   	}
   	v[i]=cnt;
   }

   cout << solve(0,xx,0) - (K==1) << endl;

   return 0;
}

