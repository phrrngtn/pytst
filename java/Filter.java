/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class Filter extends _Filter {
  private long swigCPtr;

  protected Filter(long cPtr, boolean cMemoryOwn) {
    super(tstJNI.SWIGFilterUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Filter obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      tstJNI.delete_Filter(swigCPtr);
    }
    swigCPtr = 0;
    super.delete();
  }

  public Object perform(String key, int remaining_distance, Object data) {
    return tstJNI.Filter_perform(swigCPtr, key, remaining_distance, data);
  }

  public Filter() {
    this(tstJNI.new_Filter(), true);
  }

}
