#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
    q.push(1);
    q.push(3);
    cout<<q.top()<<endl;;
}