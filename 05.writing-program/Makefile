CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++

.PHONY: default clean

OUTS = 5.3.1.first_attempt.out 5.3.1.next_steps.out 5.6.tt.calculator00.out 5.7.calculator01.out \
			 5.9.tt.calculator01.out 5.d.calculator02buggy.out 5.e.2.adding_braces.out \
			 5.e.3.adding_factor.out 5.e.4.name_value_class.out 5.e.5.bitwise_logical_expressions.out \
			 5.e.6.bulls_n_cows.out 5.e.7.integer_composer.out 5.e.8.permutations_n_combinations.out

default: std.pcm ${OUTS}

%.out: %.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^

clean:
	rm -rf *.out *.pcm compile_commands.json .cache
