#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Write your code here
    int n;
    cin>>n;
    vector<pair<int,int>> m;

    for(int i=0;i<n;i++)
    {
        long first,second;
        cin>>first>>second;
        m.push_back(make_pair<int,int>(second,first));


    }

    //we can use map but map not assign duplicate value


    vector<pair<int,int>> ::iterator i;
    long *start=new long[n];
    long *end = new long[n];
    int index = 0;

    sort(m.begin(),m.end());

    for(i=m.begin();i!=m.end();i++){
        start[index]=i->second;

        end[index] = i->first;
        // cout<<start[index]<<" "<<end[index]<<endl;
        index++;

    }

    long count=1;
    int x=0;

    for(int i=1;i<n;i++)
    {
        if (start[i]>=end[x])
        {
            count++;
            x=i;
                             }

    }

    delete [] start;
    delete [] end;

    cout<<count<<endl;

    return 0;
}
