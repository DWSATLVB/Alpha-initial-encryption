#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

void generateRandomMapping(unordered_map<char, int> &charToNum, unordered_map<int, char> &numToChar) {
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,!?@#$%^&*()-_=+[]{}:;\"'<>/\\";

    vector<int> positions;
    for (int i = 1; i <= characters.length(); i++) {
        positions.push_back(i);
    }

    // Stronger random shuffle with high-entropy seed
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    shuffle(positions.begin(), positions.end(), mt19937(seed));

    // Assign shuffled positions to characters
    for (size_t i = 0; i < characters.length(); i++) {
        charToNum[characters[i]] = positions[i];
        numToChar[positions[i]] = characters[i];
    }
}

void printMapping(const unordered_map<char, int> &charToNum) {
    cout << "\nCharacter Mapping:\n";
    for (const auto &pair : charToNum) {
        cout << "'" << pair.first << "' -> " << pair.second << ", ";
    }
    cout << endl;
}

string encryptMessage(const string &message, const string &key, unordered_map<char, int> &charToNum, unordered_map<int, char> &numToChar) {
    string encryptedText = "";

    // Extend key to match message length
    string extendedKey = key;
    while (extendedKey.length() < message.length()) {
        extendedKey += key;
    }
    extendedKey = extendedKey.substr(0, message.length());

    // Encrypt message
    for (size_t i = 0; i < message.length(); i++) {
        int charPos = charToNum[message[i]];
        int keyPos = charToNum[extendedKey[i]];
        int newPos = (charPos + keyPos) % charToNum.size();  // Ensure it wraps around

        if (newPos == 0) newPos = charToNum.size();  // Avoid zero index
        encryptedText += numToChar[newPos];
    }

    return encryptedText;
}

int main() {
    unordered_map<char, int> charToNum;
    unordered_map<int, char> numToChar;

    // Generate a truly random mapping every time
    generateRandomMapping(charToNum, numToChar);

    // Print mapping
    printMapping(charToNum);

    // Get user input
    string message, key;
    cout << "\nEnter the message to encrypt: ";
    getline(cin, message);
    cout << "Enter the key: ";
    getline(cin, key);

    // Encrypt the message
    string encryptedMessage = encryptMessage(message, key, charToNum, numToChar);
    cout << "\nEncrypted Message: " << encryptedMessage << endl;

    return 0;
}
