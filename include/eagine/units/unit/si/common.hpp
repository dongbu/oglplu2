/**
 *  @file eagine/units/unit/si/common.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#pragma once

#ifndef EAGINE_UNITS_UNIT_SI_COMMON_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_COMMON_1512222148_HPP

#include "../../base_dim.hpp"
#include "../../base_unit.hpp"
#include "../../base_scaled_unit.hpp"
#include "../../unit.hpp"
#include "../../scaled_unit.hpp"

namespace eagine {
namespace units {

// international system of units
struct si
{
	template <typename BaseDim>
	struct base_unit;
};

template <>
struct system_id<si>
 : int_constant<0>
{ };

template <>
struct si::base_unit<nothing_t> : nothing_t { };

template <typename Dim>
struct si::base_unit<base::dimension<Dim>>
 : si::base_unit<Dim>
{ };

} // namespace units
} // namespace eagine

#endif //include guard

