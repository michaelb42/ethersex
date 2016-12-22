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

#ifndef NEPTUN_H
#define NEPTUN_H

#include <stdint.h>
#include <stdarg.h>

#include <avr/pgmspace.h>

#include "config.h"


#ifdef DEBUG_NEPTUN
#include "core/debug.h"
// #define NEPTUN_DEBUG(fnc, msg...) debug_printf("Neptun: %s: ", fnc); debug_printf(msg)
#define NEPTUN_DEBUG(fnc, s, args...) printf_P(PSTR("D: Neptun: " #fnc ": " s), ## args)
#else
#define NEPTUN_DEBUG(fnc, s, args...)
#endif

#define NEPTUN_OK       0

typedef enum
{
  CORE_INITIALIZING = 0,
  CORE_RUNNING,
  CORE_SHUTDOWN,
  CORE_STANDBY,
  CORE_SERVICE
} neptun_core_states;


/**
 * Initialize Neptun.
 */
void neptun_core_init(void);

/**
 * Neptun core main.
 */
void neptun_core_main(void);

/**
 * Get Neptun Core state.
 */
neptun_core_states neptun_core_get_state(void);


#endif /* NEPTUN_H */
