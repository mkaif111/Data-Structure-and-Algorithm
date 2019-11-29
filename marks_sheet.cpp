#include<bits/stdc++.h>
using namespace std;

struct mark_sheet{
  int marks;
  int roll_n;
  string name;

};
bool compare(mark_sheet x , mark_sheet y){
  if (x.marks == y.marks) {
    return x.roll_n<y.roll_n;
  }
  else{return x.marks > y.marks;}
}

int main(){

//       mark_sheet arr[] = {{10,1,"aman"},{10,2,"akbar"},{111,3,"lucy"}};
//       sort(arr,arr+3,compare);

//       for(int i=0;i<3;i++){cout<<arr[i].name<<endl;}

    int n;
    cin>>n;
    mark_sheet arr[n];
    for(int i=0;i<n;i++){
        int m1,m2,m3;
        string name;
        cin>>name >> m1 >> m2 >> m3;
        int total = m1+m2+m3;
        arr[i] = {total,i+1,name};
    }
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<arr[i].name<<endl;
    }





}
