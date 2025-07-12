#ifndef LOCAL
#include "tickets.h"
#endif
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll INF=1e18;
const int MX=1500+10;

//------------------------------------------------------------//

//K=1 (subtask 1 & 2)

int N,M; 
ll memo[MX][MX],mn[MX],mx[MX];
int nxt[MX][MX];

ll solve(int i, int n){
	if(i==N){
		if(n==N/2) return 0;
		return -INF;
	}

	ll &ind=memo[i][n];
	if(ind!=-2*INF) return ind;

	ll ans=solve(i+1,n)+mx[i];
	nxt[i][n]=n;

	if(ckmax(ans,solve(i+1,n+1)-mn[i]))
		nxt[i][n]=n+1;

	return ind=ans;
}

ll find_maximum(int K, vector<vi> X) {
	N = X.size();
	M = X[0].size();
	
	FOR(i,0,N){
		mn[i]=X[i][0];
		mx[i]=X[i][M-1];
	}	

	FOR(i,0,N) FOR(j,0,N) memo[i][j]=-2*INF;
	ll x=solve(0,0);

	vector<vi>ans;
	ans.resize(N);
	FOR(i,0,N){
		ans[i].assign(M,-1);
	}

	int i=0,n=0;
	while(i<N){
		if(nxt[i][n]==n){
			ans[i][M-1]=0;
		}
		else{
			ans[i][0]=0;
			n++;
		}
		i++;
	}

	allocate_tickets(ans);
	//FOR(i,0,N) FOR(j,0,M) cout << ans[i][j] << " \n"[j==M-1];

	return x; 
}

//-------------------------------------------------------------//
void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
#ifdef LOCAL
int main(){
	IO();

	int N,M,K; cin>>N>>M>>K;
	vector<vi>a;
	a.resize(N);
	FOR(i,0,N){
		a[i].resize(M);
		FOR(j,0,M) cin>>a[i][j];
	}

	cout << find_maximum(K,a) << endl;
}
#endif