/*
 * Copyright (C) 2007 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVUTIL_SHA_H
#define AVUTIL_SHA_H

#include <stddef.h>
#include <stdint.h>

#include "attributes.h"
#include "version.h"

/**
 * @defgroup lavu_sha SHA
 * @ingroup lavu_crypto
 * @{
 */

struct AVSHA;

/**
 * Allocate an AVSHA context.
 */
struct AVSHA *av_sha_alloc(void);

/**
 * Initialize SHA-1 or SHA-2 hashing.
 *
 * @param context pointer to the function context (of size av_sha_size)
 * @param bits    number of bits in digest (SHA-1 - 160 bits, SHA-2 224 or 256 bits)
 * @return        zero if initialization succeeded, -1 otherwise
 */
int av_sha_init(struct AVSHA* context, int bits);

/**
 * Update hash value.
 *
 * @param ctx     hash function context
 * @param data    input data to update hash with
 * @param len     input data length
 */
#if FF_API_CRYPTO_SIZE_T
void av_sha_update(struct AVSHA *ctx, const uint8_t *data, unsigned int len);
#else
void av_sha_update(struct AVSHA *ctx, const uint8_t *data, size_t len);
#endif

/**
 * Finish hashing and output digest value.
 *
 * @param context hash function context
 * @param digest  buffer where output digest value is stored
 */
void av_sha_final(struct AVSHA* context, uint8_t *digest);

/**
 * @}
 */

#endif /* AVUTIL_SHA_H */
