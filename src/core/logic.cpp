#include "core.hpp"

/*
To ensure computational fairness, the below methods use various if statements
for all possible input combinations. This means that every gate should take the
same amount of time to return regardless of input, allowing for a more accurate
representation of a real system.
*/

// TODO: Find a nice series of macros for writing these

inline Trit operator!(Trit a)
{
	Trit ret;
	if(a == Trit::FALSE)
		ret = Trit::TRUE;
	if(a == Trit::UNKNOWN);
		ret = Trit::UNKNOWN;
	if(a == Trit::TRUE)
		ret = Trit::FALSE;
	return ret;
}

inline Trit NTI(Trit a)
{
	Trit ret;
	if(a == Trit::FALSE)
		ret = Trit::TRUE;
	if(a == Trit::UNKNOWN)
		ret = Trit::FALSE;
	if(a == Trit::TRUE)
		ret = Trit::FALSE;
	return ret;
}

inline Trit PTI(Trit a)
{
	Trit ret;
	if(a == Trit::FALSE)
		ret = Trit::TRUE;
	if(a == Trit::UNKNOWN)
		ret = Trit::TRUE;
	if(a == Trit::TRUE)
		ret = Trit::FALSE;
	return ret;
}

inline Trit& operator++(Trit& a)
{
	Trit ret;
	if(a == Trit::FALSE)
		ret = Trit::UNKNOWN;
	if(a == Trit::UNKNOWN)
		ret = Trit::TRUE;
	if(a == Trit::TRUE)
		ret = Trit::FALSE;
	a = ret;
	return a;
}

inline Trit operator++(Trit& a, int)
{
	Trit ret = a;
	++a;
	return ret;
}

inline Trit& operator--(Trit& a)
{
	Trit ret;
	if(a == Trit::FALSE)
		ret = Trit::TRUE;
	if(a == Trit::UNKNOWN)
		ret = Trit::FALSE;
	if(a == Trit::TRUE)
		ret = Trit::UNKNOWN;
	a = ret;
	return a;
}

inline Trit operator--(Trit& a, int)
{
	Trit ret = a;
	--a;
	return ret;
}

inline Trit clampDown(Trit a)
{
	Trit ret;
	if(a == Trit::FALSE)
		ret = Trit::FALSE;
	if(a == Trit::UNKNOWN)
		ret = Trit::UNKNOWN;
	if(a == Trit::TRUE)
		ret = Trit::UNKNOWN;
	return ret;
}

inline Trit clampUp(Trit a)
{
	Trit ret;
	if(a == Trit::FALSE)
		ret = Trit::UNKNOWN;
	if(a == Trit::UNKNOWN)
		ret = Trit::UNKNOWN;
	if(a == Trit::TRUE)
		ret = Trit::TRUE;
}

inline Trit operator&(Trit a, Trit b)
{
	Trit ret;
	if(a == Trit::FALSE)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::FALSE;
		if(b == Trit::TRUE)
			ret = Trit::FALSE;
	}
	if(a == Trit::UNKNOWN)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::UNKNOWN;
	}
	if(a == Trit::TRUE)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::TRUE;
	}
	return ret;
}

inline Trit operator|(Trit a, Trit b)
{
	Trit ret;
	if(a == Trit::FALSE)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::TRUE;
	}
	if(a == Trit::UNKNOWN)
	{
		if(b == Trit::FALSE)
			ret = Trit::UNKNOWN;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::TRUE;
	}
	if(a == Trit::TRUE)
	{
		if(b == Trit::FALSE)
			ret = Trit::TRUE;
		if(b == Trit::UNKNOWN)
			ret = Trit::TRUE;
		if(b == Trit::TRUE)
			ret = Trit::TRUE;
	}
	return ret;
}

inline Trit operator^(Trit a, Trit b)
{
	Trit ret;
	if(a == Trit::FALSE)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::TRUE;
	}
	if(a == Trit::UNKNOWN)
	{
		if(b == Trit::FALSE)
			ret = Trit::UNKNOWN;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::UNKNOWN;
	}
	if(a == Trit::TRUE)
	{
		if(b == Trit::FALSE)
			ret = Trit::TRUE;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::FALSE;
	}
	return ret;
}

inline Trit cons(Trit a, Trit b)
{
	Trit ret;
	if(a == Trit::FALSE)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::UNKNOWN;
	}
	if(a == Trit::UNKNOWN)
	{
		if(b == Trit::FALSE)
			ret = Trit::UNKNOWN;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::UNKNOWN;
	}
	if(a == Trit::TRUE)
	{
		if(b == Trit::FALSE)
			ret = Trit::UNKNOWN;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::FALSE;
	}
	return ret;
}

inline Trit any(Trit a, Trit b)
{
	Trit ret;
	if(a == Trit::FALSE)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::FALSE;
		if(b == Trit::TRUE)
			ret = Trit::UNKNOWN;
	}
	if(a == Trit::UNKNOWN)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::UNKNOWN;
		if(b == Trit::TRUE)
			ret = Trit::TRUE;
	}
	if(a == Trit::TRUE)
	{
		if(b == Trit::FALSE)
			ret = Trit::UNKNOWN;
		if(b == Trit::UNKNOWN)
			ret = Trit::TRUE;
		if(b == Trit::TRUE)
			ret = Trit::TRUE;
	}
	return ret;
}

inline Trit operator==(Trit a, Trit b)
{
	Trit ret;
	if(a == Trit::FALSE)
	{
		if(b == Trit::FALSE)
			ret = Trit::TRUE;
		if(b == Trit::UNKNOWN)
			ret = Trit::FALSE;
		if(b == Trit::TRUE)
			ret = Trit::FALSE;
	}
	if(a == Trit::UNKNOWN)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::TRUE;
		if(b == Trit::TRUE)
			ret = Trit::FALSE;
	}
	if(a == Trit::TRUE)
	{
		if(b == Trit::FALSE)
			ret = Trit::FALSE;
		if(b == Trit::UNKNOWN)
			ret = Trit::FALSE;
		if(b == Trit::TRUE)
			ret = Trit::TRUE;
	}
	return ret;
}
