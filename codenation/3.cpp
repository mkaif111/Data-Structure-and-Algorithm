#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSum(vector<int> candy,int not_include){
    int sum = 0;
    for(auto el: candy){
        if(el != not_include)
            sum +=el;
    }

    return sum;
}

int solution(vector<int> &candy){
    int low = INT_MAX;
    int high = INT_MIN;
    int ans = INT_MAX;
    
    int n = candy.size();
    for(int i=0;i<n;i++){
        low = min(low,candy[i]);
        high = max(high,candy[i]);
    }

    for(int i=low;i<=high;i++){
        ans = min(ans,minSum(candy,i));
    }

    return ans;
}
int main(){


    int n; cin>>n;
    vector<int> candy(n);
    for(int i=0;i<n;i++){
        cin>>candy[i];
    }
    cout<<solution(candy)<<endl;
}
