#include "StdMsgsStringSplDcps.h"
#include "ccpp_StdMsgsString.h"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__std_msgs__String__copyIn(
    c_base base,
    const struct std_msgs__String *from,
    struct _std_msgs__String *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if(from->data){
        to->data = c_stringNew_s(base, from->data);
        if(to->data == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'std_msgs__String.data' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->data = c_stringNew_s(base, from->data);
    if(to->data == NULL) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
    return result;
}

void
__std_msgs__String__copyOut(
    const void *_from,
    void *_to)
{
    const struct _std_msgs__String *from = (const struct _std_msgs__String *)_from;
    struct std_msgs__String *to = (struct std_msgs__String *)_to;
    to->data = DDS::string_dup(from->data ? from->data : "");
}

