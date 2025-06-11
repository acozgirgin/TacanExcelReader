#pragma once

#include <cstdint>
using namespace std;

namespace Enums {

	enum class Mode : uint8_t 
	{
		AG,
		AA
	};

	enum class Validty : uint8_t 
	{
		Valid,
		NotValid
	};

	enum class Extrapolation : uint8_t 
	{
		Extrapolated,
		NotExtrapolated
	};

	enum class Status: uint8_t 
	{
		Ignore,
		Pass,
		Fail
	};


	}