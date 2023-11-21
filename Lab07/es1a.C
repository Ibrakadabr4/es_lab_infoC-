#include <iostream>

using namespace std;

void scambia(int*,int*);

int main(){
    int a = 0;
    int b = 5;

    int *p, *p0;
    p = &a;
    p0 = &b;
    cout<<endl<<"Prima di scambia: ";
    cout<<endl<<*p<<"  "<<*p0;

    scambia(p,p0);
    cout<<endl<<"Dopo scambia: ";
    cout<<endl<<*p<<"  "<<*p0;

    return 0;
}

void scambia(int*p1, int*p2){
    int appo = *p1;
    *p1 = *p2;
    *p2 = appo;
}