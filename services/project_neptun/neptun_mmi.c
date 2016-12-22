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

#include <stdint.h>
#include <stdlib.h>

#include <avr/pgmspace.h>

#include <util/delay.h>

#include "config.h"

#include "core/util/fixedpoint.h"
#include "core/tty/tty.h"
#ifdef NEPTUN_MMI_HD44780_SUPPORT
#include "hardware/lcd/hd44780.h"
#endif


#include "neptun_mmi.h"

#include "neptun_datastore.h"

/**
 * All the strings and texts, might be useful for translations.
 */
#define NEPTUN_LABEL_TEMP_AMBIENT "Luft  "
#define NEPTUN_LABEL_TEMP_WATER "Wasser"

#ifdef NEPTUN_MMI_HD44780_SUPPORT
#define NEPTUN_UNIT_DEGREECENTIGRADE "\xdf" "C" // prevents gcc from interpreting the complete seq \xdfC as hex number
#else
#define NEPTUN_UNIT_DEGREECENTIGRADE "°C"
#endif

static void neptun_mmi_backlight(uint8_t state);
static void neptun_mmi_show_greeter(void);

static WINDOW *neptun_win_temp_ambient;
static WINDOW *neptun_win_temp_water;


/**
 * Control MMI Display backlight.
 */
static void
neptun_mmi_backlight(uint8_t state)
{
#ifdef NEPTUN_MMI_HD44780_SUPPORT
#ifdef HD44780_BACKLIGHT_INV
  state = (state) ? 0 : 1;
#endif
  hd44780_backlight(state);
#endif

  return;
}


/**
 * Show greeter.
 */
static void
neptun_mmi_show_greeter(void)
{
  WINDOW *greeterwin = subwin(curscr, 2, 16, 0, 0);

  waddstr_P(greeterwin, PSTR("Welcome to\nProject Neptun!"));

  free(greeterwin);

  return;
}


/**
 * MMI Startup.
 */
void
neptun_mmi_startup(void)
{
  /* LCD backlight on */
  neptun_mmi_backlight(1);

  /* ... and show greeter */
  neptun_mmi_show_greeter();

  neptun_win_temp_ambient = subwin(curscr, 1, 16, 0, 0);
  neptun_win_temp_water = subwin(curscr, 1, 16, 1, 0);

  //clear();

  return;
}


/**
 * Periodic display update
 */
void
neptun_mmi_periodic_display_update(void)
{
  static uint8_t updatecycle = 10;

  if (--updatecycle == 0)
  {
    int8_t result;
    char output[16];

    /* update temperature display */
    result =
      itoa_fixedpoint(neptun_datastore.ambient_temperature, 1, output,
                      sizeof(output));
    wclear(neptun_win_temp_ambient);
    wprintw_P(neptun_win_temp_ambient,
              PSTR(NEPTUN_LABEL_TEMP_AMBIENT " %s"
                   NEPTUN_UNIT_DEGREECENTIGRADE), output);

    result =
      itoa_fixedpoint(neptun_datastore.water_temperature, 1, output,
                      sizeof(output));
    wclear(neptun_win_temp_water);
    wprintw_P(neptun_win_temp_water,
              PSTR(NEPTUN_LABEL_TEMP_WATER " %s"
                   NEPTUN_UNIT_DEGREECENTIGRADE), output);

    updatecycle = 10;
  }

  return;
}


/*
  -- Ethersex META --
  header(services/project_neptun/neptun_mmi.h)
  startup(neptun_mmi_startup)
  timer(50, neptun_mmi_periodic_display_update)
*/
