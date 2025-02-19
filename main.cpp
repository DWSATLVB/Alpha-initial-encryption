#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void generateRandomMapping(unordered_map<char, int> &charToNum, unordered_map<int, char> &numToChar) {
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,!?@#$%^&*()-_=+[]{}:;\"'<>/\\";

    vector<int> positions;
    for (int i = 1; i <= characters.length(); i++) {
        positions.push_back(i);
    }

    // Shuffle positions to ensure randomness
    random_device rd;
    mt19937 gen(rd());
    shuffle(positions.begin(), positions.end(), gen);

    // Assign shuffled positions to characters
    for (size_t i = 0; i < characters.length(); i++) {
        charToNum[characters[i]] = positions[i];
        numToChar[positions[i]] = characters[i];
    }
}

void printMapping(const unordered_map<char, int> &charToNum) {
    cout << "Character Mapping: ";
    for (const auto &pair : charToNum) {
        cout << "'" << pair.first << "' -> " << pair.second << ", ";
    }
    cout << endl;
}

string encryptMessage(const string &message, const string &key, unordered_map<char, int> &charToNum, unordered_map<int, char> &numToChar) {
    vector<int> encryptedValues;
    string encryptedText = "";
    
    // Extend key to match the message length
    string extendedKey = key;
    while (extendedKey.length() < message.length()) {
        extendedKey += key;
    }
    extendedKey = extendedKey.substr(0, message.length());

    // Encrypt the message
    for (size_t i = 0; i < message.length(); i++) {
        int charPos = charToNum[message[i]];
        int keyPos = charToNum[extendedKey[i]];
        int newPos = charPos + keyPos;

        // Ensure it wraps around within the valid range
        if (newPos > charToNum.size()) {
            newPos -= charToNum.size();
        }

        encryptedValues.push_back(newPos);
        encryptedText += numToChar[newPos];
    }

    return encryptedText;
}

int main() {
    unordered_map<char, int> charToNum;
    unordered_map<int, char> numToChar;

    // Generate a new random mapping each time the program runs
    generateRandomMapping(charToNum, numToChar);

    // Print the mapping in a single line
    printMapping(charToNum);

    // Get user input
    string message, key;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
    cout << "Enter the key: ";
    getline(cin, key);

    // Encrypt the message
    string encryptedMessage = encryptMessage(message, key, charToNum, numToChar);
    cout << "Encrypted Message: " << encryptedMessage << endl;

    return 0;
}
