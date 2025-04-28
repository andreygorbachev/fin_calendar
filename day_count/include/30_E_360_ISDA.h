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


namespace day_count
{

	class thirty_E_360_ISDA
	{

	public:

		auto fraction(
			const std::chrono::year_month_day& start,
			const std::chrono::year_month_day& end
		) const noexcept;

	};


	using _360s = std::chrono::duration<int, std::ratio_divide<std::chrono::years::period, std::ratio<360>>>;

	inline auto thirty_E_360_ISDA::fraction(
		const std::chrono::year_month_day& start,
		const std::chrono::year_month_day& end
	) const noexcept
	{
		const auto start_year = start.year();
		const auto start_month = start.month();
		auto start_day = start.day();
		const auto end_year = end.year();
		const auto end_month = end.month();
		auto end_day = end.day();

		if (start == start.year() / start.month() / std::chrono::last)
			start_day = std::chrono::day{ 30 };
		if (end == end.year() / end.month() / std::chrono::last)
			end_day = std::chrono::day{ 30 };

		// termination date should also be part of the calculation

		const auto days_between =
			(end_year - start_year).count() * 360 +
			(end_month - start_month).count() * 30 +
			(end_day - start_day).count();

		return _360s{ days_between };
	}

}
