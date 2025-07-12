#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmin(int &x, int y){x=min(x,y);}
//------------------------------------
	

int main(){
	int N; cin>>N; 
	vi a(N);
	FOR(i,0,N){
		char c; cin>>c;
		a[i]=1;
		if(c=='T') a[i]=-1;
	}
	int Q; cin>>Q;
	while(Q--){
		int l,r; cin>>l>>r;
		l--; r--;

		vi vis(N,0);
		int ans=0,cur=0;	
		FOR(i,l,r+1){
			if(!vis[i]) cur+=a[i];
			if(cur<0){
				cur=0;
				vis[i]=1;
				ans++;
			}
		}	
		cur=0;
		ROF(i,l,r+1){
			if(!vis[i]) cur+=a[i];
			if(cur<0){
				cur=0;
				vis[i]=1;
				ans++;
			}
		}

		cout << ans << endl;
	}
}

/*

11
CCCTTTTTTCC
3
1 11
4 9
1 6

*/