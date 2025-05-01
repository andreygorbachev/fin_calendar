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

#include <30_360.h>

#include <gtest/gtest.h>

#include <chrono>
#include <array>

using namespace std;
using namespace std::chrono;


namespace day_count
{

	TEST(thirty_360, fraction1)
	{
		// from ISDA's 30-360-2006ISDADefs.xls

		const auto dc = thirty_360{};

		EXPECT_NEAR(0.0417, dc.fraction(2007y / January / 15d,   2007y / January / 30d),   0.0001);
		EXPECT_NEAR(0.0833, dc.fraction(2007y / January / 15d,   2007y / February / 15d),  0.0001);
		EXPECT_NEAR(0.5,    dc.fraction(2007y / January / 15d,   2007y / July / 15d),      0.0001);
		EXPECT_NEAR(0.5,    dc.fraction(2007y / September / 30d, 2008y / March / 31d),     0.0001);
		EXPECT_NEAR(0.0833, dc.fraction(2007y / September / 30d, 2007y / October / 31d),   0.0001);
		EXPECT_NEAR(1.0,    dc.fraction(2007y / September / 30d, 2008y / September / 30d), 0.0001);
		EXPECT_NEAR(0.0444, dc.fraction(2007y / January / 15d,   2007y / January / 31d),   0.0001);
		EXPECT_NEAR(0.0778, dc.fraction(2007y / January / 31d,   2007y / February / 28d),  0.0001);
		EXPECT_NEAR(0.0917, dc.fraction(2007y / February / 28d,  2007y / March / 31d),     0.0001);
		EXPECT_NEAR(0.4944, dc.fraction(2006y / August / 31d,    2007y / February / 28d),  0.0001);
		EXPECT_NEAR(0.5083, dc.fraction(2007y / February / 28d,  2007y / August / 31d),    0.0001);
		EXPECT_NEAR(0.0389, dc.fraction(2007y / February / 14d,  2007y / February / 28d),  0.0001);
		EXPECT_NEAR(1.0083, dc.fraction(2007y / February / 26d,  2008y / February / 29d),  0.0001);
		EXPECT_NEAR(0.9972, dc.fraction(2008y / February / 29d,  2009y / February / 28d),  0.0001);
		EXPECT_NEAR(0.0861, dc.fraction(2008y / February / 29d,  2008y / March / 30d),     0.0001);
		EXPECT_NEAR(0.0889, dc.fraction(2008y / February / 29d,  2008y / March / 31d),     0.0001);
		EXPECT_NEAR(0.0194, dc.fraction(2007y / February / 28d,  2007y / March / 5d),      0.0001);
		EXPECT_NEAR(0.0778, dc.fraction(2007y / October / 31d,   2007y / November / 28d),  0.0001);
		EXPECT_NEAR(0.4972, dc.fraction(2007y / August / 31d,    2008y / February / 29d),  0.0001);
		EXPECT_NEAR(0.5056, dc.fraction(2008y / February / 29d,  2008y / August / 31d),    0.0001);
		EXPECT_NEAR(0.4944, dc.fraction(2008y / August / 31d,    2009y / February / 28d),  0.0001);
		EXPECT_NEAR(0.5083, dc.fraction(2009y / February / 28d,  2009y / August / 31d),    0.0001);
	}

}
