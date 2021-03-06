# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

import os
import ycm_core

def ThisDir():
	return os.path.dirname(os.path.abspath(__file__))

def MakePathAbsolute(path, work_dir):
	if not os.path.isabs(path):
		path = os.path.normpath(os.path.join(work_dir, path))
	return path

def MakeOptionPathsAbsolute(old_opts, work_dir = ThisDir()):
	new_opts = list()
	make_next_abs = False
	path_flags = ['-isystem', '-I', '-iquote', '--sysroot=']

	for opt in old_opts:
		new_opt = opt
		if make_next_abs:
			new_opt = MakePathAbsolute(opt, work_dir)
			make_next_abs = False
		else:
			for path_flag in path_flags:
				if opt == path_flag:
					make_next_abs = True
					break
				if opt.startswith(path_flag):
					path = opt[len(path_flag):]
					new_opt = path_flag + MakePathAbsolute(path, work_dir)
					break

		new_opts += [new_opt]
	return new_opts

def BuildDir():
	try:
		with open(os.path.join(ThisDir(), "BINARY_DIR"), "rt") as bdf:
			return MakePathAbsolute(bdf.read(), ThisDir())
	except: pass
	return os.path.join(ThisDir(), "_build")

default_opts = [
	'-pedantic',
	'-Wall',
	'-Weverything',
	'-Werror',
	'-Wno-c++98-compat',
	'-Wno-c++98-compat-pedantic',
	'-Wno-undef',
	'-Wno-global-constructors',
	'-Wno-exit-time-destructors',
	'-Wno-date-time',
	'-Wno-weak-vtables',
	'-Wno-padded',
	'-Wno-missing-prototypes',
	'-Wno-documentation-unknown-command',
	'-Wno-switch-enum',
	'-std=c++14',
	'-x', 'c++',
	'-isystem', '/usr/include',
	'-isystem', '/usr/local/include',
	'-I', os.path.join(BuildDir(), "include"),
	'-I', 'include',
	'-I', 'implement',
	'-I', 'third_party/include',
	'-I', 'third_party/GSL/include',
	'-I', 'source/utils'
]

def FlagsForFile(filename, ** kwargs):

	final_opts = MakeOptionPathsAbsolute(default_opts)

	path, ext = os.path.splitext(filename)

	if ext == ".inl":
		def repl(x): return 'include' if name == 'implement' else name
		path = os.path.sep.join([repl(name) for name in path.split(os.path.sep)])
		inl_header = path + '.hpp'

		if os.path.isfile(inl_header):
			final_opts += ['-include', inl_header]

	return {
		'flags': final_opts,
		'do_cache': True
	}
