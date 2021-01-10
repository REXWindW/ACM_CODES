#include<iostream>
#include<queue>
#include<vector>
#include<random>
#include<windows.h>
#include<time.h> 
#include <fstream>
#include<cstring> 
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define rnd() rand() 
#define INF 0x7fffffff

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
int n = 10;//总楼层数
const int MAXN = 21;//楼层数组上限
int xx,yy;
bool tiaoshi;
int nowtime;
bool flag[10]; 
string gz[10]={
"", 
"[电梯超载规则]  如若电梯内乘客的体重总和超过电梯最大承重,则电梯超载.",
"[电梯掉头规则]  如果电梯运行的反方向有人按动电梯按钮,电梯不会掉头.",//2
"[乘客排队规则]  乘客在每个楼层会排队,上电梯时遵循先来后到的规则.", 
"[乘客耐心规则]  乘客等待会消耗耐心值,耐心值消耗殆尽以后,会放弃排队离开队列.",//4
"[乘客礼让规则]  一个人进入电梯若超载,会继续检查下一个人的体重是可以进入电梯.",
"[乘客生成规则]  每个时间节点按照给定期望y/x生成乘客,体重和耐心值在设定范围内随机."
};

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
	flag[6] = 1;
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
    rep(i,1,62) cout<<"█";
	cout<<endl;
	int buquan;//用于补全空格 
	int siz;
	repb(i,n,1){
		// check_botton();//遍历每一层的队列来检查上下按钮 
		repb(j,4,1){//每层包含地板高4
			cout<<"█";
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
				rep(i,1,40) cout<<"█";
			} 
			cout<<"█";
			cout<<endl;
		}
	}
	cout<<"[时间"<<nowtime<<"]此时电梯总荷载为"<<elevator.tot_weight<<"KG"<<endl;
	cout<<endl;
	cout<<"[电梯规则栏]"<<endl;
	rep(i,1,62) cout<<"█";
	cout<<endl<<endl;
	rep(i,1,6){
		cout<<"    ";
		if(flag[i]) cout<<"√    ";
		else cout<<"Ｘ    ";
		cout<<gz[i]<<endl;
	}
	cout<<endl;
	rep(i,1,62) cout<<"█";
	cout<<endl; 
}

int maxp,minp;
void upd(){
	maxp = 0,minp = n+1;
	rep(i,1,n){
		if(!flr[i].empty()){//最高有人楼层
			flag[3] = 1;
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

void xiadianti(ofstream& fout){//下电梯
	vector<peo>vec;
	while(!elevator.ren.empty()){
		peo tmp = elevator.ren.front();
		elevator.ren.pop();
		if(tmp.to!=elevator.lc()){//不下来 
			vec.push_back(tmp);
		}
		else{//to==这层的人下电梯 
			fout<<"["<<nowtime<<"]有人在"<<elevator.lc()<<"层下电梯"<<endl;
			elevator.tot_weight -= tmp.weight;//下电梯后减去重量 
		}
	}
	int siz = vec.size();
	rep(i,0,siz-1){
		elevator.ren.push(vec[i]);
	}
}

void shangdianti(ofstream& fout){//上电梯
	vector<peo>vec;
	while(!flr[elevator.lc()].empty()){
		peo tmp = flr[elevator.lc()].front();
		flr[elevator.lc()].pop();
		if(tmp.zhuangtai(elevator.lc())==elevator.zhuangtai){//上电梯
			if(elevator.tot_weight+tmp.weight<=elevator.max_weight){
				elevator.ren.push(tmp);
				elevator.tot_weight += tmp.weight;
				fout<<"["<<nowtime<<"]有人在"<<elevator.lc()<<"楼进入了电梯"<<endl;
			}
			else{
				vec.push_back(tmp);
				fout<<"["<<nowtime<<"]有人在"<<elevator.lc()<<"楼因为电梯超载而不能进入电梯"<<endl;
				flag[1]=flag[5] = 1;
			}
		}
		else{//不上电梯，回到队列中去
			vec.push_back(tmp);
		}
	}
	int siz = vec.size();
	rep(i,0,siz-1) flr[elevator.lc()].push(vec[i]);
}

void shengcheng(int num,ofstream& fout){//随机生成num个人插入随机楼层
	peo tmp;
	rep(i,1,num){
		int loc = rnd()%n+1;
		flr[loc].push(tmp=gen(loc));
		fout<<"["<<nowtime<<"]在"<<loc<<"楼生成了一个目标为"<<tmp.to<<"楼,耐心值"<<tmp.naixin-nowtime<<"的人"<<endl; 
	}
}

void meinaixin(ofstream& fout){//去除没耐心的人 
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
				fout<<"["<<nowtime<<"]在"<<i<<"楼有一个人因为没耐心而离开了"<<endl;
				flag[4] = 1;
			} 
		}
		int siz = vec.size();
		rep(j,0,siz-1)
			flr[i].push(vec[j]);
	}
} 

