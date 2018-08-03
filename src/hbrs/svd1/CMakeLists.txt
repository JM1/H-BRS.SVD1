# Copyright (c) 2018 Jakob Meng, <jakobmeng@web.de>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

add_library(hbrs_svd1 STATIC
	dt/rtscm.cpp
)

target_include_directories(hbrs_svd1
	PUBLIC ${PROJECT_SOURCE_DIR}/include
	PUBLIC ${PROJECT_BINARY_DIR}/include)

target_include_directories(hbrs_svd1
	SYSTEM
	PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries(hbrs_svd1 ${Boost_LIBRARIES})