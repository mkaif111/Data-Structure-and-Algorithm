#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

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
    int n,m;
    cin >> n >> m;
       
    int arr1[n];
    int arr2[n];
     
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
        
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }    

    vector<int>* edges = new vector<int>[n];

   

    for(int i=0;i<m;i++){

        int x , y;
        cin>>x>>y;
        edges[x-1].push_back(y-1);
        edges[y-1].push_back(x-1);


    }
	string ans = "YES";
    unordered_set<unordered_set<int>*>* output = getComponents(edges , n);
    unordered_set<unordered_set<int>*>:: iterator it1 = output->begin();

    while(it1!=output->end()){
        unordered_set<int>* component = *it1;
        unordered_set<int>:: iterator it2 = component->begin();
		unordered_set<int> p,q;
        
        while(it2!=component->end()){
            p.insert(arr1[*it2]);
            q.insert(arr2[*it2]);
            it2++;
        }
        if(p!=q){
            ans = "NO";
            break;
        }
        it1++;
        delete component;
    }
        
    cout<<ans<<endl;

  


    delete output;
    delete [] edges;
        
    }






}



