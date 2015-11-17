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

#include "core/util/fixedpoint.h"
#include "hardware/onewire/onewire.h"

#include "neptun_onewire.h"

#include "neptun.h"
#include "neptun_datastore.h"

/**
 * Initialize Neptun onewire module.
 */
void
neptun_onewire_init(void)
{
  hook_ow_poll_register(neptun_onewire_poll_hook);

  return;
}


void
neptun_onewire_poll_hook(ow_sensor_t * ow_sensor, uint8_t state)
{
  switch (state)
  {
    case OW_READY:
    {
      for (uint8_t i = 0; i < OW_SENSORS_COUNT; i++)
      {
        if (ow_sensor[i].present != 0)
          neptun_onewire_read_temperature(&(ow_sensor[i]));
      }
    }
      break;

    case OW_CONVERT:
      /* DO NOTHING */
      break;

    default:
      /* RFU */
      break;
  }

  return;
}


void
neptun_onewire_read_temperature(ow_sensor_t * ow_sensor)
{
  int8_t result = 0;

  if (ow_sensor->named)
  {
    if (strncasecmp_P(ow_sensor->name, PSTR("WAT"), 3) == 0)
    {
      neptun_datastore.water_temperature = ow_sensor->temp.val;
    }
    else if (strncasecmp_P(ow_sensor->name, PSTR("AMB"), 3) == 0)
    {
      neptun_datastore.ambient_temperature = ow_sensor->temp.val;
    }
  }

#ifdef DEBUG_NEPTUN
  {
    char output[10];

    result =
      itoa_fixedpoint(ow_sensor->temp.val, ow_sensor->temp.twodigits + 1,
                      output, sizeof(output));
    NEPTUN_DEBUG(neptun_onewire_read_temperature,
#ifdef ONEWIRE_NAMING_SUPPORT
                 "temperature: %s - %s\n", ow_sensor->name, output);
#else
                 "temperature: NO NAME - %s\n", output);
#endif
  }
#endif

  return;
}

/*
  -- Ethersex META --
  header(services/project_neptun/neptun_onewire.h)
  init(neptun_onewire_init)
*/
