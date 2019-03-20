#import <UIKit/UIKit.h>

@interface PuzzlePiece : UIButton

/// 本方块在原图上的位置，从0开始编号
@property (nonatomic, assign) NSInteger ID;

/// 创建实例
+ (instancetype)pieceWithID:(NSInteger)ID image:(UIImage *)image;

@end
