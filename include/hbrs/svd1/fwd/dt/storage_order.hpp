
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

#ifndef HBRS_SVD1_FWD_DT_STORAGE_ORDER_HPP
#define HBRS_SVD1_FWD_DT_STORAGE_ORDER_HPP

#include <hbrs/svd1/config.hpp>
#include <boost/hana/fwd/core/make.hpp>
#include <boost/hana/fwd/core/to.hpp>
#include <boost/hana/integral_constant.hpp>

HBRS_SVD1_NAMESPACE_BEGIN
namespace hana = boost::hana;

enum class storage_order { row_major, column_major };
template <storage_order so>
using storage_order_ = hana::integral_constant<storage_order, so>; 
template <storage_order so>
constexpr storage_order_<so> storage_order_c{};
using column_major_ = storage_order_<storage_order::column_major>;
constexpr auto column_major_c = storage_order_c<storage_order::column_major>;
using row_major_ = storage_order_<storage_order::row_major>;
constexpr auto row_major_c = storage_order_c<storage_order::row_major>;

HBRS_SVD1_NAMESPACE_END

#endif // !HBRS_SVD1_FWD_DT_STORAGE_ORDER_HPP
