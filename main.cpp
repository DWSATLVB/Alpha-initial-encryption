#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<char, int> Dict_of_store;
    unordered_map<int, char> Dict_of_store_scrap;

    int idx = 1;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        Dict_of_store[ch] = idx;
        Dict_of_store_scrap[idx] = ch;
        idx++;
    }
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        Dict_of_store[ch] = idx;
        Dict_of_store_scrap[idx] = ch;
        idx++;
    }
    Dict_of_store[' '] = 53;
    Dict_of_store_scrap[53] = ' ';

    string inp_main, key_main;
    cout << "Main: ";
    getline(cin, inp_main);
    cout << "Key: ";
    getline(cin, key_main);

    vector<char> inp(inp_main.begin(), inp_main.end());
    vector<char> key;
    string encrypted = "";

    size_t i = 0;
    if (inp_main.length() > key_main.length()) {
        for (char ch : key_main) key.push_back(ch);
        while (key.size() < inp.size()) {
            key.push_back(key_main[i % key_main.length()]);
            i++;
        }
    } else if (key_main.length() > inp_main.length()) {
        for (char ch : key_main) {
            key.push_back(ch);
            if (key.size() == inp.size()) break;
        }
    } else {
        key = vector<char>(key_main.begin(), key_main.end());
    }

    vector<int> each_element;
    for (size_t j = 0; j < inp.size(); ++j) {
        int combined = Dict_of_store[inp[j]] + Dict_of_store[key[j]];
        each_element.push_back(combined);
    }

    for (int new_main : each_element) {
        if (new_main > 53) {
            int num = new_main - 53;
            encrypted += Dict_of_store_scrap[num];
        } else {
            encrypted += Dict_of_store_scrap[new_main];
        }
    }

    cout << "Encrypted: " << encrypted << endl;
    return 0;
}
