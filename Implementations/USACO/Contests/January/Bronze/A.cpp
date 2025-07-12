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


int32_t main() {
    boost; IO();
    
    map<char,char>mp;
    for(char c='a'; c<='z'; c++){
    	char cc; cin>>cc;
    	mp[cc]=c;
    }
    string s; cin>>s;
    vi vec;
    for(auto x: s){
    	vec.pb(mp[x]-'a');
    }
    int ans=1;
    FOR(i,1,sz(vec)) if(vec[i]<=vec[i-1]) ans++;
    cout << ans << endl;

    return 0;
}
//Change your approach 