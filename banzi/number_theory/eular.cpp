int euler_phi(int n){
	int sqr = sqrt(n+0.5);
	int res = n; 
	for(int i=2;i<=sqr;i++){
		if(n%i==0){//找到一个质因子 
			res = res/i*(i-1);//先除后乘，防止越界 
			while(n%i==0) n/=i;//把这个因子从n中消除掉 
		}
	}
	if(n>1) res = res/n*(n-1);//大于sqrt的因子最多只有一个 
	return res; 
}