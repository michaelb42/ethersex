/*
 * Project Neptun
 *
 * Copyright (c) 2013-2015 Michael Brakemeier <michael@brakemeier.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * For more information on the GPL, please go to:
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef NEPTUN_DATASTORE_H
#define NEPTUN_DATASTORE_H

#include <stdint.h>

typedef struct neptun_datastore_t_
{

  /**
   * Measurement section
   */

  /* temperatures */
  int16_t ambient_temperature;  // fixedpoint, one decimal place
  int16_t water_temperature;    // fixedpoint, one decimal place

} neptun_datastore_t;

extern neptun_datastore_t neptun_datastore;

#endif /* NEPTUN_DATASTORE_H */
