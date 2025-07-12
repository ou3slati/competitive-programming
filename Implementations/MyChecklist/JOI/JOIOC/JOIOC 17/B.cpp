#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//------------------------------------------------//

typedef long double ld;

void ckmax(ll &x, ll y){x=max(x,y);}

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
int main(){
	IO();

	int N; cin>>N;
	vector<ld> X(N),Y(N),V(N);
	FOR(i,0,N) cin>>X[i]>>Y[i]>>V[i];

	ll ans=0;
	FOR(i,0,N) FOR(j,i+1,N){
		if(X[i]!=X[j]){
			FOR(k,0,N){
				ld a=((ld)(Y[j]-Y[i]))/(X[j]-X[i]);

				ld b=Y[i]-a*X[i]; 
				ld c=Y[k]-a*X[k];
				if(b>c) swap(b,c);

				ll val=0;
				FOR(l,0,N){
					ld d=Y[l]-a*X[l];
					if(d>=b && d<=c) val+=V[l];
				}
				ckmax(ans,val);
			}
		}
		else{
			FOR(k,0,N){
				int lft=X[i],rgt=X[k];
				if(lft>rgt) swap(lft,rgt);

				ll val=0;
				FOR(l,0,N){
					if(X[l]>=lft && X[l]<=rgt) val+=V[l];
				}
				ckmax(ans,val);
			}
		}
		
	}
	cout << ans << endl;
}