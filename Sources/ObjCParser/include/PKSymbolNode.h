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

#import "PKTypes.h"
#import <Foundation/Foundation.h>

/*!
    @class      PKSymbolNode
    @brief      A <tt>PKSymbolNode</tt> object is a member of a tree that contains all possible prefixes of allowable
   symbols.
    @details    A <tt>PKSymbolNode</tt> object is a member of a tree that contains all possible prefixes of allowable
   symbols. Multi-character symbols appear in a <tt>PKSymbolNode</tt> tree with one node for each character. For
   example, the symbol <tt>=:~</tt> will appear in a tree as three nodes. The first node contains an equals sign, and
   has a child; that child contains a colon and has a child; this third child contains a tilde, and has no children of
   its own. If the colon node had another child for a dollar sign character, then the tree would contain the symbol
   <tt>=:$</tt>. A tree of <tt>PKSymbolNode</tt> objects collaborate to read a (potentially multi-character) symbol from
   an input stream. A root node with no character of its own finds an initial node that represents the first character
   in the input. This node looks to see if the next character in the stream matches one of its children. If so, the node
   delegates its reading task to its child. This approach walks down the tree, pulling symbols from the input that match
   the path down the tree. When a node does not have a child that matches the next character, we will have read the
   longest possible symbol prefix. This prefix may or may not be a valid symbol. Consider a tree that has had
   <tt>=:~</tt> added and has not had <tt>=:</tt> added. In this tree, of the three nodes that contain =:~, only the
   first and third contain complete symbols. If, say, the input contains <tt>=:a</tt>, the colon node will not have a
   child that matches the <tt>'a'</tt> and so it will stop reading. The colon node has to "unread": it must push back
   its character, and ask its parent to unread. Unreading continues until it reaches an ancestor that represents a valid
   symbol.
*/
@interface PKSymbolNode : NSObject

/*!
    @brief      Initializes a <tt>PKSymbolNode</tt> with the given parent, representing the given character.
    @param      p the parent of this node
    @param      c the character for this node
    @result     An initialized <tt>PKSymbolNode</tt>
*/
- (instancetype)initWithParent:(PKSymbolNode *)p character:(PKUniChar)c;

/*!
    @property   ancestry
    @brief      The string of the mulit-character symbol this node represents.
*/
@property (nonatomic, readonly, retain) NSString *ancestry;

/*!
    @brief      If YES, -nextSymbol:startingWith: returns only explicitly-added symbols.
                If NO, any symbol is returned.
                Default is NO.
*/
@property (nonatomic, assign) BOOL reportsAddedSymbolsOnly;
@end
