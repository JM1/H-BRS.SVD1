# Copyright (c) 2016 Jakob Meng, <jakobmeng@web.de>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

############## tests ##############

get_filename_component(_pwd "${CMAKE_CURRENT_LIST_DIR}" NAME)
add_custom_target(_${_pwd}_tests)

foreach(target rtscm)
	hbrs_svd1_add_test(${target})
	target_link_libraries(${target} hbrs_svd1)
	add_dependencies(_${_pwd}_tests ${target})
endforeach()