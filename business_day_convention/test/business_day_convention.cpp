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

#include <business_day_convention.h>

#include <gtest/gtest.h>

#include <chrono>
#include <exception>

#include "setup.h"

using namespace std;
using namespace std::chrono;
using namespace gregorian;


namespace fin_calendar
{

	TEST(business_day_convention, make_business_day1)
	{
		const auto& cal = make_calendar_england();
		const auto d = 2023y / January / 1d;

		auto bdc = business_day_convention{};

		const auto na = no_adjustment{};
		bdc = na;
		EXPECT_EQ(na.adjust(d, cal), make_business_day(d, bdc, cal));

		const auto f = following{};
		bdc = f;
		EXPECT_EQ(f.adjust(d, cal), make_business_day(d, bdc, cal));

		const auto mf = modified_following{};
		bdc = mf;
		EXPECT_EQ(mf.adjust(d, cal), make_business_day(d, bdc, cal));

		const auto p = preceding{};
		bdc = p;
		EXPECT_EQ(p.adjust(d, cal), make_business_day(d, bdc, cal));

		const auto mp = modified_preceding{};
		bdc = mp;
		EXPECT_EQ(mp.adjust(d, cal), make_business_day(d, bdc, cal));
	}

	TEST(business_day_convention, make_business_day2)
	{
		const auto& cal = make_calendar_england();
		const auto d = sys_days{ 2023y / January / 1d };

		auto bdc = business_day_convention{};

		const auto na = no_adjustment{};
		bdc = na;
		EXPECT_EQ(na.adjust(d, cal), make_business_day(d, bdc, cal));

		const auto f = following{};
		bdc = f;
		EXPECT_EQ(f.adjust(d, cal), make_business_day(d, bdc, cal));

		const auto mf = modified_following{};
		bdc = mf;
		EXPECT_EQ(mf.adjust(d, cal), make_business_day(d, bdc, cal));

		const auto p = preceding{};
		bdc = p;
		EXPECT_EQ(p.adjust(d, cal), make_business_day(d, bdc, cal));

		const auto mp = modified_preceding{};
		bdc = mp;
		EXPECT_EQ(mp.adjust(d, cal), make_business_day(d, bdc, cal));
	}

}
