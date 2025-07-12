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

	/*vector<fract>vec; 
	FOR(l,0,N){
		ll p=0; 
		FOR(r,l,N){
			p+=a[r]; 
			vec.pb({p,r-l+1}); 
		}
	}*/

	/*for(auto x: vec) cout << x.p << ' ' << x.q << endl << dif(fract{0,1},x) << endl;
	cout << endl;*/

	ll sum=0; FOR(i,0,N) sum+=a[i]; 
	fract all = {sum,N}; 

	
	ld ans=1e9; 
	FOR(i,0,N){
		fract cur=all,mn=all,mx=all; 
		int l=0, r=N-1; 

		while(l<r){
			//cout << l << ' ' << r << endl; 
			ll p=cur.p; int q=cur.q;

			ll p1=p-a[l], p2=p-a[r]; 

			/*cout << dif(fract{p2,q-1}, all) << endl;
			cout << dif(all, fract{p1,q-1}) << endl;*/

			/*if(abs(dif(fract{p2,q-1}, P)) < abs(dif(fract{p1,q-1}), P))
				cur={p2,q-1},r--;
			else cur={p1,q-1},l++;*/

			if(r>i){
				cur.p-=a[r]; 
				cur.q--; 
				r--; 
			}
			else{
				cur.p-=a[l]; 
				cur.q--; 
				l++; 
			}

			if(cmp(mx,cur)) mx=cur; 
			if(cmp(cur,mn)) mn=cur; 
		}

		ans=min(ans,dif(mn,mx)); 


		cur=all,mn=all,mx=all; 
		l=0, r=N-1; 

		while(l<r){
			//cout << l << ' ' << r << endl; 
			ll p=cur.p; int q=cur.q;

			ll p1=p-a[l], p2=p-a[r]; 

			/*cout << dif(fract{p2,q-1}, all) << endl;
			cout << dif(all, fract{p1,q-1}) << endl;*/

			/*if(abs(dif(fract{p2,q-1}, P)) < abs(dif(fract{p1,q-1}), P))
				cur={p2,q-1},r--;
			else cur={p1,q-1},l++;*/

			
			if(l<i){
				cur.p-=a[l]; 
				cur.q--; 
				l++; 
			}
			else{
				cur.p-=a[r]; 
				cur.q--; 
				r--; 
			}

			if(cmp(mx,cur)) mx=cur; 
			if(cmp(cur,mn)) mn=cur; 
		}

		ans=min(ans,dif(mn,mx)); 
		
		
	}

	cout << fixed << setprecision(10) << ans << endl;

	
	

}