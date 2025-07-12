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
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};


int MXN=100000+10; //nb of sets
vi p(MXN,-1), setSize(MXN,0);
multiset <int> s;
int N;

void make_set(int v){
   p[v]=v;
   setSize[v]=1;
   s.insert(1);
}

int find_set(int v){
   return p[v]==v ? v: p[v]=find_set(p[v]);
}

void union_set(int u, int v){
   u=find_set(u); v=find_set(v);
   p[u]=find_set(v);
   s.erase(s.find(setSize[u]));
   setSize[v]+=setSize[u];
   if(v!=N)s.insert(setSize[v]);
}

int size_of_set(int u){
   return setSize[find_set(u)];
}


int32_t main(){
   boost;
   int TC; cin >>TC;
   while(TC--){
      s.clear(); p.assign(MXN,-1), setSize.assign(MXN,0);
      cin>>N;
      int t[N];
      map<int,int> mp;
      for (int i=0; i<N;i++){
         cin>>t[i];
         mp[t[i]]=i;
      }
      for (int i=0; i<=N;i++) make_set(i);
      setSize[N]=0;
      int mx=1;
      bool yes=true;

      for (int i=1; i<=N; i++){
         int pos=mp[i];
         auto it=s.end(); it--;
         mx=*it;
         //cout << pos << endl;
         if(size_of_set(pos)==mx){
            union_set(pos,pos+1);
         }
         else{
            yes=false;
            break;
         }
         if(!yes) break;
         //cout << mx << endl;
      }
      if(yes) cout <<"Yes" << endl;
      else cout << "No" << endl;
   }


   return 0;
}

