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

#include <stdint.h>

#include "config.h"

#include "neptun.h"

/**
 * Neptun Core state machine.
 */
static neptun_core_states neptun_core_state;


/**
 * Initialize Neptun.
 */
void
neptun_core_init(void)
{
  neptun_core_state = CORE_INITIALIZING;
  return;
}


/**
 * Neptun core main.
 */
void
neptun_core_main(void)
{
  switch (neptun_core_state)
  {
    case CORE_INITIALIZING:
      neptun_core_state = CORE_RUNNING;
      break;

    case CORE_SERVICE:
      break;

    case CORE_SHUTDOWN:
      break;

    case CORE_STANDBY:
      break;

    case CORE_RUNNING:
      break;

  }

  return;
}


/**
 * Get Neptun Core state.
 */
neptun_core_states
neptun_core_get_state(void)
{
  return neptun_core_state;
}


/*
  -- Ethersex META --
  header(services/project_neptun/neptun.h)
  init(neptun_core_init)
  mainloop(neptun_core_main)
*/
