/*
   Copyright (c) 2013 Snippex. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY Snippex `AS IS' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL Snippex OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "SPXDatasource.h"

/// @abstract   Defines the block that will execute when a the searchResultsTableView is presented, returning the current source data as an Array
typedef NSArray* (^SPXSearchSourceBlock)(void);
/// @abstract   Defines the block that will execute when the search string changes, returning an NSPredicate that makes uses of the searchString
typedef NSPredicate* (^SPXSearchPredicateBlock)(NSString *searchString);

/**
 This class provides a searchDisplayController's datasource. It handles the delegates for UISearchDisplayDelegate, the source and results data, as well as the searchResultsTableView.
 */
@interface SPXSearchDatasource : SPXDatasource <UISearchDisplayDelegate>

/**
 @abstract      Initializes the datasource with the specified searchDisplayController
 @param         controller The searchDisplayController that is responsible for user input and presenting results
 @return        An SPXSearchDatasource instance.
 */
+(instancetype)dataSourceForSearchDisplayController:(UISearchDisplayController *)controller;

/**
 @abstract      Sets the block that will execute when the searchTableView is loaded
 @param         block The block that will execute, returning the current source as an array
 */
-(void)setSourceWithBlock:(SPXSearchSourceBlock)block;

/**
 @abstract      Sets the block that will execute when the searchString is modified
 @param         block The block that will execute, returning an NSPredicate using the searchString
 */
-(void)setSearchPredicate:(SPXSearchPredicateBlock)block;

@end
