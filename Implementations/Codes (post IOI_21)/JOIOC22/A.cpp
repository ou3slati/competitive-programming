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

struct fract{
	ll p; int q; 
}; 

bool cmp(fract A, fract B){
	ll a=A.p, b=A.q, c=B.p, d=B.q; 
	return a*d-b*c<=0;
}


ld dif(fract A, fract B){
	ll a=A.p, b=A.q, c=B.p, d=B.q; 
	return ((ld)(-a*d+b*c))/(b*d); 
}

int main(){
	IO(); 

	int N; cin>>N; 
	vi a(N); 
	FOR(i,0,N) cin>>a[i]; 

	vector<fract>vec; 
	FOR(l,0,N){
		ll p=0; 
		FOR(r,l,N){
			p+=a[r]; 
			vec.pb({p,r-l+1}); 
		}
	}

	/*for(auto x: vec) cout << x.p << ' ' << x.q << endl << dif(fract{0,1},x) << endl;
	cout << endl;*/

	ll sum=0; FOR(i,0,N) sum+=a[i]; 
	fract all = {sum,N}; 

	ld ans=1e9; 
	for(fract mn: vec) if(cmp(mn,all)){
		int l=0, r=N-1; 

		sum=all.p; 
		fract mx=all; 
		while(l<r){
			fract cur={sum-a[r],r-l}; 
			if(cmp(mn,cur)){
				sum-=a[r]; 
				r--; 
			}
			else{
				sum-=a[l]; 
				l++; 

				cur={sum,r-l+1};
				if(cmp(mx,cur)) mx=cur; 
			}
		}

		ans=min(ans,dif(mn,mx)); 

		//if(ans==0){cout << mn.p << endl; break;}
	}
	
	cout << fixed << setprecision(10) << ans << endl;

}