#include <iostream>

using namespace std;


int getSecretKey(int keyOfFriend, int privateKey, int p)
{
    return (int)pow(keyOfFriend, privateKey) % p;
}
int main()
{
    
    setlocale(LC_ALL, "Russian");
    int p, g, secretA, secretB, publicA, publicB;
    string message = "Павлычев Алексей Сергеевич";
    cout << "p:";
    cin >> p;
    cout << "g:";
    cin >> g;
    cout << "Alice choose:";
    cin >> secretA;
    cout << "Bob choose:";
    cin >> secretB;
    publicA = (int)pow(g, secretA) % p;
    publicB = (int)pow(g, secretB) % p;
    cout <<"Key is " << getSecretKey(publicA, secretB, p) << endl;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == 32) { message[i] = ' '; }
        else
        {
            if (message[i] + getSecretKey(publicB, secretA, p) % 64 > -1) { message[i] = message[i] + getSecretKey(publicB, secretA, p) % 64 - 64; }
            else if (message[i] + getSecretKey(publicB, secretA, p) % 64 < -64) {message[i] = message[i] - getSecretKey(publicB, secretA, p) % 64 + 64;}
            else
            {
                message[i] += getSecretKey(publicB, secretA, p) % 64;
            }
        }
    }
    int key;
    cout << "Enter key" << endl;
    cin >> key;

    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == 32) { message[i] = ' '; }
        else 
        {
            if (message[i] - key % 64 > -1) { message[i] = message[i] + key % 64 - 64; }
            else if (message[i] - key % 64 < -64) { message[i] = message[i] - key % 64 + 64; }
            else
            {
                message[i] -= key % 64;
            }
        }
    }
    cout << message << endl;

    system("pause");
    
}

