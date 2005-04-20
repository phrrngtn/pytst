/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class JavaTST {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected JavaTST(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
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
  }

  public JavaTST(SWIGTYPE_p_FILE file, Serializer reader) {
    this(tstJNI.new_JavaTST__SWIG_0(SWIGTYPE_p_FILE.getCPtr(file), Serializer.getCPtr(reader)), true);
  }

  public JavaTST(int initial_size, String default_value) {
    this(tstJNI.new_JavaTST__SWIG_1(initial_size, default_value), true);
  }

  public void pack() {
    tstJNI.JavaTST_pack(swigCPtr);
  }

  public String walk(Filter filter, Action to_perform) {
    return tstJNI.JavaTST_walk(swigCPtr, Filter.getCPtr(filter), Action.getCPtr(to_perform));
  }

  public String almost(String string, int string_length, int maximum_distance, Filter filter, Action to_perform) {
    return tstJNI.JavaTST_almost(swigCPtr, string, string_length, maximum_distance, Filter.getCPtr(filter), Action.getCPtr(to_perform));
  }

  public String common_prefix(String string, Filter filter, Action to_perform) {
    return tstJNI.JavaTST_common_prefix(swigCPtr, string, Filter.getCPtr(filter), Action.getCPtr(to_perform));
  }

  public String scan(String string, Action to_perform) {
    return tstJNI.JavaTST_scan(swigCPtr, string, Action.getCPtr(to_perform));
  }

  public String scan_with_stop_chars(String string, String stop_chars, Action to_perform) {
    return tstJNI.JavaTST_scan_with_stop_chars(swigCPtr, string, stop_chars, Action.getCPtr(to_perform));
  }

  public String get(String string) {
    return tstJNI.JavaTST_get(swigCPtr, string);
  }

  public String get_or_build(String string, Filter factory) {
    return tstJNI.JavaTST_get_or_build(swigCPtr, string, Filter.getCPtr(factory));
  }

  public String put(String string, String data) {
    return tstJNI.JavaTST_put(swigCPtr, string, data);
  }

  public void remove(String string) {
    tstJNI.JavaTST_remove(swigCPtr, string);
  }

  public int get_maximum_key_length() {
    return tstJNI.JavaTST_get_maximum_key_length(swigCPtr);
  }

  public long bytes_allocated() {
    return tstJNI.JavaTST_bytes_allocated(swigCPtr);
  }

  public void write(SWIGTYPE_p_FILE file, Serializer writer) {
    tstJNI.JavaTST_write(swigCPtr, SWIGTYPE_p_FILE.getCPtr(file), Serializer.getCPtr(writer));
  }

  public void debug_print_root() {
    tstJNI.JavaTST_debug_print_root(swigCPtr);
  }

}
