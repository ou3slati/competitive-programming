//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b-1); i >=(a); --i)

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int32_t main() {
    boost; IO();

    int N,Q; cin>>N>>Q;
    string s; cin>>s;
    int p[26][N],suf[26][N];
    FOR(i,0,26){
    	bool y=0;
    	FOR(j,0,N){
    		p[i][j]=0;
    		if(s[j]-'A'==i){
    			if(!y) p[i][j]=1;
    			y=1;
    		}
    		if(s[j]-'A'<i) y=0;
    		if(j) p[i][j]+=p[i][j-1];
		}
    }
    FOR(i,0,26){
    	bool y=0;
    	ROF(j,0,N){
    		suf[i][j]=0;
    		if(s[j]-'A'==i){
    			if(!y) suf[i][j]=1;
    			y=1;
    		}
    		if(s[j]-'A'<i) y=0;
    		if(j+1<N) suf[i][j]+=suf[i][j+1];
		}
    }
    
    while(Q--){
    	int l,r; cin>>l>>r;
    	l--; r--;
    	int ans=0;
    	FOR(i,0,26){
    		if(l) ans+=p[i][l-1];
    		if(r+1<N) ans+=suf[i][r+1];
    	}
    	cout << ans << endl;
    }
    

    return 0;
}
//Change your approach 