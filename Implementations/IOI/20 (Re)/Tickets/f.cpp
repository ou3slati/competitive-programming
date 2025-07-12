#include "tickets.h"
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int) v.size()
typedef pair<ll,ll>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define FOR(i,a,b) for(int i=a; i<b; i++)

ll find_maximum(int K, vector<vi> x) {
	int N=x.size();
	int M=x[0].size();
	vector<vi> ans(N,vi(M,-1));

	ll val=0;
	vi l(N,K-1),r(N,M);
	set<pi,greater<pi>>s;
	FOR(i,0,N){
		FOR(j,0,K) val-=x[i][j];
		s.insert({x[i][M-1]+x[i][K-1],i});
	}

	int rep=(N*K)/2;
	while(rep--){
		auto it=s.begin();
		int i=(*it).se;
		ll v=(*it).fi;
		s.erase(it);

		val+=v;
		l[i]--; r[i]--;
		if(l[i]>=0)
			s.insert({x[i][r[i]-1]+x[i][l[i]],i});
	}

	int k=0;
	FOR(i,0,N){
		set<int>s;
		FOR(j,0,K) s.insert(j);

		FOR(j,0,l[i]+1){
			ans[i][j]=k;
			s.erase(k);
			k++; k%=K;
		}

		FOR(j,r[i],M){
			auto it=s.begin();
			ans[i][j]=*it;
			s.erase(it);
		}
	}


	allocate_tickets(ans);	
	return val;
}

/*
2 3 2
0 2 5
1 1 3
*/

/*
4 2 1
5 9
1 4
3 6
2 7
*/