#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativefactorial_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}




jlong factorial (int n)
{
    jlong result = 1 ;
    if( n >= 0 )
    {
        for(int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result ;
    } else
    {
        return 0 ;
    }
}
/*
extern "C"
JNIEXPORT void JNICALL
Java_com_example_nativefactorial_FactorialUtils_calcFactorial(JNIEnv *env, jobject thiz, jint num) {

    jlong result = factorial(num);

    if(result > 0)
    {
        jclass factorialUtilsClass = env->GetObjectClass(thiz);
        if(factorialUtilsClass != nullptr)
        {
            jmethodID updateGUIMethod = env->GetMethodID(factorialUtilsClass, "updateGUI", "(J)V");
            if(updateGUIMethod != nullptr)
            {
                env->CallVoidMethod(thiz, updateGUIMethod, result);

            }
        }
    }
}*/
extern "C"
JNIEXPORT void JNICALL
Java_com_example_nativefactorial_FactorialUtils_calcFactorial(JNIEnv *env, jclass clazz, jint num) {
    jlong result = factorial(num);

    if(result > 0)
    {
            jmethodID updateGUIMethod = env->GetStaticMethodID(clazz,"updateGUI", "(J)V");
            if(updateGUIMethod != nullptr) {
                env->CallStaticVoidMethod(clazz,updateGUIMethod,result);
            }
    }
}