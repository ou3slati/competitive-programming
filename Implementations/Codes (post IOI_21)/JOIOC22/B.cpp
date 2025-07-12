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

bool check(vi a){
	int N=sz(a); 
	FOR(i,0,N){
		int mn=N,mx=1; 
		FOR(j,i,N){
			mn=min(mn,a[j]); 
			mx=max(mx,a[j]); 

			if(!(min(a[i],a[j])==mn || max(a[i],a[j])==mx)) return 0; 
		}
	}
	return 1; 
}

int main(){
	IO(); 

	int N; cin>>N; 
	vi p(N); 
	FOR(i,0,N) cin>>p[i]; 
	
	vi a(N); iota(all(a),1);

	int ans=N; 
	do{
		if(check(a)){
			int n=0; 
			FOR(i,0,N) n+=(a[i]!=p[i]); 
			ans=min(ans,n); 
		}
	}while(next_permutation(all(a))); 
	cout << ans << endl;

}