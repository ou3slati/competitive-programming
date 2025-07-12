#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef long double ld; 

typedef vector<int>vi;
#define pb push_back
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()

#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}

//-----------------

const int MX=301; 

int N; 
vi p(MX);

int memo[MX][MX][MX]; 

int solve(int l, int r, int n){
	//base case
	if(l==r){
		return (n+1!=p[l]); 
	}
	

	int &ind=memo[l][r][n]; 
	if(ind!=-1) return ind; 


	int next_l=n+1, next_r=(r-l+1)+n; 

	int ans=1e9;

	//put in l
	ans=min(ans, solve(l+1,r,n+1) + (next_l!=p[l]) );
	ans=min(ans, solve(l+1,r,n) + (next_r!=p[l]) );

	//put in r
	ans=min(ans, solve(l,r-1,n) + (next_r!=p[r]) );
	ans=min(ans, solve(l,r-1,n+1) + (next_l!=p[r]) );

	return ind=ans; 

}

int main(){
	IO(); 

	cin>>N; 
	FOR(i,0,N) cin>>p[i]; 
	
	memset(memo,-1,sizeof(memo)); 
	cout << solve(0,N-1,0) << endl;

}