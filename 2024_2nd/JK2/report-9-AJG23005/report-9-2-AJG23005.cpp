//AJG23005 中 天花

#include <iostream>
#include <map>
using namespace std;

map<string, int> heights;
string name;
int height;

void add_height(){
    cout << "データを追加します (add_height)" << endl;
    cout << "名前を入力してください: ";
    cin >> name;
    cout << "身長を入力してください: ";
    cin >> height;
    heights[name] = height;
}

void search_height(){
    cout << "データを検索します (search_height)" << endl;
    cout << "名前を入力してください: ";
    cin >> name;
    if(heights.find(name)!=heights.end()){
        cout << name << "さんの身長は" << heights[name] << "cmです。" << endl;
    } else {
        cout << name << "さんのデータは見つかりませんでした。" << endl;
    }
}

void delete_height(){
    cout << "データを削除します (delete_height)" << endl;
    cout << "名前を入力してください: ";
    cin >> name;
    if(heights.find(name)!=heights.end()){
        heights.erase(name);
        cout << name << "さんのデータを削除しました。" << endl;
    } else {
        cout << name << "さんのデータは見つかりませんでした。" << endl;
    }
}

void average_height(){
    cout << "データの平均身長を計算します (average_height)" << endl;
    int sum = 0;
    for (map<string, int>::iterator it = heights.begin(); it != heights.end(); ++it) {
    sum += it->second;
}
    double average = static_cast<double>(sum) / heights.size();
    cout << "平均身長は" << average << "cmです。" << endl;
}

int main() {
    heights["a"] = 156;
    heights["b"] = 170;
    heights["c"] = 165;
    heights["d"] = 175;
    add_height();
    search_height();
    delete_height();
    average_height();
    return 0;
}
