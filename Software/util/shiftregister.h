/*  GPLv3 License
 *
 *   Copyright (c) Divergence Meter Project by waicool20
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SHIFT_REGISTER_H_
#define SHIFT_REGISTER_H_

#include <stdint.h>

void SRShift(uint8_t i);

void SRLatch();

void SRON();

void SROFF();

void SRSendOnes(uint8_t i);

void SRSendZeros(uint8_t i);

void SRSendOne();

void SRSendZero();

#endif /* SHIFT_REGISTER_H_ */
