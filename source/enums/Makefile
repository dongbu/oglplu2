#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt)
#
LIBS = oglplus eglplus oalplus oalplus_alc oalplus_alut

.PHONY: all
all: $(addprefix all-,$(LIBS))

.PHONY: all-%
all-%:
	cd $* && make && cd ..
