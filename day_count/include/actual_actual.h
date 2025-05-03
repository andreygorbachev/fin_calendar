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

	template<typename T = double>
	class actual_actual final // should we call it actual_actual_ISDA?
	{

	public:

		auto fraction(
			const std::chrono::year_month_day& start,
			const std::chrono::year_month_day& end
		) const noexcept -> T;

	};


	template<typename T>
	auto actual_actual<T>::fraction(
		const std::chrono::year_month_day& start,
		const std::chrono::year_month_day& end
	) const noexcept -> T
	{
		const auto start_date = std::chrono::sys_days{ start };
		const auto end_date = std::chrono::sys_days{ end };

		const auto start_year = start.year();
		const auto end_year = end.year();

		if (start_year == end_year)
		{
			const auto days_between = static_cast<T>((end_date - start_date).count());

			if (start_year.is_leap())
				return days_between / 366;
			else
				return days_between / 365;
		}
		else
		{
			T result;

			const auto end_year_1 = std::chrono::sys_days{ start_year / gregorian::LastDayOfDecember };
			const auto days_between_1 = static_cast<T>((end_year_1 - start_date).count() + 1);
			if (start_year.is_leap())
				result = days_between_1 / 366;
			else
				result = days_between_1 / 365;

			const auto start_year_last = std::chrono::sys_days{ end_year / gregorian::FirstDayOfJanuary };
			const auto days_between_last = static_cast<T>((end_date - start_year_last).count());
			if (end_year.is_leap())
				result += days_between_last / 366;
			else
				result += days_between_last / 365;

			result += (end_year - start_year - std::chrono::years{ 1 }).count();

			return result;
		}
	}

}
