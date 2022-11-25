#include <bits/stdc++.h>
#define SHIFT 3

using namespace std;

string encryptCaesarCipher(const string &plainText)
{
    string cipherText;

    for (auto &&ch : plainText)
    {
        if (ch == ' ')
        {
            cipherText.push_back(' ');
            continue;
        }
        int ascii = ch - 'a';
        ascii = (ascii + SHIFT) % 26;
        cipherText.push_back(ascii + 'a');
    }
    return cipherText;
}

string decryptCaesarCipher(const string &cipherText)
{
    string plainText;
    for (auto &&ch : cipherText)
    {
        if (ch == ' ')
        {
            plainText.push_back(' ');
            continue;
        }
        int ascii = ch - 'a';
        ascii = (ascii - SHIFT) % 26;
        if (ascii < 0)
            ascii += 26;
        plainText.push_back(ascii + 'a');
    }
    return plainText;
}

int main(void)
{
    string plainText, cipherText;
    int operation;
    cout << "Enter the operation you want to perform: ";
    cin >> operation;
    switch (operation)
    {
    case 1:
        cout << "Enter the plaintext: ";
        cin.ignore();
        getline(cin, plainText);
        cout << "The cipher text is: " << encryptCaesarCipher(plainText) << '\n';
        break;
    case 2:
        cout << "Enter the cipher text: ";
        cin.ignore();
        getline(cin, cipherText);
        cout << "The plain text is: " << decryptCaesarCipher(cipherText) << '\n';
        break;
    default:
        cout << "Enter the query for Encryption (1) and Decryption (2)\n";
        break;
    }
    return 0;
}