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

#import "PKDelimitDescriptorCollection.h"
#import "PKDelimitDescriptor.h"

@interface PKDelimitDescriptorCollection ()
@property (nonatomic, retain) NSMutableDictionary *descTab;
@end

@implementation PKDelimitDescriptorCollection

- (instancetype)init {
    self = [super init];
    if (self) {
        self.descTab = [NSMutableDictionary dictionary];
    }
    return self;
}

- (void)dealloc {
    self.descTab = nil;
}

- (void)add:(PKDelimitDescriptor *)desc {
    NSParameterAssert(desc);

    NSString *key = desc.startMarker;
    NSAssert([key length], @"");

    NSMutableSet *existing = _descTab[key];
    if (!existing) {
        existing = [NSMutableSet set];
        _descTab[key] = existing;
    }
    [existing addObject:desc];
}

- (void)remove:(PKDelimitDescriptor *)desc {
    NSParameterAssert(desc);

    NSString *key = desc.startMarker;
    NSAssert([key length], @"");

    NSMutableSet *existing = _descTab[key];
    NSAssert([existing containsObject:desc], @"");
    [existing removeObject:desc];
}

- (NSArray *)descriptorsForStartMarker:(NSString *)startMarker {
    NSParameterAssert(startMarker);
    return [_descTab[startMarker] allObjects];
}

@end
