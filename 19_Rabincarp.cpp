#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main(){
    string s,t;
    cin>>s>>t;
    string S = "abcdefghijklmnopqrstuvwxyz";
    map<char,int> M;
    for(int i=0;i<S.size();i++){
         M[S[i]] = i+1;
    }
    int n = s.size();
    int m = t.size();
    int phash = 0;
    vector<int> strhash(n,0);
    for(int i=0;i<m;i++){
        phash += M[t[i]]*binpow(10,(m-1)-i);
        strhash[0] += M[s[i]]*binpow(10,(m-1)-i);
    }
    cout<<phash<<endl;
    vector<int> match;
    for(int i=0;i<n;i++){
         if(i!=0){
              strhash[i] = (strhash[i-1] - M[s[i-1]]*binpow(10,m-1))*10 + M[s[(m-1)+i]];
         }
        cout<<strhash[i]<<endl;
         if(strhash[i] == phash){
               int f = 1;
               for(int j=0;j<m;j++){
                    if(s[j+i] != t[j]){
                         f=0;
                         break;
                    }
               }
               if(f==1){
                    match.push_back(i);
               }
         }
    }
    cout<<match.size();
    for(int x : match){
        cout<<x<<" ";
    }
    return 0;
}