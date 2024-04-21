#include "RC4.h"
#include <iostream>

void RC4::ksa(unsigned char * key)
{
	int j = 0;
	for (int i = 0; i < 256; i++) {
		j = (j + sbox[i] + key[i% sizeKey]) % 256;
		swap(sbox, i, j);
	}
	
}

void RC4::swap(unsigned char data[], int i, int j)
{
	unsigned char temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void RC4::prga(unsigned char * plaintext, unsigned char * cipher, int size)
{
	for (int i = 0; i < size; i++) {
		prgaIndexA = (prgaIndexA + 1) % 256;
		prgaIndexB = (prgaIndexB + sbox[prgaIndexA]) & 256;
		swap(sbox, prgaIndexA, prgaIndexB);
		cipher[i] = sbox[(sbox[prgaIndexA] + sbox[prgaIndexB]) % 256] ^ plaintext[i];
	}
}

	
void RC4::setKey(unsigned char * k, int size)
{
	prgaIndexA = 0;
	prgaIndexB = 0;
	sizeKey = size;
	for (int i = 0; i < 256; i++)
		sbox[i] =  (unsigned char)i;
	ksa(k);
}

void RC4::encrypt(unsigned char * in, unsigned char * out, int size)
{
	prga(in, out, size);
}

RC4::RC4() {
}
