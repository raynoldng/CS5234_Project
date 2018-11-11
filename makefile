all:
	$(CXX) -o fw_blocking fw_blocking.cpp
	$(CXX) -o fw_naive fw_naive.cpp

block:
	$(CXX) -o fw_blocking fw_blocking.cpp

clean:
	@-rm -rf fw_naive > /dev/null 2>&1
	@-rm -rf fw_blocking > /dev/null 2>&1