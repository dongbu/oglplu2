/**
 *  @file eagine/valid_if/lt_size_ge0.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_LT_SIZE_GE0_1509260923_HPP
#define EAGINE_VALID_IF_LT_SIZE_GE0_1509260923_HPP

#include "in_class.hpp"

namespace eagine {

// valid if greater than or equal to 0 and less than container.size()
template <typename T, typename C>
struct valid_if_lt_size_ge0_policy
{
	bool operator()(T x, const C& c) const
	{
		return (T(0) <= x) && (x < c.size());
	}

	struct do_log
	{
		inline
		do_log(const valid_if_lt_size_ge0_policy<T, C>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v, const C& c) const
		{
			log	<< "Value " << v << ", less than zero or "
				<< "not less than c.size() = "
				<< c.size() << " is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value less than 0 or not less than c.size() is invalid"
			);
		}
	};
};

template <typename C, typename T>
using valid_if_lt_size_ge0 =
	in_class_valid_if<T, C, valid_if_lt_size_ge0_policy<T, C>>;

template <typename C>
using valid_range_index = valid_if_lt_size_ge0<C, typename C::size_type>;

} // namespace eagine

#endif // include guard