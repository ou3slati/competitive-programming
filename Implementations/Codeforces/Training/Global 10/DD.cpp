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

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	int N; cin>>N;
   	str s; cin>>s;
   	int sum=0;

   	int i=0,j=N-1;
   	while(j>=0 && s[j]==s[0]){
   		sum++; j--;
   	}
   	char c=s[0];
   	while(i<=j && s[i]==c){
   		sum++; i++;
   	}

   	int ans=sum/3; if(j<0) ans=ceil((ld)sum/3);
   	for(;i<=j;){
   		c=s[i];
   		sum=0;
   		while(i<=j && s[i]==c){
   			sum++; i++;
   		} 
   		ans+=sum/3;
   	}
   	cout << ans << endl;
   }
	

   return 0;
}

