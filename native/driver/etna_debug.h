/*
 * Copyright (c) 2012-2013 Etnaviv Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/* Common debug stuffl */
#ifndef H_ETNA_DEBUG
#define H_ETNA_DEBUG

#include <stdint.h>
#include <stdlib.h>
#include "util/u_debug.h"

/* Logging */
#define ETNA_DBG_MSGS          0x1 /* Warnings and non-fatal errors */
#define ETNA_DBG_FRAME_MSGS    0x2
#define ETNA_DBG_RESOURCE_MSGS 0x4
#define ETNA_DBG_COMPILER_MSGS 0x8
#define ETNA_DBG_LINKER_MSGS   0x10
#define ETNA_DBG_DUMP_SHADERS  0x20

/* Bypasses */
#define ETNA_DBG_NO_TS         0x1000 /* Disable TS */
#define ETNA_DBG_CFLUSH_ALL    0x2000 /* Flush before every state update + draw call */
#define ETNA_DBG_MSAA_2X       0x4000 /* Force 2X MSAA for screen */
#define ETNA_DBG_MSAA_4X       0x8000 /* Force 4X MSAA for screen */
#define ETNA_DBG_FINISH_ALL    0x10000 /* Finish on every flush */
#define ETNA_DBG_FLUSH_ALL     0x20000 /* Flush after every rendered primitive */

extern uint32_t etna_mesa_debug; /* set in etna_screen.c from ETNA_DEBUG */

#define DBG_ENABLED(flag) (etna_mesa_debug & (flag))

#define DBG_F(flag, fmt, ...) \
		do { if (etna_mesa_debug & (flag)) \
			debug_printf("%s:%d: "fmt "\n", \
				__FUNCTION__, __LINE__, ##__VA_ARGS__); } while (0)

#define DBG(fmt, ...) \
		do { if (etna_mesa_debug & ETNA_DBG_MSGS) \
			debug_printf("%s:%d: "fmt "\n", \
				__FUNCTION__, __LINE__, ##__VA_ARGS__); } while (0)


#endif

