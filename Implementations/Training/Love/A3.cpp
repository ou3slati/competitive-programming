#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef string str; 

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmin(int &x, int y){x=min(x,y);}
//------------------------------------


int main(){
	int N; cin>>N;

	if(N&1){
		cout << -1 << endl;
		return 0;
	}

	map<string,int>mp;
	int cnt=-1;
	vi nxt(N);
	FOR(i,0,N){
		str s,t; cin>>s>>t;
		if(!mp.count(s)) mp[s]=++cnt; 
		if(!mp.count(t)) mp[t]=++cnt; 
	
		int u=mp[s],v=mp[t];
		nxt[u]=v;
	}

	int ans=0;
	vi vis(N,0);
	FOR(i,0,N) if(!vis[i]){
		int n=0,cur=i;
		while(!vis[cur]){
			n++;
			vis[cur]=1;
			cur=nxt[cur];
		}
		if(n!=2) ans+=(n+1)/2;
	}
	cout << ans << endl;
}