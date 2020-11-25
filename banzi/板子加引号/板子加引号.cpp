#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 486;
string s;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    for(int i=1;i<=200;i++){
        getline(cin,s);
        if(s=="rexwind") return 0;
        cout<<"\""<<s<<"\","<<endl;
    }
}