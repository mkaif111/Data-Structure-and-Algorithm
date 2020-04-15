#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
#define ll long long int
#define mod 1000000007

ll factorial(int n){
    
    // cout<<"factorial is "<<n<<endl;
    ll result = 1;
    
    for(int i=1;i<=n;i++){
        
        result = (result*i)%mod;
    }
    
    return result%mod;
    
}

bool isValid(int row , int col , int n , int m, int** horse){
    if(row>=n || col>=m || col<0 || row<0 || (horse[row][col]==-1))
        return false;
    return true;
}

void dfs(vector<int> *edges , int start , bool* visited , unordered_set<int>* component ){

    visited[start]=true;
    component->insert(start);

    for(int i=0;i<edges[start].size();i++){
        int new_v = edges[start][i];

        if(!visited[new_v]){
            dfs(edges,new_v , visited , component);

        }

    }
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges , int n){

    bool* visited = new bool[n]();

    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();

    for(int i=0;i<n;i++){
        unordered_set<int>* component = new unordered_set<int>();

        if(!visited[i]){
            dfs(edges , i , visited , component);
            output->insert(component);

        }
    }

    return output;

}

int main(){
    
    int t;
    cin>>t;
    
    while(t--){

    int n,m,q;
    cin>>n>>m>>q;


    vector<int>* edges = new vector<int>[q];

    
    int** horse = new int*[n];

    for(int i=0;i<n;i++){

        horse[i] = new int[m];

        for(int j=0;j<m;j++){
            horse[i][j] = -1;
        }
    }

	
    

    for(int i=0;i<q;i++){

        int x , y;
        cin>>x>>y;
        horse[x-1][y-1] = i;
        
    }
    
    int x_step[] = {-2,-2,1,-1,2,2,1,-1};
    int y_step[] = {-1,1,2,2,1,-1,-2,-2};
    
    for(int i=0;i<n;i++){
        
        for(int j=0;j<m;j++){
            
            if(horse[i][j]!=-1){
                // cout<<i<<j<<" xxx "<<endl;
                edges[horse[i][j]].push_back(horse[i][j]);
                for(int k=0;k<8;k++){
                    
                    int row = i + x_step[k];
                    int col = j + y_step[k];
                    
                    
                    if(isValid(row , col , n , m , horse))
                    {
                        // cout<<row<<" -- "<<col<<" --- "<<i<<j<<endl;

                        edges[horse[i][j]].push_back(horse[row][col]);
                        edges[horse[row][col]].push_back(horse[i][j]);

                        // cout<<edges[horse[i][j]].size()<<endl;
                        // cout<<edges[horse[row][col]].size()<<endl;

                        // cout<<"--------"<<endl;



                        

                    }
                    
                    
                }
                
            }
            
        }
    }
    
    
	ll result = 1;
    unordered_set<unordered_set<int>*>* output = getComponents(edges , q);
    unordered_set<unordered_set<int>*>:: iterator it1 = output->begin();

    while(it1!=output->end()){
        unordered_set<int>* component = *it1;
        
        result = (result*factorial(component->size()))%mod;
        
        it1++;
        delete component;
    }
    
    
    cout<<result<<endl;

    


    delete output;
    delete [] edges;
    
    }






}


