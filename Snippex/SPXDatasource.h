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

/// @abstract Defines the block that will be called whenever the tableView delegate -tableView:cellForRowAtIndexPath: is called
typedef UITableViewCell* (^SPXCellForIndexPathBlock)(UITableView *tableView, id object, NSIndexPath *indexPath);
/// @abstract Defines the block that will be called whenever the tableView delegate -tableView:titleForHeaderInSection: is called
typedef NSString* (^SPXTitleForHeaderInSectionBlock)(UITableView *tableView, NSUInteger section);
/// @abstract Defines the block that will be called whenever the tableView delegate -tableView:titleForFooterInSection: is called
typedef NSString* (^SPXTitleForFooterInSectionBlock)(UITableView *tableView, NSUInteger section);

/**
 Note: This is subject to change
 
 This protocol defines the methods necessary for any subsclass to call
 */
@protocol SPXDatasourceProtocol <NSObject>

@required

/**
 @abstract      The sections for this tableView
 @param         tableView The tableView
 @return        An NSArray of sections for this tableView
 */
-(NSArray *)sectionsForTableView:(UITableView *)tableView;

/**
 @abstract      Returns the associated object at the given indexPath
 @param         indexPath The indexPath of associated cell
 @return        The associated object at the given indexPath, nil if not found
 */
-(id)objectAtIndexPath:(NSIndexPath *)indexPath;

@end

/**
 This is the base datasource class for all other datasources.
 This class SHOULD NOT be implemented directly, instead use one of its provided subsclasses or implement your own.
 */
@interface SPXDatasource : NSObject <UITableViewDataSource, SPXDatasourceProtocol>

/// @abstract   Sets/gets the sort descriptors used for presenting this datasource
@property (nonatomic, copy) NSArray *sortDescriptors;

/**
 @abstract      Sets the minimim row count required, before showing the section index titles
 @param         count The minimum number of required rows
 */
-(void)setSectionIndexMinimumDisplayRowCount:(NSInteger)count;

/**
 @abstract      Specifies the block that will execute when -tableView:cellForRowAtIndexPath: is called
 @param         block The block that will execute, returning a UITableViewCell
 */
-(void)setCellForRowAtIndexPathBlock:(SPXCellForIndexPathBlock)block;

/**
 @abstract      Specifies the block that will execute when -tableView:titleForHeaderInSection: is called
 @param         block The block that will execute, returning an NSString
 */
-(void)setTitleForHeaderInSectionBlock:(SPXTitleForHeaderInSectionBlock)block;

/**
 @abstract      Specifies the block that will execute when -tableView:titleForFooterInSection: is called
 @param         block The block that will execute, returning an NSString
 */
-(void)setTitleForFooterInSectionBlock:(SPXTitleForFooterInSectionBlock)block;

@end
