#include<bits/stdc++.h>
using namespace std;

struct coder{
    int x,y,index;
};

bool operator < (coder A, coder B){
	if(A.x == B.x){
		return A.y < B.y;
	}
	return A.x < B.x;
}
void update(int y,int* BIT){
    for(;y<=100000;y+=y&(-y))
        BIT[y]++;
}
int query(int y,int* BIT){
    int count=0;
    for(;y>0;y-=y&(-y))
        count+=BIT[y];
    return count;
}


int main(){

    int n;
    cin>>n;

    coder *arr = new coder[n];
    int *BIT = new int[100001]; // initially zero
    for(int i=0;i<100001;i++)
        BIT[i]=0;

    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
        arr[i].index = i;
    }
    int *ans = new int[n];

    sort(arr,arr+n);
    for(int i=0;i<n;){
        int endindex = i;
        //avoid duplicates
        while(endindex<n and arr[i].x==arr[endindex].x and arr[i].y==arr[endindex].y)
            endindex++;
        // query first all duplicates so that it dont create extra count to non-duplicates elements
        for(int j=i;j<endindex;j++){
            ans[arr[j].index] = query(arr[j].y,BIT);
        }
        //updates 
        for(int j=i;j<endindex;j++){
            update(arr[j].y,BIT);
        }
        i = endindex;
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;





}