#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000001
#define push_back pb

typedef long long int ll;

int* sieve(){
    // vector<int>* cube = new vector<int>();
    int* cube_free = new int[MAX];
    
    for(int i=0;i<=MAX;i++){
        cube_free[i]=0;
    }
    
    for(int i=2;i<=100;i++){
        
        int indx = i*i*i;
        for(int j=indx;j<=MAX;j+=indx)
        {
            cube_free[j]=-1;
        }
        
    }
    
    int k =1;
    cube_free[1] = 1;
    cube_free[0] = 1;
    for(int i=1;i<=MAX;i++){
        if(cube_free[i]==-1){
            continue;
        }
       
            cube_free[i] = k;
            k++;
        
    }
    
  
    
    
    
    return cube_free;
    
}


int main(){
	// Write your code here
    
    //pre computation
    int* cube = sieve();
    
    
    int t;
    cin>>t;
    
   for(int j=1;j<=t;j++){
        int n;
       cin>>n;
        
        if(cube[n]>=0){
            cout<<"Case "<<j<<": "<<cube[n]<<endl;
        }
        
        else{
             cout<<"Case "<<j<<": "<<"Not Cube Free"<<endl;
        }
    }
    
    
    
    
    
    
    
    
    
    
	return 0;
}