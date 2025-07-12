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

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MX=1500;
int N; 
int g[MX][MX];

int solveR(int i){
	int a=0,b=0;
	for(int j=0; j<N; j+=2){
		a+=g[i][j];
		if(i+1<N) a+=g[i+1][j];
	}
	for(int j=1; j<N; j+=2){
		b+=g[i][j];
		if(i+1<N) b+=g[i+1][j];
	}
	return max(a,b);
}

int solveC(int j){
	int a=0,b=0;
	for(int i=0; i<N; i+=2){
		a+=g[i][j];
		if(j+1<N) a+=g[i][j+1];
	}
	for(int i=1; i<N; i+=2){
		b+=g[i][j];
		if(j+1<N) b+=g[i][j+1];
	}
	return max(a,b);
}

int32_t main() {
    boost; IO();

    cin>>N;
   
    FOR(i,0,N) FOR(j,0,N) cin>>g[i][j];

    int ans=0;
    
	int val=0;
	for(int x=0; x<N; x+=2) val+=solveR(x);
	ckmax(ans,val);
	//cout << val << endl;
	
	val=0;
	for(int y=0; y<N; y+=2) val+=solveC(y);
	ckmax(ans,val);


    
    cout << ans << endl;
    
    

    return 0;
}
//Change your approach 