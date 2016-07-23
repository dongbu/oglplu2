/**
 *  @file eagine/ecs/rel_storage.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_REL_STORAGE_1509260923_HPP
#define EAGINE_ECS_REL_STORAGE_1509260923_HPP

#include "entity_traits.hpp"
#include "storage_caps.hpp"
#include "storage_fwd.hpp"
#include "../callable_ref.hpp"
#include <cassert>

namespace eagine {
namespace ecs {

template <typename Entity>
struct storage_iterator_intf<Entity, true>
{
	virtual
	~storage_iterator_intf(void) = default;

	virtual
	void reset(void) = 0;

	virtual
	bool done(void) = 0;

	virtual
	void next(void) = 0;

	virtual
	Entity parent(void) = 0;

	virtual
	Entity child(void) = 0;
};

template <typename Entity>
class storage_iterator<Entity, true>
{
private:
	storage_iterator_intf<Entity, true>* _i;
public:
	storage_iterator(storage_iterator_intf<Entity, true>* i)
	noexcept
	 : _i(i)
	{
		assert(_i);
	}

	storage_iterator(const storage_iterator&) = delete;

	storage_iterator(storage_iterator&& tmp)
	noexcept
	 : _i(tmp._i)
	{
		tmp._i = nullptr;
	}

	~storage_iterator(void)
	noexcept
	{
		assert(_i == nullptr);
	}

	storage_iterator_intf<Entity, true>* release(void)
	{
		storage_iterator_intf<Entity, true>* p = _i;
		_i = nullptr;
		return p;
	}

	storage_iterator_intf<Entity, true>* ptr(void)
	noexcept
	{
		assert(_i);
		return _i;
	}

	storage_iterator_intf<Entity, true>& get(void)
	noexcept
	{
		assert(_i);
		return *_i;
	}

	void reset(void)
	{
		get().reset();
	}

	bool done(void)
	{
		return get().done();
	}

	void next(void)
	{
		get().next();
	}

	Entity parent(void)
	{
		return get().parent();
	}

	Entity child(void)
	{
		return get().parent();
	}
};

template <typename Entity>
struct base_storage<Entity, true>
{
	typedef entity_param_t<Entity> entity_param;
	typedef storage_iterator<Entity, true> iterator_t;

	virtual
	~base_storage(void) = default;

	virtual
	storage_caps capabilities(void) = 0;

	virtual
	iterator_t new_iterator(void) = 0;

	virtual
	void delete_iterator(iterator_t&&) = 0;

	virtual
	bool has(entity_param p, entity_param c) = 0;

	virtual
	bool store(entity_param p, entity_param c) = 0;

	virtual
	bool remove(entity_param p, entity_param c) = 0;
};

template <typename Entity, typename Relation>
struct storage<Entity, Relation, true>
 : base_storage<Entity, true>
{
	typedef entity_param_t<Entity> entity_param;
	typedef storage_iterator<Entity, true> iterator_t;

	virtual
	bool store(entity_param p, entity_param c, Relation&&) = 0;

	virtual
	void for_single(
		callable_ref<void(entity_param,entity_param, const Relation&)>,
		entity_param, entity_param
	) = 0;

	virtual
	void for_single(
		callable_ref<void(entity_param,entity_param, const Relation&)>,
		iterator_t&
	) = 0;

	virtual
	void for_single(
		callable_ref<void(entity_param,entity_param, Relation&)>,
		entity_param, entity_param
	) = 0;

	virtual
	void for_single(
		callable_ref<void(entity_param,entity_param, Relation&)>,
		iterator_t&
	) = 0;

	virtual
	void for_each(
		callable_ref<void(entity_param,entity_param, const Relation&)>
	) = 0;

	virtual
	void for_each(
		callable_ref<void(entity_param,entity_param, Relation&)>
	) = 0;
};

} // namespace ecs
} // namespace eagine

#endif //include guard
