/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.lehuen.tst;

public class LongTST extends _LongTST {
  private long swigCPtr;

  protected LongTST(long cPtr, boolean cMemoryOwn) {
    super(tstJNI.SWIGLongTSTUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(LongTST obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected LongTST() {
    this(0, false);
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      tstJNI.delete_LongTST(swigCPtr);
    }
    swigCPtr = 0;
    super.delete();
  }

  public LongTST(int initial_size, long data) {
    this(tstJNI.new_LongTST(initial_size, data), true);
  }

}
