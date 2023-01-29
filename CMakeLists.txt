project(auto_lib)

cmake_minimum_required(VERSION 3.8)

set(SRC
	./tests/test_main.cc
	./tests/test_cpuusage.cc)

include_directories(./include/)
link_directories(./lib/x86_64/)

add_executable(Test_autlib ${SRC})
target_link_libraries(Test_autlib auto_lib)

