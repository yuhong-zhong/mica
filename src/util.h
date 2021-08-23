// Copyright 2014 Carnegie Mellon University
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "common.h"

#include <assert.h>

#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <sys/resource.h>

#ifdef USE_DPDK
#include <rte_memcpy.h>
#include <rte_launch.h>
#include <rte_eal.h>
#include <rte_lcore.h>
#include <rte_byteorder.h>
#include <rte_log.h>
#include <rte_malloc.h>
#include <rte_debug.h>
#endif

#define MEHCACHED_ROUNDUP8(x) (((x) + 7UL) & (~7UL))
#define MEHCACHED_ROUNDUP64(x) (((x) + 63UL) & (~63UL))
#define MEHCACHED_ROUNDUP4K(x) (((x) + 4095UL) & (~4095UL))
#define MEHCACHED_ROUNDUP1M(x) (((x) + 1048575UL) & (~1048575UL))
#define MEHCACHED_ROUNDUP2M(x) (((x) + 2097151UL) & (~2097151UL))

MEHCACHED_BEGIN

//static
size_t
mehcached_next_power_of_two(size_t v);

//static
void
memory_barrier();

//static
void
mehcached_memcpy8(uint8_t *dest, const uint8_t *src, size_t length);

//static
bool
mehcached_memcmp8(const uint8_t *dest, const uint8_t *src, size_t length);

//static
uint32_t
mehcached_rand(uint64_t *state);

//static
double
mehcached_rand_d(uint64_t *state);

//static
int
mehcached_eal_malloc_lcore_internal(void *arg);

//static
void *
mehcached_eal_malloc_lcore(size_t size, size_t lcore);

//static
void
rte_eal_launch(lcore_function_t *f, void *arg, unsigned int core_id);

MEHCACHED_END

