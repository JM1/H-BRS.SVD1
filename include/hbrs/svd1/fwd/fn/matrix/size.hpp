/* Copyright (c) 2018 Jakob Meng, <jakobmeng@web.de>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef HBRS_SVD1_FWD_FN_MATRIX_SIZE_HPP
#define HBRS_SVD1_FWD_FN_MATRIX_SIZE_HPP

#include <hbrs/svd1/config.hpp>
#include <hbrs/svd1/fwd/dt/rtscm.hpp>
#include <boost/hana/core/tag_of.hpp>

HBRS_SVD1_NAMESPACE_BEGIN
namespace hana = boost::hana;

template <
	typename Matrix,
	typename std::enable_if_t< 
		std::is_same< hana::tag_of_t<Matrix>, rtscm_tag >::value
	>* = nullptr
>
decltype(auto)
size(Matrix && m);

HBRS_SVD1_NAMESPACE_END

#endif // !HBRS_SVD1_FWD_FN_MATRIX_SIZE_HPP