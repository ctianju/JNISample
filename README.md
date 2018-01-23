# JNISample
生成好so文件之后，就可以拿出来使用了


但是注意包名
因为生成的c语言函数名字是native函数的全名，如果找不到函数的，就是包名不对，所以生成so为文件的时候最好单独的弄一个library去生成，然后包名统一，到时候就好使用了，使用一定是通过声明native的方法然后调用的，如下：
sourceSets {
    main {
        jniLibs.srcDirs = ['src/main/jniLibs']
    }
}

 // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI1());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String stringFromJNI1();
