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
    freopen("outputt.txt", "w", stdout);
#endif
}



int32_t main(){
   boost;
   IO();
   int N,S; cin>>N>>S; S--;

   int d[N];
   set<pi,greater<pi>> st;

   for(int i=0; i<N; i++){
      cin>>d[i];
      st.insert({d[i],i});
   }


   int lvl[N];
   int l=S,r=S;
   int cnt=0; lvl[S]=0;
   while(1){
      if(l==0 && r==N-1) break;
      if(l&&(r==N-1 || d[r+1]>d[l-1])){
         l--;
         lvl[l]=++cnt;
      }
      else if(r!=N-1 && (l==0 || d[r+1]<d[l-1])){
         r++;
         lvl[r]=++cnt;
      }
   }

   int Q; cin>>Q;
   while(Q--){
      char op;cin>>op;
      if(op=='E'){
         int i,nwi; cin>>i>>nwi; i--;
         cnt=0;
         st.erase({d[i],i});
         vpi vec;
         int nw;
         for(auto it: st){
            cnt++;
            if(cnt==nwi){
               nw=it.fi;
               break;
            }
            vec.pb(it);
         }

         for(auto x: vec){
            st.erase(x);
            st.insert({x.fi+1,x.se});
            d[x.se]++;
         }

         d[i]=nw+1;
         st.insert({d[i],i});

         l=S;r=S;
         cnt=0;
         while(1){
            if(l<=0 && r>=N-1) break;
            if(l>0&&(r==N-1 || (r<N-1 && d[r+1]>d[l-1]))) {
               l--;
               lvl[l]=++cnt;
            }
            else if(r<N-1 && (l==0 || (l>0 && d[r+1]<d[l-1]))){
               r++;
               lvl[r]=++cnt;
            }
         }

      }
      else{
         int i; cin>>i; i--;
         cout << lvl[i] << endl;
      }
   }


   return 0;
}


/*
5 2
5 2 3 1 4
100
E 2 3
F 2
F 5
F 1
E 3 3
E 4 3
E 4 2
E 4 1
F 3
E 2 4
E 5 2
E 2 1
F 4
E 3 1
E 5 1
E 3 1
E 5 1
F 1
E 4 1
F 1
F 2
E 5 1
E 1 1
F 3
E 5 1
F 4
F 2
E 3 3
F 3
E 4 3
E 1 1
E 2 1
E 1 1
F 5
F 1
F 2
F 5
E 4 2
E 4 1
E 1 1
F 5
F 3
E 3 1
F 5
F 5
F 2
F 2
E 4 1
E 3 1
E 1 1
E 2 2
E 2 1
E 1 1
E 5 2
E 3 2
F 3
F 4
F 5
E 2 1
F 2
F 2
E 4 1
F 4
F 2
F 5
F 2
E 2 1
E 1 1
F 1
E 3 3
F 1
E 5 4
E 3 2
F 2
F 5
F 1
E 4 4
E 4 1
E 1 1
F 5
F 1
F 1
F 1
F 3
F 4
F 3
E 5 3
E 5 1
E 1 1
E 2 2
E 5 2
F 5
E 5 1
E 2 2
F 5
E 1 1
F 5
E 5 1
E 2 2
F 1



*/
