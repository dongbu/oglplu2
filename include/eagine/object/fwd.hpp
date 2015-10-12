/**
 *  @file eagine/object/fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OBJECT_FWD_1509260923_HPP
#define EAGINE_OBJECT_FWD_1509260923_HPP

#include "../nothing.hpp"

namespace eagine {

template <typename ObjTag>
struct object_traits;

template <typename ObjTag>
struct object_subtype
 : nothing_t
{ };

template <typename ObjTag>
using object_subtype_t = typename object_subtype<ObjTag>::type;

template <typename ObjTag, typename Storage>
class object_names;

template <typename ObjTag>
using object_name = object_names<
	ObjTag,
	typename object_traits<ObjTag>::name_type
>;

template <typename ObjTag>
class object_zero;

template <typename ObjectNames>
class owned;

template <typename ObjTag>
class object_owner;

} // namespace eagine

#endif // include guard
