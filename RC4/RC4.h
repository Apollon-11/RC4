#ifndef ARC4_H_
#define ARC4_H_

class RC4 {
public:

	void setKey(unsigned char * k, int size);
	void encrypt(unsigned char * in, unsigned char * out, int size);
	RC4();
protected:
	void ksa(unsigned char * key);
	void swap(unsigned char data[], int i, int j);
	void prga(unsigned char * plaintext, unsigned char * cipher, int size);
	unsigned char sbox[256];
	int sizeKey, prgaIndexA, prgaIndexB;
};



#endif