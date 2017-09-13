//
//  ViewController.m
//  ProtobufDemo
//
//  Created by lijunjie on 13/09/2017.
//  Copyright © 2017 wanduoduo. All rights reserved.
//

#import "ViewController.h"
#import "NNetworkServiceManager.h"
#import "Result.pbobjc.h"
#import "LLoggerUitilsMacrocDefine.h"
#import "CUCFUtils.h"

@interface ViewController ()

@end

@implementation ViewController
- (IBAction)btnAction:(id)sender {
    [[NNetworkServiceManager share] requestGetUrl:@"http://172.16.20.75:8080/pt/call/protobuf/Demo1/list" header:nil parameters:nil successBlock:^(id responseObj, NSDictionary *userInfo) {
        NSError *error = nil;
        WDPBResult *res1 = [[WDPBResult alloc] initWithData:responseObj error:&error];
        if (error) {
            NSLog(@"转换失败！");
        } else {
            NSDictionary *dict = CUCFDictionaryFromJSONString(res1.res);
            NSLog(@"%@", dict);
        }
        NSLog(@"%@",res1.description);
    } failBlock:^(NSError *error, NSDictionary *userInfo) {
        LLog(@"请求接口失败");
    } userInfo:nil];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
