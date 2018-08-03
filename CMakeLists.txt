# Copyright (c) 2018 Jakob Meng, <jakobmeng@web.de>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

#################### project settings ####################

project(H-BRS.SVD1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

include(FeatureSummary)

#################### options ####################

option(HBRS_SVD1_ENABLE_TESTS "Build unit tests." ON)

#################### macros ####################

# Inspired by: https://github.com/boostorg/hana/blob/master/CMakeLists.txt
include(CheckCCompilerFlag)
macro(hbrs_mpl_maybe_add_c_flag testname flag)
    set(extra_macro_args ${ARGN})
	check_c_compiler_flag(${flag} ${testname})
	if (${testname})
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flag}")
	endif()
endmacro()

include(CheckCXXCompilerFlag)
macro(hbrs_mpl_maybe_add_cxx_flag testname flag)
    set(extra_macro_args ${ARGN})
	check_cxx_compiler_flag(${flag} ${testname})
	if (${testname})
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}")
	endif()
endmacro()

#################### find all used packages ####################

# Hana is part of boost since 1.61, Ref.: http://www.boost.org/users/history/
# BOOST_TEST macro requires 1.59, Ref.: https://stackoverflow.com/a/38083784/6490710
find_package(Boost 1.61 COMPONENTS unit_test_framework system thread serialization chrono program_options filesystem iostreams regex exception signals)
set_package_properties(Boost PROPERTIES
	PURPOSE "Required for meta programming, unit tests and others."
	TYPE REQUIRED
)

find_package(LAPACK)
set_package_properties(LAPACK PROPERTIES
	PURPOSE "None yet."
)

find_package(Elemental)
set_package_properties(Elemental PROPERTIES
	DESCRIPTION "Distributed linear algebra algorithms"
	PURPOSE "None yet."
)

SET(QT_USE_IMPORTED_TARGETS TRUE)
find_package(Qt5 COMPONENTS Core Widgets)
set_package_properties(Qt5 PROPERTIES
	PURPOSE "Required for Elemental library."
)

#################### source settings ####################

# Always include srcdir and builddir in include path
# This saves typing ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} in about every subdir
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Src: kdelibs/cmake/modules/KDE4Defaults.cmake

# put the include dirs which are in the source or build tree before all other include dirs, so the headers in the sources are preferred over the already installed ones
set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)
# Src: kdelibs/cmake/modules/KDE4Defaults.cmake

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# C++14 is required e.g. because of decltype(auto) as return type and constexpr std::forward_as_tuple()!
# C++17 is required for constexpr lambdas

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# "CMake will generate tests only if the enable_testing() command has been invoked." [1]
# "Note that ctest expects to find a test file in the build directory root. Therefore, this command should be in the 
#  source directory root." [2]
# References:
# [1] https://cmake.org/cmake/help/latest/command/add_test.html#command:add_test
# [2] https://cmake.org/cmake/help/latest/command/enable_testing.html
if(HBRS_SVD1_ENABLE_TESTS)
	enable_testing()
endif()

#################### build settings ####################

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

hbrs_mpl_maybe_add_c_flag  (HBRS_MPL_HAS_C_WALL                         "-Wall")
hbrs_mpl_maybe_add_cxx_flag(HBRS_MPL_HAS_CXX_WALL                       "-Wall")
#hbrs_mpl_maybe_add_c_flag  (HBRS_MPL_HAS_C_WEXTRA                       "-Wextra")
#hbrs_mpl_maybe_add_cxx_flag(HBRS_MPL_HAS_CXX_WEXTRA                     "-Wextra")
hbrs_mpl_maybe_add_c_flag  (HBRS_MPL_HAS_C_WPEDANTIC                    "-Wpedantic")
hbrs_mpl_maybe_add_cxx_flag(HBRS_MPL_HAS_CXX_WPEDANTIC                  "-Wpedantic")
hbrs_mpl_maybe_add_c_flag  (HBRS_MPL_HAS_C_WERROR_RETURN_TYPE           "-Werror=return-type")
hbrs_mpl_maybe_add_cxx_flag(HBRS_MPL_HAS_CXX_WERROR_RETURN_TYPE         "-Werror=return-type")
hbrs_mpl_maybe_add_c_flag  (HBRS_MPL_HAS_C_PEDANTIC_ERRORS              "-pedantic-errors")
hbrs_mpl_maybe_add_cxx_flag(HBRS_MPL_HAS_CXX_PEDANTIC_ERRORS            "-pedantic-errors")

#################### list the subdirectories ####################

add_subdirectory(cmake)
add_subdirectory(src)
add_subdirectory(test)

#################### summary ####################

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
