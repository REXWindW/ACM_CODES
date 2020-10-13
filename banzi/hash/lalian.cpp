const int med = 1000007;//模数 
const int MAXN = 2e6+5;//数据总量 

struct Hash_table{
	struct Node{
		int next,value,key;
	}data[MAXN];//数据的总量,从1开始 
	int head[med],size;//head记录每个哈希值的链表的第一个节点
	//size记录节点总数 
	int f(int key){ return key%med; }//求哈希值
	int find(int key){
		for(int p = head[f(key)];p;p=data[p].next)//遍历这个哈希值上的链表 
			if(data[p].key==key) return data[p].value;
		return -1; 
	}
	int update(int key,int value){//更新value 
		for(int p = head[f(key)];p;p=data[p].next)
			if(data[p].key==key) return data[p].value = value;
		return -1;
	}
	int add(int key,int value){
		if(find(key)!=-1) return -1;//这个值已经被插入了
		data[++size] = (Node){head[f(key)],value,key};//从链表头部插入 
		head[f(key)] = size;//标记该链表的第一个节点 
		return value; 
	}
};