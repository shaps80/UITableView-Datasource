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

#import "SPXDatasource.h"

/**
 This class provides an NSArray based datasource for presenting data in a tableView. If takes care of all the UITableView updates and manages the source data.
 */
@interface SPXCollectionDatasource : SPXDatasource

/// @abstract   The predicate to use for filtering the array
@property (nonatomic, strong) NSPredicate *predicate;

/**
 @abstract      Initializes the datasource with the specified tableView and source
 @param         tableView The tableView that will present this data
 @param         source The source data for this tableView
 @param         An SPXCollectionDatasource instance
 */
+(instancetype)datasourceForTableView:(UITableView *)tableView
                               source:(NSArray *)source;

/**
 @abstract      Adds the specified object to the source
 @param         object The object to add
 */
-(void)addObject:(id)object;

/**
 @abstract      Removes the object at the specified index
 @param         index The index of the object to remove
 */
-(void)removeObjectAtIndex:(NSInteger)index;

/**
 @return        Returns the source in its current state, including any changes that may have been performed on it since it was originally added.
 */
-(NSArray *)source;

@end
