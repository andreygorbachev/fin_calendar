// The MIT License (MIT)
//
// Copyright (c) 2025 Andrey Gorbachev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <chrono>
#include <variant>

#include <calendar.h>

#include "no_adjustment.h"
#include "following.h"
#include "modified_following.h"
#include "preceding.h"
#include "modified_preceding.h"


namespace business_day_convention
{

	using business_day_convention = std::variant<
		no_adjustment,
		following,
		modified_following,
		preceding,
		modified_preceding
	>;


	inline auto make_business_day(
		const std::chrono::year_month_day& ymd,
		const business_day_convention& bdc,
		const gregorian::calendar& cal
	)
	{
		return std::visit(
			[&](const auto& bdc)
			{
				return bdc.adjust(ymd, cal);
			},
			bdc
		);
	}

	inline auto make_business_day(
		const std::chrono::sys_days& sd,
		const business_day_convention& bdc,
		const gregorian::calendar& cal
	)
	{
		return std::visit(
			[&](const auto& bdc)
			{
				return bdc.adjust(sd, cal);
			},
			bdc
		);
	}

}
