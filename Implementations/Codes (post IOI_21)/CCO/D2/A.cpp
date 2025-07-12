#include <bits/stdc++.h>
using namespace std; 

#define ll long long 
#define int ll

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
typedef pair<int,int>pi; 
typedef vector<pi>vpi; 
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a; i<b; i++) 

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}

//------------------

const int MX=4000+10;
const int MOD=1e9+7; 
const ll INF=1e18; 

int N,K; 
vi drop(MX,0), L(MX), R(MX); 


vi sub(MX,0), ball(MX,0); 
void dfs(int u){
	ball[u]=drop[u]; 
	sub[u]=1; 

	for(int v: {L[u], R[u]}) if(v){
		dfs(v);
		sub[u]+=sub[v]; 
		ball[u]+=ball[v]; 
	}
}

int memo[MX][MX]; 

int solve(int u, int x, int s){
	if(ball[u]+x>sub[u]) return 0;
	
	if(!u) return (x==0);  
	if(sub[u]==1) return 1;


	int &ind=memo[u][x]; 
	if(ind!=-1) return memo[u][x]; 

	int l=x*(1-s), r=x*s; 

	int ans=0; 
	if(ball[u]+x==sub[u]){
		//cout << u << ' ' << x << endl;
		if(drop[u]){
			ans+=drop[u]*solve(L[u],l,0)*solve(R[u],r,1); 
			ans%=MOD; 
		}

		if(l){
			ans+=l*solve(L[u],l-1,0)*solve(R[u],r,1);
			ans%=MOD; 
		}

		if(r){
			ans+=r*solve(L[u],l,0)*solve(R[u],r-1,1);
			ans%=MOD; 
		}
	}
	else{
		

		if(drop[u]){

			cout << u << ' ' << x << ' ' << endl;
			ans+=solve(L[u],l+1,0)*solve(R[u],r,1); 
			ans%=MOD; 
			cout << ans << endl;
			ans+=solve(L[u],l,0)*solve(R[u],r+1,1); 
			ans%=MOD; 

			
			cout << ans << endl;
		}
		else{
			ans+=solve(L[u],l,0)*solve(R[u],r,1); 
			ans%=MOD; 
		}


	}


	return ind=ans; 
}

int32_t main(){
	IO(); 

	cin>>N>>K; 
	FOR(i,0,K){
		int u; cin>>u; 
		drop[u]++;
	}

	
	FOR(i,1,N+1){
		cin>>L[i]>>R[i]; 
	}

	dfs(1); 

	//FOR(i,1,N+1) cout << ball[i] << ' ' << sub[i] << endl;

	memset(memo,-1,sizeof(memo)); 
	cout << solve(1,0,0) << endl;


	
}