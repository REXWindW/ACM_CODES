    deque<node> dq;//每行进行单调队列
	//本来想建maxn个deque的，但是这里发现可以滚动
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!dq.empty()&&dq.front().order<j-k+1) dq.pop_front();
			while(!dq.empty()&&a[i][j]>=dq.back().data) dq.pop_back();
			dq.push_back(node{a[i][j],j});
			res[i][j] = dq.front().data;
		}
		dq.clear();
	}
	//对k开始的每列进行单调队列 
	for(int j=k;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(!dq.empty()&&dq.front().order<i-k+1) dq.pop_front();
			while(!dq.empty()&&dq.back().data<=res[i][j]) dq.pop_back();
			dq.push_back(node{res[i][j],i});
			res[i][j] = dq.front().data;
		}
		dq.clear();
	}
	ll msum = 0;
	for(int i=k;i<=n;i++){
		for(int j=k;j<=m;j++){
			msum+=res[i][j];
		}
	}
	cout<<msum<<endl;