#include<bits/stdc++.h>
using namespace std;
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty())
    return -1;
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty())
    return -1;
    else if(s.top()>=minEle)
    {
        int x = s.top();
        s.pop();
        return x;
    }

    else
    {   //curr element is minElement update min and return minELement
        
        int x = minEle;
        minEle = 2*minEle - s.top();
        s.pop();
        return x;
    }
   
}

/*push element x into the stack*/
void _stack::push(int x)
{   
   //Your code here
   if(s.empty())
     {
         s.push(x);
         minEle = x;
     }
    else if(x>= minEle)
        s.push(x);
    else
    {
        s.push(2*x - minEle);
        minEle = x;
    }
   return;
    
}

int main(){
    return 0;
}