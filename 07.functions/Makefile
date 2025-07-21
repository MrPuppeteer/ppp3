CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++

.PHONY: default clean

OUTS = 7.2.0.tt.function_declaration.out 7.4.07.tt.conversion.out 7.d.1.swap_functions.out \
			 7.d.2.namespaces.out 7.d.3.use.out 7.d.4.use.out 7.e.01.calculator.out \
			 7.e.02.print_int_vector.out 7.e.03.fibonacci_vector.out 7.e.04.finding_max_fib_number.out \
			 7.e.05.reverse_vector.out 7.e.06.reverse_vector_str.out 7.e.07.name_age_pair.out \
			 7.e.08.name_age_pair_arbit.out 7.e.09.compute_sum.out 7.e.10.maxv.out 7.e.11.stats.out \
			 7.e.12.print_until.out 7.e.13.vector_str_func.out 7.e.14.calc_price.out \
			 7.e.14.print_message.out

default: std.pcm foo.pcm ${OUTS}

%.out: %.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

7.d.3.use.out: 7.d.3.use.cpp std.pcm foo.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -fmodule-file=foo=foo.pcm -o $@ $^

7.d.4.use.out: 7.d.4.use.cpp 7.d.4.foo.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^

foo.pcm: 7.d.3.foo.cppm std.pcm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -fmodule-file=std=std.pcm -o $@ $<

clean:
	rm -rf *.out *.pcm compile_commands.json .cache
