#include <iostream>
using namespace std;

int main(){
  //allocating in heap memory
  int *p = new int(10);
  cout<<*p;

  double *pd = new double(3000114);
  cout<<*pd;

  float *pf = new float(10);
  cout<<*pf;

  char *pc = new char("dynamic");
  cout<<*pc;
}
