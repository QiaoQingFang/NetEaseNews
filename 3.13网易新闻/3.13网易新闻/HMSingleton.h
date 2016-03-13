// 头文件使用的宏
// ## 表示拼接前后两个字符串
#define HMSingleton_h(name)  + (instancetype)shared##name;

#if __has_feature(objc_arc) // 是arc环境
    #define HMSingleton_m(name)  + (instancetype)shared##name {\
    return [[self alloc] init];\
    }\
    \
    + (instancetype)allocWithZone:(struct _NSZone *)zone {\
    static dispatch_once_t onceToken;\
    static id instance = nil;\
    dispatch_once(&onceToken, ^{ \
    instance = [super allocWithZone:zone];\
    });\
    return instance;\
    }\
    \
    - (id)copyWithZone:(nullable NSZone *)zone {\
    return self;\
    }
#else // MRC环境
    #define HMSingleton_m(name)  + (instancetype)shared##name {\
    return [[self alloc] init];\
    }\
    \
    + (instancetype)allocWithZone:(struct _NSZone *)zone {\
    static dispatch_once_t onceToken;\
    static id instance = nil;\
    dispatch_once(&onceToken, ^{ \
    instance = [super allocWithZone:zone];\
    });\
    return instance;\
    }\
    \
    - (id)copyWithZone:(nullable NSZone *)zone {\
    return self;\
    }\
    - (oneway void)release {\
    \
    }\
    \
    - (instancetype)autorelease {\
    return self;\
    }\
    \
    - (instancetype)retain {\
    return self;\
    }\
    \
    - (NSUInteger)retainCount {\
    return 1;\
    }
#endif






