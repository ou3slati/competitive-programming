#include "combo.h"
#include <bits/stdc++.h>
using namespace std; 

#define pb push_back
#define sz(v) (int)v.size()
typedef vector<int>vi; 
typedef string str;
#define FOR(i,a,b) for(int i=a; i<b; i++)
//-------------------------------------------------

string guess_sequence(int N) {
    str ans;

    str s="AB";
    if(press(s)){
        s="A";
        if(press(s)) ans="A";
        else ans="B";
    }
    else{
        s="X";
        if(press(s)) ans="X";
        else ans="Y";
    }

    vector<char> vec;
    for(char c: {'A','B','X','Y'}) if(c!=ans[0]) vec.pb(c);

    FOR(i,1,N){
        if(i<N-1){
            str s=ans+vec[0]+vec[0];
            s+=ans+vec[0]+vec[1];
            s+=ans+vec[0]+vec[2];
            s+=ans+vec[1];

            int x=press(s)-sz(ans);
            if(x==1) ans+=vec[1];
            else if(x==2) ans+=vec[0];
            else ans+=vec[2];
        }else{
            str s=ans+vec[0];
            if(press(s)-sz(ans)>0) ans+=vec[0];
            else{
                s=ans+vec[1];
                if(press(s)-sz(ans)>0) ans+=vec[1];
                else ans+=vec[2];
            }
            
        }
    }
    return ans; 
}
