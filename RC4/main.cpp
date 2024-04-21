#include <string>
#include "RC4.h"
#include <malloc.h>
#include <iostream>
using namespace std;

int main()
{
	string Key = "hjdjhjdjhkdjhdkfdfjhkdfsjheu23gics";
	string Plain_Text = "This text need crypt";
	RC4 rc4;
	rc4.setKey((unsigned char*)Key.c_str(), Key.length());
	unsigned char* encrypt = (unsigned char*)malloc(Plain_Text.size() + 1);

	rc4.encrypt((unsigned char*)Plain_Text.c_str(), encrypt, Plain_Text.length());
	cout << " Encrypted text" << endl;
	cout << encrypt << endl;

	unsigned char* decrypt = (unsigned char*)malloc(Plain_Text.size() + 1);

	rc4.setKey((unsigned char*)Key.c_str(), Key.length());
	rc4.encrypt(encrypt, decrypt, Plain_Text.length());

	cout << " Decrypted text" << endl;
	cout << decrypt << endl;
}
