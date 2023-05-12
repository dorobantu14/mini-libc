// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	void *ret = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if ((long int)ret < 0)
	{
		errno = -(long int)ret;
		return MAP_FAILED;
	}
	return ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	void *ret = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (ret == MAP_FAILED)
	{
		errno = -*(int *)ret;
		return MAP_FAILED;
	}
	return ret;
}

int munmap(void *addr, size_t length)
{
	int ret = syscall(__NR_munmap, addr, length);
	if (ret < 0)
	{
		errno = -ret;
		return -1;
	}
	return 0;
}
