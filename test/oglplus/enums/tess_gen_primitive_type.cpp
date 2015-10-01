//  File test/oglplus/enums/tess_gen_primitive_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_tess_gen_primitive_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_tess_gen_primitive_type)

BOOST_AUTO_TEST_CASE(enum_tess_gen_primitive_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	tess_gen_primitive_type x;
	(void)x;

#ifdef GL_ISOLINES
	x = ev.isolines;
	BOOST_CHECK(x == ev.isolines);
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_QUADS
	x = ev.quads;
# ifdef GL_ISOLINES
	BOOST_CHECK(x != ev.isolines);
# endif
	BOOST_CHECK(x == ev.quads);
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_TRIANGLES
	x = ev.triangles;
# ifdef GL_ISOLINES
	BOOST_CHECK(x != ev.isolines);
# endif
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
	BOOST_CHECK(x == ev.triangles);
#endif
}

BOOST_AUTO_TEST_SUITE_END()