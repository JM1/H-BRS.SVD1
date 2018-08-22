/* Copyright (c) 2016-2018 Jakob Meng, <jakobmeng@web.de>
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

#ifndef HBRS_SVD1_FWD_DT_RTSAM_HPP
#define HBRS_SVD1_FWD_DT_RTSAM_HPP

#include <hbrs/svd1/config.hpp>
#include <boost/hana/fwd/core/make.hpp>
#include <boost/hana/fwd/core/to.hpp>
#include <hbrs/svd1/fwd/dt/storage_order.hpp>

HBRS_SVD1_NAMESPACE_BEGIN
namespace hana = boost::hana;

/* runtime-size array/sequence/continuous matrix */
template<typename /* type of matrix entries */ Ring, storage_order Order>
struct rtsam;
struct rtsam_tag{};
constexpr auto make_rtsam = hana::make<rtsam_tag>;
constexpr auto to_rtsam = hana::to<rtsam_tag>;

HBRS_SVD1_NAMESPACE_END

#endif // !HBRS_SVD1_FWD_DT_RTSAM_HPP
