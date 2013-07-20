//
//  SPXAppDelegate.m
//  SPXDatasourceSample
//
//  Created by Shaps Mohsenin on 20/07/2013.
//  Copyright (c) 2013 Snippex. All rights reserved.
//

#import "SPXAppDelegate.h"
#import "SPXStoreManager.h"

@implementation SPXAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // load the model into a database
    SPXCoreDataStore *store = [SPXCoreDataStore storeWithDatabaseName:@"Database" modelName:@"Model"];

    // specify (if not 'identifier') the identifier key to use for an entity
    [store setIdentifierKey:@"name" forEntityName:@"Person"];

    // add the store to the manager
    [SPXStoreManager addStore:store withName:@"Database"];

    return YES;
}

@end
