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

#ifndef HBRS_SVD1_DT_SMR_HPP
#define HBRS_SVD1_DT_SMR_HPP

#include <hbrs/svd1/fwd/dt/smr.hpp>
#include <hbrs/svd1/dt/matrix_index.hpp>
#include <hbrs/svd1/fn/at.hpp>
#include <hbrs/svd1/fn/n.hpp>

#include <boost/hana/core/make.hpp>
#include <boost/hana/core/to.hpp>
#include <vector>

HBRS_SVD1_NAMESPACE_BEGIN

template<
	typename Matrix,
	typename Index
>
struct smr {
	template<typename Matrix_, typename Index_>
	constexpr
	smr(Matrix_ && a, Index_ && row) : a_{std::forward<Matrix_>(a)}, row_{std::forward<Index_>(row)} {}

	constexpr
	smr(smr const&) = default;
	constexpr
	smr(smr &&) = default;
	
	constexpr smr&
	operator=(smr const&) = default;
	constexpr smr&
	operator=(smr &&) = default;

	
	/* Allow copy construction of a row from a row view */
	template<
		typename Matrix_,
		typename Index_,
		typename std::enable_if_t<
			!std::is_lvalue_reference<Matrix>::value &&
			std::is_lvalue_reference<Matrix_>::value
		>* = nullptr
	>
	constexpr
	smr(smr<Matrix, Index> const& rhs) : a_{rhs.a_}, row_{rhs.row_} {}

	template<typename Index_>
	constexpr decltype(auto)
	at(Index_ && column) {
		using hbrs::svd1::at;
		return at(a_, make_matrix_index(row_, std::forward<Index_>(column)));
	}

	template<typename Index_>
	constexpr decltype(auto)
	at(Index_ && column) const {
		using hbrs::svd1::at;
		return at(a_, make_matrix_index(row_, std::forward<Index_>(column)));
	}
	
	constexpr auto
	size() const {
		using svd1::n;
		return n(a_);
	}
	
	template<typename Index_>
	constexpr decltype(auto)
	operator[](Index_ && column) {
		return at(std::forward<Index_>(column));
	}
	
	template<typename Index_>
	constexpr decltype(auto)
	operator[](Index_ && column) const {
		return at(std::forward<Index_>(column));
	}

private:
	Matrix a_;
	Index row_;
};

HBRS_SVD1_NAMESPACE_END

namespace boost { namespace hana {

template <typename Matrix, typename Index>
struct tag_of< hbrs::svd1::smr<Matrix, Index> > {
	using type = hbrs::svd1::smr_tag;
};

/* namespace hana */ } /* namespace boost */ }

namespace boost { namespace hana {

template <>
struct make_impl<hbrs::svd1::smr_tag> {
	template<typename Matrix, typename Index>
	static constexpr hbrs::svd1::smr< std::decay_t<Matrix>, std::decay_t<Index> >
	apply(Matrix && a, Index && row) {
		return {std::forward<Matrix>(a), std::forward<Index>(row)};
	}
};

/* namespace hana */ } /* namespace boost */ }

#endif // !HBRS_SVD1_DT_SMR_HPP
