#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

//-----------------------------------------------------

int main(){

	/*vi v={1,4,17,400,199578};

	vi vec;
	FOR(i,1,5){
		FOR(j,0,v[i]) vec.pb(i+1);
	}
	random_shuffle(all(vec));
	vec.pb(1);

	int N=2e5;
	cout << 2e5 << endl;
	for(auto x: vec) cout << x << endl;

	int cnt=0;
	FOR(i,1,N){
		if(vec[i]!=vec[i-1] || i==N-1) cnt++;
	}
	cout << cnt << endl;*/

	int ans=0;
	FOR(i,1,51){
		ans+=i*(50-i+1);
	}
	cout << ans << endl;

}