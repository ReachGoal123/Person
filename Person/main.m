//
//  main.m
//  Person
//
//  Created by wanglin on 14-12-16.
//  Copyright (c) 2014年 tarena. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Dog.h"
#import "Preson.h"
int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        Preson *father=[[Preson alloc]init];
        BOOL isclass=[father isKindOfClass:[Preson class] ];
        NSLog(@"%@",isclass?@"YES":@"NO");
        id obj=[NSClassFromString(@"Preson")new];
        isclass=[obj isKindOfClass:[Preson class]];
        NSLog(@"%@",isclass?@"YES":@"NO");
        Class name=[obj class];
        NSLog(@"%@",name);
//        SEL oldSel=@selector(test);
        SEL sel=NSSelectorFromString(@"test");
        //[obj performSelector:sel];
        NSString *string=NSStringFromSelector(sel);
        NSLog(@"string=%@",string);
        
        
        
        
//        NSSet *set = [NSSet set];
//        NSLog(@"count=%lu",set.count);
//        NSSet *set1=[NSSet setWithObjects:@"liangge",@"QQ23244", nil];
//        NSLog(@"count=%lu",set1.count);
//        if ([set1 containsObject:@"liangge"])
//        {
//            NSLog(@"YES");
//            
//        }
//        else
//        {
//            NSLog(@"NO");
//        }
//        for(id obj in set1){
//            NSLog(@"%@",obj);
//        }
//        [set1 enumerateObjectsUsingBlock:^(id obj, BOOL *stop) {
//            NSLog(@"%@",obj);
//        }];
//        NSArray *array =[set1 allObjects];
//        [array enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
//            NSLog(@"%@",obj);
//        }];
//        NSMutableSet *mset =[NSMutableSet setWithCapacity:50];
//        NSLog(@"count = %lu",mset.count);
//        NSMutableSet *new = [NSMutableSet setWithObjects:@"1",@"2",@"3", nil];
//        NSLog(@"count = %lu",new.count);
//        [new addObject:@"7"];
//        [new addObject:@"9"];
//        NSLog(@"count = %lu",new.count);
//         [new enumerateObjectsUsingBlock:^(id obj, BOOL *stop) {
//             NSLog(@"%@",obj);
//         }];
//        NSSet *newset=[NSMutableSet setWithObjects:@"1",@"2",@"3", nil];
//        if ([newset intersectsSet:new ]) {
//            NSLog(@"youjiaoji");
//            
//        }
//        if ([newset isSubsetOfSet:new]) {
//            NSLog(@"shijiji");
//        }
//       
//        
//        
   }
    return 0;
}

