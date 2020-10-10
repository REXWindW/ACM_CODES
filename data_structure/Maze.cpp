#include<iostream>
#include<algorithm>
#include<ctime>
#include<windows.h>
using namespace std;

class Node{//堆栈节点
public:
    int x,y;//记录xy坐标
    int fx;//记录方向 
    Node* next;
    Node(int x=0,int y=0,int fx=0):x(x),y(y),fx(fx),next(NULL){}
};
class Stack{
private:
    Node* head;//栈的头指针 
public:
    Stack():head(NULL){}//头指针赋值为空
    ~Stack(){//析构函数,防止内存泄漏
        Node* px;
        while(head!=NULL){
            px = head;
            head = px->next;
            delete(px);
        }
    }
    void push(int x,int y,int fx){
        Node *px = new Node(x,y,fx);//构造新节点
        px->next = head;
        head = px;
    }
    void pop(){//栈顶
        if(empty()) return;//避免栈空的情况
        Node* px = head;
        head = px->next;
        delete(px);
    }
    bool empty(){//判空
        return head==NULL;
    }
    Node& top(){//返回栈顶节点
        return *head;
    }
};
int dir[4][2] = {-1,0,1,0,0,-1,0,1};//方向数组
const int MAXNN = 72;//定义迷宫大小
int MAXN;
//MAXN可修改
bool OK(int x,int y){//判断点是否在界内
    return x>0&&x<MAXN&&y>0&&y<MAXN;
}
int shuaxintime;//刷新时间 
bool maze_map[MAXNN][MAXNN];//迷宫地图，1为墙，0为空
bool vis[MAXNN][MAXNN];
bool viss[MAXNN][MAXNN];
int d[MAXNN][MAXNN];//记录当前位置搜索的方向，输出路径时用
char jt[5][6]={"  ","↑","↓","←","→"}; 
void print_maze(){//打印迷宫
    for(int i=1;i<MAXN;i++){
        for(int j=1;j<MAXN;j++){
            if(maze_map[i][j]) cout<<"■";
            else cout<<"  ";
        }
        cout<<endl;
    }
}
void maze_path(){//在搜索时同时打印迷宫和路径
	for(int i=1;i<MAXN;i++){
        for(int j=1;j<MAXN;j++){
            if(maze_map[i][j]) cout<<"■";
            else if(d[i][j]) cout<<jt[d[i][j]];
            else cout<<"  ";
        }
        cout<<endl;
    }
} 

void maze_generate(){//Prim树结构迷宫生成
    srand((unsigned)time(NULL));//随机种子
    for(int i=1;i<MAXN;i++){
        for(int j=1;j<MAXN;j++){
            viss[i][j] = d[i][j] = vis[i][j] = 0;//重置所有点未访问
            if(i==1||i==MAXN-1||j==1||j==MAXN-1) maze_map[i][j]=1;
            else if(i%2==0&&j%2==0) maze_map[i][j]=0;
            else maze_map[i][j] = 1;
        }
    }
    maze_map[2][1] = maze_map[MAXN-2][MAXN-1] = 0;//起点和终点
    bool flag = 1;
    vis[2][2] = 1;//访问过起点
    int nowx = 2,nowy = 2;//当前访问格子
    while(flag){//直到所有点都被访问过
        while(1){
            //判断周围的点是否都被访问过
            bool flag2=1;
            int sj,dx,dy;
            for(int i=0;i<4;i++){
                dx = nowx + dir[i][0]*2;
                dy = nowy + dir[i][1]*2;
                if(!OK(dx,dy)) continue;//越界
                if(vis[dx][dy]) continue;//访问过了
                flag2=0;//有没访问过的点
            }
            if(flag2){
            	//这里是原先采取的第二种策略
				//即找到已访问的方块后，把四面都打通
				//但是这样的结果就是挖的空太多了，导致存在很多很多路径 
            	/*
            	int ss = rand()%4,tt = rand()%4;
                for(int i=ss;i<=tt;i++){
                    dx = nowx + dir[i][0]*2;
                    dy = nowy + dir[i][1]*2;
                    if(OK(dx,dy)){
                        maze_map[nowx+dir[i][0]][nowy+dir[i][1]]=0;
                    }
                }
                */
                break;//退出while
            }
            flag2 = 1;
            while(flag2){//随机找到下一个没被访问过的点
                sj = rand()%4;
                dx = nowx + dir[sj][0]*2;
                dy = nowy + dir[sj][1]*2;
                if(!OK(dx,dy)){continue;}//越界
                if(vis[dx][dy]){continue;}//访问过了
                vis[dx][dy] = 1;//访问该点
                maze_map[nowx+dir[sj][0]][nowy+dir[sj][1]]=0;
                nowx = dx;nowy = dy;
                break;
            }
        }
        //看是否所有点都被访问过
        flag = 0;//如果有则改成1
        for(int i=1;i<MAXN;i++){
            for(int j=1;j<MAXN;j++){
                if(i%2==0&&j%2==0){
                    if(!vis[i][j]){//还有点没被访问的
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        //找新的nowx,nowy
        if(!flag) break;//所有点都已经被访问
        while(1){
            nowx = rand()%(MAXN-1)+1;
            nowy = rand()%(MAXN-1)+1;
            if(nowx%2==1) nowx++;
            if(nowy%2==1) nowy++;
            if(!OK(nowx,nowy)) continue;
            if(!vis[nowx][nowy]) continue;
            //到这里说这对now xy是可以的
            break;
        }
    }
}

void dfs(int sx,int sy,int tx,int ty){//使用堆栈实现的深度优先搜索
    Stack st;//栈
	st.push(sx,sy,4);
	int x,y,dx,dy;
	while(!st.empty()){
		//输出迷宫部分
		x = st.top().x;y = st.top().y;
		viss[x][y] = 1;
		d[x][y] = st.top().fx;
		Sleep(shuaxintime);
		system("cls");
		maze_path();
		cout<<"■现在位置:("<<x<<','<<y<<")"<<endl;
		if(x==tx&&y==ty){
			cout<<"■找到终点"<<endl; 
			break;
		}
		if(st.top().fx==0){//回溯
			viss[x][y] = 1;
			st.pop();
			continue;
		}
		st.top().fx=0;
		for(int i=0;i<4;i++){
			dx = x+dir[i][0]; dy = y+dir[i][1];
			if(OK(dx,dy)&&viss[dx][dy]==0&&maze_map[dx][dy]==0){
				st.push(dx,dy,i+1);//新点入栈
			}
		}
	}
}

int main(){
	cout<<"■请自定迷宫大小"<<endl; 
	cout<<"■Option:必须为奇数,推荐在10-40之间选"<<endl;
	cout<<"□迷宫大小:";
	cin>>MAXN;
	MAXN++;
	char hc;
	system("cls");
    maze_generate();//生成树形迷宫
    print_maze();//打印迷宫 
	cout<<"■Option:迷宫为树形结构,存在且只有一条路径"<<endl;
	cout<<"□开始搜索/退出程序[Y/N]:";
	cin>>hc;
	if(hc=='Y'||hc=='y'){
		system("cls");
		print_maze();//打印迷宫 
		cout<<"■如果是20左右,推荐100,如果迷宫比较大,因为打印迷宫也需要时间,可以设置间隔为0"<<endl;
		cout<<"□输入搜索间隔(单位ms):";
		cin>>shuaxintime;
		dfs(2,1,MAXN-2,MAXN-1);//开始搜索
	}
}
