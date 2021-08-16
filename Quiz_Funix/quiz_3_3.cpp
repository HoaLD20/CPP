//
// Created by hoald on 09/08/2021.
//

#include "iostream"
#include "vector"

using namespace std;
template<class K, class V>
class Dict{
private:
    vector<K> keys;
    vector<V> values;
public:
    void insert(K key, V value){
        keys.push_back(key);
        values.push_back(value);
    }
    void get(int n){
        cout << keys[n] << ": " << values[n];
    }
};

int main(){
    Dict<string, string> dict;
    dict.insert("Hello", "Xin chao");
    dict.insert("GoodBye", "Tam biet");
    dict.get(0);
    cout << endl;
    dict.get(1);
    cout << endl;
    return 0;
}