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
 *
 * The media bus API is a Madlax kernel feature that allows different
 * types of multimedia to intercommunicate.  It is an accelerated API
 * thanks to being implemented within the kernel.  You can use the media
 * bus API for your drivers and even user space programs.
 *
 * The media bus is similar to OSC in implementation, but without the
 * overhead associated of being networkable.  Mediabus provides an
 * interface that allows you the developer/user to connect different
 * components together.
 *
*/

#ifndef MADLAX_MEDIABUS_H_
#define MADLAX_MEDIABUS_H_ TRUE

