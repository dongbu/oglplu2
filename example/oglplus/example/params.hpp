/**
 *  .file oglplus/example/params.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_PARAMS_1512120710_HPP
#define OGLPLUS_EXAMPLE_PARAMS_1512120710_HPP

#include <eagine/valid_if/positive.hpp>
#include <eagine/valid_if/not_empty.hpp>
#include <oglplus/utils/cstr_ref.hpp>
#include <oglplus/utils/quantities.hpp>
#include <cassert>

namespace oglplus {

enum class example_resource_type
{
	texture_image,
	shader_source,
	program_source
};

class example_params
{
private:
	unsigned _rand_seed;

	cstr_ref _exec_cmd;
	cstr_ref _framedump_prefix;
	cstr_ref _screenshot_path;
	float _screenshot_time;
	float _fixed_fps;

	int _x_pos;
	int _y_pos;

	int _x_tiles;
	int _y_tiles;

	int _samples;

	int _color_bits;
	int _alpha_bits;
	int _depth_bits;
	int _stencil_bits;

	bool _compat_ctxt;
	bool _debug_ctxt;
	bool _auto_tiles;
	bool _demo_mode;
public:
	example_params(void)
	noexcept;

	example_params& exec_command(eagine::valid_if_not_empty<cstr_ref> cmd)
	{
		_exec_cmd = cmd.value();
		return *this;
	}

	cstr_ref exec_command(void) const
	noexcept
	{
		return _exec_cmd;
	}

	bool is_readable_file(cstr_ref path) const
	noexcept;

	eagine::valid_if_not_empty<std::string>
	find_resource_file_path(cstr_ref res_group, cstr_ref res_name) const
	noexcept;

	eagine::valid_if_not_empty<std::string>
	find_resource_file_path(cstr_ref res_name) const
	noexcept
	{
		return find_resource_file_path(cstr_ref(), res_name);
	}

	eagine::valid_if_not_empty<std::string>
	find_resource_file_path(example_resource_type, cstr_ref res_name) const
	noexcept;

	std::string
	get_resource_file_path(example_resource_type, cstr_ref res_name) const;

	example_params&
	screenshot_path(eagine::valid_if_not_empty<cstr_ref> path)
	{
		_screenshot_path = path.value();
		return *this;
	}

	cstr_ref screenshot_path(void) const
	noexcept
	{
		return _screenshot_path;
	}

	bool doing_screenshot(void) const
	noexcept
	{
		return !_screenshot_path.empty();
	}

	example_params& screenshot_time(seconds_t<float> ss_time)
	{
		_screenshot_time = value(ss_time);
		return *this;
	}

	seconds_t<float> screenshot_time(void) const
	noexcept
	{
		return seconds_(_screenshot_time);
	}

	example_params&
	framedump_prefix(eagine::valid_if_not_empty<cstr_ref> prefix)
	{
		_framedump_prefix = prefix.value();
		return *this;
	}

	cstr_ref framedump_prefix(void) const
	noexcept
	{
		return _framedump_prefix;
	}

	bool doing_framedump(void) const
	noexcept
	{
		return !_framedump_prefix.empty();
	}

	bool fixed_framerate(void) const
	noexcept
	{
		return  doing_screenshot() || doing_framedump();
	}

	example_params& fixed_fps(eagine::valid_if_positive<float> fps)
	noexcept
	{
		_fixed_fps = fps.value();
		return *this;
	}

	float frame_time(void) const
	noexcept
	{
		return 1.0f/_fixed_fps;
	}

	example_params& window_x_pos(int pos)
	noexcept
	{
		_x_pos = pos;
		return *this;
	}

	int window_x_pos(void) const
	noexcept
	{
		return _x_pos;
	}

	example_params& window_y_pos(int pos)
	noexcept
	{
		_y_pos = pos;
		return *this;
	}

	int window_y_pos(void) const
	noexcept
	{
		return _y_pos;
	}

	example_params& rand_seed(unsigned seed)
	noexcept
	{
		_rand_seed = seed;
		return *this;
	}

	unsigned rand_seed(void) const
	noexcept
	{
		return _rand_seed;
	}

	example_params& compatibility_context(bool v)
	noexcept
	{
		_compat_ctxt = v;
		return *this;
	}

	bool compatibility_context(void) const
	noexcept
	{
		return _compat_ctxt;
	}

	example_params& debugging_context(bool v)
	noexcept
	{
		_debug_ctxt = v;
		return *this;
	}

	bool debugging_context(void) const
	noexcept
	{
		return _debug_ctxt;
	}

	example_params& auto_tiles(bool v)
	noexcept
	{
		_auto_tiles = v;
		return *this;
	}

	bool auto_tiles(void) const
	noexcept
	{
		return _auto_tiles;
	}

	example_params& x_tiles(eagine::valid_if_positive<int> n)
	noexcept
	{
		_x_tiles = n.value();
		return *this;
	}

	int x_tiles(void) const
	noexcept
	{
		return _x_tiles;
	}

	example_params& y_tiles(eagine::valid_if_positive<int> n)
	noexcept
	{
		_y_tiles = n.value();
		return *this;
	}

	int y_tiles(void) const
	noexcept
	{
		return _y_tiles;
	}

	example_params& demo_mode(bool v)
	noexcept
	{
		_demo_mode = v;
		return *this;
	}

	bool demo_mode(void) const
	noexcept
	{
		return _demo_mode;
	}

	example_params& samples(eagine::valid_if_positive<int> n)
	noexcept
	{
		_samples = n.value();
		return *this;
	}

	example_params& samples_dont_care(void)
	noexcept
	{
		_samples = 0;
		return *this;
	}

	eagine::valid_if_positive<int> samples(void) const
	noexcept
	{
		return _samples;
	}

	example_params& color_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_color_bits = n;
		return *this;
	}

	int color_bits(void) const
	noexcept
	{
		return _color_bits;
	}

	example_params& with_alpha(bool v)
	noexcept
	{
		_alpha_bits = v?8:0;
		return *this;
	}

	int alpha_bits(void) const
	noexcept
	{
		return _alpha_bits;
	}

	example_params& depth_buffer(bool v)
	noexcept
	{
		_depth_bits = v?24:0;
		return *this;
	}

	int depth_bits(void) const
	noexcept
	{
		return _depth_bits;
	}

	bool depth_buffer(void) const
	noexcept
	{
		return _depth_bits > 0;
	}

	example_params& stencil_buffer(bool v)
	noexcept
	{
		_stencil_bits = v?8:0;
		return *this;
	}

	int stencil_bits(void) const
	noexcept
	{
		return _stencil_bits;
	}

	bool stencil_buffer(void) const
	noexcept
	{
		return _stencil_bits > 0;
	}
};

extern
void adjust_params(example_params&);

} // namespace oglplus

#endif
