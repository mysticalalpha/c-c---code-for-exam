#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    map<int, string> dict;
    dict[1] = "apple";
    dict[2] = "banana";
    dict[3] = "orange";
    dict[4] = "grape";
    dict[5] = "watermelon";
    dict[6] = "apple";

    for(auto it = dict.begin(); it != dict.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}