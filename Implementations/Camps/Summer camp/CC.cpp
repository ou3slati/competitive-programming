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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //up down right left

void IO(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif
}

int N; str s;
map <char,int> mp;
int X,Y;

void no(){
	cout << -1 << endl;
	exit(0);
}

int32_t main(){
   boost;
   //IO();
   mp['U']=0; mp['D']=1; mp['R']=2; mp['L']=3;
   cin>>N>>s>>X>>Y;
   int h[4]={0};
   for(int i=0; i<N; i++) h[mp[s[i]]]++;

   if(sz(s)<abs(X)+abs(Y)) no();
   if((sz(s)-abs(X)-abs(Y))%2==1) no();

   int x=0,y=0;
   for(int i=0; i<N; i++){
   	  x+=nx[mp[s[i]]];
   	  y+=ny[mp[s[i]]];
   }

   int a=X-x,b=Y-y;
   if(abs(a)%2==1 || abs(b)%2==1) no();

   int m,mm;
   if(a>0) m=3;
   else m=2;
   if(b>0) mm=1;
   else mm=0;

   int sum=0;
   if(m==3) sum+=h[2]*2;
   else if(m==2) sum+=h[];


   /*a=abs(a)/2; b=abs(b)/2;
   int cnt=0,cntt=0;
   //cout << m  << ' ' << mm << ' ' << a << ' ' << b << endl;

   int i=0;
   int res=INF;
   for(int j=-1; j<N; j++){
   	while(j<N-1 && (cnt<a||cntt<b)){
   		j++;
   		if(s[j]==m) cnt++;
   		else if(s[j]==mm) cntt++;
   	}
   	//cout << j << endl;
      while(cnt>=a && cntt>=b){
         res=min(res,j-i+1);
         if(s[i]==m) cnt--;
         else if(s[i]==mm) cntt--;
         i++;
      }
   }
   if(res==INF) no();
   cout << res << endl;*/



   return 0;
}


