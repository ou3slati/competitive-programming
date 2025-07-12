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


const int MX=20;
int N;
vi a(MX),b(MX);

int memo[(1)<<(MX)];

int solve(int m){
	if((m)==((1)<<(N))-1) return 1;
	int &ind=memo[m];
	if(ind!=-1) return ind;

	int nb=0;
	FOR(i,0,N) if(((m)&((1)<<(i)))) nb++;

	int ans=0;
	FOR(i,0,N) if(!((m)&((1)<<(i)))){
		if(b[nb]>=a[i]){
			ans+=solve((m)|((1)<<(i)));
		}
	}
	
	return ind=ans;
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N) cin>>a[i];
    FOR(i,0,N) cin>>b[i];
	
	memset(memo,-1,sizeof(memo));
	cout << solve(0) << endl;    

    return 0;
}
//Change your approach 