//  File test/oglplus/enums/framebuffer_status.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_framebuffer_status

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_framebuffer_status)

BOOST_AUTO_TEST_CASE(enum_framebuffer_status_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_status x;
	(void)x;

#ifdef GL_FRAMEBUFFER_COMPLETE
	x = ev.framebuffer_complete;
	BOOST_CHECK(x == ev.framebuffer_complete);
# ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	BOOST_CHECK(x != ev.framebuffer_incomplete_layer_targets);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	x = ev.framebuffer_incomplete_attachment;
# ifdef GL_FRAMEBUFFER_COMPLETE
	BOOST_CHECK(x != ev.framebuffer_complete);
# endif
	BOOST_CHECK(x == ev.framebuffer_incomplete_attachment);
# ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	BOOST_CHECK(x != ev.framebuffer_incomplete_layer_targets);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	x = ev.framebuffer_incomplete_layer_targets;
# ifdef GL_FRAMEBUFFER_COMPLETE
	BOOST_CHECK(x != ev.framebuffer_complete);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_attachment);
# endif
	BOOST_CHECK(x == ev.framebuffer_incomplete_layer_targets);
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	x = ev.framebuffer_incomplete_missing_attachment;
# ifdef GL_FRAMEBUFFER_COMPLETE
	BOOST_CHECK(x != ev.framebuffer_complete);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	BOOST_CHECK(x != ev.framebuffer_incomplete_layer_targets);
# endif
	BOOST_CHECK(x == ev.framebuffer_incomplete_missing_attachment);
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	x = ev.framebuffer_incomplete_multisample;
# ifdef GL_FRAMEBUFFER_COMPLETE
	BOOST_CHECK(x != ev.framebuffer_complete);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	BOOST_CHECK(x != ev.framebuffer_incomplete_layer_targets);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
	BOOST_CHECK(x == ev.framebuffer_incomplete_multisample);
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_UNDEFINED
	x = ev.framebuffer_undefined;
# ifdef GL_FRAMEBUFFER_COMPLETE
	BOOST_CHECK(x != ev.framebuffer_complete);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	BOOST_CHECK(x != ev.framebuffer_incomplete_layer_targets);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
	BOOST_CHECK(x == ev.framebuffer_undefined);
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_UNSUPPORTED
	x = ev.framebuffer_unsupported;
# ifdef GL_FRAMEBUFFER_COMPLETE
	BOOST_CHECK(x != ev.framebuffer_complete);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	BOOST_CHECK(x != ev.framebuffer_incomplete_layer_targets);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
	BOOST_CHECK(x == ev.framebuffer_unsupported);
#endif
}

BOOST_AUTO_TEST_SUITE_END()