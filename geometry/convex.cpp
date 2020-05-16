#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
};

bool change(Point p,Point q,Point r){
    int x1 = q.x - p.x;
    int y1 = q.y - p.y;
    int x2 = r.x - q.x;
    int y2 = r.y - q.y;
    
    int value = x1*y2 - y1*x2;
    
    return value<0;
    
}

void convex(Point *points,int n){
    vector<Point> hull;
    
    int left =0;
    for(int i=0;i<n;i++)
    {
        int a=points[i].x;
        int b= points[left].x;
        
        if(a < b){
        	left =i;
        }
        
    }
    
    int p = left;
    
    do{
        hull.push_back(points[p]);
        int q = (p+1)%n;
        for(int i=0;i<n;i++)
        {
            if(change(points[p],points[q],points[i]))
               	q=i;
        }
       
         p=q;      
    }while(p!=left);
    
    for(int i=0;i<hull.size();i++)
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    
}

int main() {

	int n;
    cin>>n;
    int X[n];
    int Y[n];
    Point *points=new Point[n];
    
    for(int i=0;i<n;i++){
        cin>>X[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>Y[i];
    }
    
    for(int i=0;i<n;i++){
        points[i].x = X[i];
        points[i].y = Y[i];
    }
    
    convex(points,n);
    
}