/*
 
 tableView
 
 1.简单说明
 
 关于tableView,cell的点击事件是不可避免的。那么在开发中应该如何很好的处理cell的点击事件呢？
 可以在代理方法中对点击了那个cell进行判断，根据行数的不同，做出不同的选择。
 
 垃圾代码如下：
 
 
 2.在多数情况下，点击cell都是跳转到对应的控制器。
 
 YYCommonItem.h文件
 
 
 1 //
 2 //  YYCommonItem.h
 3 //
 4
 5 #import <Foundation/Foundation.h>
 6
 7 @interface YYCommonItem : NSObject
 8 **图标
9 @property(nonatomic,copy)NSString *icon;
10 **标题
11 @property(nonatomic,copy)NSString *title;
12 **子标题
13 @property(nonatomic,copy)NSString *subtitle;
14 **右边显示的提醒数字
15 @property(nonatomic,strong)NSString *badgeValue;
16 //点击这行cell,需要跳转到哪个控制器
17 @property(nonatomic,assign)Class destVcClass;
18
19 +(instancetype)itemWithTitle:(NSString *)title icon:(NSString *)icon;
20 +(instancetype)itemWithTitle:(NSString *)title;
21 @end

YYDiscoverViewController.m中处理cell的点击事件的代码


1 //
2 //  YYDiscoverViewController.m
3 //
4
5 #import "YYDiscoverViewController.h"
6 #import "YYSearchBar.h"
7 #import "YYCommonGroup.h"
8 #import "YYCommonItem.h"
9 #import "YYCommonCell.h"
10 #import "YYCommonArrowItem.h"
11 #import "YYCommonSwitchItem.h"
12 #import "YYCommonLabelItem.h"
13 #import "YYOneViewController.h"
14 #import "YYTwoViewController.h"
15
16 **
    17  用一个模型来描述每组的信息：组头、组尾、这组的所有行模型
    18  用一个模型来描述每行的信息：图标、标题、子标题、右边的样式（箭头、文字、数字、开关、打钩）
    19
20
21 @interface YYDiscoverViewController ()
22 @property(nonatomic,strong)NSMutableArray *groups;
23 @end
24
25 @implementation YYDiscoverViewController
26
27 #pragma mark-懒加载
28 -(NSMutableArray *)groups
29 {
    30     if (_groups==nil) {
        31         _groups=[NSMutableArray array];
        32     }
    33     return _groups;
    34 }
35
36 **屏蔽tableView的样式设置
37 -(id)init
38 {
    39     //分组模式
    40     return [self initWithStyle:UITableViewStyleGrouped];
    41 }
42 - (void)viewDidLoad
43 {
    44     [super viewDidLoad];
    45
    46     //创建并添加一个搜索框
    47     //添加一个搜索框
    48     YYSearchBar *searchBar=[YYSearchBar SearchBar];
    49     searchBar.frame=CGRectMake(0, 100, 300, 35);
    50     self.navigationItem.titleView=searchBar;
    51
    52     //设置tableview的属性
    53     //设置全局背景色
    54     self.tableView.backgroundColor=YYGlobalBg;
    55     self.tableView.sectionFooterHeight=0;
    56     self.tableView.sectionHeaderHeight=YYStatusCellMargin;
    57     self.tableView.separatorStyle=UITableViewCellSeparatorStyleNone;
    58     //不显示水平滚动条
    59     self.tableView.showsVerticalScrollIndicator=NO;
    60
    61
    62     // 初始化模型数据
    63     [self setupGroups];
    64
    65     YYLog(@"viewDidLoad---%@",NSStringFromUIEdgeInsets(self.tableView.contentInset));
    66     self.tableView.contentInset=UIEdgeInsetsMake(YYStatusCellMargin-35, 0, 0, 0);
    67 }
68
69 -(void)setupGroups
70 {
    71     //第0组
    72     [self setupGroup0];
    73     //第1组
    74     [self setupGroup1];
    75     //第2组
    76     [self setupGroup2];
    77 }
78
79 -(void)setupGroup0
80 {
    81     //1.创建组
    82     YYCommonGroup *group=[YYCommonGroup group];
    83     [self.groups addObject:group];
    84
    85     //2.设置组的基本数据
    86     group.groupheader=@"第0组";
    87     group.grougfooter=@"第0组的尾部";
    88
    89     //3.设置组中所有行的数据
    90     YYCommonArrowItem *hotStatus=[YYCommonArrowItem itemWithTitle:@"热门微博" icon:@"hot_status"];
    91     hotStatus.subtitle=@"笑话、娱乐、神最右都在这儿！";
    92     hotStatus.badgeValue=@"10";
    93
    94     YYCommonArrowItem *findPeople=[YYCommonArrowItem itemWithTitle:@"找人" icon:@"find_people"];
    95     findPeople.subtitle=@"名人，有意思的人尽在这里！";
    96
    97     group.items=@[hotStatus,findPeople];
    98 }
99
100 -(void)setupGroup1
101 {
    102     //1.创建组
    103     YYCommonGroup *group=[YYCommonGroup group];
    104     [self.groups addObject:group];
    105
    106     //2.设置组的基本数据
    107
    108     //3.设置组中所有行的数据
    109     YYCommonSwitchItem *gamecenter=[YYCommonSwitchItem itemWithTitle:@"游戏中心" icon:@"game_center"];
    110     YYCommonSwitchItem *near=[YYCommonSwitchItem itemWithTitle:@"周边" icon:@"near"];
    111
    112     group.items=@[gamecenter,near];
    113
    114 }
115
116 -(void)setupGroup2
117 {
    118     //1.创建组
    119     YYCommonGroup *group=[YYCommonGroup group];
    120     [self.groups addObject:group];
    121
    122     //2.设置组的基本数据
    123
    124     //3.设置组中所有行的数据
    125     YYCommonLabelItem *video=[YYCommonLabelItem itemWithTitle:@"视频" icon:@"video"];
    126     video.text=@"视频的右边显示文字";
    127     YYCommonItem *music=[YYCommonItem itemWithTitle:@"音乐" icon:@"music"];
    128     music.badgeValue=@"1231";
    129     YYCommonItem *movie=[YYCommonItem itemWithTitle:@"电影" icon:@"movie"];
    130     movie.destVcClass=[YYOneViewController class];
    131     YYCommonItem *cast=[YYCommonItem itemWithTitle:@"播客" icon:@"cast"];
    132     cast.destVcClass=[YYTwoViewController class];
    133     YYCommonItem *more=[YYCommonItem itemWithTitle:@"更多" icon:@"more"];
    134
    135     group.items=@[video,music,movie,cast,more];
    136 }
137
138
139 #pragma mark-tableView的代理
140 -(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
141 {
    142     return self.groups.count;
    143 }
144
145 -(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
146 {
    147     YYCommonGroup *group=self.groups[section];
    148     return group.items.count;
    149 }
150
151 -(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
152 {
    153     //1.获取cell
    154     YYCommonCell *cell=[YYCommonCell cellWithTablView:tableView];
    155     //2.设置cell的显示数据
    156     YYCommonGroup *group=self.groups[indexPath.section];
    157     YYCommonItem *item=group.items[indexPath.row];
    158     cell.item=item;
    159     [cell setindexPath:indexPath rowsInSection:group.items.count];
    160     //3.返回cell
    161     return cell;
    162 }
163
164 #pragma mark-点击cell的代理方法
165 -(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
166 {
    167     //1.取出这行对应的item模型
    168     YYCommonGroup *group=self.groups[indexPath.section];
    169     YYCommonItem *item=group.items[indexPath.row];
    170
    171     //2.判断有无需要跳转的控制器
    172     if (item.destVcClass) {
        173         UIViewController *desrVc=[[item.destVcClass alloc]init];
        174         desrVc.title=item.title;
        175         [self.navigationController pushViewController:desrVc animated:YES];
        176     }
    177 }
178 @end

实现效果(点击电影cell，跳转到one控制器界面，点击播客cell跳转到two控制器界面)：



3.还有一种情况，就是点击了cell之后是执行一段代码（并不一定是跳转，可能是弹出一个框等）

对于这种情况，可以使用block代码段来实现。

示例代码：


1 #import <Foundation/Foundation.h>
2
3 @interface YYCommonItem : NSObject
4 **图标
5 @property(nonatomic,copy)NSString *icon;
6 **标题
7 @property(nonatomic,copy)NSString *title;
8 **子标题
9 @property(nonatomic,copy)NSString *subtitle;
10 **右边显示的提醒数字
11 @property(nonatomic,strong)NSString *badgeValue;
12 //点击这行cell,需要跳转到哪个控制器
13 @property(nonatomic,assign)Class destVcClass;
14 **封装点击这行cell想做的事情
15 **注意：block一定要使用copy
16 @property(nonatomic,copy) void (^operation)();
17
18 +(instancetype)itemWithTitle:(NSString *)title icon:(NSString *)icon;
19 +(instancetype)itemWithTitle:(NSString *)title;
20 @end

设置点击找人这个cell执行的代码段（打印找人）：



在cell的点击事件代理方法中进行处理：


1 #pragma mark-点击cell的代理方法
2 -(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
3 {
    4     //1.取出这行对应的item模型
    5     YYCommonGroup *group=self.groups[indexPath.section];
    6     YYCommonItem *item=group.items[indexPath.row];
    7     
    8     //2.判断有无需要跳转的控制器
    9     if (item.destVcClass) {
        10         UIViewController *desrVc=[[item.destVcClass alloc]init];
        11         desrVc.title=item.title;
        12         [self.navigationController pushViewController:desrVc animated:YES];
        13     }
    14     
    15     //3.判断有无需要执行的代码段
    16     if (item.operation) {
        17         item.operation();
        18     }
    19 }
 
*/
