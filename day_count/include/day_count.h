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
#include "30_360.h"
#include "30_E_360.h"
#include "30_E_360_ISDA.h"
#include "actual_365_L.h"
#include "calculation_252.h"
#include "RBA_bond_basis.h"


namespace fin_calendar
{

	template<typename T = double>
	using day_count = std::variant<
		one_1<T>,
		actual_actual<T>,
		actual_actual_ICMA<T>,
		actual_365_fixed<T>,
		actual_360<T>,
		thirty_360<T>,
		thirty_E_360<T>,
		thirty_E_360_ISDA<T>,
		actual_365_L<T>,
		calculation_252<T>,
		RBA_bond_basis<T>
	>;


	template<typename T = double>
	auto fraction(
		const std::chrono::year_month_day& start,
		const std::chrono::year_month_day& end,
		const day_count<T>& dc
	) -> T
	{
		const auto yf = std::visit(
			[&](const auto& dc) { return dc.fraction(start, end); },
			dc
		);

		return yf;
	}

}
