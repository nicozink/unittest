cmake_minimum_required(VERSION 3.0)

PROJECT(unittest VERSION 1.0.0)

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

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}/")

foreach(_source IN ITEMS ${SRC_MAIN})
	get_filename_component(_source_path "${_source}" PATH)
	file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
	string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
	source_group("${_group_path}" FILES "${_source}")
endforeach()

add_library(unittest ${SRC_MAIN})

target_include_directories(unittest
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src)

set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(include_install_dir "include")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${version_config}" COMPATIBILITY SameMajorVersion)
configure_package_config_file("cmake/Config.cmake.in" "${project_config}" INSTALL_DESTINATION "${config_install_dir}")

install(TARGETS unittest EXPORT unittestTargets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	INCLUDES DESTINATION include)
install(DIRECTORY include/unittest DESTINATION include)
install(EXPORT unittestTargets
	FILE unittestTargets.cmake
	DESTINATION lib/cmake/unittest)
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)
