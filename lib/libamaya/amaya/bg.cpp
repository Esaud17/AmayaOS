/*
 * Copyright (C) 2014 Dan Rulos.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "amaya.h"
#include <stdio.h>
#include <VGA.h>

void bg()
{
    int i;
    u16 *vga;
    MemoryMessage mem;

    /* Request VGA memory. */
    mem.action    = CreatePrivate;
    mem.bytes     = PAGESIZE;
    mem.virtualAddress  = ZERO;
    mem.physicalAddress = VGA_PADDR;
    mem.protection      = PAGE_RW | PAGE_PINNED;
    mem.ipc(MEMSRV_PID, SendReceive, sizeof(mem));

    /* Point to the VGA mapping. */
    vga = (u16 *) mem.virtualAddress;

    for (i=0; i < 2000; i++) {
      vga[i] = VGA_CHAR(' ', BLUE, BLUE);
    }
}
