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

#ifndef HBRS_SVD1_DT_RTSCM_HPP
#define HBRS_SVD1_DT_RTSCM_HPP

#include <hbrs/svd1/fwd/dt/rtscm.hpp>
#include <hbrs/svd1/dt/matrix_index.hpp>
#include <hbrs/svd1/dt/matrix_size.hpp>
#include <hbrs/svd1/dt/smr.hpp>
#include <hbrs/svd1/dt/storage_order.hpp>
#include <hbrs/svd1/fn/matrix/m.hpp>
#include <hbrs/svd1/fn/matrix/n.hpp>

#include <boost/hana/core/make.hpp>
#include <boost/hana/core/to.hpp>
#include <boost/hana/type.hpp>
#include <boost/assert.hpp>
#include <vector>

HBRS_SVD1_NAMESPACE_BEGIN

template<
	typename /* type of matrix entries */ Ring,
	storage_order Order
>
struct rtscm {
	rtscm(matrix_size<std::size_t, std::size_t> sz) : rtscm(sz.m(), sz.n()) {}
	
	rtscm(std::size_t m, std::size_t n) : data_(m * n, Ring{0}), size_{m,n} {}
	
	rtscm(rtscm const&) = default;
	rtscm(rtscm &&) = default;
	
	rtscm&
	operator=(rtscm const&) = default;
	rtscm&
	operator=(rtscm &&) = default;
	
	auto const&
	size() const { return size_; };
	
	decltype(auto)
	order() const { return storage_order_c<Order>; }
	
	template<typename Index>
	decltype(auto)
	at(Index && i) { 
		return at_helper(data_, size_, std::forward<Index>(i), storage_order_c<Order>);
	}
	
	template<typename Index>
	decltype(auto)
	at(Index && i) const { 
		return at_helper(data_, size_, std::forward<Index>(i), storage_order_c<Order>);
	}
	
	template<typename Index>
	auto
	operator[](Index && i) & { return make_smr(*this, std::forward<Index>(i)); }
	
	template<typename Index>
	auto
	operator[](Index && i) const& { return make_smr(*this, std::forward<Index>(i)); }
	
	template<typename Index>
	auto
	operator[](Index && i) && { return make_smr(*this, std::forward<Index>(i)); }
	
private:
	template<
		typename Data,
		typename Size,
		typename Index
	>
	static decltype(auto)
	at_helper(Data && data, Size && size, Index && i, row_major_) {
		return std::forward<Data>(data)[
			m(std::forward<Index>(i)) * n(std::forward<Size>(size)) + n(std::forward<Index>(i))
		];
	}
	
	template<
		typename Data,
		typename Size,
		typename Index
	>
	static decltype(auto)
	at_helper(Data && data, Size && size, Index && i, column_major_) {
		return std::forward<Data>(data)[
			n(std::forward<Index>(i)) * m(std::forward<Size>(size)) + m(std::forward<Index>(i))
		];
	}
	
	std::vector<Ring> data_;
	matrix_size<std::size_t, std::size_t> size_;
};

HBRS_SVD1_NAMESPACE_END

namespace boost { namespace hana {

template <
	typename Ring,
	hbrs::svd1::storage_order Order
>
struct tag_of< hbrs::svd1::rtscm<Ring, Order> > {
	using type = hbrs::svd1::rtscm_tag;
};

template <>
struct make_impl<hbrs::svd1::rtscm_tag> {
	template <
		typename Ring,
		hbrs::svd1::storage_order Order
	>
	static hbrs::svd1::rtscm<Ring, Order>
	apply(hana::basic_type<Ring>, hbrs::svd1::matrix_size<std::size_t, std::size_t> sz, hbrs::svd1::storage_order_<Order>) {
		return {sz};
	}
};

/* namespace hana */ } /* namespace boost */ }

#endif // !HBRS_SVD1_DT_RTSCM_HPP
