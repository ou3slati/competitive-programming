#ifndef LOCAL
#include "tickets.h"
#endif
#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define se second
#define fi first
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b-1); i >= (a); --i)
 
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const ll INF=1e18;
const int MX=1500+10;
 
//------------------------------------------------------------//
 
//K=M (subtask 1 & 4)

int N,M,K,X[MX][MX]; 
 
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
 
	ll val=0;
	vector< pair<int,pi> >vec;
	FOR(i,0,N) FOR(j,0,M){
		::X[i][j]=X[i][j];
		vec.pb({X[i][j],{i,j}});
		val+=X[i][j];
	}
	sort(vec.begin(),vec.end());
 
	int a[N][M]; memset(a,0,sizeof(a));
	FOR(i,0,(N*K)/2){
		int x=vec[i].se.fi,y=vec[i].se.se,v=vec[i].fi;
		a[x][y]=1;
		val-=v*2;
	}
 
	vector<vi>ans;
	ans.resize(N);
	FOR(i,0,N){
		ans[i].assign(M,-1);
	}
 
	int k=0;
	FOR(i,0,N){
 
		set<int>s;
		FOR(j,0,K) s.insert(j);
 
		FOR(j,0,M) if(a[i][j]){
			ans[i][j]=k;
			s.erase(k);
			k++; k%=K;
		}
 
		FOR(j,0,M) if(!a[i][j]){
			auto it=s.begin();
			ans[i][j]=*it;
			s.erase(it);
		}
	}
	
 
	allocate(ans);
	
 
	return val; 
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
