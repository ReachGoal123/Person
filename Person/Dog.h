//
//  Dog.h
//  Person
//
//  Created by wanglin on 14-12-16.
//  Copyright (c) 2014年 tarena. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Dog : NSObject
/*
 面试宝典
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
 
 
 
 
 
 一、（一共三十题）
 
 1.       main()
 
 {
 
 int a[5]={1,2,3,4,5};
 
 int *ptr=(int *)(&a+1);
 
 printf("%d,%d",*(a+1),*(ptr-1));
 
 }
 
 答案：2,5
 
 *(a+1)就是a[1]，*(ptr-1)就是a[4],执行结果是2，5。a+1不是首地址+1，系统会认为加一个a数组的偏 移，是偏移了一个数组的大小（本例是5个int）
 
 　　int *ptr=(int *)(&a+1);
 
 　　则ptr实际 是&(a[5]),也就是a+5
 
 原因如下：a是数组指针，其类型为 int (*)[5];而 指针加1要根据指针类型加上一定的值，不同类型的指针+1之后增加的大小不同。a是长度为5的int数组指针，所以要加 5*sizeof(int)，以ptr实际是a[5]。但是prt与(&a+1)类型是不一样的(这点很重要)。所以prt-1只会减去sizeof(int*)，a,&a的地址是一样的，但意思不一样。 a是数组首地址，也就是a[0]的地址，&a是对象（数组）首地址， a+1是数组下一元素的地址，即a[1],&a+1是下一个对象的地址，即a[5].
 
 2.       以下为Windows NT下的32位C++程序，请计算sizeof的值
 
 void Func ( char str[100] )
 
 {     sizeof( str ) = ?   }
 
 void *p = malloc( 100 );
 
 sizeof ( p ) = ?
 
 答案：sizeof( str ) 、sizeof ( p ) 都为4。
 
 3.       还是考指针,不过我对cocoa的代码还是不太熟悉 大概是这样的 - NSString *getNSString(void)
 
 {
 
 NSString *output=@"This is a main test\n";
 
 return output;
 
 }
 
 -main(void)
 
 {   NSString *a=@"Main";
 
 NSString *aString = [NSString stringWithString:@"%@",getNSString(a)];   NSLog(@"%@\n", aString);
 
 }
 
 答案：最后问输出的字符串:NULL，output在 函数返回后，内存已经被释放。
 
 4.       用预处理指令#define声明一个常数，用以表明1年中有多少秒（忽略闰年问题） 写一个"标准"宏MIN ，这个宏输入两个参数并返回较小的一个。
 
 答案：#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL
 
 5.       写一个委托的interface
 
 答案：@protocol MyDelegate;
 
 @interface MyClass: NSObject
 
 {
 
 id   <MyDelegate> delegate;
 
 }
 
 // 委托方法
 
 @protocol MyDelegate
 
 - (void)didJobs:(NSArray *)args;
 
 @end
 
 6.       写一个NSString类的实现 - (id)initWithCString:(const char *)nullTerminatedCString encoding:(NSStringEncoding)encoding; -(void)dealloc;
 
 答案：+ (id) stringWithCString: (const char*)nullTerminatedCString
 
 encoding: (NSStringEncoding)encoding
 
 {
 
 NSString  *obj;
 
 obj = [self allocWithZone: NSDefaultMallocZone()];
 
 obj = [obj initWithCString: nullTerminatedCString encoding: encoding];
 
 return AUTORELEASE(obj);
 
 }
 
 7.       obj-c有多重继承么?不是的话有什么替代方法?
 
 答案：cocoa 中所有的类都是NSObject 的子类 ，多继承在这里是用protocol 委托代理 来实现的 ，你不用去考虑繁琐的多继承 ,虚基类的概念.ood的多态特性 在 obj-c 中通过委托来实现.
 
 8.       obj-c有私有方法么?私有变量呢
 
 答案：objective-c - 类里面的方法只有两种, 静态方法和实例方法
 
 在Objective‐C中，所有实例变量默认都是受保护的，所有实例方法默认都 是公有的
 
 9.       关键字const有什么含意？ 关键字volatile有什么含意?并给出三个不同的例子。 static 关键字的作用， extern "C" 的作用
 
 答案：const 意味着"只读"，声明一个参数为常量是为了告诉了用户这个参数的应用目的。
 
 关键字const的作用是为给读你代码的人传达非常有用的信息，实际上，声明一个参数为常量是为了告诉了用户这个参数的应用目的。如果
 
 你曾花很多 时间清理其它人留下的垃圾，你就会很快学会感谢这点多余的信息。（当然，懂得用const的程序员很少会留下的垃圾让别人来清
 
 理的。）
 
 通过给优化器一些附加的信息，使用关键字const也许能产生更紧凑的代码。
 
 合理地使用关键字const可以使编译器很自然地保护那些不希望被改变的参数，防止其被无意的代码修改。简而言之，这样可以减少bug的出现。
 
 （1）欲阻止一个变量被改变，可以使用 const 关键字。在定义该 const 变量时，通常需要对它进行初
 
 始化，因为以后就没有机会再去改变它了；
 
 （2）对指针来说，可以指定指针本身为 const，也可以指定指针所指的数据为 const，或二者同时指
 
 定为 const；
 
 （3）在一个函数声明中，const 可以修饰形参，表明它是一个输入参数，在函数内部不能改变其值；
 
 （4）对于类的成员函数，若指定其为 const 类型，则表明其是一个常函数，不能修改类的成员变量；
 
 （5）对于类的成员函数，有时候必须指定其返回值为 const 类型，以使得其返回值不为“左值”。
 
 static 关键字的作用：
 
 （1）函数体内 static 变量的作用范围为该函数体，不同于 auto 变量，该变量的内存只被分配一次，
 
 因此其值在下次调用时仍维持上次的值；
 
 （2）在模块内的 static 全局变量可以被模块内所用函数访问，但不能被模块外其它函数访问；
 
 （3）在模块内的 static 函数只可被这一模块内的其它函数调用，这个函数的使用范围被限制在声明
 
 它的模块内；
 
 （4）在类中的 static 成员变量属于整个类所拥有，对类的所有对象只有一份拷贝；
 
 （5）在类中的 static 成员函数属于整个类所拥有，这个函数不接收 this 指针，因而只能访问类的static 成员变量。
 
 extern "C" 的作用
 
 （1）被 extern "C"限定的函数或变量是 extern 类型的；
 
 extern 是 C/C++语言中表明函数和全局变量作用范围（可见性）的关键字，该关键字告诉编译器，
 
 其声明的函数和变量可以在本模块或 其它模块中使用。
 
 （2）被 extern "C"修饰的变量和函数是按照 C 语言方式编译和连接的；
 
 extern "C"的惯用法
 
 （1）在 C++中引用 C 语言中的函数和变量，在包含 C 语言头文件（假设为 cExample.h）时，需进行下列处理：
 
 extern "C"
 
 {  #include "cExample.h"  }
 
 而在 C 语言的头文件中，对其外部函数只能指定为 extern 类型，C 语言中不支持 extern "C"声明，在.c 文件中包含了 extern "C"时会出现编译语法错误。
 
 （2）在 C 中引用 C++语言中的函数和变量时，C++的头文件需添加 extern "C"，但是在 C 语言中不
 
 能直接引用声明了 extern "C"的该头文件，应该仅将 C 文件中将 C++中定义的 extern "C"函数声明为extern 类型。
 
 10.    为什么标准头文件都有类似以下的结构？      #ifndef __INCvxWorksh      #define __INCvxWorksh      #ifdef __cplusplus      extern "C" {      #endif            #ifdef __cplusplus      }      #endif      #endif  __INCvxWorksh

答案：显然，头文件中的编译宏“#ifndef __INCvxWorksh、#define __INCvxWorksh、#endif” 的作用是防止该头文件被重复引用。

11.    #import跟#include的区别,@class呢?

答案：@class一般用于头文件中需要声明该类的某个实例变量的时候用到，在m文 件中还是需要使用#import而#import比起#include的好处就是不会引起交叉编译

12.    MVC模式的理解

答案：MVC设计模式考虑三种对象：模型对象、视图对象、和控制器对象。模型对象代表特别的知识和专业技能，它们负责保有应用程序的数据和定义操作数据的逻辑。视图对象知道如何显示应用程序的模型数据，而且可能允许用户对其进行编辑。控制器对象是应用程序的视图对象和模型对象之间的协调者。

13.    线程与进程的区别和联系? 线程是否具有相同的堆栈? dll是否有独立的堆栈?

答案：进程和线程都是由操作系统所体会的程序运行的基本 单元，系统利用该基本单元实现系统对应用的并发性。

进程和线程的主要差别在于它们是不同的操作系统资源 管理方式。进程有独立的地址空间，一个进程崩溃后，在保护模式下不会对其它进程产生影响，而线程只是一个进程中的不同执行路径。线程有自己的堆栈和局部变 量，但线程之间没有单独的地址空间，一个线程死掉就等于整个进程死掉，所以多进程的程序要比多线程的程序健壮，但在进程切换时，耗费资源较大，效率要差一 些。但对于一些要求同时进行并且又要共享某些变量的并发操作，只能用线程，不能用进程。

14.    列举几种进程的同步机制，并比较其优缺点。 进程之间通信的途径 进程死锁的原因 死锁的4个必要条件 死锁的处理

答案：同步机制：原子操作，信号量机制，自旋锁，管程，会合，分布式系统

进程之间通信的途径：共享存储系统消息传递系统管道：以文件系统为基础

进 程死锁的原因：资源竞争及进程推进顺序非法

死锁的4个必要条 件：互斥、请求保持、不可剥夺、环路

死锁的处理：鸵鸟策略、预防策略、避免策略、检测与解除死锁

15.    堆和栈的区别

答案：管理方式：对于栈来讲，是由编译器自动管理，无需我们手工控制；对于堆来说，释放工作由程序员控制，容易产生memory leak。

申请大小：栈：在Windows下,栈是向低地址扩展的数据结构，是一块连续的内存的区域。这句话的意思是栈顶的地址和栈的最大容量是系统 预先规定好的，在WINDOWS下，栈的大小是2M（也有的说是1M，总之是一个编译时就确定的常数），如果申请的空间超过栈的剩余空间时，将提示 overflow。因此，能从栈获得的空间较小。

堆：堆是向高地址扩展的数据结构，是不连续的内存区域。这是由于系统是用链表来存储的空闲内存地 址的，自然是不连续的，而链表的遍历方向是由低地址向高地址。堆的大小受限于计算机系统中有效的虚拟内存。由此可见，堆获得的空间比较灵活，也比较大。

碎片问题：对于堆来讲，频繁的new/delete势必会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个 问题，因为栈是先进后出的队列，他们是如此的一一对应，以至于永远都不可能有一个内存块从栈中间弹出

分配方式：堆都是动态分配的，没有静态分配的堆。栈有2种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由 alloca函数进行分配，但是栈的动态分配和堆是不同的，他的动态分配是由编译器进行释放，无需我们手工实现。

分配效率：栈是机器系统提供的数据结构，计算机会在底层对栈提供支持：分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的 效率比较高。堆则是C/C++函数库提供的，它的机制是很复杂的。

16.    什么是键-值,键路径是什么

答案：模型的性质是通过一个简单的键（通常是个字符串）来指定的。视图和控制器通过键 来查找相应的属性值。在一个给定的实体中，同一个属性的所有值具有相同的数据类型。键-值编码技术用于进行这样的查找—它是一种间接访问对象属性的机制。

键路径是一个由用点作分隔符的键组成的字符串，用于指定一个连接在一起的对象性 质序列。第一个键的性质是由先前的性质决定的，接下来每个键的值也是相对于其前面的性质。键路径使您可以以独立于模型实现的方式指定相关 对象的性质。通过键路径，您可以指定对象图中的一个任意深度的路径，使其指向相关对象的特定属性。

17.    c和obj-c如何混用

答案：1）obj-c的编译器处理后缀为m的文件时，可以识别obj-c和c的代码， 处理mm文件可以识别obj-c,c,c++代码，但cpp文件必须只能用c/c++代码，而且cpp文件include的头文件中，也不能出现obj- c的代码，因为cpp只是cpp。

2) 在mm文件中混用cpp直接使用即可，所以obj-c混cpp不是问题

3）在cpp中混用obj- c其实就是使用obj-c编写的模块是我们想要的。

如果模块以类实现，那么要按照cpp class的标准写类的定义，头文件中不能出现obj-c的东西，包括#import cocoa的。实现文件中，即类的实现代码中可以使用obj-c的东西，可以import,只是后缀是mm。如果模块以函数实现，那么头文件要按 c的格式声明函数，实现文件中，c++函数内部可以用obj-c，但后缀还是mm或m。

总结：只要cpp文件和cpp include的文件中不包含obj-c的东西就可以用了，cpp混用obj-c的关键是使用接口，而不能直接使用实现代码，实际上cpp混用的是 obj-c编译后的o文件，这个东西其实是无差别的，所以可以用。obj-c的编译器支持cpp.

18.    目标-动作机制

答案：目标是动作消息的接收者。一个控件，或者更为常见的是它的单元，以插座变量（参 见"插座变量"部分）的形式保有其动作消息的目标。

动作是控件发送给目标的消息，或者从目标的角度看，它是目标为了响应动作而实现的方法。程序需要某些机制来进行事件和指令的翻译。这个机制就是目标-动作机制。

19.    cocoa touch框架

答案：iPhone OS 应用程序的基础 Cocoa Touch 框架重用了许多 Mac 系统的成熟模式，但是它更多地专注于触摸的接口和优化。UIKit 为您提供了在 iPhone OS 上实现图形，事件驱动程序的基本工具，其建立在和 Mac OS X 中一样的 Foundation 框架上，包括文件处理，网络，字符串操作等。

Cocoa Touch 具有和 iPhone 用户接口一致的特殊设计。有了 UIKit，您可以使用 iPhone OS 上的独特的图形接口控件，按钮，以及全屏视图的功能，您还可以使用加速仪和多点触摸手势来控制您的应用。

各色俱全的框架 除了 UIKit 外，Cocoa Touch 包含了创建世界一流 iPhone 应用程序需要的所有框架，从三维图形，到专业音效，甚至提供设备访问 API 以控制摄像头，或通过 GPS 获知当前位置。Cocoa Touch 既包含只需要几行代码就可以完成全部任务的强大的 Objective-C 框架，也在需要时提供基础的 C 语言 API 来直接访问系统。这些框架包括：

Core Animation：通过 Core Animation，您就可以通过一个基于组合独立图层的简单的编程模型来创建丰富的用户体验。

Core Audio：Core Audio 是播放，处理和录制音频的专业技术，能够轻松为您的应用程序添加强大的音频功能。

Core Data：提供了一个面向对象的数据管理解决方案，它易于使用和理解，甚至可处理任何应用 或大或小的数据模型。

下面是 Cocoa Touch 中一小部分可用的框架：

音频和视频：Core Audio、OpenAL、Media Library、AV Foundation

数据管理：Core Data、SQLite

图形和动画：Core Animation、OpenGL ES、Quartz 2D

网络/li>：onjour、WebKit、BSD Sockets

用户应用：Address Book、Core Location、ap Kit、tore Kit

20.    objc的内存管理

答案：1、 如果您通过分配和初始化（比如[[MyClass alloc] init]）的方式来创建对象，您就拥有这个对象，需要负责该对象的释放。这个规则在使用NSObject的便利方法new 时也同样适用。

2、如果您拷贝一个对象，您也拥有拷贝得到的对象，需要负责该对象的释放。

3、 如果您保持一个对象，您就部分拥有这个对象，需要在不再使用时释放该对象。 反过来， 如果您从其它对象那里接收到一个对象，则您不拥有该对象，也不应该释放它（这个规则有少数的例外，在参考文档中有显式的说明）。

21.    自动释放池是什么,如何工作

答案：当您向一个对象发送一个autorelease消息时，Cocoa就会将该对 象的一个引用放入到最新的自动释放池。它仍然是个正当的对象，因此自动释放池定义的作用域内的其它对象可以向它发送消息。当程序执行到作用域结束的位置时，自动释放池就会被释放，池中的所有对象也就被释放。

1.  ojc-c 是通过一种"referring counting"(引用计数)的方式来管理内存的, 对象在开始分配内存(alloc)的时候引用计数为一,以后每当碰到有copy,retain的时候引用计数都会加一, 每当碰到release和autorelease的时候引用计数就会减一,如果此对象的计数变为了0, 系统才会调用dealloc真正销毁这个对象.

2. NSAutoreleasePool 就是用来做引用计数的管理工作的,这个东西一般不用你管的.

3. autorelease和release没什么区别,只是引用计数减一的时机不同而已,autorelease会在对象的使用真正结束的时候才做引用计数减一.

22.    类工厂方法是什么 （就是便利构造器）

答案：类工厂方法的实现是为了向客户提供方便，它们将分配和初始化合在一个步骤中， 返回被创建的对象，并进行自动释放处理。这些方法的形式是+ (type)className...（其中 className不包括任何前缀）。

工厂方法可能不仅仅为了方便使用。它们不但可以将分配和初始化合在一起，还可以为初始化过程提供对象的分配信息。

类工厂方法的另一个目的是使类（比如NSWorkspace）提供单件实例。虽 然init...方法可以确认一个类在每次程序运行过程只存在一个实例，但它需要首先分配一个“生的”实例，然后还必须释放该实例。

工厂 方法则可以避免为可能没有用的对象盲目分配内存。

23.    单件实例是什么

答案：Foundation 和 Application Kit 框架中的一些类只允许创建单件对象，即这些类在当前进程中的唯一实例。举例来说，NSFileManager 和NSWorkspace 类在使用时都是基于进程进行单件对象的实例化。当向这些类请求实例的时候，它们会向您传递单一实例的一个引用，如果该实例还不存在，则首先进行实例的分配 和初始化。 单件对象充当控制中心的角色，负责指引或协调类的各种服务。如果类在概念上只有一个实例（比如NSWorkspace），就应该产生 一个单件实例，而不是多个实例；如果将来某一天可能有多个实例，您可以使用单件实例机制，而不是工厂方法或函数。

24.    动态绑定

答案：动态绑定——在运行时确定要调用的方法。动态绑定将调用方法的确定也推迟到运行时。在编译时，方法的调用并不和代码绑定 在一起，只有在消实发送出来之后，才确定被调用的代码。通过动态类型和动态绑定技术，您的代码每次执行都可以得到不同的结果。运行时因子负责确定消息的接收者和被调用的方法。运行时的消息分发机制为动态绑定提供支持。当您向一个动态类型确定了的对象发送消息时，运行环境系统会通过接收者的isa指针定位对象的类，并以此为起点 确定被调用的方法，方法和消息是动态绑定的。而且，您不必在Objective-C 代码中做任何工作，就可以自动获取动态绑定的好处。您在每次发送消息时，特别是当消息的接收者是动态类型已经确定的对象时，动态绑定就会例行而 透明地发生。

25.    obj-c的优缺点

答案：objc优点： 1) Cateogies 2) Posing （）3) 动态识别4) 指标计算  5）弹性讯息传递 6) 不是一个过度复杂的 C 衍生语言 7) Objective-C 与 C++ 可混合编程

缺点: 1) 不支援命名空間   2)  不支持运算符重载 3） 不支持多重继承  4） 使用动态运行时类型，所有的方法都是函数调用，所以很多编译时优化方法都用不到。（如内联函等），性能低劣。

26.    sprintf,strcpy,memcpy使用上有什么要注意的地方

答案：strcpy是一个字符串拷贝的函数，它的函数原型为strcpy(char *dst, const char *src);将src开始的一段字符串拷贝到dst开始的内存中去，结束的标志符号为 '\0'，由于拷贝的长度不是由我们自己控制的，所以这个字符串拷贝很容易出错。

具备字符串拷贝功能的函数有memcpy，这是一个内存拷贝函数，它的函 数原型为memcpy(char *dst, const char* src, unsigned int len);将长度为len的一段内存，从src拷贝到dst中去，这个函数的长度可控。但 是会有内存叠加的问题。

sprintf是格式化函数。将一段数据通过特定的格式，格式化到一个字符串缓 冲区中去。sprintf格式化的函数的长度不可控，有可能格式化后的字符串会超出缓冲区的大小，造成溢出。

27.    用变量a给出下面的定义

a)      一个整型数（An integer）

b)     一个指向整型数的指针（ A pointer to an integer）

c)      一个指向指针的的指针，它指向的指针是指向一个整型数（ A pointer to a pointer to an intege）r

d)     一个有10个整型数的数组（ An array of 10 integers）

e)      一个有10个指针的数组，该指针是指向一个整型数的。（An array of 10 pointers to integers）

f)       一个指向有10个整型数数组的指针（ A pointer to an array of 10 integers）

g)     一个指向函数的指针，该函数有一个整型参数并返回一个整型数（A pointer to a function that takes an integer as an argument  and returns an integer）

h)     一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数（ An array of ten pointers to functions t hat take an integer argument and return an integer ）

答案：

a) int a; // An integer

b) int *a; // A pointer to an integer

c) int **a; // A pointer to a pointer to an integer

d) int a[10]; // An array of 10 integers

e) int *a[10]; // An array of 10 pointers to integers

f) int (*a)[10]; // A pointer to an array of 10 integers

g) int (*a)(int); // A pointer to a function a that  takes an integer argument and returns an integer

h) int (*a[10])(int); // An array of 10 pointers to functions  that take an integer argument and return an integer

28.    cocoa有哪些设计模式?

答案：

29.    socket编程中如何判断异步connect是否成功

答案:创建一个socket,设为异步socket（fcntl）,将socket加入epoll,connect到远端（此时connect调用返回非0，但errno为EINPROGRESS，表示正在建立连接中）

epoll_wait之捕获到EPOLLOUT事件，此时便认为connect已经成功，client端开始发消息

这个过程通常能够运转，但是线上环境复杂多变，如果发生这种情况：server进程调用listen开始侦听后，被gdb或信号挂住了，此时异步connect会怎样？很遗憾，client端的epoll_wait依然返回EPOLLOUT，甚至往此socket里发消息都返回成功，只有当发的消息多得占完了server端的tcp缓冲以后（窗口收缩到很小），send调用才开始失败。这时候用 losf -i 看网络连接也很有趣，client端的机器显示连接建立了，server端的却显示没有这个连接。

仔细想想，OS这样做是正确的，毕竟connect的语义只是“连接”，当server挂住时，连接还是能成功的，但你能不能往里面发消息那就是另外一回事了。

所以对于应用来说，异步socket想要知道connect后连接是不是可以正常收发数据了，还是要靠应用层的一问一答才能知道。

30.    [[[nil retain]retain]release]有什么问题

答案：没有问题

31.    cocoa架构

答案：

32.    readwrite，readonly，assign，retain，copy，nonatomic 属性的作用

答案：@property是 一个属性访问声明，扩号内支持以下几个属性：

1.   getter=getterName，setter=setterName，设置setter与 getter的方法名

2.   readwrite,readonly，设置可供访问级别

3.   assign，setter方法直接赋值，不进行 任何retain操作，为了解决原类型与环循引用问题

4.   retain，setter方法对参数进行release旧值再retain新值，所有 实现都是这个顺序(CC上有相关资料)

5.   copy，setter方法进行Copy操作，与retain处理流程一样，先旧值release，再 Copy出新的对象，retainCount为1。这是为了减少对上下文的依赖而引入的机制。

6.   nonatomic，非原子性访问，不加同步， 多线程并发访问会提高性能。注意，如果不加此属性，则默认是两个访问方法都为原子型事务访问。锁被加到所属对象实例级(我是这么理解的...)。

二、（一共九题）

1.   络编程中设计并发服务器，使用多进程与多线程，请问有什么区别？

a)       答1)进程：子进程是父进程的复制品。子进程获得父进程数据空间、堆和栈的复制品。2)线程：相对与进程而言，线程是一个更加接近与执行体的概念，它可以与同进程的其他线程共享数据，但拥有自己的栈空间，拥有独立的执行序列。

线程和进程在使用上各有优缺点：线程执行开销小，但不利于资源管理和保护；而进程正相反。同时，线程适合于在SMP机器上运行，而进程则可以跨机器迁移。

2.       数组a[N]，存放了1至N-1个数，其中某个数重复一次。写一个函数，找出被重复的数字.时间复杂度必须为o（N）函数原型：int do_dup(int a[],int N)

答:int do_dup(int a[],intN)

{

int sum= 0;

int sum2;

for(int i=0;i<N;++i)

{
    
    Sum+=a[i];
    
}

Sum2 = (1+N-1)*N/2;

Return (sum-sum2);

}

3.       一语句实现x是否为2的若干次幂的判断

答:

方法1)int i = 512;

cout << boolalpha<< ((i & (i - 1)) ?false : true) << endl;//位与为0,则表示是2的若干次幂

方法2)return (x>>N==1);

4.       unsigned int intvert(unsigned int x,int p,intn)实现对x的进行转换,p为起始转化位,n为需要转换的长度,假设起始点在右边.如x=0b00010001,p=4,n=3转换后x=0b0110 0001

答:unsigned int intvert(unsigned int x,int p,int n)//假定p=4,n=3

unsigned int _t = 0;unsigned int _a = 1;

for(int i = 0; i <n; ++i)//循环的目的主要是-t_t |=_a;

_a = _a<<1;

_t = _t<<p;  //转换后_t变为1110000

x ^=_t;

return x;

5.       什么是预编译，何时需要预编译?

答：预编译又称为预处理 , 是做些代码文本的替换工作。处理 # 开头的指令 , 比如拷贝 #include 包含的文件代码， #define 宏定义的替换 , 条件编译等，就是为编译做的预备工作的阶段，主要处理#开始的预编译指令，预编译指令指示了在程序正式编译前就由编译器进行的操作，可以放在程序中的任何位置。c 编译系统在对程序进行通常的编译之前，先进行预处理。c 提供的预处理功能主要有以下三 种： 1 ）宏定义　 2 ）文件包含　 3 ）条件编译。

6.       下述三个有什么区别？

char * const p;

char const * p

const char *p

char * const p; //常量指针，p的值不可以修改

char const * p；//指向常量的指针，指向的常量值不可以改

const char *p； //和char const *p

7.       解释下列输出结果

char str1[] = "abc";char str2[] = "abc";const char str3[] = "abc";

const char str4[] = "abc";const char *str5 = "abc";

const char *str6 = "abc";char *str7 = "abc";char *str8 = "abc";

cout << ( str1 == str2 )<< endl;cout << ( str3 == str4 )<< endl;

cout << ( str5 == str6 )<< endl;cout << ( str7 == str8 )<< endl;

结果是：0 0 1 1

解答：str1,str2,str3,str4是数组变量，它们有各自的内存空间；而str5,str6,str7,str8是指针，它们指向相同的常量区域。

8.       以下代码中的两个sizeof用法有问题吗？[C易]

void UpperCase( char str[] ) // 将 str 中的小写字母转换成大写字母

for( size_t i=0; i<sizeof(str)/sizeof(str[0]);++i )

if( 'a'<=str[i]&& str[i]<='z'str[i] -= ('a'-'A' );
   
   char str[] = "aBcDe";
   
   cout << "str字符长度为: "<< sizeof(str)/sizeof(str[0])<< endl;
   
   UpperCase( str );
   
   cout << str<< endl;
   
   答：函数内的sizeof有问题。根据语法，sizeof如用于数组，只能测出静态数组的大小，无法检测动态分配的或外部数组大小。函数外的str是一个静态定义的数组，因此其大小为6，函数内的str实际只是一个指向字符串的指针，没有任何额外的与数组相关的信息，因此sizeof作用于上只将其当指针看，一个指针为4个字节，因此返回4。
   
   注意:数组名作为函数参数时,退化为指针.数组名作为sizeof()参数时,数组名不退化,因为sizeof不是函数.
   
   三、（一共十六题）
   
   1.       objective-c中是所有对象间的交互是如何实现的?（深圳皆凯科技有限公司笔试题）
   
   2.       如何将产品进行多语言发布？
   
   3.       objective-c中是如何实现线程同步的?
   
   4.       编写函数_memmove说明如下：实现C语言库函数memmove的功能：将一块缓冲区中的数据移动到另一块缓冲区中。可能有重复。
   
   5.       什么叫数据结构？（面试顺风快递iPhone开发）
   
   6.       编程中，保存数据有哪几种方式？
   
   7.       Sizeof与strlen的区别和联系？
   
   答案：
   
   1.       sizeof操作符的结果类型是size_t，它在头文件中typedef为unsigned　int类型。该类型保证能容纳实现所建立的最大对象的字节大小。
   
   2.       sizeof是算符，strlen是函数。
   
   3.       sizeof可以用类型做参数，strlen只能用char*做参数，且必须是以''\0''结尾的。
   
   4.       数组做sizeof的参数不退化，传递给strlen就退化为指针了。
   
   5.       大部分编译程序在编译的时候就把sizeof计算过了 是类型或是变量的长度这就是sizeof(x)可以用来定义数组维数的原因
   char str[20]="0123456789";//str是编译期大小已经固定的数组
   int a=strlen(str); //a=10;//strlen()在运行起确定
   int b=sizeof(str); //而b=20;//sizeof()在编译期确定
   
   6.       strlen的结果要在运行的时候才能计算出来，是用来计算字符串的实际长度，不是类型占内存的大小。
   
   7.       sizeof后如果是类型必须加括弧，如果是变量名可以不加括弧。这是因为sizeof是个操作符不是个函数。
   
   char c;
   
   sizeof c;//变量名可以不加括弧
   
   8.       当适用了于一个结构类型时或变量， sizeof 返回实际的大小， 当适用一静态地空间数组， sizeof 归还全部数组的尺寸。sizeof 操作符不能返回动态地被分派了的数组或外部的数组的尺寸
   
   9.       数组作为参数传给函数时传的是指针而不是数组，传递的是数组的首地址，如：
   
   fun(char [8])
   fun(char [])
   都等价于 fun(char *)
   在C++里参数传递数组永远都是传递指向数组首元素的指针，编译器不知道数组的大小
   如果想在函数内知道数组的大小， 需要这样做：
   进入函数后用memcpy拷贝出来，长度由另一个形参传进去
   fun(unsiged char *p1, int len)
{
    unsigned char* buf = new unsigned char[len+1]
    memcpy(buf, p1, len);
}
   
   我们能常在用到 sizeof 和 strlen 的时候，通常是计算字符串数组的长度
   
   看了上面的详细解释，发现两者的使用还是有区别的，从这个例子可以看得很清楚：
   
   har str[11]="0123456789";//注意这里str大小因该大于等于11，应考虑'\0'在内，否则编译器会报错
   
   int a=strlen(str); //a=10; >>>> strlen 计算字符串的长度，以结束符 0x00 为字符串结束。
   int b=sizeof(str); //而b=11; >>>> sizeof 计算的则是分配的数组 str[11] 所占的内存空间的大小，不受里面存储的内容改变。
   
   上面是对静态数组处理的结果，如果是对指针，结果就不一样了
   
   char* ss = "0123456789";
   sizeof(ss) 结果 4 ＝＝＝》ss是指向字符串常量的字符指针，sizeof 获得的是一个指针的之所占的空间,应该是长整型的，所以是4
   sizeof(*ss) 结果 1 ＝＝＝》*ss是第一个字符 其实就是获得了字符串的第一位'0' 所占的内存空间，是char类型的，占了 1 位strlen(ss)= 10 >>>> 如果要获得这个字符串的长度，则一定要使用 strlen另外,下面的方法可以用于确定该静态数组可以容纳元素的个数int a[3]={1,2,3};
   cout << sizeof a/sizeof ( typeid( a[0] ).name() );
   
   8.       什么是抽象类？抽象类有什么作用？能实例化吗？
   
   9.       用Objective-C写冒泡法．
   
   10.    考察对@interface和@property的理解？
   
   11.    IPhone开发中控制类有什么作用？
   
   12.    线程中有哪些函数？写出来。
   
   13.    有没有写过自定义的控件？
   
   14.    调用一个类的静态方法需不需要release？
   
   15.    do-while 与 while-do的区别？
   
   16.    写出几个死循环？
   
   答案：while(1){}
   
   或者do{}while(1)
   
   再或者for(;1;){}
   
   还有goto的
   
   Loop:
   
   …
   
   goto Loop;
   
   四、（一共十八题）
   
   1.       ObjC中，与alloc语义相反的方法是dealloc还是release？与retain语义相反的方法是dealloc还是release，为什么？需要与alloc配对使用的方法是dealloc还是release，为什么？
   
   答案：：alloc与dealloc语意相反，alloc是创建变量，dealloc是释放变量。 retain 对应release,retain 保留一个对象。调用之后，变量的计数加1。或许不是很明显，在这有例为证：
   
   (void) setName : (NSString*) name {
       
       [name retain];
       
       [myname release];
       
       myname = name;
       
   }
   
   我们来解释一下：设想，用户在调用这个函数的时候，他注意了内存的管理，所以他小心的写了如下代码：
   
   NSString * newname = [[NSString alloc] initWithString: @"John"];
   
   [aClass setName: newname];
   
   [newname release];
   
   我们来看一看newname的计数是怎么变化的。首先，它被alloc，count = 1; 然后，在setName中，它被retain， count = 2; 最后，用户自己释放newname，count = 1，myname指向了newname。这也解释了为什么需要调用[myname release]。我们需要在给myname赋新值的时候，释放掉以前老的变量。retain 之后直接dealloc对象计数器没有释放。alloc 需要与release配对使用，因为alloc 这个函数调用之后，变量的计数加1。所以在调用alloc 之后，一定要调用对应的release。另外，在release一个变量之后，他的值仍然有效，所以最好是后面紧接着再var = nil。
   
   在一个对象的方法里面:
   
   2.       self.name = “object”; 和 name ＝”object” 有什么不同吗?
   
   答案：：self.name = "object"会调用对象的setName()方法，name = "object"会直接把object赋值给当前对象的name 属性。
   
   [backcolor=transparent][backcolor=transparent]
   
   3.       这段代码有什么问题吗:
   
   [backcolor=transparent]@implementation Person
   
   [backcolor=transparent]- (void)setAge:(int)newAge {
       
       [backcolor=transparent]self.age = newAge;
       
       [backcolor=transparent]}
   
   [backcolor=transparent]@end
   
   答案：会进入死循环。
   
   4.       什么是retain count?
   
   答案：：引用计数(ref count或者retain count)。对象的内部保存一个数字，表示被引用的次数。例如，某个对象被两个指针所指向（引用）那么它的retain count为2。需要销毁对 象的时候，不直接调用dealloc，而是调用release。release会 让retain count减1，只有retain count等于0，系统才会调用dealloc真正销毁这个对象。
   
   5.       以下每行代码执行后，person对象的retain count分别是多少
   
   Person *person = [[Person alloc] init]; count 1
   
   [person retain]; count 2
   
   [person release];count 1
   
   [person release];retain count = 1;
   
   6.       为什么很多内置类如UITableViewController的delegate属性都是assign而不是retain的？
   
   答案：会引起循环引用。
   
   7.       定义属性时，什么情况使用copy，assign，和retain 。
   
   答案：assign用于简单数据类型，如NSInteger,double,bool,retain 和copy用户对象，copy用于当 a指向一个对象，b也想指向同样的对象的时候，如果用assign，a如果释放，再调用b会crash,如果用copy 的方式，a和b各自有自己的内存，就可以解决这个问题。retain 会使计数器加一，也可以解决assign的问题。另外：atomic和nonatomic用来决定编译器生成的getter和setter是否为原子操作。在多线程环境下，原子操作是必要的，否则有可能引起错误的结果。加了atomic，setter函数会变成下面这样：
   
   if (property != newValue) {       [property release];       property = [newValue retain];   }
   
   8.       Autorelease的对象是在什么时候被release的？
   
   答案：autorelease实际上只是把对release的调用延迟了，对于每一个Autorelease，系统只是把该Object放入了当前的Autorelease pool中，当该pool被释放时，该pool中的所有Object会被调用Release。对于每一个Runloop， 系统会隐式创建一个Autorelease pool，这样所有的release pool会构成一个象CallStack一样的一个栈式结构，在每一个Runloop结束时，当前栈顶的Autorelease pool会被销毁，这样这个pool里的每个Object（就是autorelease的对象）会被release。那什么是一个Runloop呢？ 一个UI事件，Timer call， delegate call， 都会是一个新的Runloop。那什么是一个Runloop呢？ 一个UI事件，Timer call， delegate call， 都会是一个新的Runloop。
   
   9.       这段代码有什么问题,如何修改
   
   for (int i = 0; i < someLargeNumber; i++)
   
{
    
    NSString *string = @”Abc”;
    
    string = [string lowercaseString];
    
    string = [string stringByAppendingString:@"xyz"];
    
    NSLog(@“%@”, string);
    
}答案：：会内存泄露，
   
   修改：
   
   for(int i = 0; i<1000;i++){
       
       NSAutoreleasePool * pool1 = [[NSAutoreleasePool alloc] init];
       
       NSString *string = @"Abc";
       
       string = [string lowercaseString];
       
       string = [string stringByAppendingString:@"xyz"];
       
       NSLog(@"%@",string);
       
       [pool1 drain];
       
   }
   
   你的解决方法效率低，没必要在每个循环都建立autorelease pool。在循环外面建一个就行了。
   
   NSAutoreleasePool * pool1 = [[NSAutoreleasePool alloc] init];
   
   for(int i = 0; i<1000;i++){
       
       NSString *string = @"Abc";
       
       string = [string lowercaseString];
       
       string = [string stringByAppendingString:@"xyz"];
       
       NSLog(@"%@",string);
       
   }
   
   [pool1 release];//[pool1 drain];效果相同，但我更喜欢release，看起来传统一点
   
   10.    autorelease和垃圾回收机制(gc)有什么关系？答案：：不懂
   
   11.    IPhone OS有没有垃圾回收（gc）？没有
   
   12.    什么是Notification？答案：观察者模式，controller向defaultNotificationCenter添加自己的notification，其他类注册这个notification就可以收到通知，这些类可以在收到通知时做自己的操作（多观察者默认随机顺序发通知给观察者们，而且每个观察者都要等当前的某个观察者的操作做完才能轮到他来操作，可以用NotificationQueue的方式安排观察者的反应顺序，也可以在添加观察者中设定反映时间，取消观察需要在viewDidUnload 跟dealloc中都要注销）。参考链接：http://useyourloaf.com/blog/2010/6/6/delegation-or-notification.html
   
   13.    什么时候用delegate，什么时候用Notification？答案：delegate针对one-to-one关系，并且reciever可以返回值给sender，notification 可以针对one-to-one/many/none,reciever无法返回值给sender.所以，delegate用于sender希望接受到reciever的某个功能反馈值，notification用于通知多个object某个事件。
   
   14.    什么是KVC和KVO？答案：KVC(Key-Value-Coding)内部的实现：一个对象在调用setValue的时候，
   
   （1）首先根据方法名找到运行方法的时候所需要的环境参数。
   
   （2）他会从自己isa指针结合环境参数，找到具体的方法实现的接口。
   
   （3）再直接查找得来的具体的方法实现。KVO（Key-Value-Observing）：当观察者为一个对象的属性进行了注册，被观察对象的isa指针被修改的时候，isa指针就会指向一个中间类，而不是真实的类。所以isa指针其实不需要指向实例对象真实的类。所以我们的程序最好不要依赖于isa指针。在调用类的方法的时候，最好要明确对象实例的类名。
   
   15.    Notification和KVO有什么不同？答：不知道
   
   16.    KVO在ObjC中是怎么实现的？答：不知道
   
   17.    ViewController 的 loadView, viewDidLoad, viewDidUnload 分别是在什么时候调用的？在自定义ViewController的时候这几个函数里面应该做什么工作？
   
   答案：viewDidLoad在view 从nib文件初始化时调用，loadView在controller的view为nil时调用。此方法在编程实现view时调用,view 控制器默认会注册memory warning notification,当view controller的任何view 没有用的时候，viewDidUnload会被调用，在这里实现将retain 的view release,如果是retain的IBOutlet view 属性则不要在这里release,IBOutlet会负责release 。
   
   18.    ViewController 的 didReceiveMemoryWarning 是在什么时候被调用的？默认的操作是什么? 答案：默认调用[super didReceiveMemoryWarning]
   
   五、一共七题
   
   1.       Objective-C的内存管理方式, NSAutoreleasePool的作用
   
   2.       写一个retain方式声名属性的setter方法
   
   3.       Objective-C与C的区别有哪些
   
   4.       列出你常用的几个设计模式，列出如何在Objective-C中实现与应用
   
   5.       drawRect, lasyoutSubViews的区别
   
   6.       列举Cocoa中常用的几种多线程实现，并谈谈多线程安全问题的几种解决方案，什么地方会用到多线程
   
   7.       Socket连接相关库，TCP，UDP的连接方法，HTTP的几种常用方式
   
   六、一共四题
   
   1.       用Objective-C写冒泡法
   
   2.       Cocoa 函数库的使用
   
   3.       考察对线程的理解
   
   4.       考察对MVC的理解？模型—视图—控制器
   
   七、一共九题
   
   1.       Objective－C内部的实现
   
   2.       CALayer和View的关系
   
   3.        http协议，tcp/ip
   
   4.        UITableView的那些元素是可以自定义的？
   
   5.        c语言的，定义变量，比如int，在什么情况下，其最大值是不同的
   
   6.        比较32位平台和64位平台不同
   
   7.        iPhone app为什么会被打回来，如何避免??
   
   8.        为啥离开团队？
   
   八、一共十题
   
   1.       为什么很多内置类如UITableViewController的delegate属性都是assign而不是retain？
   
   会导致循环引用。
   
   2.       有如下一个类定义
   
   interface MyClass : NSObject
   
{     }
   
   @property(retain) NSString *myProp;
   
   @end
   
   请完成myProp属性的set方法：
   
   -        (void)setMyProp:(NSString *)aProp
   
{
    
    if(myProp!=aPtrop)
        
        [myProp release]
        
        myProp=[aProp retain ]
        
        }
   
   3.       写出下面程序段的输出结果
   
   NSString *aStr = [[[NSString alloc] initWithString:@”Hello World”] autoRelease];
   
   NSMutableArray *aArray = [NSMutableArray array];
   
   [aArray addObject:aStr];
   
   NSLog(@”ref=%d”, [aStr retainCount])
   
   4.       简述Notification的工作机制。
   
   5.       有一个UIView 对象aView，当前大小为全屏。请编写代码实现如下效果：将aView的宽和高各缩小为原来一半，中心点仍在屏幕中心，并在缩小的同时实现渐隐。
   
   
   
   6.       写出下面程序段的输出结果
   
   NSDictionary *dict = [NSDictionary dictionaryWithObject:@"a string value" forKey:@"akey"];
   
   NSLog(@"%@", [dict objectForKey:@"akey"]);
   
   [dict release];
   
   7.       @class关键字有什么作用
   
   8.       不使用继承，为NSStirng类添加新方法 myPrint。
   
   9.       写出下面程序段的输出结果
   
   NSArray array = [NSArray arrayWithObjects:@"one",@"two",@"three",nil];
   
   NSLog(@"％@", [array objectAtIndex:1]);
   
   NSLog(@"%@", [array objectAtIndex:3]);
   
   
   语法问题？
   
   coreplot第三方库 用于画图像 柱形 折线 饼状之类的 用于股票的
   
   cocoachina  stack overflow code4app
   
   
   
   类别有什么作用？
   
   类别有三大作用：1 可以使本来需要在.h中声明的方法放到.m文件中声明，使方法变成私有。 2 可以扩展或覆盖一个类的功能，包括系统类，维护了代码原本的结构不受影响。3 可以分散代码到不同的文件之中，比如系统类库里有一个NSObject的类别，并没有写在NSObject类里，而写到另外一个类里，主要是因为这个类别扩展的功能跟那个类相关，便于将来查看。
   
   
   举例：如何让一个导航条加一个背景图。
   
   以下“自定义的类别”就是针对 UINavigationBar系统类的，覆盖了其系统方法  (void) drawRect:(CGRect)rect，将来导航栏显示的时，方法 drawRect会自动调用，达到把图片显示到导航栏中。
   
   @interface UINavigationBar (MyCustomNavBar)
   
   
   @end
   
   @implementation UINavigationBar (MyCustomNavBar)
   
   - (void) drawRect:(CGRect)rect {
       
       UIImage *barImage = [UIImage imageNamed:@"nav11.png"];
       
       [barImage drawInRect:rect];
       
   }
   
   @end
   
   //5.0之上的用下面这个方法
   
   [navcontroller.navigationBar setBackgroundImage:[UIImage imageNamed:@"1.png"] forBarMetrics:UIBarMetricsDefault];
   
   
   
   如果是改变导航条的前景颜色则很简单
   
   nav.navigationBar.tintColor=[UIColor redColor];
   
   
   
   
   1.协议是什么？
   
   协议很像java中的接口，某个类实现协议后，就必须实现协议中规定的@require的方法，
   
   @optional的方法是可选的。
   
   比如一个类A, 一个类B都实现某“协议”后，这个类A的对象和B的对象都可以赋值给这个协议的类型变量，比如  id<协议> 变量名 = A类对象／B类对象， 于是这个变量就完成了能够指向多个不同的类的对象并调用对象中的实现协议的方法。
   
   
   2.委托是什么？
   
   答：委托就是一个对象要求另外一个对象（委托对象）执行对他的操作。
   
   举例： 在一个控制器里弹出了一个提示框(UIActionSheet)，提示框是一个对象，当点提   示框的某个按钮时，干什么功能是委托给原控制器来处理，原控制器就是委托对象，这个提示框就是被委托对象。
   
   
   
   你平时开发的时候，如何进行内存管理的？
   
   
   平时开发的时候遵守谁创建谁释放的原则，前期进行手工的释放，比如alloc, copy,new创建对象使用完毕后要relase。 retian（获得对象使用权）和 release（释放对象使用权）要配对，dealloc里释放实例变量。 后期用内存检测工具，比如leaks 或clang（3.25以上版本） 检测工具检测内存泄露问题，leaks检测没有clang准确。
   
   
   所谓谁创建谁释放，谁保留谁释放的原则是，比如一个类的方法将返回一个alloc创建的对象，在返回时给这个对象加上autorelease，就是为了维护谁创建谁释放的原则。在另外的类调用此方法得到对象时候，为了能够安全使用，则将此对象retain（保留），用完之后进行release。
   
   
   还比如如果手工创建一个UILabel对象（引用计数为1），添加到视图中后，引用计数会增加1一次(系统内部将其retain了一次)，手工release之后, 这个UILabel的最终释放权由self.view决定，当控制器被释放时，dealloc方法会被调用，内部[super dealloc]会完成视图的卸载，视图卸载时会将其子视图（那个UILabel对象）再释放一次。
   
   
   
   
   
   
   
   11.是不是任何对象都可以被copy，什么样的对象可以被copy？什么时候常用copy属性，哪些常用assign？   Retain,copy属性的底层实现是什么？
   
   1，不是，只有实现了NSCopying协议的类的对象才能被拷贝
   
   
   NSCopying协议方法为：- (id)copyWithZone:(NSZone *)zone {
       
       
       
       MyObject *copy = [[[self class] allocWithZone: zone] init];
       
       
       copy.username = [self.username copyWithZone:zone];
       
       
       
       return copy;
       
   }
   
   
   2，字符串的赋值时，常用copy，原因是字符串的内存创建比较特殊，对于NSString *s1=@”111”;  NSString *s2=@”111”;这种创建对象方式会造成内存地址共享，s1和s2完全指向同一个地址空间，也就是同一个对象了，改变或释放这个地址空间的内容就意味着s1和s2都变了。为了避免修改一方影响到另外一方，字符串赋值时常copy一个新的对象比较安全。
   
   
   3，基本类型（简单类型）的变量赋值只能用assign。对象使用assign属性常见于delegate(不会增加引用计数), 而不是retain, 主要目的是为了避免循环引用的问题。在电话会议里出现过类似问题，创建一个控制器对象被压栈后如果释放一次，将来出栈后控制器对象会被释放(dealloc被调用)， 但是如果你这么做了却在出栈后发现dealloc没有被调用，出现这情况是控制器对象在创建初始化的时候使用了自定义的表对象，并且把本控制对象赋给表对象属性时被retain了，导致控制器引用技术增加，所以将来出栈也无法释放了，应将retain修改为release.
   
   
   造成循环引用的问题：
   
   比如创建了对象a，  对象a 中创建并保留了对象b，而对象b的delegate属性又保留了对象a, 如果这个delegate是retain，那基本上就没有机会释放这两个对象了，所以使用assign.
   
   
   4，一个描述为copy的属性被赋值的set方法
   
   -(void)setObject :(MyObject *)test{
       
       if(object!=test){
           
           [object release];
           
           object= [test copy];
           
       }
       
   }
   
   
   
   5，一个描述为retain的属性被赋值的set方法
   
   -(void)seStr:(MyObject *)test{
       
       if(object2!=test){
           
           [object2 release];
           
           object2= [test retain]  ;
           
       }
       
   }
   
   
   6.自动释放池？
   
   
   1系统释放池在哪定义，什么时候调用？
   
   在main.m中定义如下：
   
   int main(int argc, char *argv[]) {
       
       NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
       
       int retVal = UIApplicationMain(argc, argv, nil, nil);
       
       [pool release];
       
       return retVal;
       
   }
   
   整个主线程中的所有的autorelease对象都会自动放入系统pool中，在基于appliction Kit的程序中 并不是在程序结束的时候才释放掉 系统池中的autorelease对象的，是在程序进行中 例如一个事件周期内 会释放自动释放池的东西,
   
   
   2.为什么启动线程的方法内要用到自动释放池？
   
   在线程方法内不创建线程池，会在控制台有警告。系统认为分线程是独立运行，需要有一个独立的 NSAutoreleasePool。
   
   
   3.除了线程方法内部，还有在什么时候需要创建局部自动释放池？
   
   在局部产生大量自动释放的对象时候，可以用自动释放池提前释放部分自动释放的对象。
   
   NSArray *someArray;
   
   -(void) threadAutoreleasePool{
       
       
       
       NSAutoreleasePool *pool =[[NSAutoreleasePool alloc] init];
       
       
       
       for(int i = 0; i<1000000; i++){
           
           id object = [someArray objectAtIndex:i];
           
           //这个对象是带有autorelease
           
           NSString *desc = [object description];
           
           
           
           //在局部自动释放池中每积压一千个对象，让池释放一次
           
           if(i%1000 == 0){
               
               [pool   release];
               
               pool = [[NSAutoreleasePool alloc] init];
               
           }
           
       }
       
   }
   
   
   
   
   
   ui 问题
   
   1,   表中的常见委托方法，能说出表的大部分委托方法的功能
   
   
   2，如何实现一个跑马灯
   
   
   
   3 得到导航器里面所包含的控制器？
   
   NSArray *allControllers = self.navigationController.viewControllers;
   
   这句话可以返回一个数组，数组里有导航栏里的视图控制器
   
   
   
   
   
   4 view的frame和bounds的区别
   
   frame和bounds在大小方面是没有区别的，区别在于两者的相对坐标不同 bounds是相对自己本身窗口的坐标
   
   而frame是相对这个view的父视图的坐标
   
   
   7，UITableView中的单元格在初始化的时候就会默认为自动释放 那么这个单元格是在什么时候释放的
   
   
   单元格对象创建之后，附加了autorelease, 于是单元格对象会被放到内部自动释放池中。单元格肯定要被添加到表中的，引用技数会又增加一次，于是单元格对象不会消失。当表视图被释放，表所管理的所有单元格会被释放一次。自动释放池又会在将来把池中的单元格对象再释放一次以达到将单元格对象最终释放。
   
   
   
   5.1  view的touch事件有哪些？有四个
   
   
   
   - (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
   
   - (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
   
   - (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event; (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;
   
   
   
   segment怎么切换视图?
   
   UISegmentController可以绑定方法，方法被调用后可以获得segment的索引，从而判断哪个视图将被显示，于是可以将原视图从父视图中删除，添加新视图。
   
   
   时间picker有几种形式？4种形式
   
   data, time  data&time   timer
   
   
   
   你使用过哪些自定义的UI控件？
   
   1，自定义UILabel子类实现跑马灯。
   
   2，自定义UIImageView子类(扩展了属性)实现类似j2me的下雪。
   
   3，自定义 UIView实现系统UIActionSheet类。
   
   4,   自定义带背景颜色的picker选择器。
   
   5，自定义模态进度条(用两个系统控件配合，UIActionSheet类里添加UIProgressView）。
              
              6，自定义可以自动随进度变换颜色的进度条。
              
              7，自定义一个下拉菜单（固定下拉菜单项的数量和使用表实现不限制下拉菜单项的数据）。
              
              8， 自定义一个广告栏，八卦项目中的滚动面板上放置自动缓慢循环滚动的图片视图，手工可以加快滚动，点击可停下显示大图片信息。
              
              
              9，用UIWebView实现自定义浏览器（在显示页面的基础上加个工具栏放点功能按钮就行了）。
              
              
              10，自定义 实现UITabbarController控件，运用字典，点5个按钮的一个可以从字典里选择一个控制器的对象，将其view显示到主控制器视图上。
              
              11,  其他UI控件: 理论上所有系统控件都是可以用UIView自定义去实现其功能，因为 Ui控件都是继承自UIView.
              
              
              
              通信问题？
              
              
              10 Get请求和Post请求的区别
              
              在http通讯协议中默认的就是Get请求，Get请求是在请求地址后加上了要提交的信息， 以问号标记，问号之后追加参数名=参数值，各参数之间用&隔开。 doGet适合数据量比较小，格式简单的，不私密的数据。
              
              对于http报文而言，因为get请求的信息在请求地址后面追加，所以其信息只在http报文的信息头中，http报文实体部分并无数据内容。
              
              
              Post请求适合于比较私密的数据 比如用户名 密码 , 可以提交二进制数据，或大量数据 。 通过post提交的数据在http报文的实体部分。
              
              具体HTTP报文参考之前给的文档。
              
              
              
              
              Socket中的默认连接超时时间是30秒
              
              默认大小是8k，可以理解为一个数据包的极限大小，如果向网络另一端发送的数据超过8k范围，则肯定要被肢解成多个包发送。
              
              
              
              
              3.你平时做项目时怎么实现http协议的通信的？
              
              可以直接使用ASIHttpRequest通讯包，其中的ASIHTTPRequest是父类，继承了NSOpertion类。此通讯包使用CFNetwork框架，内部实现了http协议的封装，可以用于http协议的请求。
              
              
              另外，也可以不使用此通讯包，采用NSURLConnection实现http请求，此类支持同步数据的请求（NSURLConnection sendSynchronousRequest:）和异步数据的请求（[[NSURLConnection alloc] initWithRequest:theRequest delegate:self]）。
              
              
              
              
              
              13.什么是通讯的同步和异步？
              
              通信在主线程中直接请求，服务器返回迟缓可导致程序卡死一直等待服务器回传数据，可以称之为同步。如果启动线程或将请求放入线程或线程队列，则不影响主线程运行，可称为异步。
              
              
              
              问，你连接服务器用的是什么方法，在http请求时，你是如何处理网络问题的？
              
              1，可以先检测网络是否可连接（wifi，WCDMA). 网上有现成的类。
   
   2，如果手机是联网的，如果开发时是使用AsiHttpRequest通信包，可以先获得是否因为请求地址错误而产生NSError错误。
   
   3，在请求过程中，如果超时，AsiHttpRequest通信包有超时提示。
   
   4，如果使用的是NSUrlConnection 请求，如果网络出了问题了，会自动调用其委托方法让你来做相关处理。 (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error{
       
       
       
       http请求的报文？ 404错误 和 500错误分别代表什么错误？
       
       （1）请求行
       
       请求行由请求方法字段、URL字段和HTTP协议版本字段3个字段组成，它们用空格分隔。例如，GET /index.html HTTP/1.1。
       
       HTTP协议的请求方法有GET、POST、HEAD、PUT、DELETE、OPTIONS、TRACE、CONNECT。这里介绍最常用的GET方法和POST方法。
       
       （2）请求头部
       
       Range头返回服务器断点虚传的
       
       请求头部由关键字/值对组成，每行一对，关键字和值用英文冒号“:”分隔。请求头部通知服务器有关于客户端请求的信息，典型的请求头有：
       
       User-Agent：产生请求的浏览器类型。
       
       Accept：客户端可识别的内容类型列表。
       
       Host：请求的主机名，允许多个域名同处一个IP地址，即虚拟主机。
       
       （3）空行
       
       最后一个请求头之后是一个空行，发送回车符和换行符，通知服务器以下不再有请求头。
       
       （4）实体数据
       
       请求数据不在GET方法中使用，而是在POST方法中使用。POST方法适用于需要客户填写表单的场合。与请求数据相关的最常使用的请求头是
       
       （照片上次的时候用到的请求头是content-type）Content-Type和Content-Length。
       
       
       
       404代表找不到服务器的资源。
       
       500 代表服务器遇到了意料不到的情况，不能完成客户的请求。
       
       
       解析问题
       
       
       4.你是如何处理xml解析的？
       
       SAX 流式解析 解析比较慢
       
       DOM 整个文档加载到内存 一下子就解析了  比较快 但耗内存
       
       KissXML第三方
       
       setNetworkActivityIndicatoryVisible 请求网络时出现的风火轮
       
       使用系统控件NSXMLParser实现解析。
       
       对象创建：NSXMLParser *parser = [[NSXMLParser alloc] initWithData:data];
       
       委托方法：
       
       [parser setDelegate:self];
       
       设置委托后，委托方法自动执行，根据xml文件的标签进行解析。
       
       
       
       5.你是如何处理json解析的？ 底层如何实现
       
       1网上下载json开发包实现json数据的解析。
       
       
       2底层原理是遍历字符串中的字符，最终根据格式规定的特殊字符，比如{}号，[]号, : 号 等进行区分，
       
       
       {}号是一个字典的开始，[]号是一个数组的开始, : 号是字典的键和值的分水岭，最终乃是将json数据转化为字典，字典中值可能是字典，数组，或字符串而已。
       
       
       
       你还用到哪些解析方式？
       
       111#222#333｜111#222#333 为代表的字符串解析
       
       
       电话会议为代表的字节数组解析（简称二进制解析），原理就是，字节数组里某一个字节或两个字节来放置长度，表示后面多少个字节是实际内容。
       
       
       
       线程问题？
       
       
       7.线程有几种创建方法？
       
       -            (id)init;
       
       -(id)initWithTarget:  //创建对象后需要start
       
       -+ (void)detachNewThreadSelector.
       
       -
       
       -            GCD
       
       -
       
       -            NSOperation
       
       
       
       12.什么是线程的同步？（线程没有什么异步的说法）
       
       多线程环境中，一个线程访问资源时，让其他线程不能访问此资源，表示同步。让线程同步，就是对资源加锁。具体是创建NSCondition对象，调用lock方法对资源加锁。
       
       
       在分线程中回调主线程的方法？
       
       1， [target performSelector:@selector(addData:) onThread:[NSThread mainThread] withObject:item waitUntilDone:YES];
       
       
       2，[self performSelectorOnMainThread:@selector(buttonGo2) withObject:nil waitUntilDone:YES];
       
       
       多线程同步问题？
       
       线程锁（多线程机制）
       
       答：NSCondition  类
       
       方法：
       
       NSConditon *myCondition;
       
       [myCondition lock];//加锁
       
       sleep(n);//线程休眠
       
       [myCondition singnal];//相当于通知，告诉其他线程
       
       [myCondition unlock];//解锁
       
       [NSThread exit];//线程退出
       
       
       
       
       
       14.操作队列的作用？（可以理解为线程池或者线程队列）
       
       
       常用于需要启动多个线程分别完成特定任务的场合。
       
       一个继承NSOperition的类的对象，可以放到到操作队列中，操作队列会在内部启动线程之行那个对象的main方法，当main方法执行完毕，操作对象会将那个对象移除。
       
       队列 不用关线程同步问题
       
       
       
       
       
       设计模式问题？好扩展 维护 耦合
       
       mvc设计模式 ，模型，视图，控制器，可以将整个应用程序在思想上分成三大块，对应是的数据的存储或处理，前台的显示，业务逻辑的控制。 Iphone本身的设计思想就是遵循mvc设计模式。其不属于23中设计模式范畴。
       
       
       怎么实现一个单例模式？
       
       +(WatchDog *)luckDog{
           
           @synchronized(self){
               
               if(nil==_instance){
                   
                   _instance=[[WatchDog alloc] init]
                   
               }
               
               retrun _instance;
               
           }
           
           
       }
       
       代理模式：两个对象协同完成同一个操作，iphone中大量的委托机制就是使用代理模式。
       
       
       观察者模式：一个对象发现变化，立刻通知另外一个对象或多个对象。  
       
       Iphone的 NSNotificationCenter就是使用观察者模式。
       
       UIApplication *app = [UIApplication sharedApplication];
       
       [[NSNotificationCenter defaultCenter] addObserver:self
        
                                                selector:@selector(applicationWillTerminate:)
        
                                                    name:UIApplicationWillTerminateNotification
        
                                                  object:app];
       
       
       数据存储问题？
       
       
       数据存储的形式有哪些？
       
       1,Sqlite
       
       2,NSString(writetofile) ,NSData(writetofile), NSArray(writetofile 必须是string data 等类型 plist文件),  NSDictionary(writetofile)这些基本类型都可以直接进行文件存取。
       
       3,对象序列化可将对象保存在文件里。
       
       4,Core data 跟对象序列化差不多，只不过提供了可视化创建将被序列化的对象的模型。(NSEncodeing)
       
       5,直接进行io操作。NSInputStream, NSOutputStream
       
       
       分页重点啊
       
       每次取几行 select * from table limit 10,50;
       
       
       plist文件怎么获取里面的数据？
       
       以通过字典直接读入plist，将来从字典中获取数据
       
       
       NSDictionary *dict = [[NSDictionary alloc] initWithContentsOfFile:path];
       
       
       plist最大的特点是标签是一些规定标签，比如字典对应<dict>,数组对应<array>,
       
       字符串对应<string>
       
       
       
       sqlite和sqlserver有哪些区别？
       
       
       sqlite只能添加和修改字段，不能删除字段。
       
       sqlite只支持单事务，不能支持多事务。
       
       Sqlite 对触发器支持不完整。
       
       Sqlite 对左连接右连接支持的不好
       
       
       什么是左连接和右连接？
       
       
       左连接:以左表为基础来连接,如果左表的某行内容无法在右表中找到相对的row,则将右表统统用null来表示.
       
       右连接:与左连接相反.
       
       
       
       
       
       其他零散问题？
       
       
       16.怎样查看一个对象的引用计数？
       
       retainCount方法
       
       
       
       
       18.Kvc是什么，Kvo是什么？有什么特性？
       
       1、Key-value coding 机制允许通过变量名设置和获取变量值。
       
       
       [myObject setValue:valueObject forKey:@"myKey"];
       
       
       
       [myObject valueForKey:@"myKey"];
       
       
       KVC只能处理对象，不能处理int、float等类型；
       
       
       2、Key-value observing    将变量与某个控件绑定，当变量变化时，将通知控件进行相应改变。
       
       
       
       
       20.浅复制（拷贝）和深复制（拷贝）分别指的是什么？
       
       答：浅复制和深复制是对于包含对象成员的对象而言的。
       
       浅复制：只复制对象本身，对象的成员只复制指针。
       
       深复制：在浅复制的基础上，同时复制对象的成员。
       
       线程和进程之间的区别？
       
       进程在执行过程中拥有独立的内存单元，而多个线程共享内存单元。进行可以包含多个线程。
       
       一个程序至少拥有一个进程，一个进程至少有一个线程。
       
       
       什么叫响应者链？
       
       UIApplication、UIWindow、和UIView－都是UIResponder的直接或间接子类的实例响应者，
       
       说白了不就是一个窗口中添加了多个视图，处于最上层的优先获得响应，一旦上面的获得，下面的获得不了了。
       
       
       
       
       
       问  你做iphone开发时候，有哪些传值方式？View和view之间是如何传值的？
       
       对象的property属性传值。
       
       方法参数传值。
       
       静态方法传值
       
       NSUserDefault传值
       
       还有用给指向指针的指针赋值的方式传值。
       
       
       
       问，让一个物体从界面中的一点运动到另外一点，有哪些方法？
       
       四种方式，1 beginAnimation 2 线程 3 NSTimer 4 图层动画（路径）
       
       ，5 touch事件
       
       
       问，你了解哪些加密方式？
       
       Base64, MD5等常见加密方式, 循环右移位等自定义加密方式
       
       
       问，java里的对象和object-c的对象有什么区别？arc iphone5自动释放内存
       
       java对象可以自动被垃圾回收器回收，iphone里的对象则分为
       
       手动释放和autorelease, java对象赋给一个句柄，底层虽为指针，但并不如此说。iphone对象赋值给一个指针，明确说明指针保存对象的地址。
       
       
       是否支持try—catch
       
       
       支持，可以用来检测异常，但是因为ios系统并非象java那样的虚拟机模式，所以检测的异常很有限。
       
       
       NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
       
       
       Fraction * f = [[Fraction alloc] init];
       
       
       @try{
           
           [f noSuchMethod];
           
           
       }
       
       @catch (NSException *exception){
           
           NSLog (@"Caught %@%@", [exception name], [exception reason]);
           
       }
       
       
       
       [pool drains];
       
       
       
       问，你了解图层么？能用图层做些什么
       
       
       放大，缩小，渐变， 设置路径，旋转等
       
       
       
       
       iphone和ipad里有什么区别，有哪些组件不一样？
       
       Ipad里面多了两个控件：弹出控制器(UIPopoverController)，分割视图控制器(UISplitViewController)
       
       
       问，你平时是如何学习iphone的，常去哪些外国网站。
       
       HYPERLINK "http://www.cocoachina.com/"http://www.cocoachina.com/
       
       国外网站：
       
       
       定时器误差
       
       误差的原因：定时器到时间后产生定时中断，然后事件触发后调用到你的selector可能花费了较长时间。
       
       比如说：一开始的调用OK，没问题。但是你选中了repeat之后，定时器在到时间后不会被停止，又在走时。如果系统在定时器事件到达后花费了10ms才调用到了你的selector，那么这个时间差就会不断地被积累。
       
       
       
       
       解决方法：计算出执行方法所需要的时间，CFTimeInterval curr = CFAbsoluteTimeGetCurrent();   根据所需要的时间更新nstimer基准值
       
       
       
       
       你切换界面用到了哪些方式？
       
       
       1，以登陆注册为代表的直接切换法。删除原视图，把新控制的视图添加到到UIWindow上
       
       
       2，以导航为代表的压栈法
       
       
       3，以模态为代表的 [self presentModalViewController:four animated:YES];
       
       
       
       
       
       
       项目问题
       
       
       具体说说你在项目中做了哪些模块，此模块的是怎么实现的？
       
       
       
       
       
       
       电话会议用到的什么技术？是自己实现的多人会议吗？
       
       
       
       
       不是，是通过联通的电话回拨技术。给联通发送请求的时候用的是循环右移动自定义的加密方法，与联通的需求文档想照应的。
       
       
       
       
       
       
       
       
       
       
       
       
       能通过加载数据的大小来计算UIWebView的大小吗？
       
       
       
       
       不能
       
       
       
       
       
       
       
       
       你的项目都用到哪些控件了？
       
       
       
       
       几乎所有控件都用到了。（这样回答太笼统，强烈建议一口气说出各种控件的类名, 我还会自定义控件）
       
       
       
       
       
       
       怎么通过数据内容的多少来计算UILabel的frame大小？
       
       
       
       
       气泡聊天生成气泡视图那有写。
 
 
 
 
 ++++++
 ----------------------------------------单例
 +(ABCDEFG*)abc
 {
 static ABCDEFG *aa;
 @synchronized(self)
 {
 if(aa==nil)
 {
 aa=[[ABCDEFG alloc]init];
 }
 return aa;
 }
 }
 
 
 
 
 
 
 
 
 
 
 -------------------------------------------------C语言冒泡排序
 void swap(int *a,int length)
 
 {
 
 for (int i=0; i<length; i++) {
 
 for (int j=0; j<length-i-1; j++) {
 
 if (a[j]<a[j+1]) {
 
 int temp=a[j];
 
 a[j]=a[j+1];
 
 a[j+1]=temp;
 
 temp=a[j+1];
 
 }
 
 }
 
 }
 
 }
 
 
 
 int main()
 
 {
 
 int a[10]={1,2,3,4,5,6,7,8,9,0};
 
 swap(a, 10);
 
 
 
 for (int i =0; i<10; i++) {
 
 printf("%d ",a[i]);
 
 }
 
 }
 
 
 
 
 
 
 
 
 
 ----------------------------------------------------------------------OC语言冒泡排序
 NSMutableArray* a=[[NSMutableArray alloc]initWithObjects:@"1",@"26",@"4",    nil];
 
 for (int i=0; i<a.count; i++) {
 
 for (int j=0; j<a.count; j++) {
 
 int aa=[[a objectAtIndex:i]intValue];
 
 int bb=[[a objectAtIndex:j]intValue];
 
 if (aa>bb) {
 
 [a replaceObjectAtIndex:i withObject:[NSString stringWithFormat:@"%d",bb]];
 
 [a replaceObjectAtIndex:j withObject:[NSString stringWithFormat:@"%d",aa]];
 
 }
 
 }
 
 }
 
 for (int i =0; i<3; i++) {
 
 NSLog(@"%@",a[i]);
 
 }
 
 @brief 图片加载通用函数 * @parma imageName 图片名  - (void)imageStartLoading:(NSString *)imageName{ NSURL *url = [NSURL URLWithString:imageName]; if([_fileUtil hasCachedImage:url]){ UIImageView *imageView = [[UIImageView alloc] init]; NSString *path = [_fileUtil pathForUrl:url]; imageView = [_imageLoad compressImage:MY_WIDTH/3 imageView:nil imageName:path flag:NO]; [self addImage:imageView name:path]; [self adjustContentSize:NO]; }else{ UIImageView *imageView = [[UIImageView alloc] init]; NSDictionary *dic = [NSDictionary dictionaryWithObjectsAndKeys:url, @"URL", imageView, @"imageView", nil]; [NSThread detachNewThreadSelector:@selector(cacheImage:) toTarget:[ImageCacher shareInstance] withObject:dic]; } }
这个函数的作用是为每一张网络图片开启一个下载线程，但是因为该程序用到了图片缓存的技术，所以在每次开线程下载图片的时候都会去本地缓存目录查找一下，- 这里我用了比较轻量级的NSThread,detachNewThreadSelector函数中所传的函数名：
cacheImage是类ImageCache中得函数，这里通过iOS开发中使用的比较多的单例模式，

得到了ImageCache的句柄，参数dic中主要存放了图片的网络地址以及imageView用来add图片进视图以及根据图片的大小压缩成合适的大小.-(void)cacheImage:(NSDictionary*)dic{
    NSURL *url = [dic objectForKey:@"URL"]; NSFileManager *fileManage = [NSFileManager defaultManager]; NSData *data = [NSData dataWithContentsOfURL:url]; NSString *fileName = [_fileUtil pathForUrl:url]; if(data){ [fileManage createFileAtPath:fileName contents:data attributes:nil]; } UIImageView *imageView = [dic objectForKey:@"imageView"]; imageView.image = [UIImage imageWithData:data]; imageView = [_imageLoader compressImage:MY_WIDTH/3 imageView:imageView imageName:nil flag:YES]; [self.myDelegate addImage:imageView name:fileName]; [self.myDelegate adjustContentSize:NO]; }
该函数用来将下载下来的图片缓存进入文件沙盒中（缓存文件可以自己定义并指定）,并且按照图片的大小进行等比例压缩，固定宽度是屏幕的三分之一大小，这样一来，
图片显示就不会出现不全或失真的现象。由于ImageCache和MyScrollView是两个独立的类，所以这里通过使用ios的delegate(代理)来进行图片在scrollView上的加载，



下面我们来看如何在沙盒中建立缓存文件夹，其实缓存文件夹跟普通的文件夹一样，只是该文件夹是专门用来存放缓存文件的而已。类代码如下所示：//

// FileUtil.m // Test515 // // Created by silicon on 14-5-30. // Copyright (c) 2014年 silicon. All rights reserved. // #import "FileUtil.h" @implementation FileUtil + (FileUtil *)shareInstance{ static FileUtil *instance; static dispatch_once_t onceToken; dispatch_once(&onceToken, ^{ instance = [[self alloc] init]; }); return instance; }  
 @breif 创建缓存文件夹  - (void)createPathInDocumentDirectory{ NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES); NSString *diskCachePath = [[[paths objectAtIndex:0] stringByAppendingPathComponent:@"ImageCache"] retain]; NSLog(@"%@", diskCachePath); if(![[NSFileManager defaultManager] fileExistsAtPath:diskCachePath]){ NSError *error = nil; [[NSFileManager defaultManager] createDirectoryAtPath:diskCachePath withIntermediateDirectories:YES attributes:nil error:&error]; } }  
 @breif 获取沙盒中文档目录 @param fileName:文件名字  - (NSString *)pathInDocumentDirectory:(NSString *)fileName{ NSArray *fileArray = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES); NSString *cacheDirectory = [fileArray objectAtIndex:0]; return [cacheDirectory stringByAppendingPathComponent:fileName]; }  
 @breif 获取沙盒中缓存文件目录  @param fileName:文件名字  - (NSString *)pathInCacheDirectory:(NSString *)fileName{ NSArray *fileArray = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES); NSString *cacheDirectory = [fileArray objectAtIndex:0]; return [cacheDirectory stringByAppendingPathComponent:fileName]; } 
 @breif 判断是否已经缓存 @param url:图片名称  - (BOOL)hasCachedImage:(NSURL *)url{ NSFileManager *fileManager = [NSFileManager defaultManager]; if([fileManager fileExistsAtPath:[self pathForUrl:url]]){ return YES; }else{ return NO; } } 
 @breif 根据URL的給图片命名 @param url:图片url  - (NSString *)pathForUrl:(NSURL *)url{ return [self pathInCacheDirectory:[NSString stringWithFormat:@"qiaoqiao-%u", [[url description] hash]]]; } @end
//在这次的demo中，我新加入了用户可以点击图片放大 并可以左右滑动的功能，其实实现起来很简单，我一开始为每一个ScrollView 中得ImageView都设置了tag值，并且添加了
//手势（UITapGestureRecognizer），当用户点击图片时，程序可以根据点击视图的tag值来获得相应的图片是哪一张，从而可以加载。支持左右滑动的功能在新的界面中增加了

//一个ScrollView,然后将下载下来的图片添加到scrollView中。代码如下



// // PhotoViewController.m // Test515 // // Created by silicon on 14-5-22. // Copyright (c) 2014年 silicon. All rights reserved. // #import "PhotoViewController.h" #import "ImageLoader.h" @interface PhotoViewController () @end @implementation PhotoViewController @synthesize scrollView = _scrollView; @synthesize imageArray = _imageArray; @synthesize page = _page; - (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil { self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]; if (self) { // Custom initialization } return self; } - (void)viewDidLoad { [super viewDidLoad]; // Do any additional setup after loading the view. [self.view setFrame:CGRectMake(0, 0, MY_WIDTH, MY_HEIGHT)]; [self.view setBackgroundColor:[UIColor blackColor]]; self.scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 20, MY_WIDTH, MY_HEIGHT)]; _scrollView.delegate = self; _scrollView.contentSize = CGSizeMake(MY_WIDTH * [_imageArray count], MY_HEIGHT); _scrollView.showsVerticalScrollIndicator = NO; _scrollView.showsHorizontalScrollIndicator = NO; _scrollView.backgroundColor = [UIColor blackColor]; _scrollView.bounces = YES; _scrollView.pagingEnabled = YES; [self.view addSubview:_scrollView]; //图片添加事件响应 UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(closePhotoView)]; tapRecognizer.delegate = self; _scrollView.userInteractionEnabled = YES; [_scrollView addGestureRecognizer:tapRecognizer]; [tapRecognizer release]; [self loadingImages]; } - (void)viewWillAppear:(BOOL)animated{ [_scrollView setContentOffset:CGPointMake([_imageArray indexOfObject:_imageName] * MY_WIDTH, 0)]; } - (void)didReceiveMemoryWarning { [super didReceiveMemoryWarning]; // Dispose of any resources that can be recreated. } //关闭 - (void)closePhotoView{ [self.view removeFromSuperview]; } - (void)dealloc{ [_scrollView release]; [super dealloc]; } - (void)loadingImages{ //加载图片 for(int i = 0; i < [_imageArray count]; i++){ NSString *picName = [_imageArray objectAtIndex:i]; UIImageView *imageV = [[ImageLoader shareInstance] compressImage:MY_WIDTH imageView:nil imageName:picName flag:NO]; float width = imageV.image.size.width; float height = imageV.image.size.height; float new_width = MY_WIDTH; float new_height = (MY_WIDTH * height)/width; imageV.frame = CGRectMake(MY_WIDTH * i, 0, new_width, new_height); [_scrollView addSubview:imageV]; [imageV release]; } } - (void)scrollViewDidScroll:(UIScrollView *)_scrollView{ }
 
 
 
 
 */

@end
