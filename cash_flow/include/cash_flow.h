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


namespace fin_calendar
{

	template<typename T = double>
	class cash_flow final
	{

	public:

		explicit cash_flow(std::chrono::year_month_day payment_date, T amount) noexcept;
		// we can also add currency here (to allow securities to make payments in more than one currency)
		// if currency has a calendar associated with it we can also check that we have a good payment date here

	public:

		auto get_payment_date() const noexcept -> const std::chrono::year_month_day&;
		auto get_amount() const noexcept -> const T&;

	private:

		std::chrono::year_month_day payment_date_{};
		T amount_{};

	};


	template<typename T>
	cash_flow<T>::cash_flow(std::chrono::year_month_day payment_date, T amount) noexcept :
		payment_date_{ std::move(payment_date) },
		amount_{ std::move(amount) }
	{
	}


	template<typename T>
	auto cash_flow<T>::get_payment_date() const noexcept -> const std::chrono::year_month_day&
	{
		return payment_date_;
	}

	template<typename T>
	auto cash_flow<T>::get_amount() const noexcept -> const T&
	{
		return amount_;
	}

}
