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
#include <utility>

#include <calendar.h>
#include <period.h>


namespace day_count
{

	template<typename T = double>
	class calculation_252 final
	{

	public:

		explicit calculation_252(gregorian::calendar cal);

	public:

		auto fraction(
			const std::chrono::year_month_day& start,
			const std::chrono::year_month_day& end
		) const -> T;

	private:

		gregorian::calendar cal_;

	};


	template<typename T>
	calculation_252<T>::calculation_252(gregorian::calendar cal) :
		cal_{ std::move(cal) }
	{
	}


	template<typename T>
	auto calculation_252<T>::fraction(
		const std::chrono::year_month_day& start,
		const std::chrono::year_month_day& end
	) const -> T
	{
		const auto start_end = gregorian::days_period{
			start,
			std::chrono::sys_days{ end } - std::chrono::days{ 1 } // exclude the end date
		}; // this will only work for end after start at the moment
		const auto days_between = static_cast<T>(cal_.count_business_days(start_end));

		return days_between / 252;
	}

}
