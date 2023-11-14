#include "core.hpp"

#include <format>
#include <stdexcept>

/// @brief Initialises a tryte to 0.
Tryte::Tryte()
{
	trits[0] = 0b00000000;
	trits[1] = 0b00000000;
	trits[2] = 0b00000000;
};

/// @brief Initialises a tryte to a specific value.
/// @param trits An array of trits to set the tryte to.
Tryte::Tryte(Trit trits[TRITS_PER_TRYTE])
{
	this->trits[2] = (unsigned char)(
		(unsigned char)trits[8]			|
		(unsigned char)trits[7] << 2	|
		(unsigned char)trits[6] << 4	|
		(unsigned char)trits[5] << 6 
	);
	this->trits[1] = (unsigned char)(
		(unsigned char)trits[4]			|
		(unsigned char)trits[3] << 2	|
		(unsigned char)trits[2] << 4	|
		(unsigned char)trits[1] << 6 
	);
	this->trits[0] = (unsigned char)trits[0];
};

/// @brief Sets a given trit of a tryte to a given value.
/// @param index Trit to set the value of.
/// @param value Value to set the trit to.
void Tryte::setTrit(unsigned char index, Trit value)
{
	if(index >= TRITS_PER_TRYTE)
		throw std::invalid_argument(
			std::format("Trit index cannot exceed or be equal to {}, an index of {} was supplied.", TRITS_PER_TRYTE, index)
		);
	
	unsigned char shift		= BITS_PER_TRIT * (index % (BITS_PER_BYTE / BITS_PER_TRIT));
	unsigned char* state	= &this->trits[
		BYTES_PER_TRYTE - 1 - ((BITS_PER_TRIT * index) / BITS_PER_BYTE)
	];

	*state = *state & ~(TRIT_MASK << shift) | (unsigned char)value << shift; 
};

/// @brief Gets a specified trit of a tryte.
/// @param index The index of the trit to get.
/// @return The trit at the specified index.
Trit Tryte::getTrit(unsigned char index)
{
	unsigned char shift		= BITS_PER_TRIT * (index % (BITS_PER_BYTE / BITS_PER_TRIT));
	unsigned char* state	= &this->trits[
		BYTES_PER_TRYTE - 1 - ((BITS_PER_TRIT * index) / BITS_PER_BYTE)
	];

	return (Trit)(*state >> shift & TRIT_MASK);
}