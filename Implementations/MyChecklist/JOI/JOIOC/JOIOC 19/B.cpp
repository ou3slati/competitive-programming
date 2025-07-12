#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define dbgv(v) for(auto x: v) cerr << x << ' '; cerr << endl;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

const int nx[4]={-1,0,1,0},ny[4]={0,1,0,-1};

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

//-----------------------------------------------//

void no(){
	cout << "No" << endl;
	exit(0);
}

int main(){
	IO();

	int N; cin>>N;
	vector<ll> a(N+1),b(N+1),c(N+1),power(N+1,1);
	ll sum=0;
	FOR(i,1,N+1){
		cin>>a[i]>>b[i];
		c[i]=b[i]-a[i];	

		sum+=a[i];
		power[i]=power[i-1]*2;
	}

	ll x=0;
	FOR(i,1,N+1) x+=power[i-1]*c[i];
	if(x%(1-power[N])!=0) no();
	x/=(1-power[N]);
	if(x<0) no();

	vector<ll> X(N+1); X[N]=x; 
	ROF(i,1,N){
		X[i]=c[i+1]+2*X[i+1];
		if(X[i]<0) no();
	}
	assert(X[N]==c[1]+2*X[1]);

	//checking

	int rep=5e5;
	while(rep--){
		FOR(i,1,N+1){
			int n=min(X[i],a[i]/2);

			a[i]-=2*n; X[i]-=n;
 
			int nxt=i+1; 
			if(i==N) nxt=1;
			a[nxt]+=n;

		}
	}
	FOR(i,1,N+1) if(X[i]) no();

	FOR(i,1,N+1) if(a[i]!=b[i]) no();

	cout << "Yes" << endl;
}