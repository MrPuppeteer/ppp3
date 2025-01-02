CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++

default: 1.2.hello_world.out 1.3.hello_world_err.out

1.2.hello_world.out: std.pcm 1.2.hello_world.cpp
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

1.3.hello_world_err.out: std.pcm 1.3.hello_world_err.cpp
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^
