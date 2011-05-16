#ifndef _AES_H_
#define _AES_H_
#endif
#if !defined(TRUE)
#define TRUE 1
#endif

#if !defined(FALSE)
#define FALSE 0
#endif

#define MAX_KEY_SIZE  64
#define MAX_TEXT_SIZE 128 
#define MAX_IV_SIZE  64
#define MAX_COUNTER_SIZE 16
#define AES_BLOCK_SIZE	16

struct cipher_test_vector {
	char key[MAX_KEY_SIZE];
	unsigned char klen;
	char plaintext[MAX_TEXT_SIZE];
	unsigned char plen;
	char ciphertext[MAX_TEXT_SIZE];
	unsigned char clen;
	char iv[MAX_IV_SIZE];
	unsigned char ivlen;
	char counter[MAX_COUNTER_SIZE];
	unsigned char counterlen;
	unsigned int counterbits;
};

struct test_suite_info {
	const char *name;
	unsigned int tvcount;
	struct cipher_test_vector *ctv;
	unsigned long mechcrypt;
	unsigned long mechpad;
};
	

static struct cipher_test_vector aes_ecb_cipher_tv[] = {
	{
		.key = 	      { 0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,
				0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c },
		.klen = 16,
		.plaintext =  {	0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,
				0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,
				0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,
				0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51,
				0x30,0xc8,0x1c,0x46,0xa3,0x5c,0xe4,0x11,
				0xe5,0xfb,0xc1,0x19,0x1a,0x0a,0x52,0xef,
				0xf6,0x9f,0x24,0x45,0xdf,0x4f,0x9b,0x17,
				0xad,0x2b,0x41,0x7b,0xe6,0x6c,0x37,0x10 },
		.plen = 64,
		.ciphertext = { 0x3a,0xd7,0x7b,0xb4,0x0d,0x7a,0x36,0x60,
				0xa8,0x9e,0xca,0xf3,0x24,0x66,0xef,0x97,
				0xf5,0xd3,0xd5,0x85,0x03,0xb9,0x69,0x9d,
				0xe7,0x85,0x89,0x5a,0x96,0xfd,0xba,0xaf,
				0x43,0xb1,0xcd,0x7f,0x59,0x8e,0xce,0x23,
				0x88,0x1b,0x00,0xe3,0xed,0x03,0x06,0x88,
				0x7b,0x0c,0x78,0x5e,0x27,0xe8,0xad,0x3f,
				0x82,0x23,0x20,0x71,0x04,0x72,0x5d,0xd4 },
		.clen = 64,
	}, {
		.key =	      { 0x8e,0x73,0xb0,0xf7,0xda,0x0e,0x64,0x52,
				0xc8,0x10,0xf3,0x2b,0x80,0x90,0x79,0xe5,
				0x62,0xf8,0xea,0xd2,0x52,0x2c,0x6b,0x7b },
		.klen = 24,
		.plaintext =  {	0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,
				0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,
				0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,
				0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51,
				0x30,0xc8,0x1c,0x46,0xa3,0x5c,0xe4,0x11,
				0xe5,0xfb,0xc1,0x19,0x1a,0x0a,0x52,0xef,
				0xf6,0x9f,0x24,0x45,0xdf,0x4f,0x9b,0x17,
				0xad,0x2b,0x41,0x7b,0xe6,0x6c,0x37,0x10 },
		.plen = 64,
		.ciphertext = { 0xbd,0x33,0x4f,0x1d,0x6e,0x45,0xf2,0x5f,
				0xf7,0x12,0xa2,0x14,0x57,0x1f,0xa5,0xcc,
				0x97,0x41,0x04,0x84,0x6d,0x0a,0xd3,0xad,
				0x77,0x34,0xec,0xb3,0xec,0xee,0x4e,0xef,
				0xef,0x7a,0xfd,0x22,0x70,0xe2,0xe6,0x0a,
				0xdc,0xe0,0xba,0x2f,0xac,0xe6,0x44,0x4e,
				0x9a,0x4b,0x41,0xba,0x73,0x8d,0x6c,0x72,
				0xfb,0x16,0x69,0x16,0x03,0xc1,0x8e,0x0e },
		.clen = 64,
	}, {
		.key =	      {	0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,
				0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,
				0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,
				0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4 },
		.klen = 32,
		.plaintext =  {	0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,
				0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,
				0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,
				0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51,
				0x30,0xc8,0x1c,0x46,0xa3,0x5c,0xe4,0x11,
				0xe5,0xfb,0xc1,0x19,0x1a,0x0a,0x52,0xef,
				0xf6,0x9f,0x24,0x45,0xdf,0x4f,0x9b,0x17,
				0xad,0x2b,0x41,0x7b,0xe6,0x6c,0x37,0x10 },
		.plen = 64,
		.ciphertext = { 0xf3,0xee,0xd1,0xbd,0xb5,0xd2,0xa0,0x3c,
				0x06,0x4b,0x5a,0x7e,0x3d,0xb1,0x81,0xf8,
				0x59,0x1c,0xcb,0x10,0xd4,0x10,0xed,0x26,
				0xdc,0x5b,0xa7,0x4a,0x31,0x36,0x28,0x70,
				0xb6,0xed,0x21,0xb9,0x9c,0xa6,0xf4,0xf9,
				0xf1,0x53,0xe7,0xb1,0xbe,0xaf,0xed,0x1d,
				0x23,0x30,0x4b,0x7a,0x39,0xf9,0xf3,0xff,
				0x06,0x7d,0x8d,0x8f,0x9e,0x24,0xec,0xc7 },
		.clen = 64,
	},
};

