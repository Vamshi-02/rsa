#include <bits/stdc++.h>
using namespace std;

int calculateModulus(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int calculateGCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void generateKeys(int p, int q, int& publicKey, int& privateKey, int& modulus) {
    int n, phi, e, d;
    n = p * q;
    modulus = n;
    phi = (p - 1) * (q - 1);
    for (e = 2; e < phi; e++) {
        if (calculateGCD(e, phi) == 1) {
            break;
        }
    }
    publicKey = e;

    d = 1;
    while (((d * e) % phi) != 1) {
        d++;
    }
    privateKey = d;
}

int encrypt(int data, int publicKey, int modulus) {
    return calculateModulus(data, publicKey, modulus);
}

int decrypt(int data, int privateKey, int modulus) {
    return calculateModulus(data, privateKey, modulus);
}

int main() {
    int p, q;
    int publicKey, privateKey, modulus;
    int data, encryptedData, decryptedData;

    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;
    generateKeys(p, q, publicKey, privateKey, modulus);
    cout << "Enter data to encrypt: ";
    cin >> data;

    encryptedData = encrypt(data, publicKey, modulus);
    cout << "Encrypted data: " << encryptedData << endl;

    decryptedData = decrypt(encryptedData, privateKey, modulus);
    cout << "Decrypted data: " << decryptedData << endl;

    return 0;
}
