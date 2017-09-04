cmake_minimum_required(VERSION 3.0)

PROJECT(unittest_tests)

enable_testing()

include(unittest.cmake)

file(
	GLOB_RECURSE SRC_TEST
	LIST_DIRECTORIES false
	${CMAKE_CURRENT_SOURCE_DIR}/test/*.c*
)

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}/src")

foreach(_source IN ITEMS ${SRC_TEST})
	get_filename_component(_source_path "${_source}" PATH)
	file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
	string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
	source_group("${_group_path}" FILES "${_source}")
endforeach()

ADD_EXECUTABLE(
	unittest_tests
	${SRC_TEST})

target_link_libraries(unittest_tests unittest)

add_test(NAME MyTest
         COMMAND unittest_tests)
