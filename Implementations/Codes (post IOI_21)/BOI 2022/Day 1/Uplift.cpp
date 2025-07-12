#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
typedef vector<int>vi; 
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()

typedef pair<int,int>pi;
typedef vector<pi>vpi; 
#define fi first
#define se second
 
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
 
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int INF=2e9;
 
 
 
void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


const int MX=1e5+10; 
vi mp(MX*3,-1); 

int main(){
	IO(); boost; 


	int M; 
	long long L; 
	cin>>M>>L; 

	if(!(L+MX>=0 && L+MX<sz(mp))) { cout << "impossible" << endl; return 0; }
	 
	FOR(i,-M,M+1){
		int n; cin>>n; 
		while(n--){
			vpi vec; 
			FOR(x,0,MX*2) if(mp[x]!=-1){
				vec.pb({x+i, mp[x]+1}); 
			}

			for(auto it: vec){
				int k=it.fi, x=it.se; 
				ckmax(mp[k],x); 
			}

			ckmax(mp[i+MX],1); 
		}
	}


	if(mp[L+MX]==-1) cout << "impossible" << endl; 
	else cout << mp[L+MX] << endl;

	


}