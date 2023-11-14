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

		void setTrit(unsigned char index, Trit value);
		Trit getTrit(unsigned char index);

	private:
		unsigned char trits[BYTES_PER_TRYTE];
};

/// @brief Ternary NOT operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit operator!(Trit a);
/// @brief Ternary Negative Threshold Inverter
/// @see The Ternary Manifesto (Jones, 2012)
Trit NTI(Trit a);
/// @brief Ternary Positive Threshold Inverter
/// @see The Ternary Manifesto (Jones, 2012)
Trit PTI(Trit a);
/// @brief Ternary prefix increment operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit& operator++(Trit& a);
/// @brief Ternary postfix increment operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit operator++(Trit& a, int);
/// @brief Ternary prefix decrement operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit& operator--(Trit& a);
/// @brief Ternary postfix decrement operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit operator--(Trit& a, int);
/// @brief Ternary clamp down
/// @see The Ternary Manifesto (Jones, 2012)
Trit clampDown(Trit a);
/// @brief Ternary clamp up
/// @see The Ternary Manifesto (Jones, 2012)
Trit clampUp(Trit a);
/// @brief Ternary AND operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit operator&(Trit a, Trit b);
/// @brief Ternary OR operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit operator|(Trit a, Trit b);
/// @brief Ternary XOR operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit operator^(Trit a, Trit b);
/// @brief Ternary consensus
/// @see The Ternary Manifesto (Jones, 2012)
Trit cons(Trit a, Trit b);
/// @brief Ternary accept anything
/// @see The Ternary Manifesto (Jones, 2012)
Trit any(Trit a, Trit b);
/// @brief Ternary equality operator
/// @see The Ternary Manifesto (Jones, 2012)
Trit operator==(Trit a, Trit b);
