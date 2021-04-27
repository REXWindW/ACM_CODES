#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int main(){
    string s;
    cin>>s;
    int siz = s.size();
    if(siz==4){
        int tmp = 10*(s[0]-'0')+(s[1]-'0');
        if(tmp<22)cout<<20;
        else cout<<19;
        cout<<s[0]<<s[1]<<'-'<<s[2]<<s[3]<<endl;
    }
    else{
        cout<<s[0]<<s[1]<<s[2]<<s[3]<<'-'<<s[4]<<s[5]<<endl;
    }
}