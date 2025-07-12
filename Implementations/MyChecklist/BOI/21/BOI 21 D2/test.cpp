#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
typedef pair<int,int> pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)

void ckmin(int &x, int y){x=min(x,y);}

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
//------------------------------------------------//



int main(){
	IO();

	int N; cin>>N;
	set<pi>s;
	FOR(i,1,N+1) FOR(j,i+1,N+1) s.insert({i,j});
	
	int ans=0;
	while(sz(s)){
		ans++;
		vi vis(N+1,0);
		vpi vec;
		for(auto it: s){
			int u=it.fi,v=it.se;
			if(!vis[u] && !vis[v]){
				vec.eb(it);
				vis[u]=vis[v]=1;
			}
		}
		for(auto x: vec) s.erase(x);
	}
	cout << ans << endl;

}

