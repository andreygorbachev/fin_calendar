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

#include <calendar.h>
//#include <schedule.h>


namespace day_count
{

	class actual_actual
	{

	public:

		auto fraction(
			const std::chrono::year_month_day& start,
			const std::chrono::year_month_day& end
		) const noexcept;

	};


	using _365s = std::chrono::duration<int, std::ratio_divide<std::chrono::years::period, std::ratio<365>>>;
	using _366s = std::chrono::duration<int, std::ratio_divide<std::chrono::years::period, std::ratio<366>>>;

	inline auto actual_actual::fraction(
		const std::chrono::year_month_day& start,
		const std::chrono::year_month_day& end
	) const noexcept
	{
		const auto start_year = start.year();
		const auto end_year = end.year();

		if (start_year == end_year)
		{
			const auto start_date = std::chrono::sys_days{ start };
			const auto end_date = std::chrono::sys_days{ end };
			const auto days_between = (end_date - start_date).count();

			if (start_year.is_leap())
				return _366s{ days_between } + _365s{ 0 }; // maybe specify the return type explicitly, so no need to do magic here
			else
				return _366s{ 0 } + _365s{ days_between };
		}
		else
			return
				fraction(start, start_year / gregorian::LastDayOfDecember) + // might not be right
				fraction(end_year / gregorian::FirstDayOfJanuary, end) +
				_365s{ ((end_year - start_year).count() - 1) * 365};
//				end_year - start_year - 1;
	}

}
