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
int n = 10;//��¥����
const int MAXN = 21;//¥����������
int xx,yy;
bool tiaoshi;
int nowtime;
bool flag[10]; 
string gz[10]={
"", 
"[���ݳ��ع���]  ���������ڳ˿͵������ܺͳ�������������,����ݳ���.",
"[���ݵ�ͷ����]  ����������еķ��������˰������ݰ�ť,���ݲ����ͷ.",//2
"[�˿��Ŷӹ���]  �˿���ÿ��¥����Ŷ�,�ϵ���ʱ��ѭ�����󵽵Ĺ���.", 
"[�˿����Ĺ���]  �˿͵ȴ�����������ֵ,����ֵ���Ĵ����Ժ�,������Ŷ��뿪����.",//4
"[�˿����ù���]  һ���˽������������,����������һ���˵������ǿ��Խ������.",
"[�˿����ɹ���]  ÿ��ʱ��ڵ㰴�ո�������y/x���ɳ˿�,���غ�����ֵ���趨��Χ�����."
};

struct peo{//people
    int to;
    int weight;
    int naixin;
	int zhuangtai(int lc){//�˵�״̬,1��¥��,-1��¥��
		if(to>lc) return 1;
		else return -1;
	}
};

int px,py;
peo gen(int lc){
	flag[6] = 1;
    peo ret;
	ret.to = rnd()%n+1;//ȥ�Ķ�
    while(ret.to==lc) ret.to = rnd()%n+1;
    ret.weight = rnd()%51+50;//50-100��������� 
    ret.naixin = nowtime + px + rnd()%(py-px+1);//����ֵ��10��50����� 
	return ret;
}

struct Elevator{
    queue<peo>member;
    int mi;
    const int max_weight = 600;//������600KG 
    int tot_weight;
	int zhuangtai;//����״̬-1,0,1
    Elevator():zhuangtai(0),mi(1),tot_weight(0){}
	queue<peo> ren;
	int lc(){//�õ�¥��
		return mi/4+1;
	}
}elevator;

queue<peo>flr[MAXN];//ÿ��Ķ���
bool up_botton[MAXN];
bool down_botton[MAXN];//�ļ��Ǹ���ť

