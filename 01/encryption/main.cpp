#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

using namespace std;

string encryption_key;
string text_to_encrypt;

bool is_valid_key(const string& key) {
    if (key.length() != 26) {
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return false;
    }
    for (char ch : key) {
        if (!islower(ch)) {
            cout << "Error! The encryption key must contain only lower case characters." << endl;
            return false;
        }
    }
    set<char> unique_chars(key.begin(), key.end());
    if (unique_chars.size() != 26) {
        cout << "Error! The encryption key must contain all alphabets a-z." << endl;
        return false;
    }
    return true;
}

string encrypt_text(const string& text, const string& key) {
    string encrypted_text;
    for (char ch : text) {
        encrypted_text += key[ch - 'a'];
    }
    return encrypted_text;
}

int main() {
    cout << "Enter the encryption key: ";
    cin >> encryption_key;

    if (!is_valid_key(encryption_key)) {
        return EXIT_FAILURE;
    }

    cout << "Enter the text to be encrypted: ";
    cin >> text_to_encrypt;

    string encrypted_text = encrypt_text(text_to_encrypt, encryption_key);
    cout << "Encrypted text: " << encrypted_text << endl;

    return 0;
}
