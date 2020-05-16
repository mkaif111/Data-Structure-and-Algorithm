#include<bits/stdc++.h>
using namespace std;

class points{
    public:
    double x,y;
};
class Polygon {
    public:
    points *point;

    Polygon(int n){
        point = new points[n];
    }
};

double area(Polygon p,int n){
    double ans=0;
    for(int i=1;i<n-1;i++){
        double x1 = p.point[i].x-p.point[0].x;
        double y1 = p.point[i].y-p.point[0].y;
        double x2 = p.point[i+1].x-p.point[0].x;
        double y2 = p.point[i+1].y-p.point[0].y;
        
        double cross_p = x1*y2 - x2*y1;
        ans+=cross_p;
        
    }
    
    return abs(ans/2);
    

}

int main(){

    string s;
    cin>>s;
    int n=s.length();
    
    
    int arr[n];
    for(int i=0;i<n;i++)
        {cin>>arr[i];}
    
    Polygon p(n);
    double x,y;
    x=y=0;
    for(int i=0;i<n;i++){

        if(s[i]=='N')
            x+=arr[i];
        else if(s[i]=='S')
            x-=arr[i];
        else if(s[i]=='W')
            y+=arr[i];
        else if(s[i]=='E')
            y-=arr[i];

        p.point[i].x = x;
        p.point[i].y = y;
        
    }

    cout<<(int)area(p,n)<<endl;



}