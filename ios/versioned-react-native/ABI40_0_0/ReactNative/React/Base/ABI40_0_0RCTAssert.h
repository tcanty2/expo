/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <ABI40_0_0React/ABI40_0_0RCTDefines.h>

/*
 * Defined in ABI40_0_0RCTUtils.m
 */
ABI40_0_0RCT_EXTERN BOOL ABI40_0_0RCTIsMainQueue(void);

/**
 * This is the main assert macro that you should use. Asserts should be compiled out
 * in production builds. You can customize the assert behaviour by setting a custom
 * assert handler through `ABI40_0_0RCTSetAssertFunction`.
 */
#ifndef NS_BLOCK_ASSERTIONS
#define ABI40_0_0RCTAssert(condition, ...)                                                                      \
  do {                                                                                                 \
    if ((condition) == 0) {                                                                            \
      _ABI40_0_0RCTAssertFormat(#condition, __FILE__, __LINE__, __func__, __VA_ARGS__);                         \
      if (ABI40_0_0RCT_NSASSERT) {                                                                              \
        [[NSAssertionHandler currentHandler] handleFailureInFunction:(NSString * _Nonnull) @(__func__) \
                                                                file:(NSString * _Nonnull) @(__FILE__) \
                                                          lineNumber:__LINE__                          \
                                                         description:__VA_ARGS__];                     \
      }                                                                                                \
    }                                                                                                  \
  } while (false)
#else
#define ABI40_0_0RCTAssert(condition, ...) \
  do {                            \
  } while (false)
#endif
ABI40_0_0RCT_EXTERN void _ABI40_0_0RCTAssertFormat(const char *, const char *, int, const char *, NSString *, ...)
    NS_FORMAT_FUNCTION(5, 6);

/**
 * Report a fatal condition when executing. These calls will _NOT_ be compiled out
 * in production, and crash the app by default. You can customize the fatal behaviour
 * by setting a custom fatal handler through `ABI40_0_0RCTSetFatalHandler` and
 * `ABI40_0_0RCTSetFatalExceptionHandler`.
 */
ABI40_0_0RCT_EXTERN void ABI40_0_0RCTFatal(NSError *error);
ABI40_0_0RCT_EXTERN void ABI40_0_0RCTFatalException(NSException *exception);

/**
 * The default error domain to be used for ABI40_0_0React errors.
 */
ABI40_0_0RCT_EXTERN NSString *const ABI40_0_0RCTErrorDomain;

/**
 * JS Stack trace provided as part of an NSError's userInfo
 */
ABI40_0_0RCT_EXTERN NSString *const ABI40_0_0RCTJSStackTraceKey;

/**
 * Raw JS Stack trace string provided as part of an NSError's userInfo
 */
ABI40_0_0RCT_EXTERN NSString *const ABI40_0_0RCTJSRawStackTraceKey;

/**
 * Name of fatal exceptions generated by ABI40_0_0RCTFatal
 */
ABI40_0_0RCT_EXTERN NSString *const ABI40_0_0RCTFatalExceptionName;

/**
 * A block signature to be used for custom assertion handling.
 */
typedef void (^ABI40_0_0RCTAssertFunction)(
    NSString *condition,
    NSString *fileName,
    NSNumber *lineNumber,
    NSString *function,
    NSString *message);

typedef void (^ABI40_0_0RCTFatalHandler)(NSError *error);
typedef void (^ABI40_0_0RCTFatalExceptionHandler)(NSException *exception);

/**
 * Convenience macro for asserting that a parameter is non-nil/non-zero.
 */
#define ABI40_0_0RCTAssertParam(name) ABI40_0_0RCTAssert(name, @"'%s' is a required parameter", #name)

/**
 * Convenience macro for asserting that we're running on main queue.
 */
#define ABI40_0_0RCTAssertMainQueue() ABI40_0_0RCTAssert(ABI40_0_0RCTIsMainQueue(), @"This function must be called on the main queue")

/**
 * Convenience macro for asserting that we're running off the main queue.
 */
#define ABI40_0_0RCTAssertNotMainQueue() ABI40_0_0RCTAssert(!ABI40_0_0RCTIsMainQueue(), @"This function must not be called on the main queue")

/**
 * These methods get and set the current assert function called by the ABI40_0_0RCTAssert
 * macros. You can use these to replace the standard behavior with custom assert
 * functionality.
 */
ABI40_0_0RCT_EXTERN void ABI40_0_0RCTSetAssertFunction(ABI40_0_0RCTAssertFunction assertFunction);
ABI40_0_0RCT_EXTERN ABI40_0_0RCTAssertFunction ABI40_0_0RCTGetAssertFunction(void);

/**
 * This appends additional code to the existing assert function, without
 * replacing the existing functionality. Useful if you just want to forward
 * assert info to an extra service without changing the default behavior.
 */
ABI40_0_0RCT_EXTERN void ABI40_0_0RCTAddAssertFunction(ABI40_0_0RCTAssertFunction assertFunction);

/**
 * This method temporarily overrides the assert function while performing the
 * specified block. This is useful for testing purposes (to detect if a given
 * function asserts something) or to suppress or override assertions temporarily.
 */
ABI40_0_0RCT_EXTERN void ABI40_0_0RCTPerformBlockWithAssertFunction(void (^block)(void), ABI40_0_0RCTAssertFunction assertFunction);

/**
 * These methods get and set the current fatal handler called by the `ABI40_0_0RCTFatal`
 * and `ABI40_0_0RCTFatalException` methods.
 */
ABI40_0_0RCT_EXTERN void ABI40_0_0RCTSetFatalHandler(ABI40_0_0RCTFatalHandler fatalHandler);
ABI40_0_0RCT_EXTERN ABI40_0_0RCTFatalHandler ABI40_0_0RCTGetFatalHandler(void);
ABI40_0_0RCT_EXTERN void ABI40_0_0RCTSetFatalExceptionHandler(ABI40_0_0RCTFatalExceptionHandler fatalExceptionHandler);
ABI40_0_0RCT_EXTERN ABI40_0_0RCTFatalExceptionHandler ABI40_0_0RCTGetFatalExceptionHandler(void);

/**
 * Get the current thread's name (or the current queue, if in debug mode)
 */
ABI40_0_0RCT_EXTERN NSString *ABI40_0_0RCTCurrentThreadName(void);

/**
 * Helper to get generate exception message from NSError
 */
ABI40_0_0RCT_EXTERN NSString *
ABI40_0_0RCTFormatError(NSString *message, NSArray<NSDictionary<NSString *, id> *> *stacktrace, NSUInteger maxMessageLength);

/**
 * Formats a JS stack trace for logging.
 */
ABI40_0_0RCT_EXTERN NSString *ABI40_0_0RCTFormatStackTrace(NSArray<NSDictionary<NSString *, id> *> *stackTrace);

/**
 * Convenience macro to assert which thread is currently running (DEBUG mode only)
 */
#if DEBUG

#define ABI40_0_0RCTAssertThread(thread, format...)                                                                          \
  _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") ABI40_0_0RCTAssert(     \
      [(id)thread isKindOfClass:[NSString class]]                                                                   \
          ? [ABI40_0_0RCTCurrentThreadName() isEqualToString:(NSString *)thread]                                             \
          : [(id)thread isKindOfClass:[NSThread class]] ? [NSThread currentThread] == (NSThread *)thread            \
                                                        : dispatch_get_current_queue() == (dispatch_queue_t)thread, \
      format);                                                                                                      \
  _Pragma("clang diagnostic pop")

#else

#define ABI40_0_0RCTAssertThread(thread, format...) \
  do {                                     \
  } while (0)

#endif
