//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 41;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}
#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

struct Point { 
    int x, y; 
}; 

bool equal(Point a, Point b){
	return a.x==b.x && a.y==b.y; 
}

int orientation(Point p, Point q, Point r){ 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val > 0)? 1: 2; 
}   

bool doIntersect(Point p1, Point q1, Point p2, Point q2){ 
	if(equal(p1,p2) || equal(p1,q2) || equal(q1,p2) || equal(q1,q2)) return 0; 

    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) return 1;
    return 0; 
} 




ld area(int x1, int y1, int x2, int y2, int x3, int y3){
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
  
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y){  
	ld A = area (x1, y1, x2, y2, x3, y3);
	ld A1 = area (x, y, x2, y2, x3, y3);
	ld A2 = area (x1, y1, x, y, x3, y3); 
	ld A3 = area (x1, y1, x2, y2, x, y);

	return (A == A1 + A2 + A3);
}

//-------------------

int N; 
vi X(MX), Y(MX); 

int main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N) cin>>X[i]>>Y[i];  


    vi vec(N); iota(all(vec),0); 

    int ans=0; 
    do{
    	int j=vec[0], k=vec[1], l=vec[2]; 

    	int flag=1;

    	FOR(idx,3,N){
    		int i=vec[idx];

    		if(!isInside(X[j],Y[j],X[k],Y[k],X[l],Y[l],X[i],Y[i])){
    			int f=1; //no intersection?

    			for(int m: {j,k,l}){
    				//i->m
    				Point p1={X[i],Y[i]}, q1={X[m],Y[m]};

    				Point p2={X[j],Y[j]}, q2={X[k],Y[k]}; 
    				f&=!doIntersect(p1,q1,p2,q2);

    				p2={X[k],Y[k]}, q2={X[l],Y[l]}; 
    				f&=!doIntersect(p1,q1,p2,q2);

    				p2={X[l],Y[l]}, q2={X[j],Y[j]}; 
    				f&=!doIntersect(p1,q1,p2,q2);
    			}

    			if(!f){flag=0; break;} 

    			if(isInside(X[i],Y[i],X[k],Y[k],X[l],Y[l],X[j],Y[j])) j=i; 
    			else if(isInside(X[j],Y[j],X[i],Y[i],X[l],Y[l],X[k],Y[k])) k=i; 
    			else l=i; 
    		}
    	}

    	ans+=flag; 

    }while(next_permutation(all(vec))); 

    cout << ans << endl;  

    /*struct Point p1 = {0, 0}, q1 = {5, 5}; 
    struct Point p2 = {5, 5}, q2 = {10, 5}; 
  
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; */

	/*if (isInside(0, 0, 20, 0, 10, 30, 10, 15))
		cout <<"Inside";
	else
		cout <<"Not Inside";*/




    return 0;
}
//Change your approach 