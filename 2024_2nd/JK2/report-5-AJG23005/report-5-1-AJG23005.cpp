//AJG23005 中 天花

#include <iostream>
#include "assignment5.h"
using namespace std;

class apple : public base{
    public:
        double get_price(double weight){
            int price = 0; //代金
            return price += weight * unit_price;
        }
    //コンストラクタ
    //基本クラスのコンストラクタで初期化
    apple(string nm, double up) : base(nm, up){}
};

class yogurt : public base{
    public:
    double get_price(double weight){
            int price = 0; //代金
            return price += weight * unit_price + 50;
        }
    yogurt(string nm, double up) : base(nm, up){}
};

int main(){
    base *p;
    apple Apple("apple", 1000);
    yogurt Yogurt("yogurt", 350);

    while(true){
        cout << "Enter 'name' (apple or yogurt)." << endl;
        string name;
        cin >> name;
        if(name == "apple"){
            p = &Apple;
        } else if(name == "yogurt"){
            p = &Yogurt;
        }
        cout << "Enter 'weight' (kg)." << endl;
        double weight;
        cin >> weight;
        if (name == "apple"){
            cout << "The price of apple is " << p->get_price(weight) << " yen." << endl;
        } else if (name == "yogurt"){
            cout << "The price of yogurt is " << p->get_price(weight) << " yen." << endl;
        }
        cout << endl;
    }

    return 0;
};
