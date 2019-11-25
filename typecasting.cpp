#include <iostream>
using namespace std;

void updateValue(int *p){
    *p = 610 % 255;
}

int main(){
    char ch = 'A';
    updateValue((int*)&ch);
    cout << ch;

    //implicit Typecasting

    int i = 108;
    char c = i;
    cout<<c<<endl;

    //Explicit Typecasting (pointer typecasting)

    int *p = &i;
    char *pc = (char *)p;

    cout<<*p<< " "<< pc;



}
