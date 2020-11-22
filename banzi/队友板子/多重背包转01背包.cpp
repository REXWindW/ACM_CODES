//多重背包转01背包
int t,n,w1[1007],v1[1007],s[1007],w2[1007],v2[1007],num=0;

void proc(){
    for(int i=0;i<n;++i){
        int p=1;
        while(s[i]-p>0){
            w2[num]=p*w1[i];
            v2[num]=p*v1[i];
            num++;
            s[i]-=p;
            p<<=1;
        }
        if(s[i]){
            w2[num]=s[i]*w1[i];
            v2[num]=s[i]*v1[i];
            num++;
        }
    }
}