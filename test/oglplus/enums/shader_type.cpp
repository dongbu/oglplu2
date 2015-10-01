//  File test/oglplus/enums/shader_type.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_shader_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_shader_type)

BOOST_AUTO_TEST_CASE(enum_shader_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	shader_type x;
	(void)x;

#ifdef GL_COMPUTE_SHADER
	x = ev.compute_shader;
	BOOST_CHECK(x == ev.compute_shader);
# ifdef GL_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.fragment_shader);
# endif
# ifdef GL_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.geometry_shader);
# endif
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_FRAGMENT_SHADER
	x = ev.fragment_shader;
# ifdef GL_COMPUTE_SHADER
	BOOST_CHECK(x != ev.compute_shader);
# endif
	BOOST_CHECK(x == ev.fragment_shader);
# ifdef GL_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.geometry_shader);
# endif
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_GEOMETRY_SHADER
	x = ev.geometry_shader;
# ifdef GL_COMPUTE_SHADER
	BOOST_CHECK(x != ev.compute_shader);
# endif
# ifdef GL_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.fragment_shader);
# endif
	BOOST_CHECK(x == ev.geometry_shader);
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_TESS_CONTROL_SHADER
	x = ev.tess_control_shader;
# ifdef GL_COMPUTE_SHADER
	BOOST_CHECK(x != ev.compute_shader);
# endif
# ifdef GL_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.fragment_shader);
# endif
# ifdef GL_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.geometry_shader);
# endif
	BOOST_CHECK(x == ev.tess_control_shader);
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_TESS_EVALUATION_SHADER
	x = ev.tess_evaluation_shader;
# ifdef GL_COMPUTE_SHADER
	BOOST_CHECK(x != ev.compute_shader);
# endif
# ifdef GL_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.fragment_shader);
# endif
# ifdef GL_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.geometry_shader);
# endif
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
	BOOST_CHECK(x == ev.tess_evaluation_shader);
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_VERTEX_SHADER
	x = ev.vertex_shader;
# ifdef GL_COMPUTE_SHADER
	BOOST_CHECK(x != ev.compute_shader);
# endif
# ifdef GL_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.fragment_shader);
# endif
# ifdef GL_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.geometry_shader);
# endif
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
	BOOST_CHECK(x == ev.vertex_shader);
#endif
}

BOOST_AUTO_TEST_SUITE_END()