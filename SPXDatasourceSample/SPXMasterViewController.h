//
//  SPXMasterViewController.h
//  SPXDatasourceSample
//
//  Created by Shaps Mohsenin on 20/07/2013.
//  Copyright (c) 2013 Snippex. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Snippex.h"

@interface SPXMasterViewController : UITableViewController

@property (nonatomic, weak) SPXCoreDataStore *store;
@property (nonatomic, strong) SPXCoreDataDatasource *coreDataSoure;
@property (nonatomic, strong) SPXSearchDatasource *searchDataSource;

- (IBAction)addPerson:(id)sender;

@end
