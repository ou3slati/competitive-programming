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

const int MX=1e6+10;


int N; 
vi B(MX), P(MX), U(MX); 

int main(){
	boost; IO(); 

	cin>>N; 
	FOR(i,1,N+1) cin>>B[i]; 
	FOR(i,1,N) cin>>P[i]; 
	FOR(i,1,N) cin>>U[i];

	//U[i]=0
	int f=1,sum=0,rem=0; 
	vector<pair<pi,int>>vec; 
	FOR(i,1,N){
		int l=P[i], r=0, x=0; 
		if(l>B[i]){
			r+=l-B[i]; 
			l=B[i]; 
			if(r>B[i+1]){
				x=r-B[i+1];

				rem+=U[i]; 
				if(x>rem)
					f=0; 
				rem-=x; 
				sum+=x; 

				r=B[i+1]; 
			}

			B[i+1]-=r; 
		}
		vec.pb({{l,x},r}); 
	}

	if(!f) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		cout << sum << endl;
		for(auto v: vec){
			cout << v.fi.fi << ' ' << v.fi.se << ' ' << v.se << endl;
		}
	}
}