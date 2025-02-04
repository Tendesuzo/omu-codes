//AJG23005 中 天花

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int n = 500; //最大反復回数
double a = 0.1; //学習率
double eps = 0.0001; //微小な数
double x[500]; //xの値を格納する配列
double fx[500]; //f(x)の値を格納する配列
double grad[500]; //勾配を格納する配列
int cnt = 0; //繰り返し回数を記憶

int main(){
    for (int i = 0; i < 500; i++){
        x[i] = 0; // 初期値を0に設定
    }
    for (int i = 0; i < 500; i++){
        fx[i] = 0; // 初期値を0に設定
    }
    for (int i = 0; i < 500; i++){
        grad[i] = 0; // 初期値を0に設定
    }

    x[0] = 2.0; //xの初期値を設定

    fx[0] = cos(x[0]);//fx[0]を計算

    grad[0] = -sin(x[0]); //勾配を計算

    for (int i=0; i<n; i++){
        if(abs(grad[i])>eps){
            x[i+1] = x[i] - a * grad[i]; //xを更新
            fx[i+1] = cos(x[i+1]); //f(x[i+1])を計算
            grad[i+1] = -sin(x[i+1]); //勾配を更新
        }else{
            cnt = i+1; //繰り返し回数を記憶
            break; // 勾配がeps以下なら終了
        }
    }

    // ファイルに出力
    ofstream outFile("report-4-2-AJG23005.txt");
    if (outFile.is_open()) {
        outFile << "f(x)=cos(x)" << endl;
        for (int i=0; i<cnt; i++){
        outFile << setw(2) << i << "        " << "x=" << left << setw(10) << x[i] << "     " << "f(x)=" << setw(10) << fx[i] << "     " << "grad=" << grad[i] << endl;
    }
    }
    return 0;
}
