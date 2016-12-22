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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <util/delay.h>

#include <avr/io.h>
#include <avr/pgmspace.h>

#include "config.h"
#include "neptun.h"
#include "protocols/ecmd/ecmd-base.h"

int16_t
parse_cmd_neptun_command(char *cmd, char *output, uint16_t len)
{
  NEPTUN_DEBUG(parse_cmd_neptun_command, "%s\n", cmd);

  return ECMD_FINAL_OK;
}

int16_t
parse_cmd_neptun_mode(char *cmd, char *output, uint16_t len)
{
  NEPTUN_DEBUG(parse_cmd_neptun_mode, "%s\n", cmd);

  return ECMD_FINAL_OK;
}

/*
  -- Ethersex META --
  block([[Neptun]])
  ecmd_feature(neptun_command, "neptun command", COMMAND, Manually call neptun application COMMAND )
  ecmd_feature(neptun_mode, "neptun mode", MODE, Set operating mode MODE)
*/