static struct cipher_test_vector aes_cbc_cipher_tv[] = {
	{
		.key =		{ 0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,
				  0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c },
		.klen = 16,
		.plaintext =  {	0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,
				0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,
				0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,
				0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51,
				0x30,0xc8,0x1c,0x46,0xa3,0x5c,0xe4,0x11,
				0xe5,0xfb,0xc1,0x19,0x1a,0x0a,0x52,0xef,
				0xf6,0x9f,0x24,0x45,0xdf,0x4f,0x9b,0x17,
				0xad,0x2b,0x41,0x7b,0xe6,0x6c,0x37,0x10 },
		.plen = 64,
		.ciphertext = { 0x76,0x49,0xab,0xac,0x81,0x19,0xb2,0x46,
				0xce,0xe9,0x8e,0x9b,0x12,0xe9,0x19,0x7d,
				0x50,0x86,0xcb,0x9b,0x50,0x72,0x19,0xee,
				0x95,0xdb,0x11,0x3a,0x91,0x76,0x78,0xb2,
				0x73,0xbe,0xd6,0xb8,0xe3,0xc1,0x74,0x3b,
				0x71,0x16,0xe6,0x9e,0x22,0x22,0x95,0x16,
				0x3f,0xf1,0xca,0xa1,0x68,0x1f,0xac,0x09,
				0x12,0x0e,0xca,0x30,0x75,0x86,0xe1,0xa7 },
		.clen = 64,
		.iv =		{ 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
				  0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f },
		.ivlen = 16,
	}, {
		.key = 		{ 0x8e,0x73,0xb0,0xf7,0xda,0x0e,0x64,0x52,
				  0xc8,0x10,0xf3,0x2b,0x80,0x90,0x79,0xe5,
				  0x62,0xf8,0xea,0xd2,0x52,0x2c,0x6b,0x7b },
		.klen = 24,
		.plaintext =  {	0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,
				0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,
				0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,
				0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51,
				0x30,0xc8,0x1c,0x46,0xa3,0x5c,0xe4,0x11,
				0xe5,0xfb,0xc1,0x19,0x1a,0x0a,0x52,0xef,
				0xf6,0x9f,0x24,0x45,0xdf,0x4f,0x9b,0x17,
				0xad,0x2b,0x41,0x7b,0xe6,0x6c,0x37,0x10 },
		.plen = 64,
		.ciphertext = { 0x4f,0x02,0x1d,0xb2,0x43,0xbc,0x63,0x3d,
				0x71,0x78,0x18,0x3a,0x9f,0xa0,0x71,0xe8,
				0xb4,0xd9,0xad,0xa9,0xad,0x7d,0xed,0xf4,
				0xe5,0xe7,0x38,0x76,0x3f,0x69,0x14,0x5a,
				0x57,0x1b,0x24,0x20,0x12,0xfb,0x7a,0xe0,
				0x7f,0xa9,0xba,0xac,0x3d,0xf1,0x02,0xe0,
				0x08,0xb0,0xe2,0x79,0x88,0x59,0x88,0x81,
				0xd9,0x20,0xa9,0xe6,0x4f,0x56,0x15,0xcd },
		.clen = 64,
		.iv =		{ 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
				  0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f },
		.ivlen = 16,
	}, {
		.key =	      {	0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,
				0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,
				0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,
				0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4 },
		.klen = 32,
		.plaintext =  {	0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,
				0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,
				0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,
				0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51,
				0x30,0xc8,0x1c,0x46,0xa3,0x5c,0xe4,0x11,
				0xe5,0xfb,0xc1,0x19,0x1a,0x0a,0x52,0xef,
				0xf6,0x9f,0x24,0x45,0xdf,0x4f,0x9b,0x17,
				0xad,0x2b,0x41,0x7b,0xe6,0x6c,0x37,0x10 },
		.plen = 64,
		.ciphertext = { 0xf5,0x8c,0x4c,0x04,0xd6,0xe5,0xf1,0xba,
				0x77,0x9e,0xab,0xfb,0x5f,0x7b,0xfb,0xd6,
				0x9c,0xfc,0x4e,0x96,0x7e,0xdb,0x80,0x8d,
				0x67,0x9f,0x77,0x7b,0xc6,0x70,0x2c,0x7d,
				0x39,0xf2,0x33,0x69,0xa9,0xd9,0xba,0xcf,
				0xa5,0x30,0xe2,0x63,0x04,0x23,0x14,0x61,
				0xb2,0xeb,0x05,0xe2,0xc3,0x9b,0xe9,0xfc,
				0xda,0x6c,0x19,0x07,0x8c,0x6a,0x9d,0x1b },
		.clen = 64,
		.iv =		{ 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
				  0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f },
		.ivlen = 16,
	},
};
static struct cipher_test_vector aes_ctr_cipher_tv[] = {
	{
		.key = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 
			 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C },
		.klen = 16,
		.counter = { 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 
			     0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC,  0xFD,
			     0xFE, 0xFF },
		.counterlen = 16,
		.counterbits = 128,
		.plaintext = { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 
			       0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 
			       0x17, 0x2A, 0xAE, 0x2D, 0x8A, 0x57, 0x1E, 
			       0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 
			       0x45, 0x45, 0xAF, 0x8E, 0x51,0x30, 0xC8, 
			       0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 
		               0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF,
			       0xF6, 0x9F, 0x24, 0x45, 0xDF, 0x4F, 0x9B, 
		               0x17, 0xAD, 0x2B, 0x41, 0x7B, 0xE6, 0x6C, 
			       0x37, 0x10 },
		.plen = 16,
		.ciphertext = { 0x87, 0x4D, 0x61, 0x91, 0xB6, 0x20, 0xE3, 
				0x26, 0x1B, 0xEF, 0x68, 0x64, 0x99, 0x0D, 
				0xB6, 0xCE,0x98, 0x06, 0xF6, 0x6B, 0x79, 
				0x70, 0xFD, 0xFF, 0x86, 0x17, 0x18, 0x7B, 
				0xB9, 0xFF, 0xFD, 0xFF,0x5A, 0xE4, 0xDF, 
				0x3E, 0xDB, 0xD5, 0xD3, 0x5E, 0x5B, 0x4F, 
				0x09, 0x02, 0x0D, 0xB0, 0x3E, 0xAB,0x1E, 
				0x03, 0x1D, 0xDA, 0x2F, 0xBE, 0x03, 0xD1, 
				0x79, 0x21, 0x70, 0xA0, 0xF3, 0x00, 0x9C, 
				0xEE },
		.clen = 16,

	},
	{	.key = { 0x8e, 0x73, 0xB0, 0xF7, 0xDA, 0x0E, 0x64, 0x52, 
			 0xC8, 0x10, 0xF3, 0x2B, 0x80, 0x90, 0x79, 0xE5, 
			 0x62, 0xF8, 0xEA, 0xD2, 0x52, 0x2C, 0x6B, 0x7B },
		.klen = 24,
		.counter = { 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 
			     0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 
			     0xFE, 0xFF },
		.counterlen = 16,
		.counterbits = 128,
		.plaintext = { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 
			       0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 
			       0x17, 0x2A, 0xAE, 0x2D, 0x8A, 0x57, 0x1E, 
			       0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 
			       0x45, 0x45, 0xAF, 0x8E, 0x51, 0x30, 0xC8, 
			       0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 
			       0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF, 
			       0xF6, 0x9F, 0x24, 0x45, 0xDF, 0x4F, 0x9B, 
			       0x17, 0xAD, 0x2B, 0x41, 0x7B, 0xE6, 0x6C, 
			       0x37, 0x10 },
		.plen =  16,
		.ciphertext = { 0x1A, 0xBC, 0x93, 0x24, 0x17, 0x52, 0x1C, 
				0xA2, 0x4F, 0x2B, 0x04, 0x59, 0xFE, 0x7E, 
				0x6E, 0x0B, 0x09, 0x03, 0x39, 0xEC, 0x0A, 
				0xA6, 0xFA, 0xEF, 0xD5, 0xCC, 0xC2, 0xC6, 
				0xF4, 0xCE, 0x8E, 0x94, 0x1E, 0x36,0xB2, 
				0x6B, 0xD1, 0xEB, 0xC6, 0x70, 0xD1, 0xBD, 
				0x1D, 0x66, 0x56, 0x20, 0xAB, 0xF7, 0x4F, 
				0x78, 0xA7, 0xF6, 0xD2, 0x98, 0x09, 0x58,
				0x5A, 0x97, 0xDA, 0xEC, 0x58, 0xC6, 0xB0, 
				0x50 },
		.clen = 16,
	},
	{	.key = { 0x60, 0x3D, 0xEB, 0x10, 0x15, 0xCA, 0x71, 0xBE, 
			 0x2B, 0x73, 0xAE, 0xF0, 0x85, 0x7D, 0x77, 0x81, 
			 0x1F, 0x35, 0x2C, 0x07, 0x3B, 0x61, 0x08, 0xD7, 				     
			 0x2D, 0x98, 0x10, 0xA3, 0x09, 0x14, 0xDF, 0xF4
			},
		.klen = 32,
		.counter = { 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 
			     0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 
			     0xFE, 0xFF },
		.counterlen = 16,
		.counterbits = 128,
		.plaintext = { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 
			       0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 
			       0x17, 0x2A, 0xAE, 0x2D, 0x8A, 0x57, 0x1E, 
			       0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 
			       0x45, 0x45, 0xAF, 0x8E, 0x51, 0x30, 0xC8, 
			       0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 
			       0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF, 
			       0xF6, 0x9F, 0x24, 0x45, 0xDF, 0x4F, 0x9B, 
			       0x17, 0xAD, 0x2B, 0x41, 0x7B, 0xE6, 0x6C, 
			       0x37, 0x10 },
		.plen = 16,
		.ciphertext = { 0x60, 0x1E, 0xC3, 0x13, 0x77, 0x57, 0x89, 
				0xA5, 0xB7, 0xA7, 0xF5, 0x04, 0xBB, 0xF3, 
				0xD2, 0x28, 0xF4, 0x43, 0xE3, 0xCA, 0x4D, 
				0x62, 0xB5, 0x9A, 0xCA, 0x84, 0xE9, 0x90, 
				0xCA, 0xCA, 0xF5, 0xC5, 0x2B, 0x09, 0x30, 
				0xDA, 0xA2, 0x3D, 0xE9, 0x4C, 0xE8, 0x70, 
				0x17, 0xBA, 0x2D, 0x84, 0x98, 0x8D, 0xDF, 
				0xC9, 0xC5, 0x8D, 0xB6, 0x7A, 0xAd, 0xA6, 
				0x13, 0xC2, 0xDD, 0x08, 0x45, 0x79, 0x41,
			        0xA6 },
		.clen = 16,
	},
};


# define NUM_OF_TESTSUITES	3

const struct test_suite_info test_suites[] = {
	{
		.name="aes_ecb",
		.tvcount = 3,
		.ctv = aes_ecb_cipher_tv,
		.mechcrypt = CKM_AES_ECB,
		.mechpad = 0,
	}, {
		.name = "aes_cbc",
		.tvcount = 3,
		.ctv = aes_cbc_cipher_tv,
		.mechcrypt = CKM_AES_CBC,
		.mechpad = CKM_AES_CBC_PAD,
	},
	{
		.name = "aes_ctr",
		.tvcount = 3,
		.ctv =  aes_ctr_cipher_tv,
		.mechcrypt = CKM_AES_CTR,
		.mechpad = 0,
	}
};
