#include<iostream>
#include<queue>
#include<vector>
#include<random>
#include<windows.h>
#include<time.h> 
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define rnd() rand() 
#define INF 0x7fffffff
int n = 5;//总楼层数
const int MAXN = 21;//楼层数组上限
int xx,yy;
bool tiaoshi;
int nowtime;

struct peo{//people
    int to;
    int weight;
    int naixin;
	int zhuangtai(int lc){//人的状态,1上楼人,-1下楼人
		if(to>lc) return 1;
		else return -1;
	}
};
int px,py;
peo gen(int lc){
    peo ret;
	ret.to = rnd()%n+1;//去哪儿
    while(ret.to==lc) ret.to = rnd()%n+1;
    ret.weight = rnd()%51+50;//50-100内随机体重 
    ret.naixin = nowtime + px + rnd()%(py-px+1);//耐心值在10到50内随机 
	return ret;
}

struct Elevator{
    queue<peo>member;
    int mi;
    const int max_weight = 600;//最大荷载600KG 
    int tot_weight;
	int zhuangtai;//电梯状态-1,0,1
    Elevator():zhuangtai(0),mi(1),tot_weight(0){}
	queue<peo> ren;
	int lc(){//得到楼层
		return mi/4+1;
	}
}elevator;

queue<peo>flr[MAXN];//每层的队列
bool up_botton[MAXN];
bool down_botton[MAXN];//夏季那个按钮

