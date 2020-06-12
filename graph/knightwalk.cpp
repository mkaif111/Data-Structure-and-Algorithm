#include<bits/stdc++.h>
using namespace std;
bool pathexist(int s1,int s2, int d1,int d2,int n,int m,bool**visited){

    if(s1==d1 and s2==d2)
        return true;

    visited[s1][s2] = true;

    int x_step[] = {-2,-2,2,2,-1,1,-1,1};
    int y_step[] = {1,-1,1,-1,2,2,-2,-2};

    for(int i=0;i<8;i++){
        int r = s1+x_step[i];
        int c = s2+y_step[i];

        if(c>=0 && c<m && r>=0 && r<n && !visited[r][c]){
            if(pathexist(r,c,d1,d2,n,m,visited));
                return true;
        }
            
    }

    return false;


}
int dfs(int s1,int s2, int d1,int d2,int n,int m,bool**visited){

    if(s1==d1 and s2==d2)
        return 0;

    visited[s1][s2] = true;

    int x_step[] = {-2,-2,2,2,-1,1,-1,1};
    int y_step[] = {1,-1,1,-1,2,2,-2,-2};

    int count=1000000;

    for(int i=0;i<8;i++){
        int r = s1+x_step[i];
        int c = s2+y_step[i];

        if(c>=0 && c<m && r>=0 && r<n && !visited[r][c]){
            count = min(dfs(r,c,d1,d2,n,m,visited),count);
            visited[r][c]=false;
        }
            
    }
    

    return count+1;


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
        bool **visited = new bool*[n];
        for(int i=0;i<n;i++){
            visited[i] = new bool[m]();
        }

        if(pathexist(s1-1,s2-1,d1-1,d2-1,n,m,visited))
           {   for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   visited[i][j] = false;
               }
           }
               cout<< dfs(s1-1,s2-1,d1-1,d2-1,n,m,visited)<<endl;
               
            }
        else
            cout<<-1<<endl;

	    
	}
	return 0;
}