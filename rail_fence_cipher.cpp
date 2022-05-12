#include <bits/stdc++.h>
using namespace std;

/*string removeSpace(string message)
{
    string str = "";
    for(int i=0;i<message.size();i++)
    {
        if(message[i] != ' ')
            str += message[i];
    }
    cout<<str<<endl;
    return str;
}*/
// function to encrypt a message
string encryptRailFence(string text, int key)
{
	// create the matrix to cipher plain text key = rows , length(text) = columns
	char rail[key][(text.length())];

	// filling the rail matrix to distinguish filled spaces from blank ones
	for (int i=0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			rail[i][j] = '\n';

	// to find the direction
	bool dir_down = false;
	int row = 0, col = 0;

	for (int i=0; i < text.length(); i++)
	{
		// check the direction of flow reverse the direction if we've just filled the top or bottom rail
		if (row == 0 || row == key-1)
			dir_down = !dir_down;

		// fill the corresponding alphabet
		rail[row][col++] = text[i];

		// find the next row using direction flag
		dir_down?row++ : row--;
	}

	//now we can construct the cipher using the rail matrix
	string result;
	for (int i=0; i < key; i++)
		for (int j=0; j < text.length(); j++)
			if (rail[i][j]!='\n')
				result.push_back(rail[i][j]);

	return result;
}

string decryptRailFence(string cipher, int key)
{
	char rail[key][cipher.length()];
	for (int i=0; i < key; i++)
		for (int j=0; j < cipher.length(); j++)
			rail[i][j] = '\n';

	bool dir_down;

	int row = 0, col = 0;

	for (int i=0; i < cipher.length(); i++)
	{
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		rail[row][col++] = '*';
		dir_down?row++ : row--;
	}

	int index = 0;
	for (int i=0; i<key; i++)
		for (int j=0; j<cipher.length(); j++)
			if (rail[i][j] == '*' && index<cipher.length())
				rail[i][j] = cipher[index++];

	string result;

	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++)
	{
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		if (rail[row][col] != '*')
			result.push_back(rail[row][col++]);

		dir_down?row++: row--;
	}
	return result;
}

int main()
{
    string msg,msg1;
    cout<<"Enter the message for encryption: "<<endl;
    getline(cin,msg);
    //msg = removeSpace(msg);
    //msg1 = encryptRailFence(msg, 2);
	//cout <<"Encrypted message: "<<msg1 << endl;
	//cout << "Decrypted message: "<<decryptRailFence(msg1,3) << endl;
	cout <<"Encrypted message: "<<encryptRailFence(msg,2) << endl;
	cout<<"Enter the message for decryption: "<<endl;
    getline(cin,msg1);
	cout << "Decrypted message: "<<decryptRailFence(msg1,2) << endl;
	return 0;
}
