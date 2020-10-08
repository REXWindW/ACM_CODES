#include<iostream>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
int main(){
    rep(i,0,7){
        if(i%2==0)
            rep(j,1,8){
                cout<<"\"";
                cout<<(char)('a'+i);
                cout<<j<<"\",";
            }
        else
            repb(j,8,1){
                cout<<"\"";
                cout<<(char)('a'+i);
                cout<<j<<"\",";;
            }
    }
}