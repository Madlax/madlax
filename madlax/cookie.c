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

#ifndef NEED_CONFIG_H_
#include <config.h>
#endif

/**
  Cookie jar handling routines
  ----------------------------
  
  The "cookie jar" is an area of memory reserved by Madlax for tokens,
  tags, and other "cookies" (similar to http cookies).  A cookie, is a
  small piece of data sent from an application and stored inside the jar 
  while a user session is in play.  When the user logs back in, the data 
  stored in the "cookie jar" will notify the session manager of the 
  user's previous activity.
                         **/

#include <madlax/madlax.h>
#include <libkern/libkern.h>
#include <arch/cache.h>

#include "cookie.h"
#include "atomic.h"
#include "global.h"
#include "memory.h"
#include "async_IO.h"

#ifdef JAR_PRIVATE
#include <arch/user_things.h>
#include "proc.h"
#endif

static struct cookie *oldcookie = NULL;
static struct cookie *newcookie;

#ifdef JAR_PRIVATE
#define MASTERCOOKIES 128
static struct cookie masterjar[MASTERCOOKIES];
#else
/* Memory region that holds the cooie jar */
static MEMORYID *newjar_region;
#endif

/* Cookies to skip putting in the cookie jar */
static const long skiplist[] =
{
   COOKIE_USRDATA,  /* We're not interested in user's private data */
   COOKIE_OLDDATA,  /* We're not interested in the old session state */
   COOKIE__CPU,
   COOKIE__FPU,
   
