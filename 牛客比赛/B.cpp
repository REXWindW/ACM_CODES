#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 2020;
string s;
queue< vector<char> >q;
void clear(queue<vector<char>>& q) {
	queue<vector<char>> empty;
	swap(empty, q);
}

void qout(){
    cout<<"wow"<<endl;
    vector<vector<char>> tmpp;
    while(!q.empty()){
        vector<char> tmp = q.front();
        tmpp.push_back(tmp);
    }
    cout<<" (";
    rep(i,0,tmpp.size()-1){
        rep(j,0,tmpp[i].size()) cout<<tmpp[i][j];
        if(i!=tmpp.size()-1) cout<<' ';
    }
    cout<<')';
}

void work(){
    int siz = s.size();
    cout<<siz<<endl;
    rep(i,0,siz-1){
        cout<<'['<<i<<']'<<endl;
        cout<<q.size()<<endl;
        //cout<<i<<endl;
        if(isupper(s[i])){//统计大小写
            vector<char> tmp;
            tmp.push_back(s[i]);
            i++;
            while(i<siz&&islower(s[i])){
                tmp.push_back(s[i]);
                i++;
            }
            //if(tmp.size()==1)//单个大写情况
            if(i==siz){//到行末尾情况
                cout<<"reach the end"<<endl;
                q.push(tmp);
                if(q.size()>1) qout();
                else rep(i,0,tmp.size()-1) cout<<tmp[i];
                clear(q);//清空队列
            }
            else if(s[i]==' '){//空格，这个单词可以了
                q.push(tmp);
            }
            else if(!isupper(s[i])){//句号打断，加入队列后输出
                q.push(tmp);
                if(q.size()>1) qout();
                else//太少了不能缩写
                    rep(i,0,tmp.size()-1) cout<<tmp[i];
                cout<<s[i];//这个符号记得输出
                clear(q);//清空队列
            }
            else{//单词中大写字母打断的情况
                if(q.size()>1) qout();
                else{
                    vector<char> tmpv = q.front();
                    rep(i,0,tmpv.size()-1) cout<<tmpv[i];
                }
                clear(q);
                rep(i,0,tmp.size()-1) cout<<tmp[i];
            }
        }
        cout<<s[i];
        i++;
    }
    if(!q.empty()){
        if(q.size()>1){
            qout();
        }
        else{
            cout<<"check"<<endl;
            vector<char> tmp = q.front();
            rep(i,0,tmp.size()-1) cout<<tmp[i];
        }
    }
    clear(q);
}
int main(){
	while(getline(cin,s)){
        work();
        cout<<endl;//换行注意
    }
}