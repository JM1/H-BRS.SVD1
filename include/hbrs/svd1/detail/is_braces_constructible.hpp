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

#ifndef HBRS_SVD1_DETAIL_IS_BRACES_CONSTRUCTIBLE_HPP
#define HBRS_SVD1_DETAIL_IS_BRACES_CONSTRUCTIBLE_HPP

#include <hbrs/svd1/config.hpp>
#include <type_traits>

HBRS_SVD1_NAMESPACE_BEGIN
namespace detail {

template<class T, typename... Args>
decltype(void(T{std::declval<Args>()...}), std::true_type())
test_is_braces_constructible(int);

template<class T, typename... Args>
std::false_type
test_is_braces_constructible(...);

/* Src.: https://stackoverflow.com/a/20885988/6490710 */
template<class T, typename... Args>
struct is_braces_constructible : decltype(test_is_braces_constructible<T, Args...>(0))
{};

/* namespace detail */ }
HBRS_SVD1_NAMESPACE_END

#endif // !HBRS_SVD1_DETAIL_IS_BRACES_CONSTRUCTIBLE_HPP
