// this program only calculate grundy number
#include<bits/stdc++.h>
using namespace std;

int calculateMex(unordered_set<int> Set) 
{ 
    int Mex = 0; 
  
    while (Set.find(Mex) != Set.end()) 
        Mex++; 
  
    return (Mex); 
} 

int calculateGrundy(int n, int Grundy[]) 
{ 
    Grundy[0] = 0; 
    Grundy[1] = 1; 
    Grundy[2] = 2; 
    Grundy[3] = 3; 
  
    if (Grundy[n] != -1) 
        return (Grundy[n]); 
  
    unordered_set<int> Set; // A Hash Table 
  
     
    Set.insert (calculateGrundy (n/2, Grundy)); 
    Set.insert (calculateGrundy (n/3, Grundy)); 
    Set.insert (calculateGrundy (n/6, Grundy)); 
  
    // Store the result 
    Grundy[n] = calculateMex (Set); 
  
    return (Grundy[n]); 
} 


int main() {

	// Write your code here
    int n;
    cin>>n;
    int Grundy[n+ 1]; 
    memset(Grundy, -1, sizeof (Grundy));
    
    cout<<calculateGrundy(n,Grundy)<<endl;
    
    
}