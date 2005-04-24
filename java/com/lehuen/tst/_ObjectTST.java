/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.lehuen.tst;

public class _ObjectTST {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected _ObjectTST(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(_ObjectTST obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected _ObjectTST() {
    this(0, false);
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      tstJNI.delete__ObjectTST(swigCPtr);
    }
    swigCPtr = 0;
  }

  public _ObjectTST(SWIGTYPE_p_memory_storageTjchar_jobject_t storage, SWIGTYPE_p_FILE file, _ObjectSerializer reader) {
    this(tstJNI.new__ObjectTST__SWIG_0(SWIGTYPE_p_memory_storageTjchar_jobject_t.getCPtr(storage), SWIGTYPE_p_FILE.getCPtr(file), _ObjectSerializer.getCPtr(reader)), true);
  }

  public _ObjectTST(SWIGTYPE_p_memory_storageTjchar_jobject_t storage, Object default_value) {
    this(tstJNI.new__ObjectTST__SWIG_1(SWIGTYPE_p_memory_storageTjchar_jobject_t.getCPtr(storage), default_value), true);
  }

  public void pack() {
    tstJNI._ObjectTST_pack(swigCPtr);
  }

  public Object walk(_ObjectFilter filter, _ObjectAction to_perform) {
    return tstJNI._ObjectTST_walk(swigCPtr, _ObjectFilter.getCPtr(filter), _ObjectAction.getCPtr(to_perform));
  }

  public Object almost(String string, int maximum_distance, _ObjectFilter filter, _ObjectAction to_perform) {
    return tstJNI._ObjectTST_almost(swigCPtr, string, maximum_distance, _ObjectFilter.getCPtr(filter), _ObjectAction.getCPtr(to_perform));
  }

  public Object common_prefix(String string, _ObjectFilter filter, _ObjectAction to_perform) {
    return tstJNI._ObjectTST_common_prefix(swigCPtr, string, _ObjectFilter.getCPtr(filter), _ObjectAction.getCPtr(to_perform));
  }

  public Object get(String string) {
    return tstJNI._ObjectTST_get(swigCPtr, string);
  }

  public Object get_or_build(String string, _ObjectFilter factory) {
    return tstJNI._ObjectTST_get_or_build(swigCPtr, string, _ObjectFilter.getCPtr(factory));
  }

  public Object put(String string, Object data) {
    return tstJNI._ObjectTST_put(swigCPtr, string, data);
  }

  public void remove(String string) {
    tstJNI._ObjectTST_remove(swigCPtr, string);
  }

  public int get_maximum_key_length() {
    return tstJNI._ObjectTST_get_maximum_key_length(swigCPtr);
  }

  public long bytes_allocated() {
    return tstJNI._ObjectTST_bytes_allocated(swigCPtr);
  }

  public void write(SWIGTYPE_p_FILE file, _ObjectSerializer writer) {
    tstJNI._ObjectTST_write(swigCPtr, SWIGTYPE_p_FILE.getCPtr(file), _ObjectSerializer.getCPtr(writer));
  }

  public void debug_print_root() {
    tstJNI._ObjectTST_debug_print_root(swigCPtr);
  }

  public Object scan(String string, _ObjectAction to_perform) {
    return tstJNI._ObjectTST_scan(swigCPtr, string, _ObjectAction.getCPtr(to_perform));
  }

  public Object scan_with_stop_chars(String string, String stop_chars, _ObjectAction to_perform) {
    return tstJNI._ObjectTST_scan_with_stop_chars(swigCPtr, string, stop_chars, _ObjectAction.getCPtr(to_perform));
  }

}
