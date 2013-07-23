/* --- MADLAX-LICENSE-HEADER-BEGIN ---
 *
 * Copyright (C) 2000-2011 Daniel Hoggan. All rights reserved.
 *
 * This Package is made available to you under the terms of the Open 
 * Development License.  This Package should be accompanied by a file
 * that contains the associated licensing terms. If you are unable to
 * find this file, a copy of the License can be found in the file
 * LICENSE.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *    1. Redistributions of the Package must retain the above 
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *    
 *    3. The name of the Copyright Holder may not be used to endorse
 *       or promote products that use the Package without specific
 *       prior written permission.
 *
 * THIS PACKAGE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * --- MADLAX-LICENSE-HEADER-END ---
*/

#ifndef SYS_ASYNCIO_H_
#define SYS_ASYNCIO_H_ TRUE

#ifndef ASYNC_IO_H_
#include "async_IO.h"
#endif

#include <sys/select.h>

#define SEL_READ	0	/* Code for a READ */
#define SEL_WRITE	1	/* Code for a WRITE */
#define SEL_EXCEPT	2	/* Code for some exception */
#define SEL_NR		3	/* Number of codes */

struct _asynfd
{
   int	afd_seen;		/* Set if we manage this descriptor */
   int	afd_flags;		/* File flags by fcntl (fd, F_GETFL) */
   int	afd_state[SEL_NR];	/* Operation state */
};

typedef struct
{
   int	asyn_more;		/* Set if more to do before blocking */
   struct _asynfd asyn_afd[FD_SETSIZE];
   fd_set 	  asyn_fdset[SEL_NR];	/* Select() fd sets */
} asyncio_t;

#define ASYN_INPROGRESS EAGAIN	/* Errno code telling "nothing yet" */
#define ASYN_NONBLOCK   0x01	/* If asyn_wait() mustn't block */

struct timeval;

void asyn_init(asyncio_t *_asyn);
ssize_t asyn_read(asyncio_t *_asyn, int _fd, void *_buf, size_t _len);
ssize_t asyn_write(asyncio_t *_asyn, int _fd, const void *_buf, size_t _len);
int asyn_special(asyncio_t *_asyn, int _fd, int _op);
int asyn_result(asyncio_t *_asyn, int _fd, int _op, int _result);
int asyn_wait(asyncio_t *_asyn, int _flags, struct timeval *to);
int asyn_cancel(asyncio_t *_asyn, int _fd, int _op);
int asyn_pending(asyncio_t *_asyn, int _fd, int _op);
int asyn_synch(asyncio_t *_asyn, int _fd);
int asyn_close(asyncio_t *_asyn, int _fd);

#endif /* SYS_ASYNCIO_H_ */
