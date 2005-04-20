/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */


#ifdef __cplusplus
template<class T> class SwigValueWrapper {
    T *tt;
public:
    SwigValueWrapper() : tt(0) { }
    SwigValueWrapper(const SwigValueWrapper<T>& rhs) : tt(new T(*rhs.tt)) { }
    SwigValueWrapper(const T& t) : tt(new T(t)) { }
    ~SwigValueWrapper() { delete tt; } 
    SwigValueWrapper& operator=(const T& t) { delete tt; tt = new T(t); return *this; }
    operator T&() const { return *tt; }
    T *operator&() { return tt; }
private:
    SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
};
#endif


#ifndef SWIG_TEMPLATE_DISAMBIGUATOR
#  if defined(__SUNPRO_CC) 
#    define SWIG_TEMPLATE_DISAMBIGUATOR template
#  else
#    define SWIG_TEMPLATE_DISAMBIGUATOR 
#  endif
#endif


#if defined(__GNUC__)
    typedef long long __int64; /*For gcc on Windows */
#endif
#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" } };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  jenv->ExceptionClear();
  excep = jenv->FindClass(except_ptr->java_exception);
  if (excep)
    jenv->ThrowNew(excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include "javaTST.h"


#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_tstJNI_get_1UNDEFINED_1INDEX(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int) -1;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jstring JNICALL Java_tstJNI_get_1TST_1VERSION(JNIEnv *jenv, jclass jcls) {
    jstring jresult = 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    result = (char *) "0.6";
    
    {
        if(result) jresult = jenv->NewStringUTF(result); 
    }
    return jresult;
}


