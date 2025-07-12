#include "bits/stdc++.h"
using namespace std; 

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//------------------------------------------------------//

void ckmin(int &x, int y){x=min(x,y);}

const int MX=2e5;
int N,K,R; 
vi a(MX),rq(MX,0);

int main(){
	IO();

	cin>>N>>K>>R;
	FOR(i,0,N) cin>>a[i];

	FOR(i,0,R){
		int x; cin>>x;
		cin>>rq[x];
	}

	int j=0,needed=R,ans=1e9;
	vi cnt(K,0);
	FOR(i,0,N){
		cnt[a[i]]++;
		if(cnt[a[i]]==rq[a[i]]) needed--;

		if(needed==0){
			while(cnt[a[j]]-1>=rq[a[j]]){
				cnt[a[j]]--;
				j++;
			}
			ckmin(ans,i-j+1);
		}
	}
	if(ans==1e9) cout << "impossible" << endl;
	else cout << ans << endl;

	
}
