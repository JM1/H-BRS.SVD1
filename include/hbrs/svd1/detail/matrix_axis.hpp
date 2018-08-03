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

#ifndef HBRS_SVD1_DETAIL_MATRIX_AXIS_HPP
#define HBRS_SVD1_DETAIL_MATRIX_AXIS_HPP

#include <hbrs/svd1/config.hpp>
#include <hbrs/svd1/detail/is_braces_constructible.hpp>
#include <boost/hana/core/make.hpp>
#include <boost/hana/core/to.hpp>
#include <type_traits>
#include <ostream>

#define HBRS_SVD1_DEFINE_MATRIX_AXIS(cname, tname)                                                                     \
	HBRS_SVD1_NAMESPACE_BEGIN                                                                                          \
	                                                                                                                   \
	template<typename tname ## M, typename tname ## N>                                                                 \
	struct cname {                                                                                                     \
		                                                                                                               \
		template<typename tname ## M_, typename tname ## N_>                                                           \
		friend struct cname;                                                                                           \
		                                                                                                               \
		template<typename tname ## M_, typename tname ## N_>                                                           \
		constexpr                                                                                                      \
		cname(tname ## M_ && m, tname ## N_ && n)                                                                      \
		: m_{std::forward<tname ## M_>(m)}, n_{std::forward<tname ## N_>(n)} {}                                        \
		                                                                                                               \
		constexpr                                                                                                      \
		cname(cname const&) = default;                                                                                 \
		                                                                                                               \
		template<                                                                                                      \
			typename tname ## M_,                                                                                      \
			typename tname ## N_,                                                                                      \
			typename std::enable_if_t<                                                                                 \
				hbrs::svd1::detail::is_braces_constructible< tname ## M, tname ## M_>::value &&                        \
				hbrs::svd1::detail::is_braces_constructible< tname ## N, tname ## N_>::value                           \
			>* = nullptr                                                                                               \
		>                                                                                                              \
		constexpr                                                                                                      \
		cname(cname<tname ## M_, tname ## N_> const& rhs)                                                              \
		: m_{rhs.m_}, n_{rhs.n_} {}                                                                                    \
		                                                                                                               \
		template<                                                                                                      \
			typename tname ## M_,                                                                                      \
			typename tname ## N_,                                                                                      \
			typename std::enable_if_t<                                                                                 \
				hbrs::svd1::detail::is_braces_constructible< tname ## M, tname ## M_>::value &&                        \
				hbrs::svd1::detail::is_braces_constructible< tname ## N, tname ## N_>::value                           \
			>* = nullptr                                                                                               \
		>                                                                                                              \
		constexpr                                                                                                      \
		cname(cname<tname ## M_, tname ## N_> && rhs)                                                                  \
		: m_{std::forward<decltype(rhs)>(rhs).m_}, n_{std::forward<decltype(rhs)>(rhs).n_} {}                          \
		                                                                                                               \
		                                                                                                               \
		constexpr                                                                                                      \
		cname(cname &&) = default;                                                                                     \
		                                                                                                               \
		cname&                                                                                                         \
		operator=(cname const&) = default;                                                                             \
		cname&                                                                                                         \
		operator=(cname &&) = default;                                                                                 \
		                                                                                                               \
		constexpr decltype(auto)                                                                                       \
		m() { return m_; };                                                                                            \
		                                                                                                               \
		constexpr decltype(auto)                                                                                       \
		m() const { return m_; };                                                                                      \
		                                                                                                               \
		constexpr decltype(auto)                                                                                       \
		n() { return n_; };                                                                                            \
		                                                                                                               \
		constexpr decltype(auto)                                                                                       \
		n() const { return n_; };                                                                                      \
		                                                                                                               \
	private:                                                                                                           \
		tname ## M m_;                                                                                                 \
		tname ## N n_;                                                                                                 \
	};                                                                                                                 \
	HBRS_SVD1_NAMESPACE_END                                                                                            \
	                                                                                                                   \
	namespace boost { namespace hana {                                                                                 \
                                                                                                                       \
	template <typename tname ## M, typename tname ## N>                                                                \
	struct tag_of< hbrs::svd1::cname<tname ## M, tname ## N> > {                                                       \
		using type = hbrs::svd1::cname ## _tag;                                                                        \
	};                                                                                                                 \
                                                                                                                       \
	template <>                                                                                                        \
	struct make_impl<hbrs::svd1::cname ## _tag> {                                                                      \
		template <typename tname ## M, typename tname ## N>                                                            \
		static constexpr hbrs::svd1::cname<                                                                            \
			std::decay_t<tname ## M>,                                                                                  \
			std::decay_t<tname ## N>                                                                                   \
		>                                                                                                              \
		apply(tname ## M && m, tname ## N && n) {                                                                      \
			return { std::forward<tname ## M>(m),std::forward<tname ## N>(n) };                                        \
		}                                                                                                              \
	};                                                                                                                 \
	                                                                                                                   \
	/* namespace hana */ } /* namespace boost */ }                                                                     \
	                                                                                                                   \
	HBRS_SVD1_NAMESPACE_BEGIN                                                                                          \
                                                                                                                       \
	/* TODO: Write macro for binary operators! */                                                                      \
	template<                                                                                                          \
		typename tname ## L,                                                                                           \
		typename tname ## R,                                                                                           \
		typename std::enable_if_t<                                                                                     \
			std::is_same< cname ## _tag, hana::tag_of_t<tname ## L> >::value &&                                        \
			std::is_same< cname ## _tag, hana::tag_of_t<tname ## R> >::value &&                                        \
			std::is_same< hana::tag_of_t<tname ## L>, hana::tag_of_t<tname ## R> >:: value /* TODO: is_same required? */ \
		>* = nullptr                                                                                                   \
	>                                                                                                                  \
	constexpr decltype(auto)                                                                                           \
	operator==(tname ## L && l, tname ## R && r) {                                                                     \
		return (std::forward<tname ## L>(l).m() == std::forward<tname ## R>(r).m()) &&                                 \
			(std::forward<tname ## L>(l).n() == std::forward<tname ## R>(r).n());                                      \
	}                                                                                                                  \
                                                                                                                       \
	template<                                                                                                          \
		typename tname ## L,                                                                                           \
		typename tname ## R,                                                                                           \
		typename std::enable_if_t<                                                                                     \
			std::is_same< cname ## _tag, hana::tag_of_t<tname ## L> >::value &&                                        \
			std::is_same< cname ## _tag, hana::tag_of_t<tname ## R> >::value &&                                        \
			std::is_same< hana::tag_of_t<tname ## L>, hana::tag_of_t<tname ## R> >:: value /* TODO: is_same required? */ \
		>* = nullptr                                                                                                   \
	>                                                                                                                  \
	constexpr decltype(auto)                                                                                           \
	operator!=(tname ## L && l, tname ## R && r) {                                                                     \
		return !(std::forward<tname ## L>(l) == std::forward<tname ## R>(r));                                          \
	}                                                                                                                  \
                                                                                                                       \
	template<typename tname ## M, typename tname ## N>                                                                 \
	std::ostream& operator<<(std::ostream& os, cname<tname ## M, tname ## N> const& x) {                               \
		os << "m:=" << x.m() << " n:=" << x.n();                                                                       \
		return os;                                                                                                     \
	}                                                                                                                  \
	HBRS_SVD1_NAMESPACE_END


#endif // !HBRS_SVD1_DETAIL_MATRIX_AXIS_HPP
