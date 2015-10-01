/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_enum_bitfield
#include <boost/test/unit_test.hpp>

#include <eagine/enum_bitfield.hpp>

namespace eagine {

struct ec_A
 : enum_class<ec_A, unsigned>
{ using enum_class<ec_A, unsigned>::enum_class; };

struct ec_B
 : enum_class<ec_B, unsigned>
{ using enum_class<ec_B, unsigned>::enum_class; };

struct ec_C
 : enum_class<ec_C, unsigned>
{ using enum_class<ec_C, unsigned>::enum_class; };

struct ec_D
 : enum_class<ec_D, unsigned>
{ using enum_class<ec_D, unsigned>::enum_class; };

static constexpr const enum_value<unsigned, 1 << 0, mp_list<ec_A>> ev_1 = {};
static constexpr const enum_value<unsigned, 1 << 1, mp_list<ec_A, ec_B>> ev_2 = {};
static constexpr const enum_value<unsigned, 1 << 2, mp_list<ec_A, ec_B, ec_C>> ev_3 = {};
static constexpr const enum_value<unsigned, 1 << 3, mp_list<ec_B, ec_C, ec_D>> ev_4 = {};
static constexpr const enum_value<unsigned, 1 << 4, mp_list<ec_B, ec_D>> ev_5 = {};
static constexpr const enum_value<unsigned, 1 << 5, mp_list<ec_D>> ev_6 = {};

} // namespace eagine

BOOST_AUTO_TEST_SUITE(enum_bitfield)

BOOST_AUTO_TEST_CASE(enum_bitfield_1)
{
	using namespace eagine;

	enum_bitfield<ec_A> a1 = ev_1;
	BOOST_CHECK( a1.has(ev_1));
	BOOST_CHECK(!a1.has(ev_2));
	BOOST_CHECK(!a1.has(ev_3));

	enum_bitfield<ec_A> a2 = ev_2;
	BOOST_CHECK(!a2.has(ev_1));
	BOOST_CHECK( a2.has(ev_2));
	BOOST_CHECK(!a2.has(ev_3));

	enum_bitfield<ec_A> a13 = ev_1|ev_3;
	BOOST_CHECK( a13.has(ev_1));
	BOOST_CHECK(!a13.has(ev_2));
	BOOST_CHECK( a13.has(ev_3));

	enum_bitfield<ec_A> a31 = ev_3|ev_1;
	BOOST_CHECK(a13 == a31);

	enum_bitfield<ec_A> a123 = ev_1|ev_2|ev_3;

	BOOST_CHECK( a123.has(ev_1));
	BOOST_CHECK( a123.has(ev_2));
	BOOST_CHECK( a123.has(ev_3));
}

BOOST_AUTO_TEST_CASE(enum_bitfield_2)
{
	using namespace eagine;

	enum_bitfield<ec_B> b2 = ev_2;
	enum_bitfield<ec_B> b23 = b2|ev_3;

	BOOST_CHECK( b23.has(ev_2));
	BOOST_CHECK( b23.has(ev_3));
	BOOST_CHECK(!b23.has(ev_4));
	BOOST_CHECK(!b23.has(ev_5));

	enum_bitfield<ec_B> b234 = b2|ev_3|ev_4;

	BOOST_CHECK( b234.has(ev_2));
	BOOST_CHECK( b234.has(ev_3));
	BOOST_CHECK( b234.has(ev_4));
	BOOST_CHECK(!b234.has(ev_5));
}

BOOST_AUTO_TEST_CASE(enum_bitfield_3)
{
	using namespace eagine;

	enum_bitfield<ec_C> c3 = ev_3;
	BOOST_CHECK((c3 & ev_3) == ev_3);
	BOOST_CHECK((c3 & ev_4) != ev_4);

	enum_bitfield<ec_C> c4 = ev_4;
	BOOST_CHECK((c4 & ev_3) != ev_3);
	BOOST_CHECK((c4 & ev_4) == ev_4);

	enum_bitfield<ec_C> c34 = c3|c4;
	BOOST_CHECK((c34 & ev_3) == ev_3);
	BOOST_CHECK((c34 & ev_4) == ev_4);
}

BOOST_AUTO_TEST_CASE(enum_bitfield_4)
{
	using namespace eagine;

	enum_bitfield<ec_D> d;

	BOOST_CHECK(!d.has(ev_5));
	BOOST_CHECK(!d.has(ev_6));

	BOOST_CHECK(d != ev_5);
	BOOST_CHECK(d != ev_6);

	BOOST_CHECK((d|ev_5).has(ev_5));
	BOOST_CHECK((d|ev_6).has(ev_6));

	BOOST_CHECK((d|ev_5) == ev_5);
	BOOST_CHECK((d|ev_6) == ev_6);

	BOOST_CHECK(unsigned(d) == 0);
	BOOST_CHECK(unsigned(d|ev_5) == unsigned(ev_5));
	BOOST_CHECK(unsigned(d|ev_6) == unsigned(ev_6));
}

BOOST_AUTO_TEST_SUITE_END()