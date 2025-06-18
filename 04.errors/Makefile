CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++

.PHONY: default clean

OUTS = 4.3.1.tt.syntax_errors.out 4.3.2.tt.type_errors.out 4.5.3.tt.error_reporting.out \
			 4.6.3.tt.uncaught_except_error.out 4.7.3.3.tt.postconditions.out 4.d.errors.out \
			 4.e.02.finding_errors.out 4.e.03.abs_zero_fix_main.out 4.e.04.abs_zero_fix_func.out \
			 4.e.05.add_ktoc_converter.out 4.e.06.ftoc_ctof_converter.out 4.e.07.quadratic_eq.out \
			 4.e.08.sum_of_n.out 4.e.09.handling_int_value.out 4.e.10.sum_of_n_dbl.out \
			 4.e.11.fibonacci_numbers.out 4.e.12.bulls_n_cows.out 4.e.13.bulls_n_cows_improved.out \
			 4.e.14.weekday_values.out

default: std.pcm ${OUTS}

%.out: %.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^

clean:
	rm -rf *.out *.pcm compile_commands.json .cache