JNIEXPORT jlong JNICALL Java_tstJNI_new_1_1JavaTST_1_1SWIG_10(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
    jlong jresult = 0 ;
    FILE *arg1 = (FILE *) 0 ;
    serializer<char,jobject > *arg2 = (serializer<char,jobject > *) 0 ;
    tst<char,jobject > *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(FILE **)&jarg1; 
    arg2 = *(serializer<char,jobject > **)&jarg2; 
    result = (tst<char,jobject > *)new tst<char,jobject >(arg1,arg2);
    
    *(tst<char,jobject > **)&jresult = result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_tstJNI_new_1_1JavaTST_1_1SWIG_11(JNIEnv *jenv, jclass jcls, jint jarg1, jobject jarg2) {
    jlong jresult = 0 ;
    int arg1 ;
    jobject arg2 ;
    tst<char,jobject > *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = (int)jarg1; 
    arg2 = jarg2; 
    result = (tst<char,jobject > *)new tst<char,jobject >(arg1,arg2);
    
    *(tst<char,jobject > **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI_delete_1_1JavaTST(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    delete arg1;
    
}


JNIEXPORT void JNICALL Java_tstJNI__1JavaTST_1pack(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    (arg1)->pack();
    
}


JNIEXPORT jobject JNICALL Java_tstJNI__1JavaTST_1walk(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
    jobject jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    filter<char,jobject > *arg2 = (filter<char,jobject > *) 0 ;
    action<char,jobject > *arg3 = (action<char,jobject > *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    arg2 = *(filter<char,jobject > **)&jarg2; 
    arg3 = *(action<char,jobject > **)&jarg3; 
    result = (arg1)->walk(arg2,arg3);
    
    jresult = result; 
    return jresult;
}


JNIEXPORT jobject JNICALL Java_tstJNI__1JavaTST_1almost(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jint jarg3, jint jarg4, jlong jarg5, jlong jarg6) {
    jobject jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    int arg3 ;
    int arg4 ;
    filter<char,jobject > *arg5 = (filter<char,jobject > *) 0 ;
    action<char,jobject > *arg6 = (action<char,jobject > *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    arg3 = (int)jarg3; 
    arg4 = (int)jarg4; 
    arg5 = *(filter<char,jobject > **)&jarg5; 
    arg6 = *(action<char,jobject > **)&jarg6; 
    result = (arg1)->almost(arg2,arg3,arg4,arg5,arg6);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jobject JNICALL Java_tstJNI__1JavaTST_1common_1prefix(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jlong jarg3, jlong jarg4) {
    jobject jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    filter<char,jobject > *arg3 = (filter<char,jobject > *) 0 ;
    action<char,jobject > *arg4 = (action<char,jobject > *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    arg3 = *(filter<char,jobject > **)&jarg3; 
    arg4 = *(action<char,jobject > **)&jarg4; 
    result = (arg1)->common_prefix(arg2,arg3,arg4);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jobject JNICALL Java_tstJNI__1JavaTST_1scan(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jlong jarg3) {
    jobject jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    action<char,jobject > *arg3 = (action<char,jobject > *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    arg3 = *(action<char,jobject > **)&jarg3; 
    result = (arg1)->scan(arg2,arg3);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jobject JNICALL Java_tstJNI__1JavaTST_1scan_1with_1stop_1chars(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jlong jarg4) {
    jobject jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    char *arg3 = (char *) 0 ;
    action<char,jobject > *arg4 = (action<char,jobject > *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)jenv->GetStringUTFChars(jarg3, 0);
            if (!arg3) return 0;
        }
    }
    arg4 = *(action<char,jobject > **)&jarg4; 
    result = (arg1)->scan_with_stop_chars(arg2,arg3,arg4);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    {
        if (arg3) jenv->ReleaseStringUTFChars(jarg3, arg3); 
    }
    return jresult;
}


JNIEXPORT jobject JNICALL Java_tstJNI__1JavaTST_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    jobject jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    result = (arg1)->get(arg2);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jobject JNICALL Java_tstJNI__1JavaTST_1get_1or_1build(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jlong jarg3) {
    jobject jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    filter<char,jobject > *arg3 = (filter<char,jobject > *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    arg3 = *(filter<char,jobject > **)&jarg3; 
    result = (arg1)->get_or_build(arg2,arg3);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jobject JNICALL Java_tstJNI__1JavaTST_1put(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jobject jarg3) {
    jobject jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    jobject arg3 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    arg3 = jarg3; 
    result = (arg1)->put(arg2,arg3);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI__1JavaTST_1remove(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return ;
        }
    }
    (arg1)->remove(arg2);
    
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
}


JNIEXPORT jint JNICALL Java_tstJNI__1JavaTST_1get_1maximum_1key_1length(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    result = (int)(arg1)->get_maximum_key_length();
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_tstJNI__1JavaTST_1bytes_1allocated(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jlong jresult = 0 ;
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    size_t result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    result = (arg1)->bytes_allocated();
    
    jresult = (jlong)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI__1JavaTST_1write(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    FILE *arg2 = (FILE *) 0 ;
    serializer<char,jobject > *arg3 = (serializer<char,jobject > *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    arg2 = *(FILE **)&jarg2; 
    arg3 = *(serializer<char,jobject > **)&jarg3; 
    (arg1)->write(arg2,arg3);
    
}


JNIEXPORT void JNICALL Java_tstJNI__1JavaTST_1debug_1print_1root(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    tst<char,jobject > *arg1 = (tst<char,jobject > *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(tst<char,jobject > **)&jarg1; 
    (arg1)->debug_print_root();
    
}


JNIEXPORT void JNICALL Java_tstJNI_delete_1_1Action(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    action<char,jobject > *arg1 = (action<char,jobject > *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(action<char,jobject > **)&jarg1; 
    delete arg1;
    
}


JNIEXPORT void JNICALL Java_tstJNI__1Action_1perform(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jint jarg3, jobject jarg4) {
    action<char,jobject > *arg1 = (action<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    int arg3 ;
    jobject arg4 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(action<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return ;
        }
    }
    arg3 = (int)jarg3; 
    arg4 = jarg4; 
    (arg1)->perform(arg2,arg3,arg4);
    
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
}


JNIEXPORT jobject JNICALL Java_tstJNI__1Action_1result(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jobject jresult = 0 ;
    action<char,jobject > *arg1 = (action<char,jobject > *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(action<char,jobject > **)&jarg1; 
    result = (arg1)->result();
    
    jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI_delete_1_1Filter(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    filter<char,jobject > *arg1 = (filter<char,jobject > *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(filter<char,jobject > **)&jarg1; 
    delete arg1;
    
}


JNIEXPORT jobject JNICALL Java_tstJNI__1Filter_1perform(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jint jarg3, jobject jarg4) {
    jobject jresult = 0 ;
    filter<char,jobject > *arg1 = (filter<char,jobject > *) 0 ;
    char *arg2 = (char *) 0 ;
    int arg3 ;
    jobject arg4 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(filter<char,jobject > **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    arg3 = (int)jarg3; 
    arg4 = jarg4; 
    result = (arg1)->perform(arg2,arg3,arg4);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI_delete_1_1Serializer(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    serializer<char,jobject > *arg1 = (serializer<char,jobject > *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(serializer<char,jobject > **)&jarg1; 
    delete arg1;
    
}


JNIEXPORT void JNICALL Java_tstJNI__1Serializer_1write(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jobject jarg3) {
    serializer<char,jobject > *arg1 = (serializer<char,jobject > *) 0 ;
    FILE *arg2 = (FILE *) 0 ;
    jobject arg3 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(serializer<char,jobject > **)&jarg1; 
    arg2 = *(FILE **)&jarg2; 
    arg3 = jarg3; 
    (arg1)->write(arg2,arg3);
    
}


JNIEXPORT jobject JNICALL Java_tstJNI__1Serializer_1read(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
    jobject jresult = 0 ;
    serializer<char,jobject > *arg1 = (serializer<char,jobject > *) 0 ;
    FILE *arg2 = (FILE *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(serializer<char,jobject > **)&jarg1; 
    arg2 = *(FILE **)&jarg2; 
    result = (arg1)->read(arg2);
    
    jresult = result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_tstJNI_new_1JavaTST(JNIEnv *jenv, jclass jcls) {
    jlong jresult = 0 ;
    JavaTST *result;
    
    (void)jenv;
    (void)jcls;
    result = (JavaTST *)new JavaTST();
    
    *(JavaTST **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI_delete_1JavaTST(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    JavaTST *arg1 = (JavaTST *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(JavaTST **)&jarg1; 
    delete arg1;
    
}


JNIEXPORT jlong JNICALL Java_tstJNI_new_1Action(JNIEnv *jenv, jclass jcls, jobject jarg1) {
    jlong jresult = 0 ;
    jobject arg1 ;
    Action *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = jarg1; 
    result = (Action *)new Action(arg1);
    
    *(Action **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI_Action_1perform(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jint jarg3, jobject jarg4) {
    Action *arg1 = (Action *) 0 ;
    char *arg2 = (char *) 0 ;
    int arg3 ;
    jobject arg4 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(Action **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return ;
        }
    }
    arg3 = (int)jarg3; 
    arg4 = jarg4; 
    (arg1)->perform(arg2,arg3,arg4);
    
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
}


JNIEXPORT jobject JNICALL Java_tstJNI_Action_1result(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jobject jresult = 0 ;
    Action *arg1 = (Action *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(Action **)&jarg1; 
    result = (arg1)->result();
    
    jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI_delete_1Action(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    Action *arg1 = (Action *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(Action **)&jarg1; 
    delete arg1;
    
}


JNIEXPORT jobject JNICALL Java_tstJNI_Filter_1perform(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jint jarg3, jobject jarg4) {
    jobject jresult = 0 ;
    Filter *arg1 = (Filter *) 0 ;
    char *arg2 = (char *) 0 ;
    int arg3 ;
    jobject arg4 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(Filter **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
            if (!arg2) return 0;
        }
    }
    arg3 = (int)jarg3; 
    arg4 = jarg4; 
    result = (arg1)->perform(arg2,arg3,arg4);
    
    jresult = result; 
    {
        if (arg2) jenv->ReleaseStringUTFChars(jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jlong JNICALL Java_tstJNI_new_1Filter(JNIEnv *jenv, jclass jcls) {
    jlong jresult = 0 ;
    Filter *result;
    
    (void)jenv;
    (void)jcls;
    result = (Filter *)new Filter();
    
    *(Filter **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI_delete_1Filter(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    Filter *arg1 = (Filter *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(Filter **)&jarg1; 
    delete arg1;
    
}


JNIEXPORT void JNICALL Java_tstJNI_Serializer_1write(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jobject jarg3) {
    Serializer *arg1 = (Serializer *) 0 ;
    FILE *arg2 = (FILE *) 0 ;
    jobject arg3 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(Serializer **)&jarg1; 
    arg2 = *(FILE **)&jarg2; 
    arg3 = jarg3; 
    (arg1)->write(arg2,arg3);
    
}


JNIEXPORT jobject JNICALL Java_tstJNI_Serializer_1read(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
    jobject jresult = 0 ;
    Serializer *arg1 = (Serializer *) 0 ;
    FILE *arg2 = (FILE *) 0 ;
    jobject result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(Serializer **)&jarg1; 
    arg2 = *(FILE **)&jarg2; 
    result = (arg1)->read(arg2);
    
    jresult = result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_tstJNI_new_1Serializer(JNIEnv *jenv, jclass jcls) {
    jlong jresult = 0 ;
    Serializer *result;
    
    (void)jenv;
    (void)jcls;
    result = (Serializer *)new Serializer();
    
    *(Serializer **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_tstJNI_delete_1Serializer(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    Serializer *arg1 = (Serializer *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(Serializer **)&jarg1; 
    delete arg1;
    
}


JNIEXPORT jlong JNICALL Java_tstJNI_SWIGJavaTSTUpcast(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jlong baseptr = 0;
    (void)jenv;
    (void)jcls;
    *(tst<char,jobject > **)&baseptr = *(JavaTST **)&jarg1;
    return baseptr;
}

JNIEXPORT jlong JNICALL Java_tstJNI_SWIGActionUpcast(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jlong baseptr = 0;
    (void)jenv;
    (void)jcls;
    *(action<char,jobject > **)&baseptr = *(Action **)&jarg1;
    return baseptr;
}

JNIEXPORT jlong JNICALL Java_tstJNI_SWIGFilterUpcast(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jlong baseptr = 0;
    (void)jenv;
    (void)jcls;
    *(filter<char,jobject > **)&baseptr = *(Filter **)&jarg1;
    return baseptr;
}

JNIEXPORT jlong JNICALL Java_tstJNI_SWIGSerializerUpcast(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jlong baseptr = 0;
    (void)jenv;
    (void)jcls;
    *(serializer<char,jobject > **)&baseptr = *(Serializer **)&jarg1;
    return baseptr;
}

#ifdef __cplusplus
}
#endif

