//AJG23005 中 天花

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main(void){
    int a = 1;
    int b = 2;
    cout << "a = " << a << ",b = " << b << endl;
    swap(a, b);
    cout << "swap" << endl;
    cout << "a = " << a << ",b = " << b << endl;
    return 0;
}
