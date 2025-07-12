//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+5;

int nxtt[MX],prevv[MX];
bool cnt[MX]={false},cnt2[MX]={false};
bool used[MX]={false};

int32_t main(){
   boost;
   IO();
   int N,K; cin>>N>>K;

   
   /*memset(nxtt,-1,MX);
   memset(prevv,-1,MX);*/

   int f,s,l,bl;
   

   for(int i=0; i<N; i++){
   	int a,b; cin>>a>>b;
   	used[a]=used[b]=true;
   	cnt2[a]=1;
   	cnt[b]=1;
   	if(a==0){
   		s=b;
   	}
   	else nxtt[a]=b;

   	if(b==0){
   		bl=a;
   	}
   	else prevv[b]=a;
   }

   for(int i=1; i<=100000; i++)if(!cnt[i] && used[i]) {f=i;  break;}
   for(int i=1; i<=100000; i++)if(!cnt2[i] && used[i]) {l=i;  break;}

   //cout << f << ' ' << s << ' ' << bl << ' ' << l << endl;

   vi res(N);
   bool vis[100001]={false};
   int cur=f;
   int i=0,j=N-1;
   while(1){
   	res[i]=f;
   	f=nxtt[f]; i+=2;
   	if(i>=j) break;
   	res[j]=l;
   	l=prevv[l]; j-=2;
   	if(i>=j) break;
   }

   i=1; j=N-2;
   while(1){
   	res[i]=s;
   	s=nxtt[s]; i+=2;
   	if(i>=j) break;
   	res[j]=bl;
   	bl=prevv[bl]; j-=2;
   	if(i>=j) break;
   }

   cout << res[K-1] << endl;
	

   return 0;
}

