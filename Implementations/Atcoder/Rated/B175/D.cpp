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

const int MX=5000+10;
int N,K;
int P[MX],C[MX];
const int LOG=30;

int memo[MX][LOG+2],memo2[MX][LOG+2];

int jump(int u, int k){
	if(memo[u][k]!=-1) return memo[u][k];
	if(k==0) return memo[u][0]= P[u];
	return memo[u][k]=jump(jump(u,k-1),k-1);
}

int jumpV(int u, int k){
	if(memo2[u][k]!=-1) return memo2[u][k];
	if(k==0) return memo2[u][k]=C[P[u]];
	return memo2[u][k]=jumpV(u,k-1)+jumpV(jump(u,k-1),k-1);
}

int32_t main(){
   boost;
   IO();
	
	for(int i=0; i<MX; i++)for(int j=0; j<=LOG; j++) memo[i][j]=memo2[i][j]=-1;	

	cin>>N>>K;
	for(int i=1; i<=N; i++) cin>>P[i];
	for(int i=1; i<=N; i++) cin>>C[i];

	int res=-INF;
	for(int i=1; i<=N; i++){
		int ans=-INF;

		int sum=0;

		int ii=i;
		

		for(int j=1; j<=min(K,N+10); j++){
			sum+=jumpV(ii,0);
			ii=P[ii];
			ans=max(ans,sum);
		}

		int s=0;
		ii=i;

		int KK=max((ll)0,K-N-10);
		int KKK=KK;

		for(int j=LOG; j>=0; j--)if(((1)<<(j))<=KK){
			s+=jumpV(ii,j);
			ii=jump(ii,j);
			KK-=((1)<<(j));
			ans=max(ans,s);
		}

		for(int j=1; j<=K-KKK; j++){
			s+=jumpV(ii,0);
			ii=jump(ii,0);
			ans=max(ans,s);
		}
		ans=max(ans,s);

		res=max(res,ans);
	}

	cout << res << endl;


   return 0;
}

