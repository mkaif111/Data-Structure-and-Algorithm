#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int a = 7;
  int *c = &a;
  c = c + 3;
  cout  << c << endl;
}
