/**
 *  .file oglplus/example/state_view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_STATE_VIEW_1512120710_HPP
#define OGLPLUS_EXAMPLE_STATE_VIEW_1512120710_HPP

#include <eagine/value_with_history.hpp>
#include <cassert>
#include <eagine/valid_if/positive.hpp>
#include <oglplus/utils/quantities.hpp>

namespace oglplus {

template <typename T>
using example_state_value = eagine::value_with_history<T, 3>;

template <typename T>
using example_state_variable = eagine::variable_with_history<T, 3>;

class example_state_view {

protected:
	example_state_variable<eagine::valid_if_positive<int>> _width;
	example_state_variable<eagine::valid_if_positive<int>> _height;
	example_state_variable<eagine::valid_if_positive<int>> _depth;

	example_state_variable<int> _mouse_x;
	example_state_variable<int> _mouse_y;
	example_state_variable<int> _mouse_z;

	static constexpr const int _mouse_btn_count = 4;
	example_state_variable<bool> _mouse_btn[_mouse_btn_count];

	example_state_variable<float> _exe_time;
	float _usr_act_time;

	bool _notice_user_activity(bool something_changed = true)
	noexcept;

	int _frame_no;

	int _x_tiles, _tile_i;
	int _y_tiles, _tile_j;

	bool _old_user_idle : 1;
	bool _new_user_idle : 1;

	example_state_view(void)
	noexcept;
public:
	const auto& width(void) const
	noexcept { return _width; }

	const auto& height(void) const
	noexcept { return _height; }

	const auto& depth(void) const
	noexcept { return _depth; }

	const auto& mouse_x(void) const
	noexcept { return _mouse_x; }

	const auto& mouse_y(void) const
	noexcept { return _mouse_y; }

	const auto& mouse_z(void) const
	noexcept { return _mouse_z; }

	auto aspect(void) const
	noexcept {
		return width().as<float>()/height().as<float>();
	}

	seconds_t<float> exec_time(void) const
	noexcept {
		return seconds_(_exe_time.value());
	}

	seconds_t<float> user_activity_time(void) const
	noexcept {
		return seconds_(_usr_act_time);
	}

	seconds_t<float> user_idle_time(void) const
	noexcept {
		return exec_time() - user_activity_time();
	}

	example_state_value<bool> user_idle(void) const
	noexcept {
		return {_new_user_idle, _old_user_idle};
	}

	bool user_became_idle(void) const
	noexcept {
		return user_idle().delta() > 0;
	}

	bool user_became_active(void) const
	noexcept {
		return user_idle().delta() < 0;
	}

	seconds_t<float> frame_duration(void) const
	noexcept {
		return seconds_(_exe_time.delta());
	}

	int frame_number(void) const
	noexcept { return _frame_no; }

	int x_tiles(void) const
	noexcept { return _x_tiles; }

	int tile_i(void) const
	noexcept {
		assert(_tile_i < _x_tiles);
		return _tile_i;
	}

	int tile_w(void) const
	noexcept {
		return (width()/x_tiles())+((tile_i()+1 == x_tiles())?1:0);
	}

	int tile_x(void) const
	noexcept {
		return tile_i()*(width()/x_tiles());
	}

	int y_tiles(void) const
	noexcept { return _y_tiles; }

	int tile_j(void) const
	noexcept {
		assert(_tile_j < _y_tiles);
		return _tile_j;
	}

	int tile_h(void) const
	noexcept {
		return (height()/y_tiles())+((tile_j()+1 == y_tiles())?1:0);
	}

	int tile_y(void) const
	noexcept {
		return tile_j()*(height()/y_tiles());
	}

	bool multiple_tiles(void) const
	noexcept {
		return x_tiles() > 1 || y_tiles() > 1;
	}

	example_state_value<bool>
	mouse_button_pressed(int button) const
	noexcept;

	bool pointer_dragging(int index = 0) const
	noexcept;

	example_state_value<float>
	norm_pointer_x(int index = 0) const
	noexcept;

	example_state_value<float>
	norm_pointer_y(int index = 0) const
	noexcept;

	example_state_value<float>
	norm_pointer_z(int index = 0) const
	noexcept;

	example_state_value<float>
	ndc_pointer_x(int index = 0) const
	noexcept;

	example_state_value<float>
	ndc_pointer_y(int index = 0) const
	noexcept;

	example_state_value<float>
	pointer_radius(int index = 0) const
	noexcept;

	example_state_value<radians_t<float>>
	pointer_angle(int index = 0) const
	noexcept;
};

class example_state;

} // namespace oglplus

#endif
