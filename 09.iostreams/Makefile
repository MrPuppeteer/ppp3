CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++
CXXFLAGS += -D_LIBCPP_ENABLE_EXPERIMENTAL

.PHONY: default clean

OUTS = 9.10.1.tt.birthyear.out 9.10.6.tt.format.out 9.d.01-07.test_output.out \
			 9.d.08.test_input.out 9.d.09.test_float_output.out 9.d.10.friends_table.out \
			 9.d.11-17.point.out 9.e.01.lowercase.out 9.e.02.find_word.out 9.e.03.remove_vowels.out \
			 9.e.04.multi_input.out 9.e.05.char_classification_str.out 9.e.06.replace_punct.out \
			 9.e.07.replace_punct_modified.out 9.e.08.sorted_list_of_words.out \
			 9.e.11.reverse_order_of_chars.out 9.e.12.reverse_order_of_words.out \
			 9.e.13.char_classification_file.out 9.e.14.formatting_scientific_number.out \
			 9.e.15.ordered_numbers_w_occur.out 9.e.16.sum_of_int_numbers.out 9.e.17.store_temps.out \
			 9.e.18.temp_stats.out 9.e.19.store_temps.out 9.e.19.temp_stats.out 9.e.20.print_year.out \
			 9.e.21.roman_int.out 9.e.22.roman_calculator.out 9.e.23.concat_files.out \
			 9.e.24.merge_ordered_words_files.out 9.e.25.calculator_files_command.out \
			 9.e.26.sum_of_int_in_txt_file.out

default: std.pcm ${OUTS}

%.out: %.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^ -lc++experimental

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^

clean:
	rm -rf *.out *.pcm compile_commands.json .cache
