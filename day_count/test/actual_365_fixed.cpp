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

#include <actual_365_fixed.h>

#include <gtest/gtest.h>

#include <chrono>

using namespace std;
using namespace std::chrono;


namespace fin_calendar
{
	// from "CANADIAN CONVENTIONS IN FIXED INCOME MARKETS"

	TEST(actual_365_fixed, fraction1)
	{
		const auto dc = actual_365_fixed{};

		EXPECT_NEAR(0.284931506849315, dc.fraction(2005y / December / 1d, 2006y / March / 15d), 1.0e-15);
	}

	TEST(actual_365_fixed, fraction2)
	{
		const auto dc = actual_365_fixed{};

		EXPECT_EQ(0.0, dc.fraction(2025y / May / 13d, 2025y / May / 13d));
		// add more tests:
		// end date before start date
		// more?
	}

}
