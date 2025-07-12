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

int N; 
str s;
int X,Y;

void no(){
	cout << -1 << endl;
	exit(0);
}

int32_t main(){
   boost;
   IO();
   cin>>N>>s>>X>>Y;
   if(sz(s)<abs(X)+abs(Y)) no();

   int up[N],down[N],right[N],left[N];

   for(int i=0;i<N; i++){
   	up[i]=down[i]=right[i]=left[i]=0;
   	if(s[i]=='U') up[i]++;
   	else if(s[i]=='D') down[i]++;
   	else if(s[i]=='R') right[i]++;
   	else left[i]++;
   	if(i){
   		right[i]+=right[i-1];
   		up[i]+=up[i-1];
   		down[i]+=down[i-1];
   		left[i]+=left[i-1];
   	}
   }

   int l=0,r=N;
   int res=INF;

   while(l<=r){
   	int m=(l+r)/2;
   	bool yy=false;
   	for(int i=0; i<N-m+1; i++){
   		int R=0,L=0,D=0,U=0;
   		if(i){R+=right[i-1]; L+=left[i-1]; U+=up[i-1]; D+=down[i-1];}
   		R+=right[N-1]-right[i+m-1];
   		L+=left[N-1]-left[i+m-1];  
   		U+=up[N-1]-up[i+m-1]; 
   		D+=down[N-1]-down[i+m-1];

   		int x=X-(R-L);
   		int y=Y-(U-D);
   		if(!(m<abs(x)+abs(y)||(m-abs(x)-abs(y))%2==1)) yy=true;
   	}
   	if(yy){
   		res=min(res,m); r=m-1;
   	}
   	else l=m+1;
   }
   if(res==INF) no();
   cout << res << endl;

   return 0;
}

