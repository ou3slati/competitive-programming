#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void ckmin(int &x, int y){x=min(x,y);}
void ckmax(int &x, int y){x=max(x,y);}

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
//------------------------------------------------//

const int MX=2e6+10;
const int INF=1e9;
int N,M,T; 
vi a(MX);

int v[1005][1005];

void compute(){
	FOR(i,1,N+1){
		int r=-1,cur=0;
		FOR(j,i,N+1){
			if(a[j]<=T){
				ckmax(r,j+T-a[j]);
			}
			if(j<=r) cur++;
			v[i][j]=cur;
		}
	}
	FOR(i,1,N+1) v[i][N+1]=v[i][N];
	v[N+1][N+1]=0;
}

int main(){
	IO();

	cin>>N>>M>>T;
	FOR(i,1,N+1) cin>>a[i];
	
	if(M==1){
		FOR(i,0,N) a[i]=a[i+1];
		set<int>s;
		vi val(N+1,0);
		ROF(i,0,N){
			if(i+1<N) val[i]+=val[i+1];
			if(a[i]<=T){
				int j=i+T-a[i];
				val[i]++;
				while(sz(s) && *s.begin()<=j){
					val[i]++;
					s.erase(s.begin());
				}
			}
			else{
				s.insert(i);
			}
		}
		//FOR(i,0,N) cout << val[i] << ' '; cout << endl;

		int ans=INF,r=-1,cur=0; 
		FOR(i,0,N){
			if(a[i]<=T){
				int j=i+T-a[i];
				ckmax(r,j);
			}
			if(i<=r) cur++;

			ckmin(ans,cur+val[i+1]);
		}
		cout << ans << endl;
	}
	else{

		compute();
		/*FOR(i,1,N+1){
			FOR(j,i,N+1) cout << v[i][j] << ' '; cout << endl;
		}*/

		int dp[N+2][M+2];
		FOR(i,0,N+2) FOR(j,0,M+2) dp[i][j]=INF; 
		dp[0][0]=0;
		FOR(i,1,N+2) FOR(k,1,M+2){
			FOR(j,0,i) ckmin(dp[i][k],dp[j][k-1]+v[j+1][i]);
		}
		cout << dp[N+1][M+1] << endl;
	}
	
}

