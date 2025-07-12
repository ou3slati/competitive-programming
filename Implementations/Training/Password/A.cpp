#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef string str; 

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmin(int &x, int y){x=min(x,y);}
//------------------------------------

int query(string S);

int alp;

void upd(str &s, int idx, char c){
    str ss;
    FOR(i,0,sz(s)+1){
        if(i==idx) ss+=c;
        if(i<sz(s)) ss+=s[i];
    }
    s=ss; 
}

bool check(str s, int idx, char c){
    str ss; 
    FOR(i,0,min(idx,sz(s))) ss+=s[i];
    ss+=c; 

    FOR(i,idx,sz(s)) if(s[i]==c) ss+=s[i];

    return query(ss)==sz(ss);
}

str guess(int N, int S){
    alp=S; 
    vi nb(alp,0);
    for(char c='a'; c<=char('a'+alp-1); c++){
        str s;
        FOR(i,0,N) s+=c; 
        nb[c-'a']=query(s);
    }

     
    int idx=0;
    FOR(i,0,alp) if(nb[i]>nb[idx]) idx=i; 

    if(N<=3500) idx=0; 

    str cur;
    FOR(i,0,nb[idx]) cur+=char(idx+'a');

    FOR(i,0,alp) if(i!=idx){
        char c=i+'a';
        while(nb[i]--){
            int l=0,r=sz(cur),ind=-1;
            while(l<=r){
                int m=(l+r)/2;
                if(check(cur,m,c)){
                    ind=m; 
                    l=m+1;
                }
                else r=m-1;
            }
            if(ind==-1){
            	return ".";
            }

            upd(cur,ind,c);

            //cout << cur << endl;
        }
    }
    //cout << sz(cur) << endl;
    return cur; 
}