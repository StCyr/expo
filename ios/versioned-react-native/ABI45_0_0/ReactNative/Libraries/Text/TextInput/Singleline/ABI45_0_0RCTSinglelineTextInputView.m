/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI45_0_0React/ABI45_0_0RCTSinglelineTextInputView.h>

#import <ABI45_0_0React/ABI45_0_0RCTBridge.h>

#import <ABI45_0_0React/ABI45_0_0RCTUITextField.h>

@implementation ABI45_0_0RCTSinglelineTextInputView
{
  ABI45_0_0RCTUITextField *_backedTextInputView;
}

- (instancetype)initWithBridge:(ABI45_0_0RCTBridge *)bridge
{
  if (self = [super initWithBridge:bridge]) {
    // `blurOnSubmit` defaults to `true` for <TextInput multiline={false}> by design.
    self.blurOnSubmit = YES;

    _backedTextInputView = [[ABI45_0_0RCTUITextField alloc] initWithFrame:self.bounds];
    _backedTextInputView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    _backedTextInputView.textInputDelegate = self;

    [self addSubview:_backedTextInputView];
  }

  return self;
}

- (id<ABI45_0_0RCTBackedTextInputViewProtocol>)backedTextInputView
{
  return _backedTextInputView;
}

@end
