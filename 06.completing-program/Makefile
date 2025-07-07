CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++

.PHONY: default clean

OUTS = 6.3.error_handling.out 6.4.negative_numbers.out 6.5.remainder.out \
			 6.6.1.symbolic_constants.out 6.6.2.use_of_functions.out 6.6.3.code_layout.out \
			 6.7.recovering_from_errors.out 6.8.variables.out 6.9.predefined_names.out \
			 6.d.calculator08buggy.out 6.e.01.allow_underscores.out 6.e.02.add_assignment.out \
			 6.e.03.add_named_constants.out 6.e.04.define_symbol_table.out \
			 6.e.05.modify_token_stream_get.out 6.e.06.add_help.out 6.e.07.change_commands.out \
			 6.e.09.some_improvement.out 6.e.10.int_calculator.out 6.e.11.ch3.5.guessing_game.out \
			 6.e.11.ch4.5.ctok_ktoc_converter.out 6.e.12.istream.out

default: std.pcm ${OUTS}

%.out: %.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^

clean:
	rm -rf *.out *.pcm compile_commands.json .cache
