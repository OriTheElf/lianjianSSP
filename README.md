# lianjianSSP接入文档
```
1. 横幅广告
2. 插屏广告
```

## 接入lianjianSSP
设置网络请求模式为允许http协议访问，设置方法是，首先找到以-Info.plist结尾的项目配置文件，添加NSAppTransportSecurity，将其Type属性设置为Dictionary；然后添加NSAllowsArbitraryLoads，将其Type属性设置为Boolean，然后设置为YES。如图所示:
![turn_off_ATS](http://owi3iar2y.bkt.clouddn.com/turn_off_ATS.png)
开启定位权限
![turn_on_location](http://owi3iar2y.bkt.clouddn.com/setup_locate_info_plist.png)
设置跳转地图的Scheme
![add_map_schemes](http://owi3iar2y.bkt.clouddn.com/add_schemes.png)
### info.plist文件的配置
```
<key>NSAppTransportSecurity</key>
<dict>
	<key>NSAllowsArbitraryLoads</key>
	<true/>
</dict>
<key>NSLocationWhenInUseUsageDescription</key>
<string>允许获取位置</string>
<key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
<string>允许获取位置</string>
<key>LSApplicationQueriesSchemes</key>
<array>
	<string>baidumap</string>
	<string>iosamap</string>
</array>
```
####集成方式
> 自动集成

如果你使用 Cocoapods做第三方框架依赖，只需要在Podfile里添加如下代码，执行`pod update`即可

#### Podfile

```ruby
platform :ios, '8.0'

target 'TargetName' do
  pod 'lianjianSSP'
end
```
> 手动集成

1. [点此下载](https://github.com/OrisForest/lianjianSSP)最新的示例程序，把 `lianjianSSP.framework` 文件和`LSResource.bundle`文件添加到你的项目中
2. 在项目Target的Build Settings中查找 Other Linker Flags, 添加 '-ObjC' 
3. 完成上面两步以后如果编译没有错误，就可以开始使用了

##使用方法
在想要集成广告的控制器中引入头文件 `import <lianjianSSP/lianjianSSP.h>`

***注意:
1. 执行`[LMLaunchManager openDebugLog:YES];`可显示日志信息
2. 横幅广告 Banner的`hostController`属性为必填项
3. 插屏广告的`LSAdInstlManager`对象需被其他对象强引用
4. SDK中使用了IDFA广告标识符，如果你的应用要上传到App Store，请正确配置IDFA一栏***
***示例代码:

> 获取横幅广告

```
// 顶部横幅
[LSBannerView bannerWithTagid:@"127" setup:^(LSBannerView *set) {
    set.hostController = self;
    set.adSize = kLSSizeBanner;
    set.delegate = self;
    set.refreshInterval = 20;
}];

// 底部横幅
[LSBannerView bannerWithTagid:@"222" setup:^(LSBannerView *set) {
    set.hostController = self;
    set.adSize = kLSSizeBanner;
    set.position = LSBannerPositionBottom;
    set.delegate = self;
    set.refreshInterval = 20;
}];

// 可配置参数
/**
 横幅广告位置（默认为在顶部显示）
 */
@property (nonatomic, assign) LSBannerPosition position;

/**
 相对顶部或底部的偏移（范围:[0...100],默认为0）
 */
@property (nonatomic, assign) CGFloat offset;

/**
 广告尺寸大小
 可选推荐尺寸,也可自定广告位尺寸
 kLSSizeBanner [320x50]
 kLSSizeLargeBanner [320x100]
 kLSSizeMediumRectangle [320x250]
 kLSSizeFullBanner [468x60]
 kLSSizeLeaderboard [728x90]）
 */
@property (nonatomic, assign) CGSize adSize;

/**
 自动刷新时间(单位: 秒)（范围[20...60],设置为0不轮播,默认20s）
 */
@property (nonatomic) NSUInteger refreshInterval;

/**
 代理对象
 */
@property (nonatomic, weak) id <LSBannerViewDelegate> delegate;

/**
 宿主视图控制器（必选项）
 */
@property (nonatomic, weak) UIViewController *hostController;

/**
 是否使用Safari打开广告详情 (默认使用内部浏览器打开)
 */
@property (nonatomic, assign) BOOL showAdDetailUsingSafari;

/**
 关闭按钮位置 (默认在右上角显示)
 */
@property (nonatomic, assign) LSAdCloseButtonPosition closeButtonPosition;

/**
 切换动画 (默认为自动切换动画效果)
 */
@property (nonatomic, assign) LSAnimation animation;

```
> 获取插屏广告

```
LSAdInstlManager *instlManager = [LSAdInstlManager managerWithPlacementID:@"225" delegate:self];
instlManager.openInside = YES;
instlManager.instlSize = kLSSize300x250;
instlManager.animation = LSAnimationTransitionAuto;
[instlManager loadAdInstl];
self.instlManager = instlManager;

// 可配置参数
/**
 自动切换时间(秒)（范围[20...60],设置为0不轮播,默认20s）
 */
@property (nonatomic) NSUInteger refreshInterval;

/**
  关闭按钮位置 (默认在右上角显示)
 */
@property (nonatomic, assign) LSAdCloseButtonPosition closePosition;

/**
 点击后是否移除广告广告  YES 是 NO 否  默认为 NO
*/
@property (nonatomic, assign, getter=isHiddenWhenClicked) BOOL hiddenWhenClicked;

/**
 广告尺寸 (默认全屏)
*/
@property (nonatomic, assign) CGSize instlSize;

/**
 广告点击跳转 YES 应用内打开  NO跳转Safari打开链接  默认为 NO
 */
@property (nonatomic, assign) BOOL openInside;


/**
 切换动画 默认LSAnimationTransitionFade
 */
@property (nonatomic, assign) LSAnimation animation;
```
