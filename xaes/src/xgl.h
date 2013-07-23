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

#ifndef XAES_XGL_H_
#define XAES_XGL_H_ TRUE

#ifndef __madlax__
#include <madlax/madlax.h>
#endif

#ifndef __egl__
#include <egl/egl.h>
#endif

#ifndef __glut__
#include <glu/glut.h>
#endif

#ifndef __gl__
#include <gl/gl.h>
#endif

#include "xaes.h"
#include "global.h"
#include <arch/cpuid.h>
#include <arch/cache.h>
#include <arch/channel.h>
#include <arch/slabs.h>
#include <arch/dma.h>
#include <arch/device.h>
#include <arch/intr.h>
#include <arch/machine.h>
#include <arch/fpu.h>
#include <cpu_event.h>
#include <init.h>

#include "xgl_clut.h"
#include "xgl_dlist.h"
#include "xgl_dma.h"
#include "xgl_drawabl.h"
#include "xgl_fbdev.h"
#include "xgl_hash.h"
#include "xgl_pipeline.h"
#include "xgl_rast.h"
#include "xgl_shm.h"
#include "xgl_slab.h"

