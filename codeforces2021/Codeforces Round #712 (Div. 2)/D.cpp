#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//cout.flush();
int a[114][514];
int n,x;
int ji = 0;
int cji,cjj,coi,coj;
int jj,oo;
void solve(){
    cin>>n;
    cji=1,cjj=1;
    coi=1,coj=2;
    int k;
    for(k=1;k<=n*n;k++){
        cin>>x;
        if(k==1){
            jj = x%3+1;
            //cout<<"jj"<<jj<<endl;
        }
        if(oo==0&&x==jj) oo = x%3+1;
        //确定jj和oo,奇数偶数上先让他们其中的一个放满
        //有一个放满以后，直接随便乱放了
        if(x!=jj){//让这个尽可能放满
            cout.flush();
            cout<<jj<<' '<<cji<<' '<<cjj<<endl<<endl;
            a[cji][cjj] = jj;
            cjj+=2;
            if(cjj>n){
                cji++;
                cjj = (cji-1)%2+1;
            }
        }
        else if(x!=oo){
            cout.flush();
            cout<<oo<<' '<<coi<<' '<<coj<<endl<<endl;
            a[coi][coj] = oo;
            coj+=2;
            if(coj>n){
                coi++;
                coj = coi%2+1;
            }
        }
        //检查是否放满，放满后随便放
        if(coi>n||cji>n){
            k++;break;
        }
    }
    if(!oo){//如果给的全都是一种数字，特判随便选一个做oo
        oo = jj%3+1;
    }
    int othe = 6-jj-oo;//找出第三个数字
    //之后处理放满的情况
    int fm;
    if(cji>n) fm = 1;
    else fm = 0;
    for(;k<=n*n;k++){
        cin>>x;
        if(fm==1){//偶数没放满的情况
            if(x==oo){
                cout.flush();
                cout<<othe<<' '<<coi<<' '<<coj<<endl<<endl;
                a[coi][coj] = othe;
            }
            else{
                cout.flush();
                cout<<oo<<' '<<coi<<' '<<coj<<endl<<endl;
                a[coi][coj] = oo;
            }
            coj+=2;
            if(coj>n){
                coi++;
                coj = coi%2+1;
            }
        }
        else{//奇数没放满的情况
            if(x==jj){
                cout.flush();
                cout<<othe<<' '<<cji<<' '<<cjj<<endl<<endl;
                a[cji][cjj] = othe;
            }
            else{
                cout.flush();
                cout<<jj<<' '<<cji<<' '<<cjj<<endl<<endl;
                a[cji][cjj] = jj;
            }
            cjj+=2;
            if(cjj>n){
                cji++;
                cjj = (cji-1)%2+1;
            }
        }
    }
    //debug
    /*
    cout<<"check matrix"<<endl;
    rep(ii,1,n){
        rep(jj,1,n){
            cout<<a[ii][jj]<<' ';
        }
        cout<<endl;
    }
    */
}

int main(){
    solve();
}