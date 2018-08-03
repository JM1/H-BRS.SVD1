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

#include <hbrs/svd1/dt/rtscm.hpp>

HBRS_SVD1_NAMESPACE_BEGIN
template struct rtscm<int, storage_order::row_major>;
template struct rtscm<int, storage_order::column_major>;
template struct rtscm<float, storage_order::row_major>;
template struct rtscm<float, storage_order::column_major>;
template struct rtscm<double, storage_order::row_major>;
template struct rtscm<double, storage_order::column_major>;
HBRS_SVD1_NAMESPACE_END
