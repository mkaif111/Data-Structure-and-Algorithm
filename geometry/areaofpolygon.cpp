#include<bits/stdc++.h>
using namespace std;

class points{
    public:
     double x,y;
};
class Polygon{
    public:
    points *point;
    Polygon(int n){
        point = new points[n];
    }
};

int area(Polygon p,int n){
    
    int ans=0;
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
int main() {

	// Write your code here
    int n;
    cin>>n;
    
    Polygon p(n);
    int x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
     for(int i=0;i<n;i++){
         
        p.point[i].x = x[i];
        p.point[i].y = y[i]; 
    }
    
    
    double ans = area(p,n);
    
    cout<<(int)ans<<endl;
    
    
    
    
    
    
    
    
}