void work(ofstream& fout){
	Sleep(300);
	system("cls");
	show();
	if(nowtime!=0)fout<<endl;
	memset(flag,0,sizeof(flag));
	fout<<"<<<时间戳"<<nowtime<<">>>"<<endl;
	fout<<"["<<nowtime<<"]电梯中有"<<elevator.ren.size()<<"人,总荷载为"<<elevator.tot_weight<<"KG"<<endl; 
	if(rnd()%xx==0) shengcheng(yy,fout);//随机生成人到楼层--------------------这里调整生成速度 
	upd();//更新最高位置maxp和最低位置minp
	meinaixin(fout);//清除没耐心的 
	if(OK(elevator.mi)){//检查是不是到了整楼层的高度
		xiadianti(fout);//下电梯
		shangdianti(fout);
		if(elevator.zhuangtai==1&&elevator.lc()>=maxp){//该换方向了
			elevator.zhuangtai = 0;//换方向的情况先把状态变成0,等下次判断
		}
		else if(elevator.zhuangtai==-1&&elevator.lc()<=minp){//换方向
			elevator.zhuangtai = 0;
		}
		else if(elevator.zhuangtai==0){//电梯从静止到启动
			if(maxp>elevator.lc()){
				elevator.zhuangtai=1;
				shangdianti(fout);
			} 
			else if(minp<elevator.lc()){
				elevator.zhuangtai=-1;
				shangdianti(fout);
			}
			//else elevator.zhuangtai = 0;
		}
	}
	if(elevator.zhuangtai==0){
		fout<<"["<<nowtime<<"]电梯在"<<elevator.lc()<<"楼处于停止状态"<<endl; 
	}
	else{
		fout<<"["<<nowtime<<"]电梯从高度"<<elevator.mi<<"移动到"<<elevator.mi+elevator.zhuangtai<<endl; 
		if(minp<elevator.lc()) flag[2] = 1;
	}
	elevator.mi+=elevator.zhuangtai;//电梯移动！
}

int main(){
	ofstream fout("out.txt");
	srand(time(0));
	//show();
	//system("pause");
	cout<<"[注意]运行日志输出到同目录下的out.txt中"<<endl; 
	cout<<"设置楼层数n(2<=n<=20)"<<endl;
	cin>>n;
	cout<<"设置有1/x的概率生成y个人,即平均每秒生成y/x个人:"<<endl<<"请输入两个正整数x和y(经测试,1/3概率生成2个人是刚刚好的)"<<endl; 
	cin>>xx>>yy; 
	cout<<"设置乘客耐心值的随机范围px到py:"<<endl;
	cin>>px>>py;
	cout<<"输入电梯需要运行多长时间"<<endl;
	int tim;
	cin>>tim;
	system("cls");
	for(nowtime=0;nowtime<tim;nowtime++){
		work(fout);
	}
}
