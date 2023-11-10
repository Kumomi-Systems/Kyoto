#pragma once

#include <src/compiler.h>

#define BITS_PER_TRIT	2
#define BITS_PER_BYTE	8
#define TRIT_MASK		0b11
 
typedef enum Trit:unsigned char
{
	FALSE	= 0b00,	// This allows us to do some clever boolean casting
	UNKNOWN	= 0b01,
	TRUE	= 0b10
} Trit;

#define BYTES_PER_TRYTE	3
#define TRITS_PER_TRYTE	9

OPTION_PACKED
/// Tryte class
class Tryte
{
	public:
		Tryte();
		Tryte(Trit trits[TRITS_PER_TRYTE]);

		void SetTrit(unsigned char index, Trit value);
		Trit GetTrit(unsigned char index);

	private:
		unsigned char Trits[BYTES_PER_TRYTE];
};

Trit& operator++(Trit& a);
Trit operator++(Trit& a, int);
