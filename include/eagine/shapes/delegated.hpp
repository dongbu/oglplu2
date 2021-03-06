/**
 *  @file eagine/shapes/delegated.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_DELEGATED_1509260923_HPP
#define EAGINE_SHAPES_DELEGATED_1509260923_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <memory>

namespace eagine {
namespace shapes {

class delegated_gen
 : public generator_intf
{
private:
	std::unique_ptr<generator_intf> _gen;
public:
	delegated_gen(std::unique_ptr<generator_intf>&& gen)
	noexcept
	 : _gen(std::move(gen))
	{ }

	span_size_t vertex_count(void)
	override { return _gen->vertex_count(); }

	span_size_t values_per_vertex(vertex_attrib_kind attr)
	override { return _gen->values_per_vertex(attr); }

	void attrib_values(vertex_attrib_kind attr, const span<float>& dest)
	override { _gen->attrib_values(attr, dest); }

	index_data_type index_type(void)
	override { return _gen->index_type(); }

	span_size_t index_count(void)
	override { return _gen->index_count(); }

	void indices(const span<unsigned>& dest)
	override { _gen->indices(dest); }

	span_size_t operation_count(void)
	override { return _gen->operation_count(); }

	void instructions(const span<draw_operation>& ops)
	override { _gen->instructions(ops); }
};

} // namespace shapes
} // namespace eagine

#endif // include guard
