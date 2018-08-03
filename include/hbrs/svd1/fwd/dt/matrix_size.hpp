
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

#ifndef HBRS_SVD1_FWD_DT_MATRIX_SIZE_HPP
#define HBRS_SVD1_FWD_DT_MATRIX_SIZE_HPP

#include <hbrs/svd1/config.hpp>
#include <boost/hana/fwd/core/make.hpp>
#include <boost/hana/fwd/core/to.hpp>
#include <ostream>

HBRS_SVD1_NAMESPACE_BEGIN
namespace hana = boost::hana;

template<typename Rows, typename Columns>
struct matrix_size;
struct matrix_size_tag{};
constexpr auto make_matrix_size = hana::make<matrix_size_tag>;
constexpr auto to_matrix_size = hana::to<matrix_size_tag>;

template<typename Rows, typename Columns>
std::ostream& operator<<(std::ostream& os, matrix_size<Rows, Columns> const& sz);

HBRS_SVD1_NAMESPACE_END

#endif // !HBRS_SVD1_FWD_DT_MATRIX_SIZE_HPP
