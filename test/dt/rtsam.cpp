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

#include <hbrs/svd1/dt/rtsam.hpp>

#include "../data.hpp"
#include <hbrs/svd1/fn/size.hpp>
#include <hbrs/svd1/fn/m.hpp>
#include <hbrs/svd1/fn/n.hpp>
#include <hbrs/svd1/fn/at.hpp>

#define BOOST_TEST_MODULE rtsam_test
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(rtsam_test)

namespace utf = boost::unit_test;
namespace tt = boost::test_tools;

BOOST_AUTO_TEST_CASE(m_n_size_assignment) {
	using namespace hbrs::svd1;
	
	auto m1_sz = make_matrix_size(test::mat_g_m, test::mat_g_n);
	auto m1 = make_rtsam(hana::type_c<double>, m1_sz, row_major_c);
	
	auto m1_m = m(size(m1));
	auto m1_n = n(size(m1));
	
	BOOST_TEST(size(m1) == m1_sz);
	BOOST_TEST(m1_m == test::mat_g_m);
	BOOST_TEST(m1_n == test::mat_g_n);
	
	for(std::size_t i = 0; i < m1_m; ++i) {
		for(std::size_t j = 0; j < m1_n; ++j) {
			BOOST_TEST(at(m1, make_matrix_index(i,j)) == 0);
		}
	}
	
	auto m2 = make_rtsam(hana::type_c<double>, make_matrix_size(test::mat_g_m, test::mat_g_n), row_major_c);
	auto m2_m = m(size(m1));
	auto m2_n = n(size(m1));
	
	for(std::size_t i = 0; i < m2_m; ++i) {
		for(std::size_t j = 0; j < m2_n; ++j) {
			at(m2, make_matrix_index(i,j)) = test::mat_g[i * m2_n + j];
		}
	}
	
	m1 = m2;
	
	for(std::size_t i = 0; i < m2_m; ++i) {
		for(std::size_t j = 0; j < m2_n; ++j) {
			BOOST_TEST(at(m1, make_matrix_index(i,j)) == test::mat_g[i * m2_n + j]);
		}
	}
}

BOOST_AUTO_TEST_SUITE_END()
