#include "core.hpp"

/*
To ensure computational fairness, the below methods use various if statements
for all possible input combinations. This means that every gate should take the
same amount of time to return regardless of input, allowing for a more accurate
representation of a real system.
*/

#define TritSetup Trit Tritret

#define TritMonadicBind(input, output)				\
if(a == Trit::input)								\
	Tritret = Trit::output;

#define TritDyadicBind(input1, input2, output)		\
if(													\
	a << BITS_PER_TRIT | b ==						\
	Trit::input1 << BITS_PER_TRIT | Trit::input2	\
)													\
	Tritret = Trit::output;

#define TritReturn { a = Tritret; return a; }

Trit& operator++(Trit& a)
{
	TritSetup;
	TritMonadicBind(FALSE,		UNKNOWN);
	TritMonadicBind(UNKNOWN,	TRUE);
	TritMonadicBind(TRUE,		FALSE);
	TritReturn;
}

Trit operator++(Trit& a, int)
{
	TritSetup;
	Tritret = a;
	++a;
	TritReturn;
}