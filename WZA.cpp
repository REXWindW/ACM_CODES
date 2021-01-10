#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stu{
    char name[10];//姓名
    char num[10];//学号
    int grade;
    Stu *nxt;
}head;

void insert(Stu x){//插入
    Stu* px = (Stu*)malloc(sizeof(Stu));//malloc是给新的节点申请内存
    *px = x;
    //把新的节点接到头节点head后面。
    px->nxt = head.nxt;
    head.nxt = px;
}

void del(char* dnum){//按照学号删除
    Stu* pre = &head;
    Stu* px = head.nxt;
    while(px!=NULL&&strcmp(dnum,px->num)!=0){//strcmp判别是否是要找的对应学号
        pre = px;
        px = px->nxt;//指针往下移动，顺着链表一步一步往下找
    }
    if(px==NULL){
        printf("抱歉未找到这名学生,请检查学号是否输入正确\n");
        return;
    }
    if(strcmp(px->num,dnum)==0){//如果找到了，执行删去该节点
        pre->nxt = px->nxt;//x前面元素的nxt指向x后面的元素，相当于把x这个元素去掉。
        free(px);
        printf("删除成功\n");
    }
}

void find1(char* dnum){
    Stu* px = head.nxt;
    while(px!=NULL&&strcmp(dnum,px->num)!=0){
        px = px->nxt;
    }
    if(px==NULL){
        printf("抱歉未找到这名学生,请检查学号是否输入正确\n");
        return;
    }
    if(strcmp(px->num,dnum)==0){
        printf("为你找到一名学生\n");
        printf("%s %s %d\n",px->name,px->num,px->grade);
    }
}//按照学号查找学生

void find2(char* dname){
    Stu* px = head.nxt;
    while(px!=NULL&&strcmp(dname,px->name)!=0){//如果通过strcmp判断这个学生就是要找的学生，就退出循环
        px = px->nxt;
    }
    if(px==NULL){
        printf("抱歉未找到这名学生,请检查姓名是否输入正确\n");
        return;
    }
    if(strcmp(px->name,dname)==0){
        printf("为你找到一名学生\n");
        printf("%s %s %d\n",px->name,px->num,px->grade);
    }
}//按照姓名查找学生

void show_60(){//输出60以下的
    printf("以下为成绩小于等于60的学生\n");
    Stu* px = head.nxt;//px一开始指向链表头
    while(px!=NULL){
        if(px->grade<=60)//如果符合60分以下的条件，则输出这个学生
            printf("%s %s %d\n",px->name,px->num,px->grade);
        px = px->nxt;//px顺着链表往下走
    }
}

void show(){//显示当前所有的学生
    printf("以下为所有学生清单\n"); 
    Stu* px = head.nxt;//px是一个指针，从链表头开始，一步一步往下走
    while(px!=NULL){
        printf("%s %s %d\n",px->name,px->num,px->grade);
        px = px->nxt;//px顺着链表往下走
    }
}

int typ;

int main(){
    //head.nxt = NULL;
    Stu tmp;
    //printf("输入1插入学生，2删除学生,3显示所有学生,4按照学号查找,5按照姓名查找,6输出所有60分以下的学生,0结束程序\n");
    printf("输入1插入学生，2删除学生,3显示所有学生,4按照姓名查找,5按照学号查找,6输出所有60分以下的学生,0结束程序\n");
    while(scanf("%d",&typ)){
        if(typ==0) break;
        if(typ==1){//插入学生
            printf("请输入姓名\n");
            scanf("%s",tmp.name);
            printf("请输入学号\n");
            scanf("%s",tmp.num);
            printf("请输入成绩\n");
            scanf("%d",&tmp.grade);
            insert(tmp);
        }
        else if(typ==2){//按照学号找到学生并且删除
            printf("请输入删除学生的学号\n");
            char dnum[10];
            scanf("%s",dnum);
            del(dnum);
        }
        else if(typ==3){//打印所有学生
            show();
        }
        else if(typ==4){//按照姓名找到学生
            printf("请输入要查找的学生姓名\n");
            char dname[10];
            scanf("%s",&dname);
            find2(dname);
        }
        else if(typ==5){//按照学号查找学生
            printf("请输入要查找的学生学号\n");
            char dnum[10];
            scanf("%s",&dnum);
            find1(dnum);
        }
        else if(typ==6){//打印60分以下的人
            show_60();
        }
        else{
            printf("不要输入规定以外的数字\n");
        }
    }
    freopen("out.txt","w",stdout);
    show();
    show_60();
}