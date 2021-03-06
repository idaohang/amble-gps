/*
 * global.c
 *
 *  Created on: Apr 27, 2013
 *      Author: yiding
 */

#include "global.h"

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

CheckSum_t ChecksumCalculator(const void * buf, size_t n) {
	CheckSum_t checksum = 0;
	unsigned i;
	for (i = 0; i < n; i++) {
		checksum += *(((uint8_t *)buf) + i);
	}
	//printf("checksum %u\n", checksum);
	return checksum;
}
