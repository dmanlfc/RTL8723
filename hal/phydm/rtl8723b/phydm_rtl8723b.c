/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/

/* ************************************************************
 * include files
 * ************************************************************ */

#include "mp_precomp.h"
#include "../phydm_precomp.h"

#if (RTL8723B_SUPPORT == 1)

s8 phydm_cck_rssi_8723b(struct dm_struct *dm, u8 lna_idx, u8 vga_idx)
{
	s8 rx_pwr_all = 0x00;
	switch (lna_idx) {
	/* 46  53 73 95 201301231630 */
	/* 46 53 77 99 201301241630 */

	case 6:
		rx_pwr_all = -40 - (2 * vga_idx);
		break;
	case 4:
		rx_pwr_all = -20 - (2 * vga_idx);
		break;
	case 1:
		rx_pwr_all = 0 - (2 * vga_idx);
		break;
	case 0:
		rx_pwr_all = 10 - (2 * vga_idx);
		break;
	default:
		/*rx_pwr_all = -53 + (2 * (31 - vga_idx));*/
		/*dbg_print("wrong LNA index\n");*/
		break;
	}
	return rx_pwr_all;
}

#endif /* end if RTL8723B */
