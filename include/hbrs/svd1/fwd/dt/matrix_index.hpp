
/* Copyright (c) 2016 Jakob Meng, <jakobmeng@web.de>
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

#ifndef HBRS_SVD1_FWD_DT_MATRIX_INDEX_HPP
#define HBRS_SVD1_FWD_DT_MATRIX_INDEX_HPP

#include <hbrs/svd1/config.hpp>
#include <boost/hana/fwd/core/make.hpp>
#include <boost/hana/fwd/core/to.hpp>
#include <ostream>

HBRS_SVD1_NAMESPACE_BEGIN
namespace hana = boost::hana;

template<typename RowIndex, typename ColumnIndex>
struct matrix_index;
struct matrix_index_tag{};
constexpr auto make_matrix_index = hana::make<matrix_index_tag>;
constexpr auto to_matrix_index = hana::to<matrix_index_tag>;

template<typename RowIndex, typename ColumnIndex>
std::ostream& operator<<(std::ostream& os, matrix_index<RowIndex, ColumnIndex> const& i);

HBRS_SVD1_NAMESPACE_END

#endif // !HBRS_SVD1_FWD_DT_MATRIX_INDEX_HPP
