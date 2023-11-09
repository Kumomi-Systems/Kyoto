#pragma once

// Detect compiler

#ifdef _ACC_
	#define COMPILER_ACC
#endif
#ifdef __clang__
	#define COMPILER_CLANG
#endif
#ifdef __BORLANDC__
	#define COMPILER_BORLAND
#endif
#ifdef __GNUC__
	#define COMPILER_GCC
#endif
#ifdef _MSC_VER
	#define COMPILER_MSVC
#endif

#if defined(COMPILER_MSVC) || defined(COMPILER_GCC)
	#define OPTION_PACKED _Pragma("pack(1)")
#endif
#if defined(COMPILER_ACC)
	#define OPTION_PACKED _Pragma("pack 1")
#endif

