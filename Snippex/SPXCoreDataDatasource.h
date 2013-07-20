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
#import <CoreData/CoreData.h>
#import "SPXDatasource.h"

/**
 This class provides a CoreData based datasource. It takes care of NSFetchedResultsController and UITableView updates.
 */
@interface SPXCoreDataDatasource : SPXDatasource <NSFetchedResultsControllerDelegate>

/// @abstract   Gets/sets teh sectionNameKeyPath used by the NSFetchRequest and UITableView
@property (nonatomic, copy) NSString *sectionNameKeyPath;

/// @abstract   Gets/sets the predicate used to filter the tableView source
@property (nonatomic, copy) NSPredicate *predicate;

/**
 @abstract      Initializes the datasource with the specified tableView, context and entityName configured
 @param         tableView The tableView that will present this data
 @param         context The NSManagedObjectContext assocaited with the source objects
 @param         entityName The name of the entity the NSFetchedResultsController will perform requests on using the specified context
 @return        Returns an SPXCoreDataDatasource instance
 */
+(instancetype)dataSourceForTableView:(UITableView *)tableView
                              context:(NSManagedObjectContext *)context
                           entityName:(NSString *)entityName;

/**
 @abstract      Unlike [tableview reloadData] this method resets the NSFetchedResultsController before reloading the tableView.
 */
-(void)reload;

/**
 @return        Returns the source objects in their current state from the NSFetchedResultsController's fetchedObjects method.
 */
-(NSArray *)source;

@end
