#include<iostream>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long num=0;
    int i=1;
    while(n>10){
        int digit = n%10;
        if(9-digit<digit){
            num +=i*(9-digit);
            i*=10;
            // n=n/10;

        }
        else{
            num+=i*digit;
            i*=10;


        }
        n=n/10;

    }
    if (9-n%10==0){
        num+=i*(n%10);

    }
    else{
        int last_digit = n%10;
        if(9-last_digit>last_digit){
            num+=i*last_digit;

        }
        else{
            num += i*(9-last_digit);

        }

    }
    cout<<num;

	return 0;

}
