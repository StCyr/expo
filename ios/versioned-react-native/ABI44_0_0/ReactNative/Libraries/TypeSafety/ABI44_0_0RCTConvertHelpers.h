/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <vector>

#import <Foundation/Foundation.h>

#import <ABI44_0_0FBLazyVector/ABI44_0_0FBLazyVector.h>
#import <folly/Optional.h>

namespace ABI44_0_0facebook {
namespace ABI44_0_0React {
  template<typename T>
  using LazyVector = FB::LazyVector<T, id>;
}}

template<typename ContainerT>
NSArray *ABI44_0_0RCTConvertVecToArray(const ContainerT &vec, id (^convertor)(typename ContainerT::value_type element))
{
  NSMutableArray *array = [NSMutableArray new];
  for (size_t i = 0, size = vec.size(); i < size; ++i) {
    id object = convertor(vec[i]);
    array[i] = object ?: (id)kCFNull;
  }
  return array;
}
template<typename ContainerT>
NSArray *ABI44_0_0RCTConvertVecToArray(const ContainerT &vec)
{
  return ABI44_0_0RCTConvertVecToArray(vec, ^id(typename ContainerT::value_type element) { return element; });
}

template<typename ContainerT>
NSArray *ABI44_0_0RCTConvertOptionalVecToArray(const folly::Optional<ContainerT> &vec, id (^convertor)(typename ContainerT::value_type element))
{
  return vec.hasValue() ? ABI44_0_0RCTConvertVecToArray(vec.value(), convertor) : nil;
}

template<typename ContainerT>
NSArray *ABI44_0_0RCTConvertOptionalVecToArray(const folly::Optional<ContainerT> &vec)
{
  return vec.hasValue() ? ABI44_0_0RCTConvertVecToArray(vec.value(), ^id(typename ContainerT::value_type element) { return element; }) : nil;
}

bool ABI44_0_0RCTBridgingToBool(id value);
folly::Optional<bool> ABI44_0_0RCTBridgingToOptionalBool(id value);
NSString *ABI44_0_0RCTBridgingToString(id value);
NSString *ABI44_0_0RCTBridgingToOptionalString(id value);
folly::Optional<double> ABI44_0_0RCTBridgingToOptionalDouble(id value);
double ABI44_0_0RCTBridgingToDouble(id value);
NSArray *ABI44_0_0RCTBridgingToArray(id value);

template<typename T>
ABI44_0_0facebook::ABI44_0_0React::LazyVector<T> ABI44_0_0RCTBridgingToVec(id value, T (^ctor)(id element))
{
  NSArray *array = ABI44_0_0RCTBridgingToArray(value);
  typedef typename ABI44_0_0facebook::ABI44_0_0React::LazyVector<T>::size_type _size_t;
  _size_t size = static_cast<_size_t>(array.count);
  return ABI44_0_0facebook::ABI44_0_0React::LazyVector<T>::fromUnsafeRawValue(array, size, ctor);
}

template<typename T>
folly::Optional<ABI44_0_0facebook::ABI44_0_0React::LazyVector<T>> ABI44_0_0RCTBridgingToOptionalVec(id value, T (^ctor)(id element))
{
  if (value == nil || value == (id)kCFNull) {
    return folly::none;
  } else {
    return ABI44_0_0RCTBridgingToVec(value, ctor);
  }
}
