//
//  Dog.m
//  Person
//
//  Created by wanglin on 14-12-16.
//  Copyright (c) 2014年 tarena. All rights reserved.
//

#import "Dog.h"

@implementation Dog
/*
 面试++
 1、堆和栈什么区别？
 
 答：管理方式：对于栈来讲，是由编译器自动管理，无需我们手工控制；对于堆来说，释放工作由程序员控制，容易产生memory leak。
 
 
 2、数组和链表什么区别？
 
 答：数组是将元素在内存中连续存放，由于每个元素占用内存相同，可以通过下标迅速访问数组中任何元素。
 
 链表恰好相反，链表中的元素在内存中不是顺序存储的，而是通过存在元素中的指针联系到一起。
 
 3、delegate和notification什么区别，什么情况使用？
 
 答：Delegate:
 消息的发送者(sender)告知接收者(receiver)某个事件将要发生，delegate同意然然后发送者响应事件，
 
 delegate机制使得接收者可以改变发送者的行为。
 
 通常发送者和接收者的关系是直接的一对多的关系。
 
 Notification:
 消息的发送者告知接收者事件已经发生或者将要发送，仅此而已，接收者并不能反过来影响发送者的行为。
 
 通常发送者和接收者的关系是间接的多对多关系。
 
 
 
 4、什么是MVC，为什么使用MVC，有什么好处？
 
 答： 分别为： 模型(Model),视图(View)和控制Controller)。
 
 模型（Model） “数据模型”（Model）用于封装与应用程序的业务逻辑相关的数据以及对数据的处理方法。
 
 “模型”有对数据直接访问的权力，例如对数据库的访问。
 
 视图（View） 视图层能够实现数据有目的显示。
 
 控制器（Controller） 控制器起到不同层面间的组织作用，用于控制应用程序的流程。
 
 
 5、从一个数组中找出重复的元素打印出来
 
 
 
 NSArray *arr = [NSArrayarrayWithObjects:@"1",@"2",@"1",@"7",@"4",@"5",@"2",@"6",@"5",nil];
 
 NSMutableArray *arrmu = [[NSMutableArrayalloc]init];//过滤
 
 NSMutableArray *sameArray = [[NSMutableArrayalloc]init];//找出相同的
 
 for (int i = 0 ; i < [arrcount]; i++) {
 
 
 
 id str = [arr objectAtIndex:i];
 
 if ([arrmu count] == 0)
 
 {
 
 [arrmuaddObject:str];
 
 }
 
 else{
 
 BOOL flag = NO;
 
 for (int j = 0; j < [arrmucount]; j++ ) {
 
 if ([strisEqual:[arrmu objectAtIndex:j]])
 
 {
 
 [sameArrayaddObject:str];
 
 flag =YES;
 
 break;
 
 }
 
 else{
 
 flag =NO;
 
 }
 
 }
 
 if (flag == NO) {
 
 
 
 [ arrmuaddObject:str];
 
 }
 
 }
 
 }
 
 
 
 NSLog(@"sameArray : %@",sameArray);
 
 还有两种直接找出的方法，上代码：
 
 一：
 
 NSArray *arr = [NSArrayarrayWithObjects:@"1",@"2",@"1",nil];
 
 NSSet *set = [NSSetsetWithArray:arr];
 
 NSLog(@"%@",[setallObjects]);
 
 二：
 
 NSArray *arr =@[@1,@2,@1];
 
 NSMutableDictionary *dict = [NSMutableDictionarydictionary];
 
 for (NSNumber *numberin arr) {
 
 [dictsetObject:numberforKey:number];
 
 }
 
 NSLog(@"%@",[dictallValues]);
 
 
 
 
 
 6、UITableView能否绑定多个数据源？
 
 答：不能
 
 7、一个UIViewController能否管理多个UITableView ?
 
 答：可以
 
 8、ios4、5、6相对于之前的版本添加了哪些新特性？
 这个就比较多了，比如：抛弃谷歌地图 新推Maps应用 ，大幅加强中国本地化支持，Siri开口讲普通话，通过iCloud体验分享乐趣，Passbook电子票券管理，随时随地的FaceTime，电话功能增强，Safari支持全屏浏览，Mail应用新增VIP，万能辅助：更强大等等了
 
 
 
 
 
 9、同步请求和异步请求什么区别？
 
 
 
 答：发送同步请求，程序将停止用户交互，直至服务器返回数据完成，才可以进行下一步操作，
 
 异步请求不会阻塞主线程，而会建立一个新的线程来操作，用户发出异步请求后，依然可以对UI进行操作，程序可以继续运行。
 
 
 10、iOS中的多线程操作、多线程方式
 
 答：iOS提供了方便的多线程调用机制:NSOperation和NSOperationQueue。它的使用方法也很简单，
 
 一般都是将NSOperation对象加入到NSOperationQueue队列中，加入后队列就开始处理，知道任务操作完成。
 
 11、UIViewController的生命周期
 
 答：当一个视图控制器被创建，并在屏幕上显示的时候。 代码的执行顺序
 // 视图显示在屏幕上的顺序
 
 1、 alloc                    创建对象，分配空间。
 
 2、init (initWithNibName)    初始化对象,初始化数据。
 
 3、loadView                   从nib载入视图, 这一步不需要去干涉。除非没有使用xib文件创建视图。
 
 4、viewDidLoad                加载完毕，可以进行自定义数据以及动态创建其他控件。
 
 5、viewWillAppear             视图将出现在屏幕之前，马上这个视图即将显示在屏幕上。
 
 6、viewDidAppear              视图已在屏幕上渲染完成。
 
 // 视图将被从屏幕上移除的顺序
 
 1、viewWillDisappear          视图将被从屏幕上移除之前执行。
 
 2、viewDidDisappear           视图已经被从屏幕上移除。
 
 3、dealloc                    视图被销毁，此时需要在init和viewDidLoad中创建的对象进行释放。
 
 4、viewDidUnload              出现内存警告在内存不足时执行，并对所有非当前显示的controller执行。
 
 
 
 本视图的所有子视图将被销毁，以释放内存,此时开发者需要手动对viewLoad、viewDidLoad中创建的对象释放内存。
 
 因为当这个视图再次显示在屏幕上的时候，viewLoad、viewDidLoad 再次被调用，以便再次构造视图。
 
 
 
 12、Autorerelease对象什么时候释放？
 
 答：autorelease实际上只是把对release的调用延迟了，对于每一个Autorelease，系统只是把该Object放入了当前的Autorelease pool中，当该pool被释放时，该pool中的所有Object会被调用Release。
 
 
 13、iOS数据持久化方式
 
 答：四种：属性列表、对象归档、SQLite3和Core Data
 
 
 
 14、Object－c的类可以多重继承么？可以实现多个接口么？Category是什么？重写一个类的方式用继承好还是分类好？为什么？
 
 答：Object-c的类不可以多重继承；可以实现多个接口，通过实现多个接口可以完成C++的多重继承；Category是类别，一般情况用分类好，用Category去重写类的方法，仅对本Category有效，不会影响到其他类与原有类的关系。
 
 
 
 15. #import 跟#include 又什么区别，@class呢, ＃import<> 跟 #import”"又什么区别？
 
 答：#import是Objective-C导入头文件的关键字，#include是C/C++导入头文件的关键字,使 用#import头文件会自动只导入一次，不会重复导入，相当于#include和#pragma once；@class告诉编译器某个类的声明，当执行时，才去查看类的实现文件，可以解决头文件的相互包含；#import<>用来包含系 统的头文件，#import””用来包含用户头文件。
 
 
 
 16.属性readwrite，readonly，assign，retain，copy，nonatomic 各是什么作用，在那种情况下用？
 
 答：readwrite 是可读可写特性；需要生成getter方法和setter方法时
 
 readonly 是只读特性  只会生成getter方法 不会生成setter方法 ;不希望属性在类外改变
 
 assign 是赋值特性，setter方法将传入参数赋值给实例变量；仅设置变量时；
 
 retain 表示持有特性，setter方法将传入参数先保留，再赋值，传入参数的retaincount会+1;
 
 copy 表示赋值特性，setter方法将传入对象复制一份；需要完全一份新的变量时。
 
 nonatomic 非原子操作，决定编译器生成的setter getter是否是原子操作，atomic表示多线程安全，一般使用nonatomic
 
 
 
 17.常见的object-c的数据类型有那些， 和C的基本数据类型有什么区别？如：NSInteger和int
 
 答：object-c的数据类型有 NSString，NSNumber，NSArray，NSMutableArray，NSData等等，这些都是class，创建后便是对象，而C语言的基本数据类型int，只是一定字节的内存空间，用于存放数值；而object-c的NSNumber包含有父类NSObject的方法和 NSNumber自己的方法，可以完成复杂的操作。
 
 
 
 18.Objective-C如何对内存管理的,说说你的看法和解决方法?
 
 答：Objective-C的内存管理主要有三种方式ARC（自动内存计数）、手动内存计数、内存池。
 
 解决方法的话： 谁持有，谁释放。
 
 
 
 19.如何对iOS设备进行性能测试?
 
 答：Profile-> Instruments ->Time Profiler
 
 
 
 20.Object C中创建线程的方法是什么？如果在主线程中执行代码，方法是什么？如果想延时执行代码、方法又是什么？
 
 答：线程创建有三种方法：使用NSThread创建、使用 GCD的dispatch、使用子类化的NSOperation,然后将其加入NSOperationQueue;在主线程执行代码，方法是 performSelectorOnMainThread，如果想延时执行代码可以用performSelector:onThread:withObject:waitUntilDone:
 
 
 
 21.描述一下iOS SDK中如何实现MVC的开发模式
 
 答：MVC是：模型--视图--控制  开发模式，对于iOS SDK，所有的View都是视图层的，它应该独立于模型层，由视图控制层来控制。所有的用户数据都是模型层，它应该独立于视图。所有的ViewController都是控制层，由它负责控制视图，访问模型数据。
 
 
 
 22.定义属性时，什么情况使用copy、assign、retain？
 
 答：assign用于简单数据类型，如NSInteger,double,bool, 其实还有后面的block等；
 
 retain和copy用于对象，copy用于当a指向一个对象，b也想指向同样的对象的时候，如果用assign，a如果释放，再调用b会crash,如果用copy 的方式，a和b各自有自己的内存，  就可以解决这个问题。
 
 retain 会使计数器加一，也可以解决assign的问题。
 
 另外：atomic和nonatomic用来决定编译器生成的getter和setter是否为原子操作。在多线程环境下，原子操作是必要的，否则有可能引起错误的结果。
 
 加了atomic，setter函数会变成下面这样：
 
 if (property != newValue) {
 
 [property release];
 
 property = [newValue retain];
 
 }
 
 
 
 23. Object-C有私有方法吗？私有变量呢？
 
 答：objective-c – 类里面的方法只有两种, 静态方法和实例方法，所有实例变量默认都是私有的，所有实例方法默认都是公有的。
 
 
 
 24.浅拷贝和深拷贝区别是什么
 
 答：浅拷贝：只复制指向对象的指针，而不复制引用对象本身。
 
 
 深拷贝：复制引用对象本身。
 
 
 
 25.自动释放池是什么,如何工作
 
 答： 当您向一个对象发送一个autorelease消息时，Cocoa就会将该对 象的一个引用放入到最新的自动释放池。
 
 它仍然是个正当的对象，因此自动释放池定义的作用域内的其它对象可以向它发送消息。当程序执行到作用域结束的位置时，
 
 自动释放池就会被释放，池中的所有对象也就被释放。
 
 
 
 26.单件实例是什么
 
 答： Foundation 和 Application Kit 框架中的一些类只允许创建单件对象，即这些类在当前进程中的唯一实例。
 
 举例：NSFileManager 和NSWorkspace类在使用时都是基于进程进行单件对象的实例化。
 
 当向这些类请求实例的时候，它们会向您传递单一实例的一个引用，如果该实例还不存在，则首先进行实例的分配 和初始化。
 
 
 
 27.类别的作用？继承和类别在实现中有何区别？
 答：category 可以在不获悉，不改变原来代码的情况下往里面添加新的方法，只能添加，不能删除修改。
 
 
 并且如果类别和原来类中的方法产生名称冲突，则类别将覆盖原来的方法，因为类别具有更高的优先级。
 类别主要有3个作用：
 
 
 (1)将类的实现分散到多个不同文件或多个不同框架中。
 
 
 (2)创建对私有方法的前向引用。
 
 
 (3)向对象添加非正式协议。
 
 
 继承可以增加，修改或者删除方法，并且可以增加属性。
 
 
 
 28.类别和类扩展的区别。
 答：category和extensions的不同在于 后者可以添加属性。另外后者添加的方法是必须要实现的。
 extensions可以认为是一个私有的Category。
 
 
 
 29.KVO and KVC?
 
 
 答：kvc:键 - 值编码是一种间接访问对象的属性，使用字符串来标识属性，而不是通过调用存取方法，直接或通过实例变量访问的机制。
 很多情况下可以简化程序代码。apple文档其实给了一个很好的例子。
 kvo:键值观察机制，他提供了观察某一属性变化的方法，极大的简化了代码。
 具体用看到用到过的一个地方是对于按钮点击变化状态的的监控。
 比如我自定义的一个button
 [cpp]
 
 
 [self addObserver:self forKeyPath:@"highlighted" options:0 context:nil];
 
 
 
 
 #pragma mark KVO
 
 
 
 - (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
 {
 
 
 if ([keyPath isEqualToString:@"highlighted"] ) {
 
 
 [self setNeedsDisplay];
 
 
 }
 
 }
 
 对于系统是根据keypath去取的到相应的值发生改变，理论上来说是和kvc机制的道理是一样的。
 对于kvc机制如何通过key寻找到value：
 “当通过KVC调用对象时，比如：[self valueForKey:@”someKey”]时，程序会自动试图通过几种不同的方式解析这个调用。首先查找对象是否带有 someKey 这个方法，如果没找到，会继续查找对象是否带有someKey这个实例变量（iVar），如果还没有找到，程序会继续试图调用
 
 -(id) valueForUndefinedKey:这个方法。如果这个方法还是没有被实现的话，程序会抛出一个NSUndefinedKeyException异常错误。
 
 
 
 
 
 (cocoachina.com注：Key-Value Coding查找方法的时候，不仅仅会查找someKey这个方法，还会查找getsomeKey这个方法，前面加一个get，或者_someKey以及_getsomeKey这几种形式。同时，查找实例变量的时候也会不仅仅查找someKey这个变量，也会查找_someKey这个变量是否存在。）
 
 设计valueForUndefinedKey:方法的主要目的是当你使用-(id)valueForKey方法从对象中请求值时，对象能够在错误发生前，有最后的机会响应这个请求。这样做有很多好处，下面的两个例子说明了这样做的好处。“
 来至cocoa，这个说法应该挺有道理。
 
 
 因为我们知道button却是存在一个highlighted实例变量.因此为何上面我们只是add一个相关的keypath就行了，
 
 
 可以按照kvc查找的逻辑理解，就说的过去了。
 
 
 
 30.代理的作用？
 
 答：代理的目的是改变或传递控制链。允许一个类在某些特定时刻通知到其他类，而不需要获取到那些类的指针。可以减少框架复杂度。
 另外一点，代理可以理解为java中的回调监听机制的一种类似。
 
 
 
 31.说说响应链
 
 
 答： 事件响应链。包括点击事件，画面刷新事件等。在视图栈内从上至下，或者从下之上传播。
 
 
 
 32.frame和bounds有什么不同？
 
 
 答：frame指的是：该view在父view坐标系统中的位置和大小。（参照点是父亲的坐标系统）
 bounds指的是：该view在本身坐标系统中 的位置和大小。（参照点是本身坐标系统）
 
 
 
 33.方法和选择器有何不同？
 
 
 答：selector是一个方法的名字，method是一个组合体。
 
 
 
 34.Object－c的类可以多重继承么？可以实现多个接口么？重写一个类的方式用继承好还是分类好？为什么？
 
 答：Objective-c只支持单继承，如果要实现多继承的话，可以通过类别和协议的方式来实现，cocoa 中所有的类都是NSObject 的子类，多继承在这里是用protocol 委托代理 来实现的。
 
 
 
 35.ARC自动引用技术
 
 答:1.ARC是编译特性，不是运行时特性，只是在编译的时候，编译器会自动加上释放代码
 
 2.不能调用release、retain、autorelease、retainCount
 
 3.dealloc注意
 
 1> 不能在dealloc中调用[super dealloc]
 
 2> 不能在dealloc中释放资源
 
 4.@property参数说明
 
 1> retain 改为 strong
 
 2> 基本数据类型(int\float)还是用assign
 
 3> copy 还是 copy
 
 4> 如果2个对象循环引用，一端用strong，一端用weak
 
 5> weak是用在对象上，weak其实作用跟assign相当
 
 5.ARC中只允许使用通过@autoreleasepool {}创建自动释放池
 
 
 
 36 GCD技术
 
 答:Grand Central Dispatch简称GCD 解决多核并行运算的一种方案
 
 看代码就行：
 
 //  Grand Central Dispatch简称GCD技术
 
 
 
 // Do any additional setup after loading the view.
 
 
 
 //    dispatch_queue_t newDispath = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
 
 //    dispatch_async(newDispath, ^{
 
 //        [self downloadImage];
 
 //    });
 
 
 
 //    #defineDISPATCH_QUEUE_PRIORITY_HIGH  2
 
 //    #defineDISPATCH_QUEUE_PRIORITY_DEFAULT  0
 
 //    #defineDISPATCH_QUEUE_PRIORITY_LOW (-2)
 
 //    #defineDISPATCH_QUEUE_PRIORITY_BACKGROUNDINT16_MIN
 
 
 
 
 
 
 
 
 dispatch queue分为下面三种：
 
 * Serial:又称为private dispatch queues，同时只执行一个任务。Serial queue通常用于同步访问特定的资源或数据。当你创建多   个        Serial queue时，虽然它们各自是同步执行的，但Serial queue与Serial queue之间是并发执行的。
 
 * Concurrent: 又称为global dispatch queue，可以并发地执行多个任务，但是执行完成的顺序是随机的。
 
 * Main dispatch queue它是全局可用的serial queue，它是在应用程序主线程上执行任务的
 




//  一般GCD 可以如下操作



dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT,0), ^{
    
    // 耗时的操作
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        // 更新界面
        
    });
    
});



[selfexampleDispatch];



 
 *系统给每一个应用程序提供了三个concurrent dispatch queues。
 
 *这三个并发调度队列是全局的，它们只有优先级的不同。
 
 *因为是全局的，我们不需要去创建。我们只需要通过使用函数dispath_get_global_queue去得到队列
 




dispatch_queue_t globalQ =dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT,0);



NSLog(@"global:%p",globalQ);

dispatch_queue_t mainQ =dispatch_get_main_queue();

NSLog(@"mainQ:%p",mainQ);


 
 *虽然dispatch queue是引用计数的对象，但是以上两个都是全局的队列，不用retain或release。
 









 
 *dispatch_group_async可以实现监听一组任务是否完成，完成后得到通知执行其他的操作。
 
 *这个方法很有用，比如你执行三个下载任务，当三个任务都下载完成后你才通知界面说完成的了。
 


timeInt = 0;

[NSTimerscheduledTimerWithTimeInterval:1
 
                                target:self
 
                              selector:@selector(checkingTime)
 
                              userInfo:nil
 
                               repeats:YES];

[selfexampleDispath_group];





dispatch_barrier_async的使用
 
 *dispatch_barrier_async是在前面的任务执行结束后它才执行，而且它后面的任务等它执行完成之后才会执行
 




[selfexampleDispatch_barrier];





dispatch_apply
 
 *执行某个代码片段N次。
 


dispatch_apply(5, globalQ, ^(size_t index) {
    
    // 执行5次
    
});









1、#import和#include的区别，@class代表什么？

@class一般用于头文件中需要声明该类的某个实例变量的时候用到，在m文件中还是需要使用#import

而#import比起#include的好处就是不会引起重复包含

2、谈谈Object-C的内存管理方式及过程？

1.当你使用new,alloc和copy方法创建一个对象时,该对象的保留计数器值为1.当你不再使用该对象时,你要负责向该对象发送一条release或autorelease消息.这样,该对象将在使用寿命结束时被销毁.

2.当你通过任何其他方法获得一个对象时,则假设该对象的保留计数器值为1,而且已经被设置为自动释放,你不需要执行任何操作来确保该对象被清理.如果你打算在一段时间内拥有该对象,则需要保留它并确保在操作完成时释放它.

3.如果你保留了某个对象,你需要(最终)释放或自动释放该对象.必须保持retain方法和release方法的使用次数相等.

3、Object-C有私有方法吗？私有变量呢？

objective-c – 类里面的方法只有两种, 静态方法和实例方法. 这似乎就不是完整的面向对象了,按照OO的原则就是一个对象只暴露有用的东西. 如果没有了私有方法的话, 对于一些小范围的代码重用就不那么顺手了. 在类里面声名一个私有方法

@interface Controller : NSObject { NSString *something; }

+ (void)thisIsAStaticMethod;

– (void)thisIsAnInstanceMethod;

@end

@interface Controller (private) -

(void)thisIsAPrivateMethod;

@end

@private可以用来修饰私有变量

在Objective‐C中，所有实例变量默认都是私有的，所有实例方法默认都是公有的

4、Object-C有多继承吗？没有的话用什么代替？cocoa 中所有的类都是NSObject 的子类

多继承在这里是用protocol 委托代理 来实现的

你不用去考虑繁琐的多继承 ,虚基类的概念.

ood的多态特性 在 obj-c 中通过委托来实现.

5、内存管理 Autorelease、retain、copy、assign的set方法和含义？

1，你初始化(alloc/init)的对象，你需要释放(release)它。例如：

NSMutableArray aArray = [[NSArray alloc] init]; 后，需要 [aArray release];

2，你retain或copy的，你需要释放它。例如：

[aArray retain] 后，需要 [aArray release];

3，被传递(assign)的对象，你需要斟酌的retain和release。例如：

obj2 = [[obj1 someMethod] autorelease];

对象2接收对象1的一个自动释放的值，或传递一个基本数据类型(NSInteger，NSString)时：你或希望将对象2进行retain，以防止它在被使用之前就被自动释放掉。但是在retain后，一定要在适当的时候进行释放。

关于索引计数(Reference Counting)的问题

retain值 = 索引计数(Reference Counting)

NSArray对象会retain(retain值加一)任何数组中的对象。当NSArray被卸载(dealloc)的时候，所有数组中的对象会 被 执行一次释放(retain值减一)。不仅仅是NSArray，任何收集类(Collection Classes)都执行类似操作。例如 NSDictionary，甚至UINavigationController。

Alloc/init建立的对象，索引计数为1。无需将其再次retain。

[NSArray array]和[NSDate date]等“方法”建立一个索引计数为1的对象，但是也是一个自动释放对象。所以是本地临时对象，那么无所谓了。如果是打算在全Class中使用的变量(iVar)，则必须retain它。

缺省的类方法返回值都被执行了“自动释放”方法。(*如上中的NSArray)

在类中的卸载方法“dealloc”中，release所有未被平衡的NS对象。(*所有未被autorelease，而retain值为1的)

6、浅拷贝和深拷贝区别是什么

简单的来说就是，在有指针的情况下，浅拷贝只是增加了一个指针指向已经存在的内存，而深拷贝就是增加一个指针并且申请一个新的内存，使这个增加的指针指向这个新的内存，采用深拷贝的情况下，释放内存的时候就不会出现在浅拷贝时重复释放同一内存的错误

7、C和obj-c 如何混用

1）obj-c的编译器处理后缀为m的文件时，可以识别obj-c和c的代码，处理mm文件可以识别obj-c,c,c++代码，但cpp文件必须只能用c/c++代码，而且cpp文件include的头文件中，也不能出现obj-c的代码，因为cpp只是cpp

2)在mm文件中混用cpp直接使用即可，所以obj-c混cpp不是问题

3）在cpp中混用obj-c其实就是使用obj-c编写的模块是我们想要的。

如果模块以类实现，那么要按照cpp class的标准写类的定义，头文件中不能出现obj-c的东西，包括#import cocoa的。实现文件中，即类的实现代码中可以使用obj-c的东西，可以import,只是后缀是mm。

如果模块以函数实现，那么头文件要按c的格式声明函数，实现文件中，c++函数内部可以用obj-c，但后缀还是mm或m。

总结：只要cpp文件和cpp include的文件中不包含obj-c的东西就可以用了，cpp混用obj-c的关键是使用接口，而不能直接使用 实现代 码，实际上cpp混用的是obj-c编译后的o文件，这个东西其实是无差别的，所以可以用。obj-c的编译器支持cpp

8、Objective-C中类别和类扩展的区别。

答案：category和extensions的不同在于后者可以添加属性。另外后者添加的方法是必须要实现的。

extensions可以认为是一个私有的Category。

9、我们说的Objective-C是动态运行时语言是什么意思？

答案：多态。 主要是将数据类型的确定由编译时，推迟到了运行时。

这个问题其实浅涉及到两个概念，运行时和多态。

简单来说，运行时机制使我们直到运行时才去决定一个对象的类别，以及调用该类别对象指定方法。

多态：不同对象以自己的方式响应相同的消息的能力叫做多态。意思就是假设生物类（life）都用有一个相同的方法-eat;

那人类属于生物，猪也属于生物，都继承了life后，实现各自的eat，但是调用是我们只需调用各自的eat方法。

也就是不同的对象以自己的方式响应了相同的消息（响应了eat这个选择器）。

因此也可以说，运行时机制是多态的基础？

10、Objective-C堆和栈的区别？

管理方式：对于栈来讲，是由编译器自动管理，无需我们手工控制；对于堆来说，释放工作由程序员控制，容易产生memory leak。

申请大小：

栈：在Windows下,栈是向低地址扩展的数据结构，是一块连续的内存的区域。这句话的意思是栈顶的地址和栈的最大容量是系统预先规定好的，在 WINDOWS下，栈的大小是2M（也有的说是1M，总之是一个编译时就确定的常数），如果申请的空间超过栈的剩余空间时，将提示overflow。因 此，能从栈获得的空间较小。

堆：堆是向高地址扩展的数据结构，是不连续的内存区域。这是由于系统是用链表来存储的空闲内存地址的，自然是不连续的，而链表的遍历方向是由低地址向高地址。堆的大小受限于计算机系统中有效的虚拟内存。由此可见，堆获得的空间比较灵活，也比较大。

碎片问题：对于堆来讲，频繁的new/delete势必会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个问题，因为栈是先进后出的队列，他们是如此的一一对应，以至于永远都不可能有一个内存块从栈中间弹出

分配方式：堆都是动态分配的，没有静态分配的堆。栈有2种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由alloca函数进行分配，但是栈的动态分配和堆是不同的，他的动态分配是由编译器进行释放，无需我们手工实现。


分配效率：栈是机器系统提供的数据结构，计算机会在底层对栈提供支持：分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的效率比较高。堆则是C/C++函数库提供的，它的机制是很复杂的。













Object-C有多继承吗？没有的话用什么代替？

cocoa 中所有的类都是NSObject 的子类
多继承在这里是用protocol 委托代理 来实现的
你不用去考虑繁琐的多继承 ,虚基类的概念.
多态特性 在 obj-c 中通过委托来实现.


Object-C有私有方法吗？私有变量呢？

objective-c – 类里面的方法只有两种, 静态方法和实例方法. 这似乎就不是完整的面向对象了,按照OO的原则就是一个对象只暴露有用的东西. 如果没有了私有方法的话, 对于一些小范围的代码重用就不那么顺手了. 在类里面声名一个私有方法
@interface Controller : NSObject { NSString *something; }
+ (void)thisIsAStaticMethod;
– (void)thisIsAnInstanceMethod;
@end
@interface Controller (private) -
(void)thisIsAPrivateMethod;
@end

@private可以用来修饰私有变量
在Objective‐C中，所有实例变量默认都是私有的，所有实例方法默认都是公有的

关键字const什么含义

const意味着”只读”，下面的声明都是什么意思？
const int a;
int const a;
const int *a;
int * const a;
int const * a const;

前两个的作用是一样，a是一个常整型数。第三个意味着a是一个指向常整型数的指针（也就是，整型数是不可修改的，但指针可以）。第四个意思a是一个指向整型数的常指针（也就是说，指针指向的整型数是可以修改的，但指针是不可修改的）。最后一个意味着a是一个指向常整型数的常指针（也就是说，指针指向的整型数是不可修改的，同时指针也是不可修改的）。

结论：
•; 关键字const的作用是为给读你代码的人传达非常有用的信息，实际上，声明一个参数为常量是为了告诉了用户这个参数的应用目的。如果
你曾花很多时间清理其它人留下的垃圾，你就会很快学会感谢这点多余的信息。（当然，懂得用const的程序员很少会留下的垃圾让别人来清
理的。）
•; 通过给优化器一些附加的信息，使用关键字const也许能产生更紧凑的代码。
•; 合理地使用关键字const可以使编译器很自然地保护那些不希望被改变的参数，防止其被无意的代码修改。简而言之，这样可以减少bug的出现。

欲阻止一个变量被改变，可以使用 const 关键字。在定义该 const 变量时，通常需要对它进行初
始化，因为以后就没有机会再去改变它了；
（2）对指针来说，可以指定指针本身为 const，也可以指定指针所指的数据为 const，或二者同时指
定为 const；
（3）在一个函数声明中，const 可以修饰形参，表明它是一个输入参数，在函数内部不能改变其值；
（4）对于类的成员函数，若指定其为 const 类型，则表明其是一个常函数，不能修改类的成员变量；
（5）对于类的成员函数，有时候必须指定其返回值为 const 类型，以使得其返回值不为“左值”。

关键字volatile有什么含义？并给出三个不同例子？

一个定义为volatile的变量是说这变量可能会被意想不到地改变，这样，编译器就不会去假设这个变量的值了。精确地说就是，优化器在用到
这个变量时必须每次都小心地重新读取这个变量的值，而不是使用保存在寄存器里的备份。下面是volatile变量的几个例子：
• 并行设备的硬件寄存器（如：状态寄存器）
• 一个中断服务子程序中会访问到的非自动变量(Non-automatic variables)
• 多线程应用中被几个任务共享的变量

• 一个参数既可以是const还可以是volatile吗？解释为什么。
• 一个指针可以是volatile 吗？解释为什么。

下面是答案：
• 是的。一个例子是只读的状态寄存器。它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。
• 是的。尽管这并不很常见。一个例子是当一个中服务子程序修该一个指向一个buffer的指针时。

static作用？

函数体内 static 变量的作用范围为该函数体，不同于 auto 变量，该变量的内存只被分配一次，
因此其值在下次调用时仍维持上次的值；
（2）在模块内的 static 全局变量可以被模块内所用函数访问，但不能被模块外其它函数访问；
（3）在模块内的 static 函数只可被这一模块内的其它函数调用，这个函数的使用范围被限制在声明
它的模块内；
（4）在类中的 static 成员变量属于整个类所拥有，对类的所有对象只有一份拷贝；
（5）在类中的 static 成员函数属于整个类所拥有，这个函数不接收 this 指针，因而只能访问类的static 成员变量。

#import和#include的区别，@class代表什么？

@class一般用于头文件中需要声明该类的某个实例变量的时候用到，在m文件中还是需要使用#import
而#import比起#include的好处就是不会引起重复包含

线程和进程的区别？

进程和线程都是由操作系统所体会的程序运行的基本单元，系统利用该基本单元实现系统对应用的并发性。
进程和线程的主要差别在于它们是不同的操作系统资源管理方式。进程有独立的地址空间，一个进程崩溃后，在保护模式下不会对其它进程产生影响，而线程只是一个进程中的不同执行路径。线程有自己的堆栈和局部变量，但线程之间没有单独的地址空间，一个线程死掉就等于整个进程死掉，所以多进程的程序要比多线程的程序健壮，但在进程切换时，耗费资源较大，效率要差一些。但对于一些要求同时进行并且又要共享某些变量的并发操作，只能用线程，不能用进程。

堆和栈的区别？

管理方式：对于栈来讲，是由编译器自动管理，无需我们手工控制；对于堆来说，释放工作由程序员控制，容易产生memory leak。
申请大小：
栈：在Windows下,栈是向低地址扩展的数据结构，是一块连续的内存的区域。这句话的意思是栈顶的地址和栈的最大容量是系统预先规定好的，在WINDOWS下，栈的大小是2M（也有的说是1M，总之是一个编译时就确定的常数），如果申请的空间超过栈的剩余空间时，将提示overflow。因此，能从栈获得的空间较小。
堆：堆是向高地址扩展的数据结构，是不连续的内存区域。这是由于系统是用链表来存储的空闲内存地址的，自然是不连续的，而链表的遍历方向是由低地址向高地址。堆的大小受限于计算机系统中有效的虚拟内存。由此可见，堆获得的空间比较灵活，也比较大。
碎片问题：对于堆来讲，频繁的new/delete势必会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个问题，因为栈是先进后出的队列，他们是如此的一一对应，以至于永远都不可能有一个内存块从栈中间弹出
分配方式：堆都是动态分配的，没有静态分配的堆。栈有2种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由alloca函数进行分配，但是栈的动态分配和堆是不同的，他的动态分配是由编译器进行释放，无需我们手工实现。
分配效率：栈是机器系统提供的数据结构，计算机会在底层对栈提供支持：分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的效率比较高。堆则是C/C++函数库提供的，它的机制是很复杂的。

Object-C的内存管理？

1.当你使用new,alloc和copy方法创建一个对象时,该对象的保留计数器值为1.当你不再使用该对象时,你要负责向该对象发送一条release或autorelease消息.这样,该对象将在使用寿命结束时被销毁.
2.当你通过任何其他方法获得一个对象时,则假设该对象的保留计数器值为1,而且已经被设置为自动释放,你不需要执行任何操作来确保该对象被清理.如果你打算在一段时间内拥有该对象,则需要保留它并确保在操作完成时释放它.
3.如果你保留了某个对象,你需要(最终)释放或自动释放该对象.必须保持retain方法和release方法的使用次数相等.

为什么很多内置的类，如TableViewController的delegate的属性是assign不是retain？

循环引用
所有的引用计数系统，都存在循环应用的问题。例如下面的引用关系：
•    对象a创建并引用到了对象b.
•    对象b创建并引用到了对象c.
•    对象c创建并引用到了对象b.
这时候b和c的引用计数分别是2和1。当a不再使用b，调用release释放对b的所有权，因为c还引用了b，所以b的引用计数为1，b不会被释放。b不释放，c的引用计数就是1，c也不会被释放。从此，b和c永远留在内存中。
这种情况，必须打断循环引用，通过其他规则来维护引用关系。比如，我们常见的delegate往往是assign方式的属性而不是retain方式 的属性，赋值不会增加引用计数，就是为了防止delegation两端产生不必要的循环引用。如果一个UITableViewController 对象a通过retain获取了UITableView对象b的所有权，这个UITableView对象b的delegate又是a， 如果这个delegate是retain方式的，那基本上就没有机会释放这两个对象了。自己在设计使用delegate模式时，也要注意这点。

定义属性时，什么情况使用copy、assign、retain？

assign用于简单数据类型，如NSInteger,double,bool,
retain和copy用于对象，
copy用于当a指向一个对象，b也想指向同样的对象的时候，如果用assign，a如果释放，再调用b会crash,如果用copy 的方式，a和b各自有自己的内存，就可以解决这个问题。
retain 会使计数器加一，也可以解决assign的问题。
另外：atomic和nonatomic用来决定编译器生成的getter和setter是否为原子操作。在多线程环境下，原子操作是必要的，否则有可能引起错误的结果。
加了atomic，setter函数会变成下面这样：
if (property != newValue) {
    [property release];
    property = [newValue retain];
}

对象是什么时候被release的？

引用计数为0时。
autorelease实际上只是把对release的调用延迟了，对于每一个Autorelease，系统只是把该Object放入了当前的Autorelease pool中，当该pool被释放时，该pool中的所有Object会被调用Release。对于每一个Runloop， 系统会隐式创建一个Autorelease pool，这样所有的release pool会构成一个象CallStack一样的一个栈式结构，在每一个Runloop结束时，当前栈顶的Autorelease pool会被销毁，这样这个pool里的每个Object（就是autorelease的对象）会被release。那什么是一个Runloop呢？ 一个UI事件，Timer call， delegate call， 都会是一个新的Runloop

iOS有没有垃圾回收？

Objective-C 2.0也是有垃圾回收机制的，但是只能在Mac OS X Leopard 10.5 以上的版本使用。

tableView的重用机制？

　查看UITableView头文件，会找到NSMutableArray*  visiableCells，和NSMutableDictnery* reusableTableCells两个结构。visiableCells内保存当前显示的cells，reusableTableCells保存可重用的cells。

　　TableView显示之初，reusableTableCells为空，那么tableView dequeueReusableCellWithIdentifier:CellIdentifier返回nil。开始的cell都是通过[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier]来创建，而且cellForRowAtIndexPath只是调用最大显示cell数的次数。

　　比如：有100条数据，iPhone一屏最多显示10个cell。程序最开始显示TableView的情况是：

　　1. 用[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier]创建10次cell，并给cell指定同样的重用标识(当然，可以为不同显示类型的cell指定不同的标识)。并且10个cell全部都加入到visiableCells数组，reusableTableCells为空。

　　2. 向下拖动tableView，当cell1完全移出屏幕，并且cell11(它也是alloc出来的，原因同上)完全显示出来的时候。cell11加入到visiableCells，cell1移出visiableCells，cell1加入到reusableTableCells。

3. 接着向下拖动tableView，因为reusableTableCells中已经有值，所以，当需要显示新的cell，cellForRowAtIndexPath再次被调用的时候，tableView dequeueReusableCellWithIdentifier:CellIdentifier，返回cell1。cell1加入到visiableCells，cell1移出reusableTableCells；cell2移出visiableCells，cell2加入到reusableTableCells。之后再需要显示的Cell就可以正常重用了。


ViewController 的loadView、viewDidLoad、viewDidUnload分别是什么时候调用的，在自定义ViewCointroller时在这几个函数中应该做什么工作？

由init、loadView、viewDidLoad、viewDidUnload、dealloc的关系说起
init方法
在init方法中实例化必要的对象
init方法中初始化ViewController本身

loadView方法
当view需要被展示而它却是nil时，viewController会调用该方法。不要直接调用该方法。
如果手工维护views，必须重载重写该方法
如果使用IB维护views，必须不能重载重写该方法

loadView和IB构建view
你在控制器中实现了loadView方法，那么你可能会在应用运行的某个时候被内存管理控制调用。 如果设备内存不足的时候， view 控制器会收到didReceiveMemoryWarning的消息。 默认的实现是检查当前控制器的view是否在使用。 如果它的view不在当前正在使用的view hierarchy里面，且你的控制器实现了loadView方法，那么这个view将被release, loadView方法将被再次调用来创建一个新的view。

viewDidLoad方法
viewDidLoad 此方法只有当view从nib文件初始化的时候才被调用。
重载重写该方法以进一步定制view
在iPhone OS 3.0及之后的版本中，还应该重载重写viewDidUnload来释放对view的任何索引
viewDidLoad后调用数据Model

viewDidUnload方法
当系统内存吃紧的时候会调用该方法（注：viewController没有被dealloc）
内存吃紧时，在iPhone OS 3.0之前didReceiveMemoryWarning是释放无用内存的唯一方式，但是OS 3.0及以后viewDidUnload方法是更好的方式
在该方法中将所有IBOutlet（无论是property还是实例变量）置为nil（系统release view时已经将其release掉了）

在该方法中释放其他与view有关的对象、其他在运行时创建（但非系统必须）的对象、在viewDidLoad中被创建的对象、缓存数据等 release对象后，将对象置为nil（IBOutlet只需要将其置为nil，系统release view时已经将其release掉了）

一般认为viewDidUnload是viewDidLoad的镜像，因为当view被重新请求时，viewDidLoad还会重新被执行

viewDidUnload中被release的对象必须是很容易被重新创建的对象（比如在viewDidLoad或其他方法中创建的对象），不要release用户数据或其他很难被重新创建的对象

dealloc方法
viewDidUnload和dealloc方法没有关联，dealloc还是继续做它该做的事情


ViewController的didReceiveMemoryWarning是在什么时候调用的？默认的操作是什么？

当程序接到内存警告时View Controller将会收到这个消息：didReceiveMemoryWarning

从iOS3.0开始，不需要重载这个函数，把释放内存的代码放到viewDidUnload中去。

这个函数的默认实现是:检查controller是否可以安全地释放它的view(这里加粗的view指的是controller的view属性)，比如view本身没有superview并且可以被很容易地重建（从nib或者loadView函数）。

如果view可以被释放，那么这个函数释放view并调用viewDidUnload。

你可以重载这个函数来释放controller中使用的其他内存。但要记得调用这个函数的super实现来允许父类（一般是UIVIewController）释放view。

如果你的ViewController保存着view的子view的引用，那么，在早期的iOS版本中，你应该在这个函数中来释放这些引用。而在iOS3.0或更高版本中，你应该在viewDidUnload中释放这些引用。



列举Cocoa中常见的集中多线程的实现，并谈谈多线程安全的几种解决办法，一般什么地方会用到多线程？

NSOperation NSThread
@sychonized

怎么理解MVC，在Cocoa中MVC是怎么实现的？

MVC设计模式考虑三种对象：模型对象、视图对象、和控制器对象。模型对象代表特别的知识和专业技能，它们负责保有应用程序的数据和定义操作数据的逻辑。视图对象知道如何显示应用程序的模型数据，而且可能允许用户对其进行编辑。控制器对象是应用程序的视图对象和模型对象之间的协调者。
ViewCotroller
Xib

delegate和notification区别，分别在什么情况下使用？

KVC(Key-Value-Coding)
KVO（Key-Value-Observing）
理解KVC与KVO（键-值-编码与键-值-监看）

当通过KVC调用对象时，比如：[self valueForKey:@”someKey”]时，程序会自动试图通过几种不同的方式解析这个调用。首先查找对象是否带有 someKey 这个方法，如果没找到，会继续查找对象是否带有someKey这个实例变量（iVar），如果还没有找到，程序会继续试图调用 -(id) valueForUndefinedKey:这个方法。如果这个方法还是没有被实现的话，程序会抛出一个NSUndefinedKeyException异常错误。

(Key-Value Coding查找方法的时候，不仅仅会查找someKey这个方法，还会查找getsomeKey这个方法，前面加一个get，或者_someKey以及_getsomeKey这几种形式。同时，查找实例变量的时候也会不仅仅查找someKey这个变量，也会查找_someKey这个变量是否存在。)

设计valueForUndefinedKey:方法的主要目的是当你使用-(id)valueForKey方法从对象中请求值时，对象能够在错误发生前，有最后的机会响应这个请求。


self.跟self什么区别？


id、nil代表什么？

id



id和void *并非完全一样。在上面的代码中，id是指向struct objc_object的一个指针，这个意思基本上是说，id是一个指向任何一个继承了Object（或者NSObject）类的对象。需要注意的是id是一个指针，所以你在使用id的时候不需要加星号。比如id foo=nil定义了一个nil指针，这个指针指向NSObject的一个任意子类。而id *foo=nil则定义了一个指针，这个指针指向另一个指针，被指向的这个指针指向NSObject的一个子类。



nil



nil和C语言的NULL相同，在objc/objc.h中定义。nil表示一个Objctive-C对象，这个对象的指针指向空（没有东西就是空）。

内存管理 Autorelease、retain、copy、assign的set方法和含义？

1，你初始化(alloc/init)的对象，你需要释放(release)它。例如：

　　NSMutableArray aArray = [[NSArray alloc] init];

　　后，需要

　　[aArray release];

　　2，你retain或copy的，你需要释放它。例如：

　　[aArray retain]

　　后，需要

　　[aArray release];

　　3，被传递(assign)的对象，你需要斟酌的retain和release。例如：

　　obj2 = [[obj1 someMethod] autorelease];

　　对象2接收对象1的一个自动释放的值，或传递一个基本数据类型(NSInteger，NSString)时： 你或希望将对象2进行retain，以防止它在被使用之前就被自动释放掉。但是在retain后，一定要在适当的时候进行释放。



　　关于索引计数(Reference Counting)的问题

　　retain值 = 索引计数(Reference Counting)

　　NSArray对象会retain(retain值加一)任何数组中的对象。当NSArray被卸载(dealloc)的时候，所有数组中的对象会被执行一次释放(retain值减一)。不仅仅是NSArray，任何收集类(Collection Classes)都执行类似操作。例如NSDictionary，甚至UINavigationController。

　　Alloc/init建立的对象，索引计数为1。无需将其再次retain。

　　[NSArray array]和[NSDate date]等“方法”建立一个索引计数为1的对象，但是也是一个自动释放对象。所以是本地临时对象，那么无所谓了。如果是打算在全Class中使用的变量(iVar)，则必须retain它。

　　缺省的类方法返回值都被执行了“自动释放”方法。(*如上中的NSArray)

　　在类中的卸载方法“dealloc”中，release所有未被平衡的NS对象。(*所有未被autorelease，而retain值为1的)

类别的作用？

有时我们需要在一个已经定义好的类中增加一些方法，而不想去重写该类。比如，当工程已经很大，代码量比较多，或者类中已经包住很多方法，已经有其他代码调用了该类创建对象并使用该类的方法时，可以使用类别对该类扩充新的方法。

注意：类别只能扩充方法，而不能扩充成员变量。

委托（举例）

委托代理（degegate），顾名思义，把某个对象要做的事情委托给别的对象去做。那么别的对象就是这个对象的代理，代替它来打理要做的事。反映到程序中，首先要明确一个对象的委托方是哪个对象，委托所做的内容是什么。
委托机制是一种设计模式，在很多语言中都用到的，这只是个通用的思想，网上会有很多关于这方面的介绍。
那么在苹果开发过程中，用到委托的程序实现思想如下，我主要拿如何在视图之间传输信息做个例子。
譬如：在两个页面（UIIview视图对象）实现传值，用委托（delegate）可以很好做到！
方法：
类A
@interface A：UIView
id transparendValueDelegate;
@property(nomatic, retain) id transparendValueDelegate;
@end

@implemtion A
@synthesize transparendValueDelegate
-(void)Function
{
    NSString* value = @"hello";
    //让代理对象执行transparendValue动作
    [transparendValueDelegate transparendValue: value];
}
@end

类B
@interface B：UIView
NSString* value;
@end

@implemtion B
-(void)transparendValue:(NSString*)fromValue
{
    value = fromValue;
    NSLog(@"the value is %@ ",value);
}
@end

//下面的设置A代理委托对象为B
//在定义A和B类对象处：

A* a = [[A alloc] init];
B* b = [[B alloc] init];
a. transparendValueDelegate = b;//设置对象a代理为对象b

这样在视图A和B之间可以通过委托来传值！

下面这个例子委托有两类：
1、一个视图类对象的代理对象为父视图，子视图用代理实现让父视图显示别的子视图
2、同一父视图下的一个子视图为另一个子视图的代理对象，让另一个子视图改变自身背景色为给定的颜色
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
规范格式如下：
@protocol TransparendValueDelegate;

@interface A：UIView
id< TransparendValueDelegate > m_dTransparendValueDelegate;
@property(nomatic, retain) id m_dTransparendValueDelegate;
@end
//代理协议的声明
@protocol TransparendValueDelegat<NSObject>
{
    -(void)transparendValue:(NSString*)fromValue;
}

retainCount？













1、objective-c中是所有对象间的交互是如何实现的?（深圳皆凯科技有限公司笔试题）

通过代理去进行通讯，或者通过观察者消息模式,Blocks ，appdelegate

2、如何将产品进行多语言发布，开发？

Xcode对多语言支持比较好，除了 h m文件之外所有其它东西都可以多语言

3、objective-c中是如何实现线程同步的?

Mutexlock，NSCondtion lock，消息传送

４、编写函数_memmove说明如下：实现C语言库函数memmove的功能：将一块缓冲区中的数据移动到另一块缓冲区中。可能有重复。

//

５、什么叫数据结构？（面试顺风快递iphone开发）

计算机 = 编程+数据结构

６、编程中，保存数据有哪几种方式？数组、自定义类、文件操作、数据库如：SQLite

文件  plist NSUserDefaults sqlite

７、Sizeof与strlen的区别和联系？

８、什么是抽象类？抽象类有什么作用？能实例化吗？

NSOperation 没有完全实现的类叫抽象类, C++,java

抽象类不能实例化, 不能 NSOperation *a =[[NSOperation alloc] init];

９、  用Objective-C写冒泡法．

//

１０、你对@interface和@property的理解？

@interface申明一个类

@property就是申明2个函数，getter setter，编译器会自动产生2个函数

retain, assign是什么意思

１１、Iphone开发中控制类有什么作用？

Controller, UIViewController, UINav, UITabBarController

UIImagePickerController, UITableViewController

UIView和UIViewController的区别 container

１２、线程中有哪些函数？写出来。

[NSThread detachNewXXXXX];

１３、有没有写过自定义的控件？

自己定义控件有2类，1类比较多的就是类似

RatingView

UIJewels : UIButton

{
    
    int x,   y;
    
    int  type;
    
    UIImage *image;
    
}

UIImageView和UIImage  UILabel和NSString

2. 用CG CoreGraphics  drawRect:

--------

|-------| 每个UIView都有一个drawRect:

１４、调用一个类的静态方法需不需要release？

静态方法就是类方法,不需要，类的方法

对象放在autorelease中

１５、do-while 与 while-do的区别？

１６、写出几个死循环？while（1），for（；；），





用预处理指令#define声明一个常数，用以表明1年中有多少秒（忽略闰年问题）

#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL



下面是笔试常靠题

a) int a; // An integer

b) int *a; // A pointer to an integer

c) int **a; // A pointer to a pointer to an integer

d) int a[10]; //一个有10个指针的数组，该指针是指向一个整型数的。

e) int *a[10]; //一个有10个指针的数组，该指针是指向一个整型数的。

f) int (*a)[10]; //一个指向有10个整型数数组的指针

g) int (*a)(int); //一个指向函数的指针，该函数有一个整型参数并返回一个整型数。

h) int (*a[10])(int); //一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数。



1。assign和retain，copy的区别

assign就是和普通语言的赋值一样

retain 在一个对象中保存该对象需要拥有的对象

对该对象进行应用计数+1

@property (retain) 为了写程序方便

copy主要是赋值

一般 代理的申明都是assign 为什么

原因有2个，

1 根本就没有必要把代理的计数器+1

2. 主要是为了避免引用技术嵌套，递归

2。如何持久保存数据

NSUserDefaults, Plist, SQLite3, file

3。网络方面得 比如如何检测联网 http  xml等

ASIHTTPRequest  Reacheable.[hm]

原理是ifconfig 是不是有ip地址

Reachability

来判断是否有网络3G Wifi

4。类之间得继承关系 比如UIview得父类是哪一个等等？

UIResponder，处理触摸，

touchBegin, touchEnd, nextResponder

5。异常处理

都是自己判断 错误信息

longjmp

char *p = malloc(100);

if (p == NULL) {
    
}



在同一个类A中,有方法a和方法b,方法b如何调用方法a?

[self  a];

有A、B两个类，B类继承于A类，都实现了方法xx。创建B类实例b,如何让b调用A类？

[super a];

const和Volatile分别代表什么意思？

Volatile表示每次都从内存取数据

类型id代表什么意思？



面向对象包含哪些元素？

继承和分类的区别？

Catogory

Catogory实现起来麻烦一些，但是使用方便

NSSet类的作用是什么？

集合

编写一个完整程序，在控制台打印字符串“HelloWorld!”

用递归实现计算n的阶乘。（用objective-c语法实现）

//



static全局变量与普通的全局变量有什么区别？static局部变量和普通局部变量有什么区别？static函数与普通函数有什么区别？

C语言中讲讲static变量和static函数有什么作用

static关键字有两种意思,你看上下文来判断

1,表示变量是静态存储变量

表示变量存放在静态存储区.

2,表示该变量是内部连接

(这种情况是指该变量不在任何{}之内,就象全局变量那样,这时候加上static)

,也就是说在其它的.cpp文件中,该变量是不可见的(你不能用).

当static加在函数前面的时候

表示该函数是内部连接,之在本文件中有效,别的文件中不能应用该函数.

不加static的函数默认为是全局的.

也就是说在其他的.cpp中只要申明一下这个函数,就可以使用它.

1、static全局变量与普通的全局变量有什么区别？static局部变量和普通局部变量有什么区别？static函数与普通函数有什么区别？

答：全局变量(外部变量)的说明之前再冠以static 就构成了静态的全局变量。全局变量本身就是静态存储方式， 静态全局变量当然也是静态存储方式。 这两者在存储方式上并无不同。这两者的区别虽在于非静态全局变量的作用域是整个源程序，当一个源程序由多个源文件组成时，非静态的全局变量在各个源文件中都是有效的。 而静态全局变量则限制了其作用域， 即只在定义该变量的源文件内有效， 在同一源程序的其它源文件中不能使用它。由于静态全局变量的作用域局限于一个源文件内，只能为该源文件内的函数公用， 因此可以避免在其它源文件中引起错误。

从以上分析可以看出， 把局部变量改变为静态变量后是改变了它的存储方式即改变了它的生存期。把全局变量改变为静态变量后是改变了它的作用域， 限制了它的使用范围。

static函数与普通函数作用域不同。static函数仅在本文件中使用。只在当前源文件中使用的函数应该说明为内部函数(static)，内部函数应该在当前源文件中说明和定义。对于可在当前源文件以外使用的函数，应该在一个头文件中说明，要使用这些函数的源文件要包含这个头文件

static全局变量与普通的全局变量有什么区别：static全局变量只初使化一次，防止在其他文件单元中被引用;

static局部变量和普通局部变量有什么区别：static局部变量只被初始化一次，下一次依据上一次结果值；

static函数与普通函数有什么区别：static函数在内存中只有一份，普通函数在每个被调用中维持一份拷贝



2、如何引用一个已经定义过的全局变量？

答：extern

可以用引用头文件的方式，也可以用extern关键字，如果用引用头文件方式来引用某个在头文件中声明的全局变理，假定你将那个变写错了，那么在编译期间 会报错，如果你用extern方式引用时，假定你犯了同样的错误，那么在编译期间不会报错，而在连接期间报错。



3、全局变量可不可以定义在可被多个.C文件包含的头文件中？为什么？

答：可以，在不同的C文件中以static形式来声明同名全局变量。

可以在不同的C文件中声明同名的全局变量，前提是其中只能有一个C文件中对此变量赋初值，此时连接不会出错。





什么是UDP和TCP的区别是什么？

TCP的全称为传输控制协议。这种协议可以提供面向连接的、可靠的、点到点的通信。

UDP的全称为用户数据报协议，它可以提供非连接的不可靠的点到多点的通信。

用TCP还是UDP，那要看你的程序注重哪一个方面？可靠还是快速？





TCP/IP 建立连接的过程

在TCP/IP协议中，TCP协议提供可靠的连接服务，采用三次握手建立一个连接。

第一次握手：建立连接时，客户端发送连接请求到服务器，并进入SYN_SEND状态，等待服务器确认；

第二次握手：服务器收到客户端连接请求，向客户端发送允许连接应答，此时服务器进入SYN_RECV状态；

第三次握手：客户端收到服务器的允许连接应答，向服务器发送确认，客户端和服务器进入通信状态，完成三次握手。

（所谓的三次握手就是要有三次连接信息的发送/接收过程。TCP连接的建立需要进行三次连接信息的发送/接收。）



-(void) print:(NSString*) msg

{
    
    NSLog(@"%@",msg);
    
}



printf("%d,%c\n",i,c)



char str[10]=",str2[]={"China"};

strcpy(str1,str2);



printf("%d",max(a,b));

把 max(a,b)作为printf函数的一个参数。





obj-c有多重继承么?不是的话有什么替代方法?

cocoa 中所有的类都是NSObject 的子类，多继承在这里是用protocol 委托代理来实现的。你不用去考虑繁琐的多继承，虚基类的概念。多态特性在 obj-c 中通过委托来实现。



线程与进程的区别和联系?



进程和线程都是由操作系统所体会的程序运行的基本单元，系统利用该基本单元实现系统对应用的并发性。



程和线程的主要差别在于它们是不同的操作系统资源管理方式。进程有独立的地址空间，一个进程崩溃后，在保护模式下不会对其它进程产生影响，而线程只是一个进程中的不同执行路径。线程有自己的堆栈和局部变量，但线程之间没有单独的地址空间，一个线程死掉就等于整个进程死掉，所以多进程的程序要比多线程的程序健壮，但在进程切换时，耗费资源较大，效率要差一些。但对于一些要求同时进行并且又要共享某些变量的并发操作，只能用线程，不能用进程。



自动释放池是什么,如何工作？

当您向一个对象发送一个autorelease消息时，Cocoa就会将该对象的一个引用放入到最新的自动释放池。它仍然是个正当的对象，因此自动释放池定义的作用域内的其它对象可以向它发送消息。当程序执行到作用域结束的位置时，自动释放池就会被释放，池中的所有对象也就被释放。



1. ojc-c 是通过一种"referring counting"(引用计数)的方式来管理内存的, 对象在开始分配内存(alloc)的时候引用计数为一,以后每当碰到有copy,retain的时候引用计数都会加一, 每当碰到release和autorelease的时候引用计数就会减一,如果此对象的计数变为了0, 就会被系统销毁.

2. NSAutoreleasePool 就是用来做引用计数的管理工作的,这个东西一般不用你管的.

3. autorelease和release没什么区别,只是引用计数减一的时机不同而已,autorelease会在对象的使用真正结束的时候才做引用计数减一。



什么是KVC和KVO？答：KVC(Key-Value-Coding)内部的实现：一个对象在调用setValue的时候，（1）首先根据方法名找到运行方法的时候所需要的环境参数。（2）他会从自己isa指针结合环境参数，找到具体的方法实现的接口。（3）再直接查找得来的具体的方法实现。KVO（Key-Value-Observing）：当观察者为一个对象的属性进行了注册，被观察对象的isa指针被修改的时候，isa指针就会指向一个中间类，而不是真实的类。所以isa指针其实不需要指向实例对象真实的类。所以我们的程序最好不要依赖于isa指针。在调用类的方法的时候，最好要明确对象实例的类名。



kvc 就是一种通过字符串去间接操作对象属性的机制。

iphone中，自定义协议？

Protocol , 看代理  viewController

协议在oc中主要用在代理中

绑定的概念？

代理的概念？对它怎么理解？

为了模块之间的松耦合

网络编程中协议的概念。

NetworkDataDelegate;

3个函数理解 didReceive,













Iphone工程师笔试试题

1.main()

{
    
    int a[5]={1,2,3,4,5};
    
    int *ptr=(int *)(&a+1);
    
    printf("%d,%d",*(a+1),*(ptr-1));
    
}

答：2,5

*(a+1）就是a[1]，*(ptr-1)就是a[4],执行结果是2，5
  　　&a+1不是首地址+1，系统会认为加一个a数组的偏移，是偏移了一个数组的大小（本例是5个int）
  　　int *ptr=(int *)(&a+1);
  　　则ptr实际是&(a[5]),也就是a+5
  原因如下：
  
  　　&a是数组指针，其类型为 int (*)[5];
  　　而指针加1要根据指针类型加上一定的值，不同类型的指针+1之后增加的大小不同。
  　　a是长度为5的int数组指针，所以要加 5*sizeof(int)
  　　所以ptr实际是a[5]
  　　但是prt与(&a+1)类型是不一样的(这点很重要)
  　　所以prt-1只会减去sizeof(int*)
  
  　　a,&a的地址是一样的，但意思不一样
  a是数组首地址，也就是a[0]的地址，&a是对象（数组）首地址， a+1是数组下一元素的地址，即a[1],&a+1是下一个对象的地址，即a[5].
  
  
  
  
  
  2. 以下为Windows NT下的32位C++程序，请计算sizeof的值
  
  void Func ( char str[100] )
{
    sizeof( str ) = ?
}
  void *p = malloc( 100 );
  sizeof ( p ) = ?
  
  
  
  这题很常见了,Func ( char str[100] )函数中数组名作为函数形参时，在函数体内，数组名失去了本身的内涵，仅仅只是一个指针；在失去其内涵的同时，它还失去了其常量特性，可以作自增、自减等操作，可以被修改。Windows NT 32位平台下，指针的长度（占用内存的大小）为4字节，故sizeof( str ) 、sizeof ( p ) 都为4。
  
  
  
  
  
  
  
  
  
  3.还是考指针,不过我对cocoa的代码还是不太熟悉
  
  大概是这样的
  
  - （void）*getNSString(const NSString * inputString)
  
{
    
    inputString = @"This is a main test\n";
    
    return ;
    
}
  
  -main(void)
  
{
    
    
    
    NSString *a=@"Main";
    
    
    
    NSString *aString = [NSString stringWithString:@"%@",getNSString(a)];
    
    
    
    NSLog(@"%@\n", aString);
    
}
  
  
  
  最后问输出的字符串:NULL,output在函数返回后，内存已经被释放。
  
  
  
  
  
  4.用预处理指令#define声明一个常数，用以表明1年中有多少秒（忽略闰年问题）
  
#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL
  我在这想看到几件事情：
  •; #define 语法的基本知识（例如：不能以分号结束，括号的使用，等等）
  •; 懂得预处理器将为你计算常数表达式的值，因此，直接写出你是如何计算一年中有多少秒而不是计算出实际的值，是更清晰而没有代价的。
  
  •; 意识到这个表达式将使一个16位机的整型数溢出-因此要用到长整型符号L,告诉编译器这个常数是的长整型数。
  •; 如果你在你的表达式中用到UL（表示无符号长整型），那么你有了一个好的起点。记住，第一印象很重要。
  
  
  
  
  
  写一个"标准"宏MIN
  
  ，这个宏输入两个参数并返回较小的一个。
  
  
  
  
#define MIN(A,B)
  
  （（A） <= (B) ? (A) : (B))
这个测试是为下面的目的而设的：
•;

标识#define在宏中应用的基本知识。这是很重要的，因为直到嵌入(inline)操作符变为标准C的一部分，宏是方便产生嵌入代码的唯一方
法，对于嵌入式系统来说，为了能达到要求的性能，嵌入代码经常是必须的方法。


•; 三重条件操作符的知识。这个操作符存在C语言中的原因是它使得编译器能产生比 if-then-else

更优化的代码，了解这个用法是很重要的。

•; 懂得在宏中小心地把参数用括号括起来
•;

我也用这个问题开始讨论宏的副作用，例如：当你写下面的代码时会发生什么事？
least = MIN(*p++, b);



结果是：
((*p++) <= (b) ? (*p++) : (*p++))
这个表达式会产生副作用，指针p会作三次++自增操作。



5.写一个委托的interface



@protocol MyDelegate;



@interface MyClass: NSObject

{
    
    id <MyDelegate> delegate;
    
}



// 委托方法

@protocol MyDelegate

- (void)didJobs:(NSArray *)args;

@end

6.写一个NSString类的实现

+ (id)initWithCString:(const char *)nullTerminatedCString encoding:(NSStringEncoding)encoding;

+ (id) stringWithCString: (const char*)nullTerminatedCString
encoding: (NSStringEncoding)encoding
{
    NSString  *obj;
    
    obj = [self allocWithZone: NSDefaultMallocZone()];
    obj = [obj initWithCString: nullTerminatedCString encoding: encoding];
    return AUTORELEASE(obj);
}

7.obj-c有多重继承么?不是的话有什么替代方法?


cocoa 中所有的类都是NSObject 的子类

多继承在这里是用protocol 委托代理 来实现的
你不用去考虑繁琐的多继承 ,虚基类的概念.
ood的多态特性  在 obj-c 中通过委托来实现.





8.obj-c有私有方法么?私有变量呢

objective-c - 类里面的方法只有两种, 静态方法和实例方法. 这似乎就不是完整的面向对象了,按照OO的原则就是一个对象只暴露有用的东西. 如果没有了私有方法的话, 对于一些小范围的代码重用就不那么顺手了. 在类里面声名一个私有方法

@interface Controller : NSObject { NSString *something; }

+ (void)thisIsAStaticMethod;

- (void)thisIsAnInstanceMethod;

@end

@interface Controller (private) //category

- (void)thisIsAPrivateMethod;

@end



@private可以用来修饰私有变量

在Objective‐C中，所有实例变量默认都是私有的，所有实例方法默认都是公有的

9.关键字const有什么含意？修饰类呢?static的作用,用于类呢?还有extern c的作用



const意味着"只读"，下面的声明都是什么意思？
const int a;
int const a;
const int *a;
int * const a;
int const * a const;



前两个的作用是一样，a是一个常整型数。第三个意味着a是一个指向常整型数的指针（也就是，整型数是不可修改的，但指针可以）。第四个意思a是一个指向整型数的常指针（也就是说，指针指向的整型数是可以修改的，但指针是不可修改的）。最后一个意味着a是一个指向常整型数的常指针（也就是说，指针指向的整型数是不可修改的，同时指针也是不可修改的）。



结论：

•; 关键字const的作用是为给读你代码的人传达非常有用的信息，实际上，声明一个参数为常量是为了告诉了用户这个参数的应用目的。如果
你曾花很多时间清理其它人留下的垃圾，你就会很快学会感谢这点多余的信息。（当然，懂得用const的程序员很少会留下的垃圾让别人来清
理的。）
•; 通过给优化器一些附加的信息，使用关键字const也许能产生更紧凑的代码。
•; 合理地使用关键字const可以使编译器很自然地保护那些不希望被改变的参数，防止其被无意的代码修改。简而言之，这样可以减少bug的出现。


（1）欲阻止一个变量被改变，可以使用 const 关键字。在定义该 const 变量时，通常需要对它进行初始化，因为以后就没有机会再去改变它了；
（2）对指针来说，可以指定指针本身为 const，也可以指定指针所指的数据为 const，或二者同时指定为 const；
（3）在一个函数声明中，const 可以修饰形参，表明它是一个输入参数，在函数内部不能改变其值；
（4）对于类的成员函数，若指定其为 const 类型，则表明其是一个常函数，不能修改类的成员变量；
（5）对于类的成员函数，有时候必须指定其返回值为 const 类型，以使得其返回值不为“左值”。

关键字volatile有什么含意?并给出三个不同的例子。



一个定义为volatile的变量是说这变量可能会被意想不到地改变，这样，编译器就不会去假设这个变量的值了。精确地说就是，优化器在用到
这个变量时必须每次都小心地重新读取这个变量的值，而不是使用保存在寄存器里的备份。下面是volatile变量的几个例子：

•; 并行设备的硬件寄存器（如：状态寄存器）
•; 一个中断服务子程序中会访问到的非自动变量(Non-automatic variables)
•; 多线程应用中被几个任务共享的变量



•; 一个参数既可以是const还可以是volatile吗？解释为什么。
•; 一个指针可以是volatile 吗？解释为什么。

下面是答案：
•; 是的。一个例子是只读的状态寄存器。它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。
•; 是的。尽管这并不很常见。一个例子是当一个中服务子程序修该一个指向一个buffer的指针时。



static 关键字的作用：

（1）函数体内 static 变量的作用范围为该函数体，不同于 auto 变量，该变量的内存只被分配一次，因此其值在下次调用时仍维持上次的值；
（2）在模块内的 static 全局变量可以被模块内所用函数访问，但不能被模块外其它函数访问；
（3）在模块内的 static 函数只可被这一模块内的其它函数调用，这个函数的使用范围被限制在声明它的模块内；
（4）在类中的 static 成员变量属于整个类所拥有，对类的所有对象只有一份拷贝；
（5）在类中的 static 成员函数属于整个类所拥有，这个函数不接收 this 指针，因而只能访问类的static 成员变量。

extern "C" 的作用

（1）被 extern "C"限定的函数或变量是 extern 类型的；

extern 是 C/C++语言中表明函数和全局变量作用范围（可见性）的关键字，该关键字告诉编译器，
其声明的函数和变量可以在本模块或其它模块中使用。

（2）被 extern "C"修饰的变量和函数是按照 C 语言方式编译和连接的；



extern "C"的惯用法

（1）在 C++中引用 C 语言中的函数和变量，在包含 C 语言头文件（假设为 cExample.h）时，需进
行下列处理：
extern "C"
{
#include "cExample.h"
}
而在 C 语言的头文件中，对其外部函数只能指定为 extern 类型，C 语言中不支持 extern "C"声明，
在.c 文件中包含了 extern "C"时会出现编译语法错误。

（2）在 C 中引用 C++语言中的函数和变量时，C++的头文件需添加 extern "C"，但是在 C 语言中不
能直接引用声明了 extern "C"的该头文件，应该仅将 C 文件中将 C++中定义的 extern "C"函数声明为
extern 类型。

10.为什么标准头文件都有类似以下的结构？
#ifndef __INCvxWorksh
#define __INCvxWorksh
#ifdef __cplusplus
extern "C" {
#endif
 
#ifdef __cplusplus
}
#endif
#endif  __INCvxWorksh

显然，头文件中的编译宏“#ifndef __INCvxWorksh、#define __INCvxWorksh、#endif” 的作用
是防止该头文件被重复引用。



11.#import跟#include的区别,@class呢?



@class一般用于头文件中需要声明该类的某个实例变量的时候用到，在m文件中还是需要使用#import

而#import比起#include的好处就是不会引起交叉编译

12.MVC模式的理解

MVC设计模式考虑三种对象：模型对象、视图对象、和控制器对象。模型对象代表特别的知识和专业技能，它们负责保有应用程序的数据和定义操作数据的逻辑。视图对象知道如何显示应用程序的模型数据，而且可能允许用户对其进行编辑。控制器对象是应用程序的视图对象和模型对象之间的协调者。

13.线程与进程的区别和联系?



进程和线程都是由操作系统所体会的程序运行的基本单元，系统利用该基本单元实现系统对应用的并发性。

进程和线程的主要差别在于它们是不同的操作系统资源管理方式。进程有独立的地址空间，一个进程崩溃后，在保护模式下不会对其它进程产生影响，而线程只是一个进程中的不同执行路径。线程有自己的堆栈和局部变量，但线程之间没有单独的地址空间，一个线程死掉就等于整个进程死掉，所以多进程的程序要比多线程的程序健壮，但在进程切换时，耗费资源较大，效率要差一些。但对于一些要求同时进行并且又要共享某些变量的并发操作，只能用线程，不能用进程。



14.列举几种进程的同步机制，并比较其优缺点。

答案：  原子操作 信号量机制    自旋锁    管程，会合，分布式系统
进程之间通信的途径

答案：共享存储系统消息传递系统管道：以文件系统为基础
进a程死锁的原因

答案：资源竞争及进程推进顺序非法
死锁的4个必要条件

答案：互斥、请求保持、不可剥夺、环路
死锁的处理

答案：鸵鸟策略、预防策略、避免策略、检测与解除死锁



15.堆和栈的区别



管理方式：对于栈来讲，是由编译器自动管理，无需我们手工控制；对于堆来说，释放工作由程序员控制，容易产生memory leak。

申请大小：
栈：在Windows下,栈是向低地址扩展的数据结构，是一块连续的内存的区域。这句话的意思是栈顶的地址和栈的最大容量是系统预先规定好的，在WINDOWS下，栈的大小是2M（也有的说是1M，总之是一个编译时就确定的常数），如果申请的空间超过栈的剩余空间时，将提示overflow。因此，能从栈获得的空间较小。
堆：堆是向高地址扩展的数据结构，是不连续的内存区域。这是由于系统是用链表来存储的空闲内存地址的，自然是不连续的，而链表的遍历方向是由低地址向高地址。堆的大小受限于计算机系统中有效的虚拟内存。由此可见，堆获得的空间比较灵活，也比较大。

碎片问题：对于堆来讲，频繁的new/delete势必会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个问题，因为栈是先进后出的队列，他们是如此的一一对应，以至于永远都不可能有一个内存块从栈中间弹出

分配方式：堆都是动态分配的，没有静态分配的堆。栈有2种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由alloca函数进行分配，但是栈的动态分配和堆是不同的，他的动态分配是由编译器进行释放，无需我们手工实现。

分配效率：栈是机器系统提供的数据结构，计算机会在底层对栈提供支持：分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的效率比较高。堆则是C/C++函数库提供的，它的机制是很复杂的。



16.什么是键-值,键路径是什么



模型的性质是通过一个简单的键（通常是个字符串）来指定的。视图和控制器通过键来查找相应的属性值。在一个给定的实体中，同一个属性的所有值具有相同的数据类型。键-值编码技术用于进行这样的查找—它是一种间接访问对象属性的机制。

键路径是一个由用点作分隔符的键组成的字符串，用于指定一个连接在一起的对象性质序列。第一个键的
性质是由先前的性质决定的，接下来每个键的值也是相对于其前面的性质。键路径使您可以以独立于模型
实现的方式指定相关对象的性质。通过键路径，您可以指定对象图中的一个任意深度的路径，使其指向相
关对象的特定属性。

For example, the key path address.streetwould get the value of the address property from the receiving

object, and then determine the street property relative to the address object.

17.c和obj-c如何混用

1）obj-c的编译器处理后缀为m的文件时，可以识别obj-c和c的代码，处理mm文件可以识别obj-c,c,c++代码，但cpp文件必须只能用c/c++代码，而且cpp文件include的头文件中，也不能出现obj-c的代码，因为cpp只是cpp
2) 在mm文件中混用cpp直接使用即可，所以obj-c混cpp不是问题
3）在cpp中混用obj-c其实就是使用obj-c编写的模块是我们想要的。
如果模块以类实现，那么要按照cpp class的标准写类的定义，头文件中不能出现obj-c的东西，包括#import cocoa的。实现文件中，即类的实现代码中可以使用obj-c的东西，可以import,只是后缀是mm。
如果模块以函数实现，那么头文件要按c的格式声明函数，实现文件中，c++函数内部可以用obj-c，但后缀还是mm或m。
`
总结：只要cpp文件和cpp include的文件中不包含obj-c的东西就可以用了，cpp混用obj-c的关键是使用接口，而不能直接使用实现代码，实际上cpp混用的是obj-c编译后的o文件，这个东西其实是无差别的，所以可以用。obj-c的编译器支持cpp.

18.目标-动作机制



目标是动作消息的接收者。一个控件，或者更为常见的是它的单元，以插座变量（参见"插座变量"部分）
的形式保有其动作消息的目标。

动作是控件发送给目标的消息，或者从目标的角度看，它是目标为了响应动作而实现的方法。

程序需要某些机制来进行事件和指令的翻译。这个机制就是目标-动作机制。

19.cocoa touch框架



iPhone OS 应用程序的基础 Cocoa Touch 框架重用了许多 Mac 系统的成熟模式，但是它更多地专注于触摸的接口和优化。UIKit 为您提供了在 iPhone OS 上实现图形，事件驱动程序的基本工具，其建立在和 Mac OS X 中一样的 Foundation 框架上，包括文件处理，网络，字符串操作等。



Cocoa Touch 具有和 iPhone 用户接口一致的特殊设计。有了 UIKit，您可以使用 iPhone OS 上的独特的图形接口控件，按钮，以及全屏视图的功能，您还可以使用加速仪和多点触摸手势来控制您的应用。



各色俱全的框架 除了 UIKit 外，Cocoa Touch 包含了创建世界一流 iPhone 应用程序需要的所有框架，从三维图形，到专业音效，甚至提供设备访问 API 以控制摄像头，或通过 GPS 获知当前位置。Cocoa Touch 既包含只需要几行代码就可以完成全部任务的强大的 Objective-C 框架，也在需要时提供基础的 C 语言 API 来直接访问系统。这些框架包括：

Core Animation

通过 Core Animation，您就可以通过一个基于组合独立图层的简单的编程模型来创建丰富的用户体验。

Core Audio

Core Audio 是播放，处理和录制音频的专业技术，能够轻松为您的应用程序添加强大的音频功能。

Core Data

提供了一个面向对象的数据管理解决方案，它易于使用和理解，甚至可处理任何应用或大或小的数据模型。

功能列表：框架分类

下面是 Cocoa Touch 中一小部分可用的框架：

音频和视频
Core Audio
OpenAL
Media Library
AV Foundation

数据管理
Core Data
SQLite

图形和动画
Core Animation
OpenGL ES
Quartz 2D

网络/li>
Bonjour
WebKit
BSD Sockets

用户应用
Address Book
Core Location
Map Kit
Store Kit

20.objc的内存管理

如果您通过分配和初始化（比如[[MyClass alloc] init]）的方式来创建对象，您就拥
有这个对象，需要负责该对象的释放。这个规则在使用NSObject的便利方法new 时也同样适用。   如果您拷贝一个对象，您也拥有拷贝得到的对象，需要负责该对象的释放。

如果您保持一个对象，您就部分拥有这个对象，需要在不再使用时释放该对象。
反过来，

如果您从其它对象那里接收到一个对象，则您不拥有该对象，也不应该释放它（这个规则有少数的例外，在参考文档中有显式的说明）。

21.自动释放池是什么,如何工作

当您向一个对象发送一个autorelease消息时，Cocoa就会将该对象的一个引用放入到最新的自动释放池。它仍然是个正当的对象，因此自动释放池定义的作用域内的其它对象可以向它发送消息。当程序执行到作用域结束的位置时，自动释放池就会被释放，池中的所有对象也就被释放。

1.  ojc-c 是通过一种"referring counting"(引用计数)的方式来管理内存的, 对象在开始分配内存(alloc)的时候引用计数为一,以后每当碰到有copy,retain的时候引用计数都会加一, 每当碰到release和autorelease的时候引用计数就会减一,如果此对象的计数变为了0, 就会被系统销毁.
2. NSAutoreleasePool 就是用来做引用计数的管理工作的,这个东西一般不用你管的.
3. autorelease和release没什么区别,只是引用计数减一的时机不同而已,autorelease会在对象的使用真正结束的时候才做引用计数减一.

22.类工厂方法是什么

类工厂方法的实现是为了向客户提供方便，它们将分配和初始化合在一个步骤中，返回被创建的对象，并进行自动释放处理。这些方法的形式是+ (type)className...（其中 className不包括任何前缀）。

工厂方法可能不仅仅为了方便使用。它们不但可以将分配和初始化合在一起，还可以为初始化过程提供对象的分配信息。

类工厂方法的另一个目的是使类（比如NSWorkspace）提供单件实例。虽然init...方法可以确认一个类在每次程序运行过程只存在一个实例，但它需要首先分配一个“生的”实例，然后还必须释放该实例。 工厂方法则可以避免为可能没有用的对象盲目分配内存。



23.单件实例是什么

Foundation 和 Application Kit 框架中的一些类只允许创建单件对象，即这些类在当前进程中的唯一实例。举例来说，NSFileManager 和NSWorkspace 类在使用时都是基于进程进行单件对象的实例化。当向这些类请求实例的时候，它们会向您传递单一实例的一个引用，如果该实例还不存在，则首先进行实例的分配和初始化。单件对象充当控制中心的角色，负责指引或协调类的各种服务。如果类在概念上只有一个实例（比如 NSWorkspace），就应该产生一个单件实例，而不是多个实例；如果将来某一天可能有多个实例，您可以使用单件实例机制，而不是工厂方法或函数。



24.动态绑定

—在运行时确定要调用的方法



动态绑定将调用方法的确定也推迟到运行时。在编译时，方法的调用并不和代码绑定在一起，只有在消实发送出来之后，才确定被调用的代码。通过动态类型和动态绑定技术，您的代码每次执行都可以得到不同的结果。运行时因子负责确定消息的接收者和被调用的方法。运行时的消息分发机制为动态绑定提供支持。当您向一个动态类型确定了的对象发送消息时，运行环境系统会通过接收者的isa指针定位对象的类，并以此为起点确定被调用的方法，方法和消息是动态绑定的。而且，您不必在Objective-C 代码中做任何工作，就可以自动获取动态绑定的好处。您在每次发送消息时， 特别是当消息的接收者是动态类型已经确定的对象时，动态绑定就会例行而透明地发生。

25.obj-c的优缺点

objc优点：
1) Cateogies
2) Posing
3) 动态识别
4) 指标计算
5）弹性讯息传递
6) 不是一个过度复杂的 C 衍生语言
7) Objective-C 与 C++ 可混合编程
缺点:
1) 不支援命名空间
2)  不支持运算符重载

3） 不支持多重继承

4） 使用动态运行时类型，所有的方法都是函数调用，所以很多编译时优化方法都用不到。（如内联函数等），性能低劣。



26.sprintf,strcpy,memcpy使用上有什么要注意的地方

strcpy是一个字符串拷贝的函数，它的函数原型为strcpy(char *dst, const char *src);

将src开始的一段字符串拷贝到dst开始的内存中去，结束的标志符号为'\0'，由于拷贝的长度不是由我们自己控制的，所以这个字符串拷贝很容易出错。

memcpy，这是一个内存拷贝函数，它的函数原型为memcpy(void * dst,const void * src,size_t n); 将长度为len的一段内存，从src拷贝到dst中去，这个函数的长度可控。但是会有内存叠加的问题。

sprintf是格式化函数。将一段数据通过特定的格式，格式化到一个字符串缓冲区中去。sprintf格式化的函数的长度不可控，有可能格式化后的字符串会超出缓冲区的大小，造成溢出。

27. 用变量a给出下面的定义

a) 一个整型数（An integer）
b)一个指向整型数的指针（ A pointer to an integer）
c)一个指向指针的的指针，它指向的指针是指向一个整型数（ A pointer to a pointer to an intege）r
d)一个有10个整型数的数组（ An array of 10 integers）
e) 一个有10个指针的数组，该指针是指向一个整型数的。（An array of 10 pointers to integers）
f) 一个指向有10个整型数数组的指针（ A pointer to an array of 10 integers）
g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数（A pointer to a function that takes an integer as an argument
and returns an integer）
h)一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数（ An array of ten pointers to functions t
hat take an integer argument and return an integer ）

答案是：
a) int a; // An integer
b) int *a; // A pointer to an integer
c) int **a; // A pointer to a pointer to an integer
d) int a[10]; // An array of 10 integers
e) int *a[10]; // An array of 10 pointers to integers
f) int (*a)[10]; // A pointer to an array of 10 integers
g) int (*a)(int); // A pointer to a function a that  takes an integer argument and returns an integer
h) int (*a[10])(int); // An array of 10 pointers to functions  that take an integer argument and return an integer

28.readwrite，readonly，assign，retain，copy，nonatomic属性的作用

@property是一个属性访问声明，扩号内支持以下几个属性：
1，getter=getterName，setter=setterName，设置setter与getter的方法名
2，readwrite,readonly，设置可供访问级别
2，assign，setter方法直接赋值，不进行任何retain操作，为了解决原类型与环循引用问题
3，retain，setter方法对参数进行release旧值再retain新值，所有实现都是这个顺序(CC上有相关资料)
4，copy，setter方法进行Copy操作，与retain处理流程一样，先旧值release，再Copy出新的对象，retainCount为1。这是为了减少对上下文的依赖而引入的机制。
5，nonatomic，非原子性访问，不加同步，多线程并发访问会提高性能。注意，如果不加此属性，则默认是两个访问方法都为原子型事务访问。锁被加到所属对象实例级(我是这么理解的...)。

@synthesize xxx;  来实现实际代码








*/
@end
