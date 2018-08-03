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

#ifndef MC_DATA_HPP
#define MC_DATA_HPP

namespace test {
	static std::size_t const
	mat_a_m = 3, mat_a_n = 3;
	
	static double 
	mat_a[mat_a_m*mat_a_n] = {
		12.0, -51.0,   4.0,
		 6.0, 167.0, -68.0,
		-4.0,  24.0, -41.0
	};
	
	static std::size_t const
	mat_b_m = 5, mat_b_n = 3;
	
	static double
	mat_b[mat_b_m*mat_b_n] = {
		12, -51,   4,
		 6, 167, -68,
		-4,  24, -41,
		-1,   1,   0,
		 2,   0,   3,
	};
	
	
	static std::size_t const
	mat_c_m = 6, mat_c_n = 5;
	
	static double 
	mat_c[mat_c_m*mat_c_n] = {
		+8.79,  +9.93,  +9.83, +5.45,  +3.16,
		+6.11,  +6.91,  +5.04, -0.27,  +7.98,
		-9.15,  -7.93,  +4.86, +4.85,  +3.01,
		+9.57,  +1.64,  +8.83, +0.74,  +5.80,
		-3.49,  +4.02,  +9.80, +10.00, +4.27,
		+9.84,  +0.15,  -8.99, -6.02,  -5.31
	};
	
	static std::size_t const
	mat_d_m = 2, mat_d_n = 2;
	
	static double 
	mat_d[mat_d_m*mat_d_n] = {
		 0,  1,
		-2, -3
	};
	
	static std::size_t const 
	mat_e_m = 4, mat_e_n = 5;
	
	static double 
	mat_e[mat_e_m*mat_e_n] = {
		1,0,0,0,2,
		0,0,3,0,0,
		0,2,0,0,0
	};
	
	static std::size_t const 
	mat_f_m = 2, mat_f_n = 3;
	
	static double 
	mat_f[mat_f_m*mat_f_n] = {
		1,2,3,
		-1,2,5
	};
	
	static constexpr std::size_t const 
	mat_g_m = 13, mat_g_n = 4;
	
	static constexpr double 
	mat_g[mat_g_m*mat_g_n] = {
        7,   26,    6,   60,
        1,   29,   15,   52,
       11,   56,    8,   20,
       11,   31,    8,   47,
        7,   52,    6,   33,
       11,   55,    9,   22,
        3,   71,   17,    6,
        1,   31,   22,   44,
        2,   54,   18,   22,
       21,   47,    4,   26,
        1,   40,   23,   34,
       11,   66,    9,   12,
       10,   68,    8,   12
	};
	
	static constexpr std::size_t const 
	mat_h_m = 3, mat_h_n = 4;
	
	static constexpr double 
	mat_h[mat_h_m*mat_h_n] = {
        11, 12, 13, 14,
		21, 22, 23, 24,
		31, 32, 33, 34
	};
	
	static constexpr std::size_t const 
	mat_i_m = 3, mat_i_n = 4;
	
	static constexpr double 
	mat_i[mat_i_m*mat_i_n] = {
        11, 21, 31, 
		12, 22, 32,
		13, 23, 33,
		14, 24, 34
	};
}

#endif
