CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++

.PHONY: default clean

OUTS = 3.4.1.1.if-statement.out 3.4.1.1.inch_cm_converter_bad.out \
			 3.4.1.1.inch_cm_converter_improved.out 3.4.1.1.tt.currency_converter.out \
			 3.4.1.2.inch_cm_converter_switch.out 3.4.1.3.tt.currency_converter_switch.out \
			 3.4.2.1.squares_table.out 3.4.2.1.tt.chars_table.out 3.4.2.3.squares_table_for.out \
			 3.4.2.3.squares_table_for_even.out 3.4.2.3.tt.chars_table_for.out \
			 3.5.1.tt.square_no_mul.out 3.6.1.traversing_vector.out 3.6.3.compute_mean_median_temp.out \
			 3.6.4.simple_dict.out 3.6.4.tt.bleep.out 3.d.values.out 3.e.02.char_int_value.out \
			 3.e.03.median_fix.out 3.e.04.cities_distance.out 3.e.05.guessing_game.out \
			 3.e.06.simple_calculator.out 3.e.07.spell_digits.out 3.e.08.digit_calculator.out \
			 3.e.09.rice_grains.out 3.e.10.rice_grains_limit.out 3.e.11.rock_paper_scissors.out \
			 3.e.12.prime_numbers.out 3.e.13.sieve_of_eratosthenes.out 3.e.14.n_prime_numbers.out \
			 3.e.15.mode.out 3.e.16.mmm_strings.out 3.e.17.quadratic_equation.out \
			 3.e.18.name_value_pairs.out 3.e.19.name_value_pairs_fname.out \
			 3.e.20.name_value_pairs_fscore.out

default: std.pcm ${OUTS}

%.out: %.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^

clean:
	rm -rf *.out *.pcm compile_commands.json .cache
