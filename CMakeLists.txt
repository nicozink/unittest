cmake_minimum_required(VERSION 3.0)

include(${LIBRARY_FOLDER}/build_tools/cmake/cmake_utils.cmake)

PROJECT(unittest VERSION 1.0.0)

enable_testing()

set(SRC_MAIN
	${CMAKE_CURRENT_SOURCE_DIR}/include/unittest/test.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_info.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_info.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_info_compare.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/unit_test_base.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/unit_test_error.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/unit_test_exception.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/unit_test_exception.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/unit_tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/unit_tests.h)

set(SRC_TEST
	${CMAKE_CURRENT_SOURCE_DIR}/test/example.cpp)

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}/")

foreach(_source IN ITEMS ${SRC_MAIN} ${SRC_TEST})
	get_filename_component(_source_path "${_source}" PATH)
	file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
	string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
	source_group("${_group_path}" FILES "${_source}")
endforeach()

create_library(unittest library ${SRC_MAIN})

target_compile_features(unittest
	PUBLIC
	cxx_strong_enums)

target_include_directories(unittest
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src)

create_library(unittest_tests tests ${SRC_TEST})
target_link_libraries(unittest_tests unittest)

create_executable(unittest_test test ${SRC_TEST})
target_link_libraries(unittest_test unittest)

if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
	add_test(NAME unittest_test COMMAND ${NODE_JS} "${CMAKE_CURRENT_BINARY_DIR}/unittest_test.js")
else ()
	add_test(NAME unittest_test COMMAND unittest_test)
endif ()
