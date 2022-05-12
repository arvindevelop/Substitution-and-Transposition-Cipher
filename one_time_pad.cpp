#include<bits/stdc++.h>
using namespace std;


string encrypt(string msg,string key)
{
    string enc = "";
    for(int i=0;i<msg.size();i++)
    {
        enc += msg[i]^key[i];
    }
    return enc;
}
string decrypt(string cip,string key)
{
    string dec = "";
    for(int i=0;i<cip.size();i++)
    {
        dec += cip[i]^key[i];
    }
    return dec;
}
int main()
{
    string msg,key;
    cout<<"Enter the message"<<endl;
    cin>>msg;
    cout<<"Enter the key"<<endl;
    cin>>key;
    string encrypMsg = encrypt(msg,key);
    cout<<"Encrypted message : "<<encrypMsg<<endl;
    string decryptMsg = decrypt(encrypMsg,key);
    cout<<"Decrypted message : "<<decryptMsg<<endl;
    return 0;
}
