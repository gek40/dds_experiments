#ifndef STDMSGSSTRINGSPLTYPES_H
#define STDMSGSSTRINGSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "ccpp_StdMsgsString.h"


extern const char *std_msgs__String_metaDescriptor[];
extern const int std_msgs__String_metaDescriptorArrLength;
extern const int std_msgs__String_metaDescriptorLength;
extern c_metaObject __std_msgs__String__load (c_base base);
struct _std_msgs__String ;
extern  v_copyin_result __std_msgs__String__copyIn(c_base base, const struct std_msgs__String *from, struct _std_msgs__String *to);
extern  void __std_msgs__String__copyOut(const void *_from, void *_to);
struct _std_msgs__String {
    c_string data;
};

#undef OS_API
#endif
