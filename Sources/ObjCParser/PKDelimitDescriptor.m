// The MIT License (MIT)
//
// Copyright (c) 2014 Todd Ditchendorf
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "PKDelimitDescriptor.h"

@implementation PKDelimitDescriptor

+ (PKDelimitDescriptor *)descriptorWithStartMarker:(NSString *)start
                                         endMarker:(NSString *)end
                                      characterSet:(NSCharacterSet *)cs {
    PKDelimitDescriptor *desc = [[[self class] alloc] init];
    desc.startMarker = start;
    desc.endMarker = end;
    desc.characterSet = cs;
    return desc;
}

- (void)dealloc {
    self.startMarker = nil;
    self.endMarker = nil;
    self.characterSet = nil;
}

- (id)copyWithZone:(NSZone *)zone {
    PKDelimitDescriptor *desc = [[PKDelimitDescriptor alloc] init];
    desc->_startMarker = _startMarker;
    desc->_endMarker = _endMarker;
    desc->_characterSet = _characterSet;
    return desc;
}

- (BOOL)isEqual:(id)obj {
    if (![obj isMemberOfClass:[self class]]) {
        return NO;
    }

    PKDelimitDescriptor *desc = (PKDelimitDescriptor *)obj;

    if (![_startMarker isEqualToString:desc->_startMarker]) {
        return NO;
    }

    if (![_endMarker isEqualToString:desc->_endMarker]) {
        return NO;
    }

    if (![_characterSet isEqual:desc->_characterSet]) {
        return NO;
    }

    return YES;
}

- (NSString *)description {
    return [NSString
        stringWithFormat:@"<%@ %p %%{'%@', %@, '%@'}>", [self class], self, _startMarker, _characterSet, _endMarker];
}

@end
