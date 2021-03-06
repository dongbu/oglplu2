/**
 *  @file oglplus/texgen/blur2d_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <string>
#include <iostream>
#include <cassert>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
blur2d_output::blur2d_output(node_intf& parent)
 : base_output(parent)
 , input(parent, cstr_ref("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
blur2d_output::type_name(void)
{
	return cstr_ref("Blur2D");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
blur2d_output::value_type(void)
{
	return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
blur2d_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	const float z = 0.f;
	const float o = 1.f;

	out << "\t" << data_type_name(value_type()) << std::endl;
	out << "\tr  = 0.20*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{ z, z, z}};
	out << ";" << std::endl;

	out << "\tr += 0.10*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{-o, z, z}};
	out << ";" << std::endl;

	out << "\tr += 0.10*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{ o, z, z}};
	out << ";" << std::endl;

	out << "\tr += 0.10*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{ z,-o, z}};
	out << ";" << std::endl;

	out << "\tr += 0.10*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{ z, o, z}};
	out << ";" << std::endl;

	out << "\tr += 0.05*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{-o,-o, z}};
	out << ";" << std::endl;

	out << "\tr += 0.05*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{-o, o, z}};
	out << ";" << std::endl;

	out << "\tr += 0.05*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{ o,-o, z}};
	out << ";" << std::endl;

	out << "\tr += 0.05*";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass_voxel_offs{input.output(),{ o, o, z}};
	out << ";" << std::endl;

	out << "\treturn r;" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

