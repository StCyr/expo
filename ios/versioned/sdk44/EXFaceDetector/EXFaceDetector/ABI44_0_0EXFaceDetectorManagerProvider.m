// Copyright 2018-present 650 Industries. All rights reserved.

#import <ABI44_0_0EXFaceDetector/ABI44_0_0EXFaceDetectorManagerProvider.h>
#import <ABI44_0_0EXFaceDetector/ABI44_0_0EXFaceDetectorManager.h>
#import <ABI44_0_0ExpoModulesCore/ABI44_0_0EXFaceDetectorManagerProviderInterface.h>
#import <ABI44_0_0ExpoModulesCore/ABI44_0_0EXDefines.h>

@implementation ABI44_0_0EXFaceDetectorManagerProvider

ABI44_0_0EX_REGISTER_MODULE();

+ (const NSArray<Protocol *> *)exportedInterfaces {
  return @[@protocol(ABI44_0_0EXFaceDetectorManagerProviderInterface)];
}

- (id<ABI44_0_0EXFaceDetectorManagerInterface>)createFaceDetectorManager {
  return [[ABI44_0_0EXFaceDetectorManager alloc] init];
}

@end
