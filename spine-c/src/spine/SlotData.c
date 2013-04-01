/*******************************************************************************
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#include <spine/SlotData.h>
#include <spine/extension.h>

#ifdef __cplusplus
namespace spine {
#endif

SlotData* SlotData_new (const char* name, BoneData* boneData) {
	SlotData* self = NEW(SlotData);
	MALLOC_STR(self->name, name);
	CONST_CAST(BoneData*, self->boneData) = boneData;
	self->r = 1;
	self->g = 1;
	self->b = 1;
	self->a = 1;
	return self;
}

void SlotData_free (SlotData* self) {
	FREE(self->name);
	FREE(self->attachmentName);
	FREE(self);
}

void SlotData_setAttachmentName (SlotData* self, const char* attachmentName) {
	FREE(self->attachmentName);
	if (attachmentName)
		MALLOC_STR(self->attachmentName, attachmentName);
	else
		CONST_CAST(char*, self->attachmentName) = 0;
}

#ifdef __cplusplus
}
#endif
