/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


class tstJNI {
  public final static native int get_UNDEFINED_INDEX();
  public final static native String get_TST_VERSION();
  public final static native long new__ObjectTST__SWIG_0(long jarg1, long jarg2);
  public final static native long new__ObjectTST__SWIG_1(int jarg1, Object jarg2);
  public final static native void delete__ObjectTST(long jarg1);
  public final static native void _ObjectTST_pack(long jarg1);
  public final static native Object _ObjectTST_walk(long jarg1, long jarg2, long jarg3);
  public final static native Object _ObjectTST_almost(long jarg1, String jarg2, int jarg3, int jarg4, long jarg5, long jarg6);
  public final static native Object _ObjectTST_common_prefix(long jarg1, String jarg2, long jarg3, long jarg4);
  public final static native Object _ObjectTST_scan(long jarg1, String jarg2, long jarg3);
  public final static native Object _ObjectTST_scan_with_stop_chars(long jarg1, String jarg2, String jarg3, long jarg4);
  public final static native Object _ObjectTST_get(long jarg1, String jarg2);
  public final static native Object _ObjectTST_get_or_build(long jarg1, String jarg2, long jarg3);
  public final static native Object _ObjectTST_put(long jarg1, String jarg2, Object jarg3);
  public final static native void _ObjectTST_remove(long jarg1, String jarg2);
  public final static native int _ObjectTST_get_maximum_key_length(long jarg1);
  public final static native long _ObjectTST_bytes_allocated(long jarg1);
  public final static native void _ObjectTST_write(long jarg1, long jarg2, long jarg3);
  public final static native void _ObjectTST_debug_print_root(long jarg1);
  public final static native void delete__ObjectAction(long jarg1);
  public final static native void _ObjectAction_perform(long jarg1, String jarg2, int jarg3, Object jarg4);
  public final static native Object _ObjectAction_result(long jarg1);
  public final static native void delete__ObjectFilter(long jarg1);
  public final static native Object _ObjectFilter_perform(long jarg1, String jarg2, int jarg3, Object jarg4);
  public final static native void delete__ObjectSerializer(long jarg1);
  public final static native void _ObjectSerializer_write(long jarg1, long jarg2, Object jarg3);
  public final static native Object _ObjectSerializer_read(long jarg1, long jarg2);
  public final static native long new_ObjectTST(Object jarg1);
  public final static native void delete_ObjectTST(long jarg1);
  public final static native long new_ObjectAction(Object jarg1, String jarg2, String jarg3);
  public final static native void delete_ObjectAction(long jarg1);
  public final static native void ObjectAction_perform(long jarg1, String jarg2, int jarg3, Object jarg4);
  public final static native Object ObjectAction_result(long jarg1);
  public final static native Object ObjectFilter_perform(long jarg1, String jarg2, int jarg3, Object jarg4);
  public final static native long new_ObjectFilter();
  public final static native void delete_ObjectFilter(long jarg1);
  public final static native void ObjectSerializer_write(long jarg1, long jarg2, Object jarg3);
  public final static native Object ObjectSerializer_read(long jarg1, long jarg2);
  public final static native long new_ObjectSerializer();
  public final static native void delete_ObjectSerializer(long jarg1);
  public final static native long SWIGObjectTSTUpcast(long jarg1);
  public final static native long SWIGObjectActionUpcast(long jarg1);
  public final static native long SWIGObjectFilterUpcast(long jarg1);
  public final static native long SWIGObjectSerializerUpcast(long jarg1);
}
