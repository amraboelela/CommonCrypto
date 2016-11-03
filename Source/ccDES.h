/*
 * Copyright (c) 2006 Apple Computer, Inc. All Rights Reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef	_CC_DES_H_
#define _CC_DES_H_

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DES_BLOCK_SIZE_BYTES		8	/* in bytes */
#define DES_KEY_SIZE_BITS			56	/* effective key size in bits */
#define DES_KEY_SIZE_BITS_EXTERNAL	64	/* clients actually pass in this much */
#define DES_KEY_SIZE_BYTES_EXTERNAL	(DES_KEY_SIZE_BITS_EXTERNAL / 8)

/*
 * Per-instance data.
 */
struct _desInst {
    	/* 8 16-bit subkeys for each of 16 rounds, initialized by setkey()
    	 */
	unsigned char kn[16][8];
};

typedef struct _desInst *desInst;

int ccDessetkey(desInst dinst, char *key, size_t keyLength);
void ccEndes(desInst dinst, char *blockIn, char *blockOut);
void ccDedes(desInst dinst, char *blockIn, char *blockOut);

/* triple DES */
struct _des3Inst {
	struct _desInst		desInst[3];
};
typedef struct _des3Inst *des3Inst;

int ccDes3setkey(des3Inst dinst, char *key, size_t keyLength);
void ccEndes3(des3Inst dinst, char *blockIn, char *blockOut);
void ccDedes3(des3Inst dinst, char *blockIn, char *blockOut);

#ifdef __cplusplus
}
#endif

#endif	/*_CK_DES_H_*/
