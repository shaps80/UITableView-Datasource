//
//  SPXMasterViewController.m
//  SPXDatasourceSample
//
//  Created by Shaps Mohsenin on 20/07/2013.
//  Copyright (c) 2013 Snippex. All rights reserved.
//

#import "SPXMasterViewController.h"

@implementation SPXMasterViewController

-(NSArray *)sortDescriptors:(BOOL)ascending
{
    return @[ [NSSortDescriptor sortDescriptorWithKey:@"name" ascending:ascending] ];
}

-(void)configureCellForDataSource:(SPXDatasource *)datasource
{
    id __weak weakSelf = self;

    [datasource setCellForRowAtIndexPathBlock:^
     UITableViewCell *(UITableView *tableView, id object, NSIndexPath *indexPath)
    {
        // we have to use self.tableView here since that's the tableView with its cell identifier's set
        UITableViewCell *cell = [[weakSelf tableView] dequeueReusableCellWithIdentifier:@"Cell"];
        cell.textLabel.text = [object valueForKey:@"name"];
        return cell;
    }];
}

-(void)configureCoreDataSource
{
    // get a new coreData based datasource
    _coreDataSoure = [SPXCoreDataDatasource dataSourceForTableView:self.tableView
                                                           context:_store.synchronousContext
                                                        entityName:@"Person"];

    // configure its sortDescriptors
    [_coreDataSoure setSortDescriptors:[self sortDescriptors:YES]];

    // configure the cells for this datasource
    [self configureCellForDataSource:_coreDataSoure];
    [self.tableView setDataSource:_coreDataSoure];
}

-(void)configureSearchDataSource
{
    // get a new search based datasource
    _searchDataSource = [SPXSearchDatasource dataSourceForSearchDisplayController:self.searchDisplayController];

    // configure its sortDescriptors
    [_searchDataSource setSortDescriptors:[self sortDescriptors:NO]];

    id __weak weakSelf = self;
    [_searchDataSource setSourceWithBlock:^NSArray *
    {
        return [[weakSelf coreDataSoure] source];
    }];

    // configure how the search will be handled
    [_searchDataSource setSearchPredicate:^NSPredicate *(NSString *searchString)
    {
        return [NSPredicate predicateWithFormat:@"SELF.name contains[c] %@", searchString];
    }];

    // configure the cells for this datasource
    [self configureCellForDataSource:_searchDataSource];
    [self.searchDisplayController setSearchResultsDataSource:_searchDataSource];
}

// This is just convenience code to demonstrate adding a new object, you can swipe to delete
-(IBAction)addPerson:(id)sender
{
    id __weak weakSelf = self;
    SPXAlert *alert = [[SPXAlert alloc] initWithTitle:@"New Person" message:@"Enter a unique name for this person" cancelButtonTitle:@"Cancel" otherButtonTitles:@"OK", nil];

    [alert setAlertViewStyle:UIAlertViewStylePlainTextInput];
    [alert showWithCompletion:^(NSInteger buttonIndex)
    {
        if (buttonIndex)
        {
            NSString *name = [[alert textFieldAtIndex:0] text];
            SPXFetchRequest *request = [SPXFetchRequest fetchRequestForStore:[weakSelf store] entityName:@"Person"];
            [request fetchObjectWithIdentifier:name create:YES objectState:nil];
            [[weakSelf store] saveSynchronousContext];
        }
    }];
}

-(void)viewDidLoad
{
    [super viewDidLoad];

    // grab the store for this viewController
    _store = [SPXStoreManager storeWithName:@"Database"];

    [self configureCoreDataSource];
    [self configureSearchDataSource];
}

#pragma mark - UITableViewDelegate

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // we use the datasource to determine the object that was selected, because we don't know if we're currently searching or not

    // grab the current datasource
    SPXDatasource *datasource = (SPXDatasource *)tableView.dataSource;

    // get the object that was selected from the datasource
    NSManagedObject *person = [datasource objectAtIndexPath:indexPath];

    // print the name of the person that was selected
    NSLog(@"%@ was selected", [person valueForKey:@"name"]);
}

@end
