/**
 *  @file eagine/ecs/cmp_storage.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_CMP_STORAGE_1509260923_HPP
#define EAGINE_ECS_CMP_STORAGE_1509260923_HPP

#include "entity_traits.hpp"
#include "storage_caps.hpp"
#include "storage_fwd.hpp"
#include "manipulator.hpp"
#include "../callable_ref.hpp"
#include <cassert>

namespace eagine {
namespace ecs {

template <typename Entity>
struct storage_iterator_intf<Entity, false>
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
	bool find(Entity) = 0;

	virtual
	Entity current(void) = 0;
};

template <typename Entity>
class storage_iterator<Entity, false>
{
private:
	storage_iterator_intf<Entity, false>* _i;
public:
	storage_iterator(storage_iterator_intf<Entity, false>* i)
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

	storage_iterator_intf<Entity, false>* release(void)
	{
		storage_iterator_intf<Entity, false>* p = _i;
		_i = nullptr;
		return p;
	}

	storage_iterator_intf<Entity, false>* ptr(void)
	noexcept
	{
		assert(_i);
		return _i;
	}

	storage_iterator_intf<Entity, false>& get(void)
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

	bool find(Entity e)
	{
		return get().find(e);
	}

	Entity current(void)
	{
		return get().current();
	}
};

template <typename Entity>
struct base_storage<Entity, false>
{
	typedef entity_param_t<Entity> entity_param;
	typedef storage_iterator<Entity, false> iterator_t;

	virtual
	~base_storage(void) = default;

	virtual
	storage_caps capabilities(void) = 0;

	virtual
	iterator_t new_iterator(void) = 0;

	virtual
	void delete_iterator(iterator_t&&) = 0;

	virtual
	bool has(entity_param) = 0;

	virtual
	bool is_hidden(entity_param) = 0;

	virtual
	bool is_hidden(iterator_t&) = 0;

	virtual
	bool hide(entity_param) = 0;

	virtual
	void hide(iterator_t&) = 0;

	virtual
	bool show(entity_param) = 0;

	virtual
	bool show(iterator_t&) = 0;

	virtual
	bool copy(entity_param from, entity_param to) = 0;

	virtual
	bool swap(entity_param a, entity_param b) = 0;

	virtual
	bool remove(entity_param) = 0;

	virtual
	void remove(iterator_t&) = 0;
};

template <typename Entity, typename Component>
struct storage<Entity, Component, false>
 : base_storage<Entity, false>
{
	typedef entity_param_t<Entity> entity_param;
	typedef storage_iterator<Entity, false> iterator_t;

	virtual
	bool store(entity_param, Component&&) = 0;

	virtual
	bool store(iterator_t&, entity_param, Component&&) = 0;

	virtual
	void for_single(
		callable_ref<void(
			entity_param,
			manipulator<const Component>&
		)>,
		entity_param
	) = 0;

	virtual
	void for_single(
		callable_ref<void(
			entity_param,
			manipulator<const Component>&
		)>,
		iterator_t&
	) = 0;

	virtual
	void for_single(
		callable_ref<void(
			entity_param,
			manipulator<Component>&
		)>,
		entity_param
	) = 0;

	virtual
	void for_single(
		callable_ref<void(
			entity_param,
			manipulator<Component>&
		)>,
		iterator_t&
	) = 0;

	virtual
	void for_each(
		callable_ref<void(
			entity_param,
			manipulator<const Component>&
		)>
	) = 0;

	virtual
	void for_each(
		callable_ref<void(
			entity_param,
			manipulator<Component>&
		)>
	) = 0;
};

} // namespace ecs
} // namespace eagine

#endif //include guard

