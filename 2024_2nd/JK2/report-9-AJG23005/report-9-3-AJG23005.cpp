//AJG23005 中 天花

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int num;

int main() {
    list<int> num_list;
    int index = 1;
    for(int i=0; true; i++) {
        cout << i+1 << "番目の数字を入力して下さい: ";
        cin >> num;
        if(num == 0) {
            break;
        } else {
            num_list.push_back(num);
        }
    }

    //標本平均を求める
    int sum = 0;
    list<int>::iterator p;
    for (p = num_list.begin(); p != num_list.end(); p++) {
        sum += *p;
    }
    double mean = static_cast<double>(sum)/num_list.size();
    cout << "入力された数字の平均は" << mean << "です" << endl;

    //平均値に最も近い値を探す
    double min_diff = abs(*num_list.begin() - mean);
    vector<int> closest_indices;
    index = 1;
    for (p = num_list.begin(); p != num_list.end(); ++p) {
        double diff = abs(*p - mean);
        if (diff < min_diff) {
            min_diff = diff;
            closest_indices.clear();
            closest_indices.push_back(index);
        } else if (diff == min_diff) {
            closest_indices.push_back(index);
        }
        index++;
    }
    cout << "これは、";
    for (int i = 0; i < closest_indices.size(); i++) {
        if (i > 0) cout << "、";
        cout << closest_indices[i];
    }
    cout << "番目に入力された値に最も近いです" << endl;
    return 0;
}
