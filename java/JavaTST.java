/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class JavaTST extends _JavaTST {
  private long swigCPtr;

  protected JavaTST(long cPtr, boolean cMemoryOwn) {
    super(tstJNI.SWIGJavaTSTUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(JavaTST obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected JavaTST() {
    this(0, false);
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      tstJNI.delete_JavaTST(swigCPtr);
    }
    swigCPtr = 0;
    super.delete();
  }

  public JavaTST(Object data) {
    this(tstJNI.new_JavaTST(data), true);
  }

}
