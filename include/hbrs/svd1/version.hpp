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

#ifndef HBRS_SVD1_VERSION_HPP
#define HBRS_SVD1_VERSION_HPP

#define HBRS_SVD1_CONFIG_VERSION(version, revision, patch) \
	(((version) << 24) + ((revision) << 16) + (patch))

#define HBRS_SVD1_MAJOR_VERSION 0
#define HBRS_SVD1_MINOR_VERSION 1
#define HBRS_SVD1_PATCH_VERSION 0

#define HBRS_SVD1_VERSION                            \
	HBRS_SVD1_CONFIG_VERSION(HBRS_SVD1_MAJOR_VERSION, \
							HBRS_SVD1_MINOR_VERSION, \
							HBRS_SVD1_PATCH_VERSION) \

#endif // !HBRS_SVD1_VERSION_HPP
