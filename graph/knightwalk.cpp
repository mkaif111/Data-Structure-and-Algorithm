#include<bits/stdc++.h>
using namespace std;
int dfs(int n, int m, int s1 ,int s2 ,int  d1 , int d2,int p_r,int p_c){
    
    if(s1==d1 and s2==d2)
        return 0;
    if(s1>n or s2>m or s1<0 or s2<0)
        return INT_MAX;
    if(s1==p_r and s2==p_c)
        return INT_MAX;



    int option1 = dfs(n,m,s1 - 2,s2+1,d1,d2, s1,s2);
    int option2 = dfs(n,m,s1 - 2,s2-1,d1,d2, s1,s2);
    int option3 = dfs(n,m,s1 + 2,s2+1,d1,d2, s1,s2);
    int option4 = dfs(n,m,s1+2,s2-1,d1,d2, s1,s2);
    int option5 = dfs(n,m,s1 - 1,s2+2,d1,d2, s1,s2);
    int option6 = dfs(n,m,s1 + 1,s2+2,d1,d2, s1,s2);
    int option7 = dfs(n,m,s1 - 1,s2-2,d1,d2, s1,s2);
    int option8 = dfs(n,m,s1+1,s2-2,d1,d2 ,s1,s2);
    
    int ans = min({option1,option2,option3,option4,option5,option6,option7,option8});
    return ans+1;
    
    
}

int main() {
	//code
	
	int t;
	cin>>t;
	
	while(t--){
	    int n, m;
	    cin>>n>>m;
	    int s1,s2,d1,d2;
	    cin >> s1 >>s2 >>d1 >> d2;
	    cout<<"great"<<endl;
	    bool** visited = new bool*[n];
        cout<<"great"<<endl;
	   
	    cout<<"great2"<<endl;
	    int ans = dfs(n,m,s1-1,s2-1,d1-1,d2-1,s1-1,s2-1);
	    cout<<ans<<endl;
	}
	return 0;
}