# Copyright (c) 2018 Jakob Meng, <jakobmeng@web.de>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

############## tests ##############

# CMake's target test does not build but only executes tests
# Ref.: https://stackoverflow.com/a/736838/6490710
if(HBRS_SVD1_ENABLE_TESTS)
	set(_MAYBE_ALL ALL)
endif()
add_custom_target(tests ${_MAYBE_ALL} COMMENT "Build all tests.")

function(hbrs_svd1_add_test target)
	add_executable(${target} EXCLUDE_FROM_ALL "${target}.cpp")
	target_link_libraries(${target} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
	target_include_directories(${target} SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})
	
	add_test(${target} ${CMAKE_CURRENT_BINARY_DIR}/${target})
	add_dependencies(tests ${target})
endfunction()

get_filename_component(_pwd "${CMAKE_CURRENT_LIST_DIR}" NAME)
add_custom_target(_${_pwd}_tests)

foreach(target)
	hbrs_svd1_add_test(${target})
	add_dependencies(_${_pwd}_tests ${target})
endforeach()

#################### list the subdirectories ####################

add_subdirectory(detail)
add_subdirectory(dt)
