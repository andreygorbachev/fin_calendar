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

#include "1_1.h"
#include "actual_actual.h"
#include "actual_actual_ICMA.h"
#include "actual_365_fixed.h"
#include "actual_360.h"
#include "calculation_252.h"


namespace day_count
{

	using day_count = std::variant<
		one_1,
		actual_actual,
		actual_actual_ICMA,
		actual_365_fixed,
		actual_360,
		calculation_252
	>;


	inline auto fraction(
		const std::chrono::year_month_day& start,
		const std::chrono::year_month_day& end,
		const day_count& dc
	) -> double
	{
		using double_fraction = std::chrono::duration<double, std::chrono::years::period>; // this allows year fraction to be something different from double (like decimal)

		const auto df = std::visit(
			[&](const auto& dc) { return double_fraction{ dc.fraction(start, end) }; },
			dc
		);

		return df.count();
	}

}
