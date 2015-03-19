LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog -lc -lz
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../shiboken/libshiboken/ $(LOCAL_PATH)/../../shiboken/ext/sparsehash/ $(LOCAL_PATH)/../../python4android/build/jni/Include $(LOCAL_PATH)/../../python4android/build/jni/

LOCAL_SRC_FILES := ../../shiboken/libshiboken/basewrapper.cpp ../../shiboken/libshiboken/bindingmanager.cpp ../../shiboken/libshiboken/debugfreehook.cpp ../../shiboken/libshiboken/gilstate.cpp ../../shiboken/libshiboken/helper.cpp ../../shiboken/libshiboken/sbkconverter.cpp ../../shiboken/libshiboken/sbkenum.cpp ../../shiboken/libshiboken/sbkmodule.cpp ../../shiboken/libshiboken/sbkstring.cpp ../../shiboken/libshiboken/shibokenbuffer.cpp ../../shiboken/libshiboken/threadstatesaver.cpp ../../shiboken/libshiboken/typeresolver.cpp

LOCAL_MODULE := shiboken

LOCAL_SHARED_LIBRARIES := python2.7

include $(BUILD_SHARED_LIBRARY)
