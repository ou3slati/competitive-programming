#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define int long long

typedef pair<int,int>pi; 
#define fi first
#define se second
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
//-------------------------

const int MX=1e6+10;


int N; 
vi B(MX), P(MX,0), U(MX,0); 

void no(){
	cout << "NO" << endl;
	exit(0); 
}

int32_t main(){
	boost; IO(); 

	cin>>N; 
	FOR(i,1,N+1) cin>>B[i]; 
	FOR(i,1,N) cin>>P[i]; 
	FOR(i,1,N) cin>>U[i];

	vi L(N+1,0), R(N+1,0); 
	FOR(i,1,N+1){
		if(P[i-1]>U[i-1]){
			int x=P[i-1]-U[i-1]; 

			if(B[i]<x) no(); 
			B[i]-=x; 
			P[i-1]-=x;	  
			
			R[i-1]+=x; 
		}



		int x=min(B[i],P[i]); 
		B[i]-=x; 
		P[i]-=x; 

		L[i]+=x; 
	}


	ROF(i,1,N){
		int x=min(B[i+1],P[i]); 
		B[i+1]-=x; P[i]-=x; R[i]+=x; 

		x=min(B[i+1],L[i]); 
		B[i+1]-=x; B[i]+=x; L[i]-=x; R[i]+=x; 
	}

	int sum=0; 
	FOR(i,1,N){
		if(P[i]>U[i]) no(); 
		sum+=P[i]; 
	}

	cout << "YES" << endl;
	cout << sum << endl;
	FOR(i,1,N){
		cout << L[i] << ' ' << P[i] << ' ' << R[i] << endl;
	}
}