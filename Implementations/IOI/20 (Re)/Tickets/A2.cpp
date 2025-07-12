#ifndef LOCAL
#include "tickets.h"
#endif
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b-1); i >= (a); --i)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll INF=1e18;
const int MX=90;

//------------------------------------------------------------//

//subtask 5

int N,M,K,X[MX][MX]; 

ll memo[MX][MX*MX];
int nxt[MX][MX*MX];

ll solve(int i, int n){
	if(i==N){
		if(n==(K*N)/2) return 0;
		return -INF;
	}

	ll &ind=memo[i][n];
	if(ind!=-2*INF) return ind;

	ll ans=-INF;
	int l=K-1,r=M;
	ll x=0,y=0;
	FOR(j,0,K) x+=X[i][j];

	ROF(j,-1,K){
		if(ckmax(ans,solve(i+1,n+j+1)+y-x)){
			nxt[i][n]=n+j+1;
		}

		if(j==-1) break;
		x-=X[i][l]; l--;
		r--; y+=X[i][r];
	}

	return ind=ans;
}

void allocate(vector<vi>ans){
	#ifndef LOCAL
	allocate_tickets(ans);
	return;
	#endif

	FOR(i,0,N) FOR(j,0,M) cout << ans[i][j] << " \n"[j==M-1];
}

ll find_maximum(int K, vector<vi> X) {
	N = X.size();
	M = X[0].size();
	::K=K;

	FOR(i,0,N) FOR(j,0,M) ::X[i][j]=X[i][j];

	FOR(i,0,N) FOR(j,0,N*M+1) memo[i][j]=-2*INF;
	ll x=solve(0,0);

	vector<vi>ans;
	ans.resize(N);
	FOR(i,0,N){
		ans[i].assign(M,-1);
	}

	int i=0,n=0,k=0;
	while(i<N){
		int m=nxt[i][n]-n;

		vi vis(K,0);
		FOR(j,0,m){
			ans[i][j]=k;
			vis[k]=1;
			k++; k%=K;
		}

		int m2=K-m;
		ROF(j,M-m2,M){
			FOR(kk,0,K) if(!vis[kk]){
				ans[i][j]=kk;
				vis[kk]=1;
				break;
			}
		}

		i++; n+=m;
	}

	allocate(ans);
	

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

/*
4 2 1
5 9
1 4
3 6
2 7
*/