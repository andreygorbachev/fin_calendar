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


namespace frequency
{

	using frequency = std::variant<
		std::chrono::months // could be poisitve of negative in this setup
	>;

	constexpr auto SemiAnnual = frequency{ std::chrono::months{ 6 } };


    template<typename... Ts>
    struct overloaded : Ts... { using Ts::operator()...; };

    inline auto advance(std::chrono::year_month_day ymd, const frequency& f) -> std::chrono::year_month_day
    {
        std::visit(
            overloaded{
                [&ymd](const std::chrono::months& ms) { ymd += ms; }
            },
            f
        );

        if(ymd.ok())
            return ymd;
        else
            // to fix the bad date we snap to the last day of the month
            return ymd.year() / ymd.month() / std::chrono::last;
    }

}
