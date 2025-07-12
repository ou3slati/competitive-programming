#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)


typedef pair<int,int>pi;
#define fi first
#define se second

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

void ckmax(int &x, int y){x=max(x,y);}
void ckmin(int &x, int y){x=min(x,y);}

//---------

const int MX=1e4;
int N,K; 
vi a(MX),p(MX),c(MX),L(MX),R(MX);
vi vec[MX];


vi vis(MX,0);

int check(int l, int r){
	if(l>r) swap(l,r);
	FOR(i,l,r+1) if(!vis[i]) return 0;

	return 1;
}
pi get(int m){
	FOR(i,1,N+1) vis[i]=0;

	int l=5000,r=-1;
	FOR(i,0,K) if((m>>i)&1){
		ckmax(r,p[i]);
		FOR(j,L[i],R[i]+1) vis[j]=1;
	}
	FOR(i,0,K) if((m>>i)&1){
		ckmin(l,p[i]);
	}

	while(l-1>=0){
		if(check(a[l],a[l-1])) l--;
		else break;
	}
	while(r+1<N){
		if(check(a[r],a[r+1])) r++;
		else break;
	}

	return pi{l,r};
}

int memo[1<<10];
int solve(int m){
	int l=get(m).fi,r=get(m).se;
	if(l==0 && r==N-1) return 0;

	int &ind=memo[m];
	if(ind!=-1) return ind; 

	int ans=2e9;
	FOR(i,l,r+1){
		for(int j: vec[i]){
			int l2=get(((m)|(1<<j))).fi,r2=get(((m)|(1<<j))).se;
			if(l2<l || r2>r) 
				ckmin(ans,solve(((m)|(1<<j)))+c[j]);
		}
	}
	return ind=ans; 
}

int main(){
	IO();

	memset(memo,-1,sizeof(memo));

	cin>>N>>K;
	FOR(i,0,N) cin>>a[i];
	FOR(i,0,K){
		cin>>p[i]>>c[i]>>L[i]>>R[i];
		p[i]--;
		vec[p[i]].pb(i);
	}

	FOR(i,0,K){
		if(a[p[i]]>=L[i] && a[p[i]]<=R[i]){
			int ans=solve(1<<i)+c[i];
			if(ans==2e9) cout << -1 << endl;
			else cout << ans << endl;
		}
		else cout << -1 << endl;
	}


	return 0;
}
