#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>  // For std::shuffle
#include <random>     // For random number generation

using namespace std;

void generateRandomMapping(unordered_map<char, int> &charToNum, unordered_map<int, char> &numToChar) {
    vector<int> positions;
    
    // Add positions for letters a-z, A-Z, and space
    for (int i = 1; i <= 53; i++) {
        positions.push_back(i);
    }

    // Add positions for digits 0-9
    for (int i = 54; i <= 63; i++) {
        positions.push_back(i);
    }

    // Add positions for punctuation and special characters
    string specialChars = ".,'\"()[]{}:;?!@#$%^&*-_+=<>";
    for (int i = 64; i < 64 + specialChars.length(); i++) {
        positions.push_back(i);
    }

    // Shuffle the positions to ensure random assignment
    random_device rd;
    mt19937 gen(rd());
    shuffle(positions.begin(), positions.end(), gen);

    // Now assign the shuffled positions to characters
    int idx = 0;

    // Assign for lowercase a-z
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        charToNum[ch] = positions[idx];
        numToChar[positions[idx]] = ch;
        idx++;
    }

    // Assign for uppercase A-Z
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        charToNum[ch] = positions[idx];
        numToChar[positions[idx]] = ch;
        idx++;
    }

    // Assign for space
    charToNum[' '] = positions[idx];
    numToChar[positions[idx]] = ' ';
    idx++;

    // Assign for digits 0-9
    for (char ch = '0'; ch <= '9'; ++ch) {
        charToNum[ch] = positions[idx];
        numToChar[positions[idx]] = ch;
        idx++;
    }

    // Assign for special characters
    for (char ch : specialChars) {
        charToNum[ch] = positions[idx];
        numToChar[positions[idx]] = ch;
        idx++;
    }
}

string encryptMessage(const string &message, const string &key, unordered_map<char, int> &charToNum, unordered_map<int, char> &numToChar) {
    vector<char> keyExpanded;
    string encrypted = "";

    // Expand key to match message length
    for (size_t i = 0; i < message.length(); i++) {
        keyExpanded.push_back(key[i % key.length()]);
    }

    for (size_t j = 0; j < message.length(); ++j) {
        int combined = charToNum[message[j]] + charToNum[keyExpanded[j]];
        
        // Ensure it wraps within the valid range
        if (combined > 63) {
            combined = (combined % 63 == 0) ? 63 : combined % 63;
        }

        encrypted += numToChar[combined];
    }

    return encrypted;
}

int main() {
    srand(time(0)); // Seed for randomness

    unordered_map<char, int> charToNum;
    unordered_map<int, char> numToChar;
    generateRandomMapping(charToNum, numToChar);

    string message, key;
    cout << "Enter Message: ";
    getline(cin, message);
    cout << "Enter Key: ";
    getline(cin, key);

    string encrypted = encryptMessage(message, key, charToNum, numToChar);

    cout << "\nEncrypted Message: " << encrypted << endl;
    
    cout << "\nCharacter Mapping:\n";
    for (auto &pair : charToNum) {
        cout << "'" << pair.first << "' -> " << pair.second << endl;
    }

    return 0;
}
