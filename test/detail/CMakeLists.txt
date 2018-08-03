# Copyright (c) 2018 Jakob Meng, <jakobmeng@web.de>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

############## tests ##############

get_filename_component(_pwd "${CMAKE_CURRENT_LIST_DIR}" NAME)
add_custom_target(_${_pwd}_tests)

foreach(target)
	hbrs_svd1_add_test(${target})
	add_dependencies(_${_pwd}_tests ${target})
endforeach()