#import "PuzzlePiece.h"

@implementation PuzzlePiece

+ (instancetype)pieceWithID:(NSInteger)ID image:(UIImage *)image {
    PuzzlePiece *piece = [[PuzzlePiece alloc] init];
    piece.ID = ID;
    piece.layer.borderWidth = 1;
    piece.layer.borderColor = [UIColor whiteColor].CGColor;
    [piece setBackgroundImage:image forState:UIControlStateNormal];
    return piece;
}

@end
