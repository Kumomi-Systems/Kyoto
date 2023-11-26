#include "arch.hpp"

OPTION_PACKED
typedef struct HalfAdderReturn
{
	Trit sumOut;
	Trit carryOut;
};

class ALU
{
	public:

	private:
		static inline Trit sum(Trit a, Trit b);
		static HalfAdderReturn halfAdder(Trit a, Trit carryInTRUE);
};

inline Trit ALU::sum(Trit a, Trit b)
{
	return (
		((a == Trit::FALSE)		& (b == Trit::FALSE)	& Trit::TRUE)		|
		((a == Trit::FALSE)		& (b == Trit::TRUE)		& Trit::UNKNOWN)	|
		((a == Trit::UNKNOWN)	& (b == Trit::UNKNOWN)	& Trit::UNKNOWN)	|
		((a == Trit::UNKNOWN)	& (b == Trit::TRUE)		& Trit::TRUE) 		|
		((a == Trit::TRUE)		& (b == Trit::FALSE)	& Trit::UNKNOWN)		|
		((a == Trit::TRUE)		& (b == Trit::UNKNOWN)	& Trit::TRUE)
	);
}

HalfAdderReturn ALU::halfAdder(Trit a, Trit carryIn)
{
	HalfAdderReturn ret;
	ret.sumOut		= sum(a, carryIn);
	ret.carryOut	= cons(a, carryIn);
	return ret;
}
