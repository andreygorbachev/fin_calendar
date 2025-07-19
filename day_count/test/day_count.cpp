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

#include "setup.h"

#include <day_count.h>

#include <gtest/gtest.h>

#include <chrono>

using namespace std;
using namespace std::chrono;


namespace fin_calendar
{

	TEST(day_count, fraction1)
	{
		auto dc = day_count<>{}; // how does this work? (do we want it to work?)

		dc = one_1{};
		EXPECT_EQ(1.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_actual{};
		EXPECT_EQ(1.0 / 365.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_actual_ICMA{};
		EXPECT_EQ(1.0 / 365.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_365_fixed{};
		EXPECT_EQ(1.0 / 365.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_360{};
		EXPECT_EQ(1.0 / 360.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = thirty_360{};
		EXPECT_EQ(1.0 / 360.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = thirty_E_360{};
		EXPECT_EQ(1.0 / 360.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = thirty_E_360_ISDA{ 2025y / April / 25d };
		EXPECT_EQ(1.0 / 360.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_365_L{};
		EXPECT_EQ(1.0 / 365.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = calculation_252{ make_calendar_ANBIMA() };
		EXPECT_EQ(1.0 / 252.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = RBA_bond_basis{};
		EXPECT_EQ(1.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));
	}

/*	TEST(day_count, fraction2)
	{
		auto dc = day_count<cpp_dec_float_50>{};

		dc = one_1{};
		EXPECT_EQ(1.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_actual{};
		EXPECT_EQ(1.0 / 365.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_actual_ICMA{};
		EXPECT_EQ(1.0 / 365.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_365_fixed{};
		EXPECT_EQ(1.0 / 365.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_360{};
		EXPECT_EQ(1.0 / 360.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = thirty_360{};
		EXPECT_EQ(1.0 / 360.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = thirty_E_360{};
		EXPECT_EQ(1.0 / 360.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = thirty_E_360_ISDA{ 2025y / April / 25d };
		EXPECT_EQ(1.0 / 360.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = actual_365_L{};
		EXPECT_EQ(1.0 / 365.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = calculation_252{ make_calendar_ANBIMA() };
		EXPECT_EQ(1.0 / 252.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));

		dc = RBA_bond_basis{};
		EXPECT_EQ(1.0, fraction(2025y / April / 24d, 2025y / April / 25d, dc));
	}*/

}