vector<peo> get(queue<peo>q){//get x th floor's people->to
    vector<peo> res;
    while(!q.empty()){
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

void show(){
    rep(i,1,62) cout<<"��";
	cout<<endl;
	int buquan;//���ڲ�ȫ�ո� 
	int siz;
	repb(i,n,1){
		// check_botton();//����ÿһ��Ķ�����������°�ť 
		repb(j,4,1){//ÿ������ذ��4
			cout<<"��";
			int tmp_mi = (i-1)*4+j;//��ǰ�����������������
			if(tmp_mi==elevator.mi+3){
				buquan = 40;
				if(elevator.zhuangtai==-1){cout<<"��������",buquan=40-8;}
				else if(elevator.zhuangtai==0){cout<<"����ֹͣ",buquan=40-8;}
				else if(elevator.zhuangtai==1){cout<<"��������",buquan=40-8;}
				rep(i,1,buquan) cout<<" ";
			}
			else if(tmp_mi==elevator.mi+2){
				buquan = 40;
				rep(i,1,buquan) cout<<' ';
			}
			else if(tmp_mi==elevator.mi+1){
				vector<peo>vec = get(elevator.ren);//����vector���棬����ӡ
				siz = vec.size(); 
				siz = min(10,siz);
				rep(k,0,siz-1){
					int to = vec[k].to;
					cout<<'F';
					if(to/10) cout<<to<<' ';
					else cout<<to<<' '<<' ';
				}
				buquan = 40-siz*4;//��ȫ�ո� 
				rep(i,1,buquan) cout<<" ";
			}
			else if(tmp_mi==elevator.mi||tmp_mi==elevator.mi+4){
				//ӡ���ݵĵذ�
				rep(i,1,20) cout<<"==";
			} 
			else rep(i,1,20) cout<<"  ";
			//¥����в���
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
				if(up_botton[i]){cout<<"��";buquan = 80-2;}
				else {cout<<"��";buquan = 80-2;}
				rep(i,1,buquan) cout<<' ';
			} 
			else if(j==3){
				if(down_botton[i]){cout<<"��";buquan = 80-2;}
				else {cout<<"��";buquan = 80-2;}
				rep(i,1,buquan) cout<<' ';
			}
			else if(j==2){
				rep(i,0,siz-1){
					int to = vec[i].to;
					cout<<"F";
					if(to/10) cout<<to<<' ';
					else cout<<to<<' '<<' ';
				}
				buquan = 80-siz*4;//��ȫ�ո�  
				rep(i,1,buquan) cout<<' ';
			}
			else if(j==1){
				rep(i,1,40) cout<<"��";
			} 
			cout<<"��";
			cout<<endl;
		}
	}
	cout<<"[ʱ��"<<nowtime<<"]��ʱ�����ܺ���Ϊ"<<elevator.tot_weight<<"KG"<<endl;
	cout<<endl;
	cout<<"[���ݹ�����]"<<endl;
	rep(i,1,62) cout<<"��";
	cout<<endl<<endl;
	rep(i,1,6){
		cout<<"    ";
		if(flag[i]) cout<<"��    ";
		else cout<<"��    ";
		cout<<gz[i]<<endl;
	}
	cout<<endl;
	rep(i,1,62) cout<<"��";
	cout<<endl; 
}

int maxp,minp;
void upd(){
	maxp = 0,minp = n+1;
	rep(i,1,n){
		if(!flr[i].empty()){//�������¥��
			flag[3] = 1;
			maxp = max(maxp,i);
			minp = min(minp,i);
		}
	}
	vector<peo>vec;
	vec = get(elevator.ren);
	int siz = vec.size();
	rep(i,0,siz-1){
		maxp = max(maxp,vec[i].to);//�����е��˵����Ŀ��¥��
		minp = min(minp,vec[i].to);
	}
}

bool OK(int mi){//�������Ƿ񵽴�¥��߶�
	return (elevator.mi-1)%4==0;
}

void xiadianti(ofstream& fout){//�µ���
	vector<peo>vec;
	while(!elevator.ren.empty()){
		peo tmp = elevator.ren.front();
		elevator.ren.pop();
		if(tmp.to!=elevator.lc()){//������ 
			vec.push_back(tmp);
		}
		else{//to==�������µ��� 
			fout<<"["<<nowtime<<"]������"<<elevator.lc()<<"���µ���"<<endl;
			elevator.tot_weight -= tmp.weight;//�µ��ݺ��ȥ���� 
		}
	}
	int siz = vec.size();
	rep(i,0,siz-1){
		elevator.ren.push(vec[i]);
	}
}

void shangdianti(ofstream& fout){//�ϵ���
	vector<peo>vec;
	while(!flr[elevator.lc()].empty()){
		peo tmp = flr[elevator.lc()].front();
		flr[elevator.lc()].pop();
		if(tmp.zhuangtai(elevator.lc())==elevator.zhuangtai){//�ϵ���
			if(elevator.tot_weight+tmp.weight<=elevator.max_weight){
				elevator.ren.push(tmp);
				elevator.tot_weight += tmp.weight;
				fout<<"["<<nowtime<<"]������"<<elevator.lc()<<"¥�����˵���"<<endl;
			}
			else{
				vec.push_back(tmp);
				fout<<"["<<nowtime<<"]������"<<elevator.lc()<<"¥��Ϊ���ݳ��ض����ܽ������"<<endl;
				flag[1]=flag[5] = 1;
			}
		}
		else{//���ϵ��ݣ��ص�������ȥ
			vec.push_back(tmp);
		}
	}
	int siz = vec.size();
	rep(i,0,siz-1) flr[elevator.lc()].push(vec[i]);
}

void shengcheng(int num,ofstream& fout){//�������num���˲������¥��
	peo tmp;
	rep(i,1,num){
		int loc = rnd()%n+1;
		flr[loc].push(tmp=gen(loc));
		fout<<"["<<nowtime<<"]��"<<loc<<"¥������һ��Ŀ��Ϊ"<<tmp.to<<"¥,����ֵ"<<tmp.naixin-nowtime<<"����"<<endl; 
	}
}

void meinaixin(ofstream& fout){//ȥ��û���ĵ��� 
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
				fout<<"["<<nowtime<<"]��"<<i<<"¥��һ������Ϊû���Ķ��뿪��"<<endl;
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
	fout<<"<<<ʱ���"<<nowtime<<">>>"<<endl;
	fout<<"["<<nowtime<<"]��������"<<elevator.ren.size()<<"��,�ܺ���Ϊ"<<elevator.tot_weight<<"KG"<<endl; 
	if(rnd()%xx==0) shengcheng(yy,fout);//��������˵�¥��--------------------������������ٶ� 
	upd();//�������λ��maxp�����λ��minp
	meinaixin(fout);//���û���ĵ� 
	if(OK(elevator.mi)){//����ǲ��ǵ�����¥��ĸ߶�
		xiadianti(fout);//�µ���
		shangdianti(fout);
		if(elevator.zhuangtai==1&&elevator.lc()>=maxp){//�û�������
			elevator.zhuangtai = 0;//�����������Ȱ�״̬���0,���´��ж�
		}
		else if(elevator.zhuangtai==-1&&elevator.lc()<=minp){//������
			elevator.zhuangtai = 0;
		}
		else if(elevator.zhuangtai==0){//���ݴӾ�ֹ������
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
		fout<<"["<<nowtime<<"]������"<<elevator.lc()<<"¥����ֹͣ״̬"<<endl; 
	}
	else{
		fout<<"["<<nowtime<<"]���ݴӸ߶�"<<elevator.mi<<"�ƶ���"<<elevator.mi+elevator.zhuangtai<<endl; 
		if(minp<elevator.lc()) flag[2] = 1;
	}
	elevator.mi+=elevator.zhuangtai;//�����ƶ���
}

int main(){
	ofstream fout("out.txt");
	srand(time(0));
	//show();
	//system("pause");
	cout<<"[ע��]������־�����ͬĿ¼�µ�out.txt��"<<endl; 
	cout<<"����¥����n(2<=n<=20)"<<endl;
	cin>>n;
	cout<<"������1/x�ĸ�������y����,��ƽ��ÿ������y/x����:"<<endl<<"����������������x��y(������,1/3��������2�����Ǹոպõ�)"<<endl; 
	cin>>xx>>yy; 
	cout<<"���ó˿�����ֵ�������Χpx��py:"<<endl;
	cin>>px>>py;
	cout<<"���������Ҫ���ж೤ʱ��"<<endl;
	int tim;
	cin>>tim;
	system("cls");
	for(nowtime=0;nowtime<tim;nowtime++){
		work(fout);
	}
}
