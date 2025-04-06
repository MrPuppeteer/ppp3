CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++

default: std.pcm 2.01.first_name.out 2.03.name_and_age.out 2.03.name_two_words.out 2.03.tt.name_and_age.out 2.04.operators_exercise.out 2.04.tt.operators_exercise.out 2.04.strings_concat.out 2.04.strings_if_compare.out 2.05.1.detect_repeated_words.out 2.05.3.find_repeated_words.out 2.06.tt.goodbye_world.out 2.09.conversions_experiment.out 2.d.form_letter.out 2.e.02.miles_to_km.out 2.e.03.illegal_names.out 2.e.04.values_comparison.out 2.e.05.values_comparison_dbl.out 2.e.06.ordered_integer.out 2.e.07.ordered_strings.out 2.e.08.odd_or_even.out 2.e.09.spell_number.out 2.e.10.operations.out 2.e.11.coins.out

2.01.first_name.out: 2.01.first_name.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.03.name_and_age.out: 2.03.name_and_age.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.03.name_two_words.out: 2.03.name_two_words.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.03.tt.name_and_age.out: 2.03.tt.name_and_age.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.04.operators_exercise.out: 2.04.operators_exercise.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.04.tt.operators_exercise.out: 2.04.tt.operators_exercise.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.04.strings_concat.out: 2.04.strings_concat.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.04.strings_if_compare.out: 2.04.strings_if_compare.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.05.1.detect_repeated_words.out: 2.05.1.detect_repeated_words.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.05.3.find_repeated_words.out: 2.05.3.find_repeated_words.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.06.tt.goodbye_world.out: 2.06.tt.goodbye_world.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.09.conversions_experiment.out: 2.09.conversions_experiment.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.d.form_letter.out: 2.d.form_letter.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.02.miles_to_km.out: 2.e.02.miles_to_km.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.03.illegal_names.out: 2.e.03.illegal_names.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.04.values_comparison.out: 2.e.04.values_comparison.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.05.values_comparison_dbl.out: 2.e.05.values_comparison_dbl.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.06.ordered_integer.out: 2.e.06.ordered_integer.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.07.ordered_strings.out: 2.e.07.ordered_strings.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.08.odd_or_even.out: 2.e.08.odd_or_even.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.09.spell_number.out: 2.e.09.spell_number.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.10.operations.out: 2.e.10.operations.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

2.e.11.coins.out: 2.e.11.coins.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^

clean:
	rm -rf *.out *.pcm compile_commands.json .cache
