apply14: apply.cpp
	g++ apply.cpp -std=c++14 -o apply14

apply11: apply.cpp
	g++ apply.cpp -std=c++11 -o apply11

memo11: memo.cpp
	g++ memo.cpp -std=c++11 -o memo11

memo14: memo.cpp
	g++ memo.cpp -std=c++14 -o memo14

clean:
	rm -rf memo14 memo11 apply14 apply11
