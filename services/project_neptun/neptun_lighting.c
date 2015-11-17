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
#include <stdbool.h>

#include "config.h"

#include "neptun.h"
#include "neptun_datastore.h"
#include "neptun_lighting.h"

static neptun_lighting_states neptun_lighting_mainlight_state;

/* prototypes */
static void neptun_lighting_set_main_switch(bool state);
static bool neptun_lighting_get_main_switch(void);

/**
 * Lighting module startup
 */
void
neptun_lighting_startup(void)
{

  neptun_lighting_set_mainlight_state(LIGHTING_OFF);

  return;
}

/**
 * Set main lighting switching state.
 */
void
neptun_lighting_set_mainlight_state(neptun_lighting_states state)
{
  if (neptun_lighting_mainlight_state != state)
  {
    neptun_lighting_mainlight_state = state;

    switch (neptun_lighting_mainlight_state)
    {
      case LIGHTING_ON:
      {
        /* switch main lighting on */
        if (!neptun_lighting_get_main_switch())
          neptun_lighting_set_main_switch(true);

        /* disable AUTO mode */
        // TODO disable cron mode
      }
        break;

      case LIGHTING_OFF:
      {
        /* switch main lighting off */
        if (neptun_lighting_get_main_switch())
          neptun_lighting_set_main_switch(false);

        /* disable AUTO mode */
        // TODO disable cron mode
      }
        break;

      case LIGHTING_AUTO:
      {
        /* activate AUTO mode */
        // TODO cron mode
      }
        break;
    }
  }

  return;
}

/**
 * Set main lighting switch.
 */
static void
neptun_lighting_set_main_switch(bool state)
{
  return;
}


/**
 * Get current main lighting switch state.
 */
static bool
neptun_lighting_get_main_switch(void)
{
  return false;
}


/*
  -- Ethersex META --
  header(services/project_neptun/neptun_lighting.h)
  startup(neptun_lighting_startup)
*/
