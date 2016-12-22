/*
 * Project Neptun
 *
 * Copyright (c) 2013-2017 Michael Brakemeier <michael@brakemeier.de>
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

#ifndef NEPTUN_LIGHTING_H
#define NEPTUN_LIGHTING_H

#include <stdint.h>

typedef enum
{
  LIGHTING_ON,
  LIGHTING_OFF,
  LIGHTING_AUTO
} neptun_lighting_states;

/**
 * Lighting module startup
 */
void neptun_lighting_startup(void);

/**
 * Set main lighting switching state.
 */
void neptun_lighting_set_mainlight_state(neptun_lighting_states state);


#endif /* NEPTUN_LIGHTING_H */
