//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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
int A[300],B[300];

int t[301];
int cnt=0;

int solve(int i){
	if(i==N){
		for(int idx=0; idx<N; idx++){
			int ii=idx,j=idx+1;
			while(ii>=0 && t[ii]<=t[idx]) ii--;
			ii++;
			while(j<N && t[j]<t[idx]) j++;
			j--;
			if(abs(abs(idx-ii)-abs(idx-j))>2) return 0;
		}
		return 1;
	}
	int ans=0;
	for(int j=A[i]; j<=B[i]; j++){
		t[i]=j; 
		ans=(ans+solve(i+1));
	}
	return ans;
}


int main(){
   boost;
   IO();

   cin>>N;
   for(int i=0; i<N; i++) cin>>A[i]>>B[i];

   cout << solve(0) << endl;
   
	

   return 0;
}