vector<peo> get(queue<peo>q){//get x th floor's people->to
    vector<peo> res;
    while(!q.empty()){
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

void show(){
    rep(i,1,62) cout<<"■";
	cout<<endl;
	int buquan;//用于补全空格 
	int siz;
	repb(i,n,1){
		// check_botton();//遍历每一层的队列来检查上下按钮 
		repb(j,4,1){//每层包含地板高4
			cout<<"■";
			int tmp_mi = (i-1)*4+j;//当前处理行数代表的米数
			if(tmp_mi==elevator.mi+3){
				buquan = 40;
				if(elevator.zhuangtai==-1){cout<<"电梯下行",buquan=40-8;}
				else if(elevator.zhuangtai==0){cout<<"电梯停止",buquan=40-8;}
				else if(elevator.zhuangtai==1){cout<<"电梯上行",buquan=40-8;}
				rep(i,1,buquan) cout<<" ";
			}
			else if(tmp_mi==elevator.mi+2){
				buquan = 40;
				rep(i,1,buquan) cout<<' ';
			}
			else if(tmp_mi==elevator.mi+1){
				vector<peo>vec = get(elevator.ren);//读到vector里面，并打印
				siz = vec.size(); 
				siz = min(10,siz);
				rep(k,0,siz-1){
					int to = vec[k].to;
					cout<<'F';
					if(to/10) cout<<to<<' ';
					else cout<<to<<' '<<' ';
				}
				buquan = 40-siz*4;//补全空格 
				rep(i,1,buquan) cout<<" ";
			}
			else if(tmp_mi==elevator.mi||tmp_mi==elevator.mi+4){
				//印电梯的地板
				rep(i,1,20) cout<<"==";
			} 
			else rep(i,1,20) cout<<"  ";
			//楼层队列部分
			vector<peo>vec =get(flr[i]);
			siz = vec.size();
			siz = min(siz,20);
			up_botton[i] = down_botton[i] = 0;
			rep(k,0,siz-1){
				if(vec[k].to>i) up_botton[i] = 1;
				if(vec[k].to<i) down_botton[i] = 1;
				if(up_botton[i]&&down_botton[i]) break;
			}
			if(j==4){
				if(up_botton[i]){cout<<"▲";buquan = 80-2;}
				else {cout<<"△";buquan = 80-2;}
				rep(i,1,buquan) cout<<' ';
			} 
			else if(j==3){
				if(down_botton[i]){cout<<"▼";buquan = 80-2;}
				else {cout<<"▽";buquan = 80-2;}
				rep(i,1,buquan) cout<<' ';
			}
			else if(j==2){
				rep(i,0,siz-1){
					int to = vec[i].to;
					cout<<"F";
					if(to/10) cout<<to<<' ';
					else cout<<to<<' '<<' ';
				}
				buquan = 80-siz*4;//补全空格  
				rep(i,1,buquan) cout<<' ';
			}
			else if(j==1){
				rep(i,1,40) cout<<"■";
			} 
			cout<<"■";
			cout<<endl;
		}
	}
	cout<<"此时电梯总荷载为"<<elevator.tot_weight<<"KG"<<endl; 
}

int maxp,minp;
void upd(){
	maxp = 0,minp = n+1;
	rep(i,1,n){
		if(!flr[i].empty()){//最高有人楼层
			maxp = max(maxp,i);
			minp = min(minp,i);
		}
	}
	vector<peo>vec;
	vec = get(elevator.ren);
	int siz = vec.size();
	rep(i,0,siz-1){
		maxp = max(maxp,vec[i].to);//电梯中的人的最高目标楼层
		minp = min(minp,vec[i].to);
	}
}

bool OK(int mi){//检查电梯是否到达楼层高度
	return (elevator.mi-1)%4==0;
}

void xiadianti(){//下电梯
	vector<peo>vec;
	while(!elevator.ren.empty()){
		peo tmp = elevator.ren.front();
		elevator.ren.pop();
		if(tmp.to!=elevator.lc()){//不下来 
			vec.push_back(tmp);
		}
		else{//to==这层的人下电梯 
			if(tiaoshi) cout<<"[调试]some one exit the elevator"<<endl;
			elevator.tot_weight -= tmp.weight;//下电梯后减去重量 
		}
	}
	int siz = vec.size();
	rep(i,0,siz-1){
		elevator.ren.push(vec[i]);
	}
}

void shangdianti(){//上电梯
	vector<peo>vec;
	while(!flr[elevator.lc()].empty()){
		peo tmp = flr[elevator.lc()].front();
		flr[elevator.lc()].pop();
		if(tmp.zhuangtai(elevator.lc())==elevator.zhuangtai){//上电梯
			if(elevator.tot_weight+tmp.weight<=elevator.max_weight){
				elevator.ren.push(tmp);
				elevator.tot_weight += tmp.weight;
				if(tiaoshi) cout<<"[调试]someone enter the elevator"<<endl;
			}
			else{
				vec.push_back(tmp);
				if(tiaoshi) cout<<"[调试]someone cannot enter : weight limit exceed"<<endl;
			}
		}
		else{//不上电梯，回到队列中去
			vec.push_back(tmp);
		}
	}
	int siz = vec.size();
	rep(i,0,siz-1) flr[elevator.lc()].push(vec[i]);
}

void shengcheng(int num){//随机生成num个人插入随机楼层
	rep(i,1,num){
		int loc = rnd()%n+1;
		flr[loc].push(gen(loc));
	}
}

void meinaixin(){//去除没耐心的人 
	vector<peo> vec;
	rep(i,1,n){
		vec.clear();
		while(!flr[i].empty()){
			peo tmp = flr[i].front();
			flr[i].pop();
			if(tmp.naixin>=nowtime){
				vec.push_back(tmp);
			}
			else{
				if(tiaoshi) cout<<"[调试]someone is out of patient and left"<<endl;
			} 
		}
		int siz = vec.size();
		rep(j,0,siz-1)
			flr[i].push(vec[j]);
	}
} 

void work(){
	Sleep(500);
	system("cls");
	show();
	cout<<"现在时间戳为"<<nowtime<<endl; 
	if(rnd()%xx==0) shengcheng(yy);//随机生成人到楼层--------------------这里调整生成速度 
	upd();//更新最高位置maxp和最低位置minp
	meinaixin();//清除没耐心的 
	if(OK(elevator.mi)){//检查是不是到了整楼层的高度
		xiadianti();//下电梯
		shangdianti();
		if(elevator.zhuangtai==1&&elevator.lc()>=maxp){//该换方向了
			elevator.zhuangtai = 0;//换方向的情况先把状态变成0,等下次判断
		}
		else if(elevator.zhuangtai==-1&&elevator.lc()<=minp){//换方向
			elevator.zhuangtai = 0;
		}
		else if(elevator.zhuangtai==0){//电梯从静止到启动
			if(maxp>elevator.lc()){
				elevator.zhuangtai=1;
				shangdianti();
			} 
			else if(minp<elevator.lc()){
				elevator.zhuangtai=-1;
				shangdianti();
			}
			//else elevator.zhuangtai = 0;
		}
	}
	elevator.mi+=elevator.zhuangtai;//电梯移动！
}

int main(){
	srand(time(0));
	//show();
	//system("pause");
	cout<<"设置有1/x的概率生成y个人,即平均每秒生成y/x个人:"<<endl<<"请输入两个正整数x和y(经测试,1/3概率生成2个人是刚刚好的)"<<endl; 
	cin>>xx>>yy;
	cout<<"设置乘客耐心值的随机范围px到py:"<<endl;
	cin>>px>>py;
	cout<<"输入电梯需要运行多长时间"<<endl;
	int tim;
	cin>>tim;
	cout<<"是否输出调试信息(1/0)"<<endl;
	cin>>tiaoshi;
	for(nowtime=0;nowtime<tim;nowtime++){
		work();
	}
	rep(i,1,40) cout<<'=';
	cout<<endl<<"程序运行结束"<<endl;
	rep(i,1,40) cout<<'='; 
	cout<<endl;
}