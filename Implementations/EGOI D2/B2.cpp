#include <bits/stdc++.h>
using namespace std; 


typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef long double ld;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//--------------------------------------------------

void ckmin(ll &x, ll y){x=min(x,y);}

const int MX=2e5+10;

int s,T,N,M; 
vi a(MX),b(MX),c(MX),d(MX);

int get(ld pos){
	int l=0,r=T-1;
	while(l<=r){
		int k=(l+r)/2;
		if(pos>a[k] && pos<b[k]) return 1;
		
		if(pos<=a[k]) r=k-1;
		else l=k+1;
	}
	return 0;
}

void yes(){
	cout << "YES" << endl;
	exit(0);
}

int main(){
	IO();

	cin>>s>>T>>N>>M; 

	FOR(i,0,T) cin>>a[i];
	FOR(i,0,T) cin>>b[i];

	FOR(i,0,N) cin>>c[i];
	FOR(i,0,M) cin>>d[i];

	FOR(i,0,N){
		FOR(j,0,M){
			int t=c[i],t2=d[j];
			if(abs(t-t2)>=s) continue;

			if(t>t2){
				int d=t-t2; 
				if(get((ld)(s-d)/2)) yes();
			}
			else{
				int d=t2-t;
				if(get((ld)(s-d)/2+d)) yes();
			}
		}
	}
	cout << "NO" << endl;
}	