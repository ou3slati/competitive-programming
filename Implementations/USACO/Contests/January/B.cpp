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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int32_t main() {
    boost; IO();

    int N; cin>>N;
    int odd=0,even=0;
    FOR(i,0,N){
    	int x; cin>>x;
    	if(x&1) odd++;
    	else even++;
    }

	while(odd>even){
		odd-=2;
		even++;
	}
	ckmin(even,odd+1);
    
    cout << even+odd << endl;
    

    return 0;
}
//Change your approach 