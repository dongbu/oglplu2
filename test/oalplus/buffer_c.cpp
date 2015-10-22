/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oalplus/al.hpp>
#include <oalplus/buffer.hpp>
#include "helper/object_c.hpp"

using namespace oalplus;

void oalplus_buffer_test_1(void)
{
	oalplus_object_name_test<buffer_name>();
	oalplus_object_test<buffer>();
}

// TODO