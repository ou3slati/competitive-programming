#include <bits/stdc++.h>
using namespace std; 


typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//--------------------------------------------------

void ckmin(ll &x, ll y){x=min(x,y);}

const int MX=1e5+10;
int N,P; 
vi a;


vector<ll> memo(MX,-1);
ll solve(int i){
	if(i==N) return 0;
	ll &ind=memo[i];
	if(ind!=-1) return ind; 

	ll ans;
	//Discount
	ans=solve(i+1)+(a[i]*P)/100;
	//Free
	if(i+2<N) ckmin(ans,solve(i+3)+a[i+1]+a[i+2]);

	return ind=ans; 
}

int main(){
	IO();

	cin>>N>>P; P=100-P;
	
	a.resize(N);
	FOR(i,0,N) cin>>a[i];
	sort(all(a)); //reverse(all(a));

	cout << solve(0) << endl;

	/*ll ans=0;
	for(int i=0; i<N;){
		if(i+2<N){
			if(a[i]+a[i+1] < ((a[i]+a[i+1]+a[i+2])*P)/100 ){
				ans+=a[i]+a[i+1];
				i+=3;
			}
			else{
				ans+=(a[i]*P)/100;
				i++;
			}
		}
		else{
			ans+=(a[i]*P)/100;
			i++;
		}
	}
	cout << ans << endl;*/
}