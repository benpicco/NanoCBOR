/*
 * Copyright (C) 2019 Koen Zandberg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    nanocbor_config NanoCBOR configuration header
 * @brief       Provides compile-time configuration for nanocbor
 */

#ifndef NANOCBOR_CONFIG_H
#define NANOCBOR_CONFIG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NANOCBOR_RECURSION_MAX
#define NANOCBOR_RECURSION_MAX  10
#endif

/**
 * @brief library providing htonll, be64toh or equivalent. Must also provide
 * the reverse operation (ntohll, htobe64 or equivalent)
 */
#ifndef NANOCBOR_BYTEORDER_HEADER
#define NANOCBOR_BYTEORDER_HEADER "endian.h"
#endif

/**
 * @brief call providing htonll or be64toh or equivalent functionality
 *
 * must take a uint64_t big endian and return it in host endianess
 */
#ifndef NANOCBOR_BE64TOH_FUNC
#define NANOCBOR_BE64TOH_FUNC(be)   (be64toh(be))
#endif

/**
 * @brief call providing htonll or htobe32 or equivalent functionality
 *
 * must take a uint32_t in host endianess and return the big endian value
 */
#ifndef NANOCBOR_HTOBE32_FUNC
#define NANOCBOR_HTOBE32_FUNC(he)   htobe32(he)
#endif

/**
 * @brief configuration for size_t SIZE_MAX equivalent
 */
#ifndef NANOCBOR_INT_VAL_SIZE
#if (SIZE_MAX == UINT16_MAX)
#define NANOCBOR_INT_VAL_SIZE           NANOCBOR_INT_VAL_UINT16
#elif (SIZE_MAX == UINT32_MAX)
#define NANOCBOR_INT_VAL_SIZE           NANOCBOR_INT_VAL_UINT32
#elif (SIZE_MAX == UINT64_MAX)
#define NANOCBOR_INT_VAL_SIZE           NANOCBOR_INT_VAL_UINT64
#else
#error ERROR: unable to determine maximum size of size_t
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* NANOCBOR_CONFIG_H */
