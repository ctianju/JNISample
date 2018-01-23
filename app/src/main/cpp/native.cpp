#include <jni.h>
#include <string>

extern "C"
{
JNIEXPORT jstring

JNICALL
Java_com_example_ctianju_jnisample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring JNICALL
Java_com_example_ctianju_jnisample_MainActivity_stringFromJNI1(JNIEnv *env, jobject /* this */) {

    // TODO
    std::string hello = "Hello from C++ too";
    return env->NewStringUTF(hello.c_str());

}
}