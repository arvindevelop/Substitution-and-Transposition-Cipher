#include<bits/stdc++.h>
using namespace std;

const int a = 17;
const int b = 20;

string encryptMessage(string msg)
{
	string cipher = "";
	for (int i = 0; i < msg.length(); i++)
	{
		// Avoid space to be encrypted
		if(msg[i]!=' ')
			/* applying encryption formula ( a x + b ) mod m*/
			cipher = cipher +(char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
		else
			//else simply append space character
			cipher += msg[i];
	}
	return cipher;
}

string decryptCipher(string cipher)
{
	string msg = "";
	int a_inv = 0;
	int flag = 0;

	//Find a^-1
	for (int i = 0; i < 26; i++)
	{
		flag = (a * i) % 26;

		//Check if (a*i)%26 == 1,
        //then i will be the multiplicative inverse of a
		if (flag == 1)
		{
			a_inv = i;
		}
	}
	for (int i = 0; i < cipher.length(); i++)
	{
		if(cipher[i]!=' ')
			msg = msg +(char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
		else
			msg += cipher[i];
	}

	return msg;
}

int main()
{
	string msg;
	cout<<"Enter a message: "<<endl;
	getline(cin,msg);
	string cipherText = encryptMessage(msg);
	cout << "Encrypted Message is : " << cipherText<<endl;

	cout << "Decrypted Message is: " << decryptCipher(cipherText);

	return 0;
}


