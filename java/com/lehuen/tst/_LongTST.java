/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.lehuen.tst;

public class _LongTST {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected _LongTST(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(_LongTST obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected _LongTST() {
    this(0, false);
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      tstJNI.delete__LongTST(swigCPtr);
    }
    swigCPtr = 0;
  }

  public _LongTST(_LongMemoryStorage storage, SWIGTYPE_p_FILE file, _LongSerializer reader) {
    this(tstJNI.new__LongTST__SWIG_0(_LongMemoryStorage.getCPtr(storage), SWIGTYPE_p_FILE.getCPtr(file), _LongSerializer.getCPtr(reader)), true);
  }

  public _LongTST(_LongMemoryStorage storage, long default_value) {
    this(tstJNI.new__LongTST__SWIG_1(_LongMemoryStorage.getCPtr(storage), default_value), true);
  }

  public void pack() {
    tstJNI._LongTST_pack(swigCPtr);
  }

  public long walk(_LongFilter filter, _LongAction to_perform) {
    return tstJNI._LongTST_walk(swigCPtr, _LongFilter.getCPtr(filter), _LongAction.getCPtr(to_perform));
  }

  public long almost(String string, int maximum_distance, _LongFilter filter, _LongAction to_perform) {
    return tstJNI._LongTST_almost(swigCPtr, string, maximum_distance, _LongFilter.getCPtr(filter), _LongAction.getCPtr(to_perform));
  }

  public long common_prefix(String string, _LongFilter filter, _LongAction to_perform) {
    return tstJNI._LongTST_common_prefix(swigCPtr, string, _LongFilter.getCPtr(filter), _LongAction.getCPtr(to_perform));
  }

  public long get(String string) {
    return tstJNI._LongTST_get(swigCPtr, string);
  }

  public long get_or_build(String string, _LongFilter factory) {
    return tstJNI._LongTST_get_or_build(swigCPtr, string, _LongFilter.getCPtr(factory));
  }

  public long put(String string, long data) {
    return tstJNI._LongTST_put(swigCPtr, string, data);
  }

  public void remove(String string) {
    tstJNI._LongTST_remove(swigCPtr, string);
  }

  public int get_maximum_key_length() {
    return tstJNI._LongTST_get_maximum_key_length(swigCPtr);
  }

  public void write(SWIGTYPE_p_FILE file, _LongSerializer writer) {
    tstJNI._LongTST_write(swigCPtr, SWIGTYPE_p_FILE.getCPtr(file), _LongSerializer.getCPtr(writer));
  }

}
