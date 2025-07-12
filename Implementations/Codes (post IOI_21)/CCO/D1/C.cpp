#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef pair<int,int>pi; 
#define fi first
#define se second
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for(int i=a; i<b; i++)


void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
//-------------------------

const int MX=2e3+10;

int N,M,K; 
vi a(MX,-1), b(MX,-1); 

int memo[MX][MX][2]; 
int solve(int i, int j, int s){
	int &ind=memo[i][j][s]; 
	if(ind!=-1) return ind; 

	int ans=0; 
	if(!s){
		if(i+1<MX) ans=max(ans, solve(i+1,j,0) + (a[i+1]!=-1 && a[i+1]!=a[i]) );
		if(i+K<MX) ans=max(ans, solve(i,i+K,1) + (b[i+K]!=-1 && (b[i+K]!=b[j] || !j) ));
	}
	else{
		if(j+1<MX) ans=max(ans, solve(i,j+1,1) + (b[j+1]!=-1 && (b[j+1]!=b[j] || !j) ));
		if(j+K<MX) ans=max(ans, solve(j+K,j,0) + (a[j+K]!=-1 && a[j+K]!=a[i]) );
	}
	return ind=ans; 
}

int main(){
	boost; IO(); 

	cin>>N>>M>>K; 
	FOR(i,0,N){
		int l,r; cin>>l>>r;
		FOR(j,l,r) a[j]=i; 
	}
	FOR(i,0,M){
		int l,r; cin>>l>>r;
		FOR(j,l,r) b[j]=i; 
	}

	memset(memo,-1,sizeof(memo)); 
	cout << solve(0,0,0)+(a[0]!=-1) << endl;
	
}