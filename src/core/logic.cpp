#include "core.hpp"

/*
To ensure computational fairness, the below methods use various if statements
for all possible input combinations. This means that every gate should take the
same amount of time to return regardless of input, allowing for a more accurate
representation of a real system.
*/

Trit Tritret;

#define TritMonadicBind(input, output)				\
if(a == Trit::input)								\
	Tritret = Trit::output;

#define TritDyadicBind(input1, input2, output)		\
if(													\
	a << BITS_PER_TRIT | b ==						\
	Trit::input1 << BITS_PER_TRIT | Trit::input2	\
)													\
	Tritret = Trit::output;

#define TritReturn return Tritret;

/// @brief Ternary tritwise NOT operator
Trit operator!(Trit a)
{
	TritMonadicBind(FALSE,		TRUE);
	TritMonadicBind(UNKNOWN,	UNKNOWN);
	TritMonadicBind(TRUE,		FALSE);
	TritReturn;
}

Trit NTI(Trit a)
{
	TritMonadicBind(FALSE,		TRUE);
	TritMonadicBind(UNKNOWN,	FALSE);
	TritMonadicBind(TRUE,		FALSE);
	TritReturn;
}

Trit PTI(Trit a)
{
	TritMonadicBind(FALSE,		TRUE);
	TritMonadicBind(UNKNOWN,	TRUE);
	TritMonadicBind(TRUE,		FALSE);
	TritReturn;
}

Trit operator++(Trit a)
{
	TritMonadicBind(FALSE,		UNKNOWN);
	TritMonadicBind(UNKNOWN,	TRUE);
	TritMonadicBind(TRUE,		FALSE);
	TritReturn;
}

Trit operator--(Trit a)
{
	TritMonadicBind(FALSE,		TRUE);
	TritMonadicBind(UNKNOWN,	FALSE);
	TritMonadicBind(TRUE,		UNKNOWN);
	TritReturn;
}

Trit ClampDown(Trit a)
{
	TritMonadicBind(FALSE,		FALSE);
	TritMonadicBind(UNKNOWN,	UNKNOWN);
	TritMonadicBind(TRUE,		UNKNOWN);
	TritReturn;
}

Trit ClampUp(Trit a)
{
	TritMonadicBind(FALSE,		UNKNOWN);
	TritMonadicBind(UNKNOWN,	UNKNOWN);
	TritMonadicBind(TRUE,		TRUE);
	TritReturn;
}

Trit operator&(Trit a, Trit b)
{
	TritDyadicBind(FALSE,		FALSE,		FALSE);
	TritDyadicBind(FALSE,		UNKNOWN,	FALSE);
	TritDyadicBind(FALSE,		TRUE,		FALSE);
	TritDyadicBind(UNKNOWN,		FALSE,		FALSE);
	TritDyadicBind(UNKNOWN,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(UNKNOWN,		TRUE,		UNKNOWN);
	TritDyadicBind(TRUE,		FALSE,		FALSE);
	TritDyadicBind(TRUE,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(TRUE,		TRUE,		TRUE);
	TritReturn;
}

Trit operator|(Trit a, Trit b)
{
	TritDyadicBind(FALSE,		FALSE,		FALSE);
	TritDyadicBind(FALSE,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(FALSE,		TRUE,		TRUE);
	TritDyadicBind(UNKNOWN,		FALSE,		UNKNOWN);
	TritDyadicBind(UNKNOWN,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(UNKNOWN,		TRUE,		TRUE);
	TritDyadicBind(TRUE,		FALSE,		TRUE);
	TritDyadicBind(TRUE,		UNKNOWN,	TRUE);
	TritDyadicBind(TRUE,		TRUE,		TRUE);
	TritReturn;
}

Trit operator^(Trit a, Trit b)
{
	TritDyadicBind(FALSE,		FALSE,		FALSE);
	TritDyadicBind(FALSE,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(FALSE,		TRUE,		TRUE);
	TritDyadicBind(UNKNOWN,		FALSE,		UNKNOWN);
	TritDyadicBind(UNKNOWN,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(UNKNOWN,		TRUE,		UNKNOWN);
	TritDyadicBind(TRUE,		FALSE,		TRUE);
	TritDyadicBind(TRUE,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(TRUE,		TRUE,		FALSE);
	TritReturn;
}

Trit Concensus(Trit a, Trit b)
{
	TritDyadicBind(FALSE,		FALSE,		FALSE);
	TritDyadicBind(FALSE,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(FALSE,		TRUE,		UNKNOWN);
	TritDyadicBind(UNKNOWN,		FALSE,		UNKNOWN);
	TritDyadicBind(UNKNOWN,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(UNKNOWN,		TRUE,		UNKNOWN);
	TritDyadicBind(TRUE,		FALSE,		UNKNOWN);
	TritDyadicBind(TRUE,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(TRUE,		TRUE,		TRUE);
	TritReturn;
}

Trit AcceptAnything(Trit a, Trit b)
{
	TritDyadicBind(FALSE,		FALSE,		FALSE);
	TritDyadicBind(FALSE,		UNKNOWN,	FALSE);
	TritDyadicBind(FALSE,		TRUE,		UNKNOWN);
	TritDyadicBind(UNKNOWN,		FALSE,		FALSE);
	TritDyadicBind(UNKNOWN,		UNKNOWN,	UNKNOWN);
	TritDyadicBind(UNKNOWN,		TRUE,		TRUE);
	TritDyadicBind(TRUE,		FALSE,		UNKNOWN);
	TritDyadicBind(TRUE,		UNKNOWN,	TRUE);
	TritDyadicBind(TRUE,		TRUE,		TRUE);
	TritReturn;
}

Trit operator==(Trit a, Trit b)
{
	TritDyadicBind(FALSE,		FALSE,		TRUE);
	TritDyadicBind(FALSE,		UNKNOWN,	FALSE);
	TritDyadicBind(FALSE,		TRUE,		FALSE);
	TritDyadicBind(UNKNOWN,		FALSE,		FALSE);
	TritDyadicBind(UNKNOWN,		UNKNOWN,	TRUE);
	TritDyadicBind(UNKNOWN,		TRUE,		FALSE);
	TritDyadicBind(TRUE,		FALSE,		FALSE);
	TritDyadicBind(TRUE,		UNKNOWN,	FALSE);
	TritDyadicBind(TRUE,		TRUE,		TRUE);
	TritReturn;
}