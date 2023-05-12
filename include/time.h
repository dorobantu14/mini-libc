/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef	__TIME_H__
#define	__TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

typedef long int __time_t;
typedef __time_t time_t;

struct timespec {
	time_t tv_sec;
	long int tv_nsec;
};

int nanosleep(const struct timespec *, struct timespec *);

#ifdef __cplusplus
}
#endif

#endif
