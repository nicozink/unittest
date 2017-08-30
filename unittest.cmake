cmake_minimum_required(VERSION 3.7)

PROJECT(unittest)

file(
	GLOB_RECURSE SRC_MAIN
	LIST_DIRECTORIES false
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*
)

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}/src")

foreach(_source IN ITEMS ${SRC_MAIN})
	get_filename_component(_source_path "${_source}" PATH)
	file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
	string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
	source_group("${_group_path}" FILES "${_source}")
endforeach()

add_library(unittest ${SRC_MAIN})

target_include_directories(unittest PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/src)
