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

#ifndef HBRS_SVD1_FN_MATRIX_M_HPP
#define HBRS_SVD1_FN_MATRIX_M_HPP

#include <hbrs/svd1/fwd/fn/matrix/m.hpp>
#include <hbrs/svd1/dt/matrix_index.hpp>
#include <hbrs/svd1/dt/matrix_size.hpp>

HBRS_SVD1_NAMESPACE_BEGIN
namespace hana = boost::hana;

template <
	typename MatrixAxis,
	typename std::enable_if_t< 
		std::is_same< hana::tag_of_t<MatrixAxis>, matrix_index_tag >::value ||
		std::is_same< hana::tag_of_t<MatrixAxis>, matrix_size_tag >::value
	>*
>
constexpr decltype(auto)
m(MatrixAxis && a) {
	return std::forward<MatrixAxis>(a).m();
}

HBRS_SVD1_NAMESPACE_END

#endif // !HBRS_SVD1_FN_MATRIX_M_HPP