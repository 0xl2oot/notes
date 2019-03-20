#import "DeviceInfo.h"

@implementation DeviceInfo

// 返回时否是手机
+ (BOOL)deviceIsPhone{
    
    BOOL _isIdiomPhone = YES;// 默认是手机
    UIDevice *currentDevice = [UIDevice currentDevice];
    
    // 项目里只用到了手机和pad所以就判断两项
    // 设备是手机
    if (currentDevice.userInterfaceIdiom == UIUserInterfaceIdiomPhone) {
        
        _isIdiomPhone = YES;
    }
    // 设备室pad
    else if (currentDevice.userInterfaceIdiom == UIUserInterfaceIdiomPad){
        
        _isIdiomPhone = NO;
    }
    
    return _isIdiomPhone;
}
@end
