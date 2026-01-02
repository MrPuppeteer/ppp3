CXX = clang++
CXXFLAGS += -Weverything -Wno-c++98-compat -Wno-pre-c++20-compat
CXXFLAGS += -std=c++23 -stdlib=libc++

.PHONY: default clean

OUTS = 8.4.4.tt.date.out 8.6.tt.operator_overloading.out 8.d.date.out 8.e.02.name_pairs.out \
			 8.e.03.name_pairs_w_global_op.out 8.e.04.name_pairs_improved.out 8.e.05.book.out \
			 8.e.06.book_operators.out 8.e.07.adding_genre.out 8.e.08.adding_patron.out \
			 8.e.09.library.out 8.e.10.leapyear.out 8.e.11.date_helper_functions.out 8.e.12.epoch.out \
			 8.e.13.rational.out 8.e.14.money.out 8.e.15.currency.out 8.e.16.io_money.out

default: std.pcm ${OUTS}

%.out: %.cpp std.pcm
	$(CXX) $(CXXFLAGS) -fmodule-file=std=std.pcm -o $@ $^

std.pcm: /usr/share/libc++/v1/std.cppm
	$(CXX) $(CXXFLAGS) -Wno-reserved-identifier -Wno-reserved-module-identifier --precompile -o $@ $^

clean:
	rm -rf *.out *.pcm compile_commands.json .cache
