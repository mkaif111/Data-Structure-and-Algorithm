#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll min(ll x,ll y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

void decToBinary(ll n) 
{ 
    // array to store binary number 
    int binaryNum[64]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]<<" "; 
    
    cout<<endl;
}


int main(){

    int t;
    cin>>t;

    while(t--){
        ll x,y,l,r;
        scanf("%lld%lld%lld%lld",&x,&y,&l,&r);
        // cin>>x>>y>>l>>r;

        
        ll r_v=1;
        
        r_v = x|y;
        // cout<<r_v<<endl;
        if(r_v<=r && min(x,y)!=0)
            {    
               printf("%lld \n",r_v);
            }
        else{


        ll ans=0;
        ll count=0;
        ll val = r;

        while(val>0){
            count++;
            val=val>>1;
            
        }
        // cout<<count<<endl;
        
        ans = 1<<count;
        // cout<<ans<<endl;
        ans = ans-1;
        // cout<<ans<<endl;
        // cout<<r_v<<endl;
        
        r_v = r_v & ans;
        // cout<<"---"<<r_v<<endl;
        ll temp = r_v;
        // cout<<"#####"<<endl;
        if(r_v>r){
            for(int i=0;i<count;i++)
            {
                ll m = 1<<i;
                // cout<<m<<endl;
                // cout<<(r_v&m)<<endl;
                if((r_v & m) == m)
                {
                    r_v = r_v^m;
                    // cout<<" r_v : "<<r_v<<endl;
                }

                if(r_v<=r){
                    break;
                }
                
                   
                
            }
        }
        
  
    for(int j=0;j<count;j++)
    {
        ll q = 1<<j;
        if(((temp & q) == q) && (r_v | q)<=r) {
            if( (r_v | q) > r_v)
                 r_v= r_v | q;
            // cout<<"&&&"<<" "<<r_v<<endl;
            
        }
    }
    
       

      
     ll an = (x & r_v)*(y & r_v);
     if(an==0){
         ll bck = 1<<(count-1);
         bck--;
         r_v = temp&bck;
        //  cout<<"[[]]"<<r_v<<endl;
         
         ll cdm = (x&r_v)*(y&r_v);
        //  printf("y : %lld x : %lld\n ",y,x);
        //  printf("y&z : %lld x&z : %lld \n",y&r_v,x&r_v);
        //  cout<<(x & r_v)*(y & r_v)<<endl;
        //  cout<<cdm<<endl;

         if(cdm==0){
             r_v = l;
         }
         
     }  
    //   cout<<r_v<<endl;
    if(x == 0 || y == 0)
    {
        r_v=l;
    }
    // printf("%lld\n",r_v);
    printf("%lld \n",r_v);
    // decToBinary(r_v);


    }// else end here

   
        
    //   decToBinary(x);
    //   decToBinary(y);
    //   decToBinary(x|y);    
        
        
    }// end while loop

    return 0;

}