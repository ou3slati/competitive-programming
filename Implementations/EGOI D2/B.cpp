#include <bits/stdc++.h>
using namespace std; 


typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

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

const int MX=1e5+10;


int main(){
	IO();

	int s,T,N,M; cin>>s>>T>>N>>M; 

	vi a(T),b(T);
	FOR(i,0,T) cin>>a[i];
	FOR(i,0,T) cin>>b[i];

	vi c(N),d(M);
	FOR(i,0,N) cin>>c[i];
	FOR(i,0,M) cin>>d[i];
	

	FOR(i,0,N){
		FOR(j,0,T){
			int d1=b[j]-a[j],d2=a[j],d3=s-(2*d1+d2);
			int t=c[i]+d2;



			int l=0,r=M-1;
			while(l<=r){
				int k=(l+r)/2;
				if(t-d[k]>d3 && t-d[k]<d3+2*d1){
					cout << "YES" << endl;
					return 0;
				}

				if(t-d[k]>=d3+2*d1) l=k+1;
				else r=k-1;
			}
		}
	}
	cout << "NO" << endl;
}	